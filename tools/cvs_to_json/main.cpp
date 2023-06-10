#include <iostream>
#include <fstream>
#include <string>

#include "external/csv.h"

int main()
{
    std::ofstream output_json_stream(OUTPUT_JSON_FILE);

    io::CSVReader<8, io::trim_chars<' '>, io::double_quote_escape<',','\"'> > in("symbols.csv");    
    in.read_header(io::ignore_no_column, "index", "symbol", "value", "table", "overlayable", "destination address string", "ssid", "description");
    
    std::string json;
    json.append("{\n");
    json.append("    \"symbols\": [\n");

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
        json.append("        {\n");
        json.append("            \"index\": \"" + index + "\",\n");
        json.append("            \"name\": \"" + name + "\",\n");
        json.append("            \"description\": \"" + description + "\",\n");
        if (value == "\\")
            json.append("            \"value\": \"\\\\\",\n");                
        else
            json.append("            \"value\": \"" + value + "\",\n");
        if (table == "\\")
            json.append("            \"table\": \"\\\\\",\n");                
        else
            json.append("            \"table\": \"" + table + "\",\n");
        json.append("            \"overlayable\": \"" + overlayable + "\",\n");        
        json.append("            \"destination_address_string\": \"" + destination_address_string + "\",\n");
        json.append("            \"ssid\": \"" + ssid + "\"\n");
        json.append("        },\n");
    }

    json = json.substr(0, json.length() - 2);

    json.append("\n");
    json.append("    ]\n");
    json.append("}");

    output_json_stream << json;

    output_json_stream.close();

    return 0;
}