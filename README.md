# libaprs

C++ header only standalone APRS parsing library.

Automatic Packet Reporting System (APRS) is a system for real-time digital data communication over ham radio.

See more info at http://www.aprs.org/ and https://groups.io/g/APRS.

## Examples

### Parsing a MIC-E packet:

``` cpp
aprs::packet packet;
packet.destination_address = "TW3WYQ";
packet.data = "`2Ajl \x1Cv/]\"3r}MONITORING 146.520=";

aprs::mic_e mic_e;
aprs::try_decode_packet_as(packet, mic_e);
```

# License

MIT License, Copyright (c) 2023 Ion Todirel