#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <fmt/format.h>
#include <nlohmann/json.hpp>

#include "external/csv.h"

struct parse_symbol_info
{
    int index = -1;
    std::string name;
    std::string description;
    char value = 0;
    char table = 0;
    bool overlayable = false;
    std::string destination_address;
    int ssid = -1;
    int unique_value;
    std::string image;
    int row;
    int column;
};

std::string escape_char(char ch)
{
    if (ch == '\'')
        return "\\'";
    else if (ch == '\\')
        return "\\\\";
    else if (ch == 0)
        return "\\0";
    return std::string(1, ch);
}

int main()
{
    // **************************************************************** //
    //                                                                  //
    // CSV TO JSON                                                      //
    //                                                                  //
    // **************************************************************** //

    std::string input_csv_file = std::filesystem::canonical(INPUT_CSV_FILE).string();
    std::string output_json_file = OUTPUT_JSON_FILE;

    printf("Using CSV input file: %s\n", input_csv_file.c_str());
    printf("Using JSON output file: %s\n", output_json_file.c_str());

    std::ofstream output_json_stream(output_json_file);

    io::CSVReader<11, io::trim_chars<' '>, io::double_quote_escape<',','\"'> > in(input_csv_file);    
    in.read_header(io::ignore_no_column, "index", "name", "value", "table", "overlayable", "destination address string", "ssid", "description", "image", "row", "column");
    
    std::string json_str;
    json_str.append("{\n");
    json_str.append("    \"symbols\": [\n");

    std::string index;
    std::string name;
    std::string value;    
    std::string table;
    std::string overlayable;
    std::string destination_address_string;
    std::string ssid;
    std::string description;
    std::string image;
    std::string row;
    std::string column;

    while (in.read_row(index, name, value, table, overlayable, destination_address_string, ssid, description, image, row, column))
    {
        json_str.append("        {\n");
        json_str.append("            \"index\": \"" + index + "\",\n");
        json_str.append("            \"name\": \"" + name + "\",\n");
        json_str.append("            \"description\": \"" + description + "\",\n");
        if (value == "\\")
            json_str.append("            \"value\": \"\\\\\",\n");                
        else
            json_str.append("            \"value\": \"" + value + "\",\n");
        if (table == "\\")
            json_str.append("            \"table\": \"\\\\\",\n");                
        else
            json_str.append("            \"table\": \"" + table + "\",\n");
        json_str.append("            \"overlayable\": \"" + overlayable + "\",\n");        
        json_str.append("            \"destination_address_string\": \"" + destination_address_string + "\",\n");
        json_str.append("            \"ssid\": \"" + ssid + "\",\n");
        json_str.append("            \"image\": \"" + image + "\",\n");
        json_str.append("            \"row\": \"" + row + "\",\n");
        json_str.append("            \"column\": \"" + column + "\"\n");
        json_str.append("        },\n");
    }

    json_str = json_str.substr(0, json_str.length() - 2);

    json_str.append("\n");
    json_str.append("    ]\n");
    json_str.append("}");

    output_json_stream << json_str;

    output_json_stream.close();

    // **************************************************************** //
    //                                                                  //
    // JSON PARSING                                                     //
    //                                                                  //
    // **************************************************************** //

    std::string output_cpp_file = OUTPUT_CPP_FILE;

    std::ifstream input_json_file(OUTPUT_JSON_FILE);
    std::ofstream output_cpp_stream(output_cpp_file);

    printf("Using C++ output file: %s\n", output_cpp_file.c_str());
    
    nlohmann::json json_object;
    input_json_file >> json_object;

    std::vector<parse_symbol_info> symbols;    

    for (const auto& symbol : json_object["symbols"])
    {
        std::string index = symbol["index"];
        std::string name = symbol["name"];
        std::string description = symbol["description"];
        std::string value = symbol["value"];
        std::string table = symbol["table"];
        std::string overlayable = symbol["overlayable"];
        std::string destination_address = symbol["destination_address_string"];
        std::string ssid = symbol["ssid"];
        std::string image = symbol["image"];
        std::string row = symbol["row"];
        std::string column = symbol["column"];

        parse_symbol_info s;

        if (!index.empty())
        {
            s.index = atoi(index.c_str());
        }

        s.name = name;
        s.description = description;

        if (!value.empty())
        {
            s.value = value[0];
        }

        if (!table.empty())
        {
            s.table = table[0];
        }

        s.overlayable = (overlayable == "true") ? true : false;

        s.destination_address = destination_address;

        if (!ssid.empty())
        {
            s.ssid = atoi(ssid.c_str());
        }

        s.image = image;
        
        if (!row.empty())
        {
            s.row = atoi(row.c_str());
        }

        if (!column.empty())
        {
            s.column = atoi(column.c_str());
        }
      
        symbols.push_back(s);
    }

    // **************************************************************** //
    //                                                                  //
    // HTML GENERATION                                                  //
    //                                                                  //
    // **************************************************************** //

    std::string output_html_file = OUTPUT_HTML_FILE;

    std::ofstream output_html_stream(output_html_file);

    printf("Using HTML output file: %s\n", output_html_file.c_str());

    std::string html;

    html.append("<!DOCTYPE html>\n"
                "<html>\n"
                "<head>\n"
                "  <title>APRS symbols</title>\n"
                "  <style>\n"
                "    table {\n"
                "      border-collapse: collapse;\n"
                "      width: auto;\n"
                "    }\n"
                "    th, td {\n"
                "      border: 1px solid black;\n"
                "      padding: 8px;\n"
                "      text-align: left;\n"
                "      white-space: nowrap;\n"
                "    }\n"
                "    th {\n"
                "      background-color: #f2f2f2;\n"
                "    }\n"
                "  </style>\n"
                "</head>\n"
                "<body>\n"
                "  <table>\n"
                "    <tr>\n"
                "      <th>Index</th>\n"
                "      <th>Name</th>\n"
                "      <th>Description</th>\n"
                "      <th>Value</th>\n"
                "      <th>Table</th>\n"
                "      <th>Overlayable</th>\n"
                "      <th>Destination Address</th>\n"
                "      <th>SSID</th>\n"
                "    </tr>\n");

    for (const auto& symbol : symbols)
    {
        html.append("    <tr>\n");        
        
        if (symbol.index > 0)
        {
            html.append("      <td>" + std::to_string(symbol.index) + "</td>\n");
        }
        else
        {
            html.append("      <td></td>\n");
        }
        html.append("      <td>" + symbol.name + "</td>\n");
        html.append("      <td>" + symbol.description + "</td>\n");
        if (symbol.value != 0)
        {
            html.append("      <td>" + std::string(1, symbol.value) + "</td>\n");
        }
        else
        {
            html.append("      <td></td>\n");
        }
        if (symbol.table != 0)
        {        
            html.append("      <td>" + std::string(1, symbol.table) + "</td>\n");
        }
        else
        {
            html.append("      <td></td>\n");
        }
        html.append("      <td>" + std::string(symbol.overlayable ? "true" : "false") + "</td>\n");
        html.append("      <td>" + symbol.destination_address + "</td>\n");
        if (symbol.ssid > 0)
        {
            html.append("      <td>" + std::to_string(symbol.ssid) + "</td>\n");
        }
        else
        {
            html.append("      <td></td>\n");
        }
        
        html.append("    </tr>\n");
    }

    html.append("  </table>\n"
            "</body>\n"
            "</html>\n");

    output_html_stream << html;

    output_html_stream.close();

    // **************************************************************** //
    //                                                                  //
    // STAGGERED ENUM GENERATION                                        //
    //                                                                  //
    // **************************************************************** //
    
    std::vector<parse_symbol_info> pri_symbols;
    std::vector<parse_symbol_info> alt_symbols;

    for (const auto& symbol : symbols)
    {
        if (symbol.table == '/')
            pri_symbols.push_back(symbol);
        else if (symbol.table == '\\')
            alt_symbols.push_back(symbol);
        else if (symbol.table != 0)
            alt_symbols.push_back(symbol);
    }

    std::sort(pri_symbols.begin(), pri_symbols.end(), [](const parse_symbol_info& a, const parse_symbol_info& b) {
        return a.value < b.value;
    });

    std::sort(alt_symbols.begin(), alt_symbols.end(), [](const parse_symbol_info& a, const parse_symbol_info& b) {
        return a.value < b.value;
    });

    std::string cpp;

    std::string staggered_enum_name = "symbol_staggered";

    cpp.append("enum class " + staggered_enum_name + " : int\n");
    cpp.append("{\n");

    size_t i = 0, j = 0;
    while (true)
    {
        if (i < pri_symbols.size() && j < alt_symbols.size())
        {
            if (pri_symbols[i].value == alt_symbols[j].value)
            {
                cpp.append(fmt::format("    {:<34}", pri_symbols[i].name + " = '" + escape_char(pri_symbols[i].value) + "',"));
                cpp.append("" + alt_symbols[j].name + " = '" + escape_char(alt_symbols[j].value) + "' + 200,");
                cpp.append("\n");
                i++;
                j++;
                continue;
            }
            else if (pri_symbols[i].value < alt_symbols[j].value)
            {
                cpp.append("    " + pri_symbols[i].name + " = '" + escape_char(pri_symbols[i].value) + "',");
                cpp.append("\n");
                i++;
                continue;
            }
            else if (pri_symbols[i].value > alt_symbols[j].value)
            {
                cpp.append(fmt::format("    {:<34}", " "));
                cpp.append("" + alt_symbols[j].name + " = '" + escape_char(alt_symbols[j].value) + "' + 200,");
                cpp.append("\n");
                j++;
                continue;
            }
        }
        if (i < pri_symbols.size())
        {
            cpp.append("    " + pri_symbols[i].name + " = '" + escape_char(pri_symbols[i].value) + "',");
            cpp.append("\n");
            i++;
            continue;
        }
        if (j < alt_symbols.size())
        {
            cpp.append("    " + alt_symbols[j].name + " = '" + escape_char(alt_symbols[j].value) + "' + 200,");
            cpp.append("\n");
            j++;
            continue;
        }
        break;        
    }

    cpp.append("};\n");

    cpp.append("\n");

    // **************************************************************** //
    //                                                                  //
    // ENCODED ENUM GENERATION                                          //
    //                                                                  //
    // **************************************************************** //

    std::vector<parse_symbol_info> pri_alt_symbols;

    pri_alt_symbols.insert(pri_alt_symbols.end(), pri_symbols.begin(), pri_symbols.end());
    pri_alt_symbols.insert(pri_alt_symbols.end(), alt_symbols.begin(), alt_symbols.end());

    std::string encoded_enum_name = "symbol_encoded";

    cpp.append("enum class " + encoded_enum_name + " : int\n");
    cpp.append("{\n");

    for (const auto& symbol : pri_alt_symbols)
    {
        if (symbol.table == '/')
            cpp.append("    " + symbol.name + " = '" + escape_char(symbol.value) + "',\n");
        else if (symbol.table == '\\')
            cpp.append("    " + symbol.name + " = '" + escape_char(symbol.value) + "' + 200,\n");
        else if (symbol.table == 'A')
            cpp.append("    " + symbol.name + " = '" + escape_char(symbol.value) + "' + 400,\n");
        else if (symbol.table == 'R')
            cpp.append("    " + symbol.name + " = '" + escape_char(symbol.value) + "' + 500,\n");
    }

    cpp.append("};\n");

    cpp.append("\n");

    // **************************************************************** //
    //                                                                  //
    // BASIC ENUM GENERATION                                            //
    //                                                                  //
    // **************************************************************** //

    std::string enum_name = "symbol";

    cpp.append("enum class " + enum_name + " : int\n");
    cpp.append("{\n");    

    for (const auto& symbol : pri_alt_symbols)
    {
        cpp.append("    " + symbol.name + ",\n");
    }

    cpp.append("    none,\n");
    cpp.append("    no_symbol,\n");

    cpp.append("};\n");    

    cpp.append("\n");    

    // **************************************************************** //
    //                                                                  //
    // MAPS GENERATION                                                  //
    //                                                                  //
    // **************************************************************** //
    
    cpp.append("#include <vector>\n"); 
    cpp.append("#include <string>\n"); 
    cpp.append("#include <unordered_map>\n"); 
    cpp.append("\n"); 
    cpp.append(
"struct symbol_info\n"
"{\n"
"    int index = -1;\n"
"    std::string name;\n"
"    std::string description;\n"
"    char value = 0;\n"
"    char table = 0;\n"
"    bool overlayable = false;\n"
"    std::string destination_address;\n"
"    int ssid = -1;\n"
"};\n");
    cpp.append("\n");

    cpp.append("struct symbol_map\n"); 
    cpp.append("{\n");
    cpp.append("    void populate()\n"); 
    cpp.append("    {\n");

    cpp.append("        symbols.reserve(" + std::to_string(pri_alt_symbols.size()) + ");\n");

    for (const auto& symbol : pri_alt_symbols)
    {
        cpp.append("        symbols.push_back({ ");
        cpp.append(std::to_string(symbol.index));
        cpp.append(", ");
        cpp.append("\"" + symbol.name + "\"");
        cpp.append(", ");
        cpp.append("\"" + symbol.description + "\"");
        cpp.append(", ");
        cpp.append("'" + escape_char(symbol.value) + "'");
        cpp.append(", ");
        cpp.append("'" + escape_char(symbol.table) + "'");
        cpp.append(", ");
        cpp.append(symbol.overlayable ? "true" : "false");
        cpp.append(", ");
        cpp.append("\"" + symbol.destination_address + "\"");
        cpp.append(", ");
        cpp.append(std::to_string(symbol.ssid));
        cpp.append(" });\n");
    }

    cpp.append("\n");

    for (size_t i = 0; i < pri_alt_symbols.size(); i++)
    {
        if (pri_alt_symbols[i].destination_address.empty())
            continue;
        cpp.append("        destination_address_map[");
        cpp.append("\"");
        cpp.append(pri_alt_symbols[i].destination_address);
        cpp.append("\"]");
        cpp.append(" = ");
        cpp.append(std::to_string(i));
        cpp.append(";");
        cpp.append("\n");
    }

    cpp.append("\n");

    for (size_t i = 0; i < pri_alt_symbols.size(); i++)
    {
        cpp.append("        symbol_code_map[");
        if (pri_alt_symbols[i].table == '/')
            cpp.append("'" + escape_char(pri_alt_symbols[i].value) + "'");
        else if (pri_alt_symbols[i].table == '\\')
            cpp.append("'" + escape_char(pri_alt_symbols[i].value) + "' + 200");
        else if (pri_alt_symbols[i].table == 'A')
            cpp.append("'" + escape_char(pri_alt_symbols[i].value) + "' + 400");
        else if (pri_alt_symbols[i].table == 'R')
            cpp.append("'" + escape_char(pri_alt_symbols[i].value) + "' + 500");
        else
        {
            break;
        }
        cpp.append("] = ");
        cpp.append(std::to_string(i));
        cpp.append(";");
        cpp.append("\n");
    }

    cpp.append("\n");

    for (size_t i = 0; i < pri_alt_symbols.size(); i++)
    {
        cpp.append("        symbol_name_map[\"" + pri_alt_symbols[i].name);
        cpp.append("\"] = ");
        cpp.append(std::to_string(i));
        cpp.append(";");
        cpp.append("\n");
    }

    cpp.append("    }\n");
    cpp.append("\n");
    cpp.append("    std::vector<symbol_info> symbols;\n");
    cpp.append("    std::unordered_map<int, int> symbol_code_map;\n");
    cpp.append("    std::unordered_map<std::string, int> destination_address_map;\n");
    cpp.append("    std::unordered_map<std::string, int> symbol_name_map;\n");
    cpp.append("};\n");

    cpp.append("\n");
    cpp.append("\n");
    cpp.append("\n");
    cpp.append("\n");

    output_cpp_stream << cpp;

    output_cpp_stream.close();

    // **************************************************************** //
    //                                                                  //
    // JAVASCRIPT GENERATION                                            //
    //                                                                  //
    // **************************************************************** //

    std::string output_js_file = OUTPUT_JS_FILE;

    std::ofstream output_js_stream(output_js_file);

    printf("Using JavaScript output file: %s\n", output_js_file.c_str());

    std::string js;

    js.append("const lookupAprsSymbolByCode = (() => {\n");
    js.append("  const symbolCodeMap = {};\n");

    for (const auto& symbol : pri_alt_symbols)
    {
        if (symbol.image.empty())
            continue;
        js.append(fmt::format("  symbolCodeMap['{}{}'] = ", escape_char(symbol.table), escape_char(symbol.value)));   
        js.append(fmt::format("{{ row: {}, column: {}, image: \"{}\", name: \"{}\" }}\n", symbol.row, symbol.column, symbol.image, symbol.name));   
    }

    js.append("\n");
    js.append("  return (symbolTable, symbolCode) => {\n");
    js.append("    const code = symbolTable + symbolCode;\n");
    js.append("    if (!symbolCodeMap.hasOwnProperty(code)) {\n");
    js.append("      return null;\n");
    js.append("    }\n");
    js.append("    return symbolCodeMap[code];\n");
    js.append("  };\n");
    js.append("\n");
    js.append("})();\n");

    js.append("\n");

    js.append("const lookupAprsSymbolByName = (() => {\n");
    js.append("  const symbolNameMap = {};\n");

    for (const auto& symbol : pri_alt_symbols)
    {
        if (symbol.image.empty())
            continue;
        js.append(fmt::format("  symbolNameMap['{}'] = ", symbol.name));   
        js.append(fmt::format("{{ row: {}, column: {}, image: \"{}\", name: \"{}\" }}\n", symbol.row, symbol.column, symbol.image, symbol.name));   
    }

    js.append("\n");
    js.append("  return (symbolName) => {\n");
    js.append("    if (!symbolNameMap.hasOwnProperty(symbolName)) {\n");
    js.append("      return null;\n");
    js.append("    }\n");
    js.append("    return symbolNameMap[symbolName];\n");
    js.append("  };\n");
    js.append("\n");
    js.append("})();\n");

    output_js_stream << js;

    output_js_stream.close();

    return 0;
}