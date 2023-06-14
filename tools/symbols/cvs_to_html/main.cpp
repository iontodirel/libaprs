#include <iostream>
#include <fstream>
#include <string>

#include "external/csv.h"

int main()
{
    std::ofstream output_html_stream(OUTPUT_HTML_FILE);

    io::CSVReader<8, io::trim_chars<' '>, io::double_quote_escape<',','\"'> > in(INPUT_JSON_FILE);    
    in.read_header(io::ignore_no_column, "index", "name", "value", "table", "overlayable", "destination address string", "ssid", "description");
    
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

    std::string index;
    std::string name;
    std::string value;    
    std::string table;
    std::string overlayable;
    std::string destination_address_string;
    std::string ssid;
    std::string description;

    while (in.read_row(index, name, value, table, overlayable, destination_address_string, ssid, description))
    {
        html.append("    <tr>\n");        
        
        html.append("      <td>" + index + "</td>\n");
        html.append("      <td>" + name + "</td>\n");
        html.append("      <td>" + description + "</td>\n");
        html.append("      <td>" + value + "</td>\n");
        html.append("      <td>" + table + "</td>\n");
        html.append("      <td>" + overlayable + "</td>\n");
        html.append("      <td>" + destination_address_string + "</td>\n");
        html.append("      <td>" + ssid + "</td>\n");
        
        html.append("    </tr>\n");
    }

    html.append("  </table>\n"
                "</body>\n"
                "</html>\n");

    output_html_stream << html;

    output_html_stream.close();

    return 0;
}