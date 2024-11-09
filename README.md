# libaprs

C++ header only standalone APRS parsing library.

Automatic Packet Reporting System (APRS) is a system for real-time digital data communication over ham radio.

See more info at http://www.aprs.org/ and https://groups.io/g/APRS.

## Examples

### Parsing a packet:

``` cpp
aprs::packet packet = "JUPITR>APN382,K1NOT*:!4741.70NB12258.05W# MT. JUPITER   K7IDX";
```

### Decoding an APRS position packet:

``` cpp
aprs::packet packet = "JUPITR>APN382,K1NOT*:!4741.70NB12258.05W# MT. JUPITER   K7IDX";

// get the APRS packet type
aprs::data_type type = aprs::get_data_type(packet);
EXPECT_TRUE(type == aprs::data_type::position_without_timestamp);

// decoding the APRS packet
aprs::position position;
aprs::try_decode_packet_as(packet, position);
EXPECT_TRUE(position.comment == " MT. JUPITER   K7IDX");
EXPECT_NEAR(position.lat, 47.7027779, 1e-6);
EXPECT_NEAR(position.lon, -122.968056, 1e-6);
EXPECT_TRUE(position.symbol_table == 'B');
EXPECT_TRUE(position.symbol_code == '#');
```

### Decoding an APRS MIC-E packet:

``` cpp
aprs::packet packet = "AB7QL>TWSUTQ:`2,zm|d>/`\"3u}_%";

// get the APRS packet type
aprs::data_type type = aprs::get_data_type(packet);
EXPECT_TRUE(type == aprs::data_type::mic_e);

// decoding the APRS packet
aprs::mic_e mic_e;
aprs::try_decode_packet_as(packet, mic_e);
EXPECT_TRUE(mic_e.text == "`\"3u}_%");
EXPECT_NEAR(mic_e.lat, 47.590168, 1e-6);
EXPECT_NEAR(mic_e.lon, -122.282333, 1e-6);
EXPECT_TRUE(mic_e.symbol_table == '/');
EXPECT_TRUE(mic_e.symbol_code == '>');
EXPECT_TRUE(mic_e.status == aprs::mic_e_status::off_duty);
```

### Parsing APRS symbols:

``` cpp
// parsing the APRS symbol
aprs::symbol symbol;
aprs::symbol_overlay overlay;
aprs::try_parse_symbol(position, symbol, overlay);
EXPECT_TRUE(symbol == aprs::symbol::digi_green);
EXPECT_TRUE(overlay == aprs::symbol_overlay::overlay_b);

// get detailed symbol info
aprs::symbol_info symbol_info = aprs::get_symbol_info(symbol);
EXPECT_TRUE(symbol_info.name == "digi_green");
EXPECT_TRUE(symbol_info.description == "Digipeater (green star)");
```

### Packet decomposition:

``` cpp
EXPECT_TRUE(packet.from == "JUPITR");
EXPECT_TRUE(packet.to == "APN382");
EXPECT_TRUE(packet.path.size() == 1);
EXPECT_TRUE(packet.path[0] == "K1NOT*");
EXPECT_TRUE(packet.data == "!4741.70NB12258.05W# MT. JUPITER   K7IDX");
EXPECT_TRUE(aprs::to_string(packet) == "JUPITR>APN382,K1NOT*:!4741.70NB12258.05W# MT. JUPITER   K7IDX");
```

### Address parsing:

``` cpp
aprs::core::address address = packet.path[0]; // K1NOT*
EXPECT_TRUE(address.text == "K1NOT");
EXPECT_TRUE(address.mark == true);
EXPECT_TRUE(address.length == 6);
EXPECT_TRUE(address.kind == aprs::core::address_kind::other);
EXPECT_TRUE(aprs::core::to_string(address) == "K1NOT*");
```

### Selective packet decoding:

``` cpp
aprs::data_type type = aprs::get_data_type(packet);
if (type == aprs::data_type::position)
{
    aprs::position position;
    aprs::try_decode_packet_as(packet, position);
}
else if (type == aprs::data_type::mic_e)
{
    aprs::mic_e mic_e;
    aprs::try_decode_packet_as(packet, mic_e);
}
else if (type == aprs::data_type::object)
{
    aprs::object object;
    aprs::try_decode_packet_as(packet, object);
}
else if (type == aprs::data_type::item)
{
    aprs::item item;
    aprs::try_decode_packet_as(packet, item);
}
else if (type == aprs::data_type::message)
{
    aprs::message message;
    aprs::try_decode_packet_as(packet, message);
}
```

## Testing

The ***tests*** directory contain the tests. `tests/aprs_tests.cpp` contains a comprehensive sets of tests, written using the Google Test framework.

Use the tests as examples of how to use the library.

## Development

The test project can be opened in Visual Studio or VSCode. And it will work out of the box if the dependencies are installed.

Install the CMake and C++ extensions in VSCode, or the Native Desktop workload inside Visual Studio (*if using Visual Studio*).

On Linux systems, install the dependencies listed in `install_dependencies.sh`, which include a compiler, the CMake build system, and a native build system like make. Example for Debian systems: `apt-get install -y gcc g++ gcc-13 g++-13 clang make cmake ninja-build`.

## Integration with CMake

As this is a header only library, you can simple download the header and use it:

`file(DOWNLOAD
    https://raw.githubusercontent.com/iontodirel/libaprs/main/aprs.hpp
    ${CMAKE_SOURCE_DIR}/external/aprs.hpp)`

Include the header in your source file:

`#include "external/aprs.hpp"`

# License

MIT License, Copyright (C) 2023 Ion Todirel

Tests use data obtained from APRS-IS. I do not hold any copyright or license claim over this data, the data is in the public domain.