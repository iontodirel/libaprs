// **************************************************************** //
// libaprs - APRS header only parsing library                       // 
// Version 0.1.0                                                    //
// https://github.com/iontodirel/libaprs                            //
// Copyright (c) 2023 Ion Todirel                                   //
// **************************************************************** //
//
// aprs.hpp
// 
// MIT License
// 
// Copyright (c) 2023 Ion Todirel
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <gtest/gtest.h>

#include "aprs.hpp"

#include <cstring>

TEST(aprs_detail, try_parse_symbol_simple)
{
    aprs::packet packet;
    packet.destination_address = "TW3WYQ";
    packet.data = "`2Ajl \x1Cv/]\"3r}MONITORING 146.520=";

    aprs::mic_e mic_e;
    aprs::try_decode_packet_as(packet, mic_e);

    aprs::symbol symbol;
    aprs::symbol_overlay symbol_overlay;
    aprs::try_parse_symbol(mic_e, symbol, symbol_overlay);
    aprs::try_parse_symbol(mic_e.symbol_table, mic_e.symbol_code, symbol, symbol_overlay);
    aprs::detail::try_parse_uncompressed_symbol(mic_e.symbol_table, mic_e.symbol_code, symbol, symbol_overlay);    

    EXPECT_TRUE(symbol == aprs::symbol::van);
    EXPECT_TRUE(symbol_overlay == aprs::symbol_overlay::none);    
    EXPECT_TRUE(aprs::to_string(symbol) == "van");

    aprs::symbol_info symbol_info = aprs::get_symbol_info(symbol);

    EXPECT_TRUE(symbol_info.name == "van");
    EXPECT_TRUE(symbol_info.description == "Van");

    aprs::try_parse_symbol("van", symbol);

    EXPECT_TRUE(symbol == aprs::symbol::van);
}

TEST(aprs_detail, try_parse_symbol)
{
    aprs::symbol symbol;
    aprs::symbol_overlay symbol_overlay;
    EXPECT_TRUE(aprs::detail::try_parse_uncompressed_symbol('I', '&', symbol, symbol_overlay));
    EXPECT_TRUE(symbol == aprs::symbol::hf_gateway_diamond);
    EXPECT_TRUE(symbol_overlay == aprs::symbol_overlay::overlay_i);
    EXPECT_TRUE(aprs::to_string(symbol) == "hf_gateway_diamond");
    EXPECT_TRUE(aprs::try_parse_symbol("hf_gateway_diamond", symbol));

    EXPECT_TRUE(aprs::detail::try_parse_uncompressed_symbol('B', '#', symbol, symbol_overlay));
    EXPECT_TRUE(symbol == aprs::symbol::digi_green);
    EXPECT_TRUE(symbol_overlay == aprs::symbol_overlay::overlay_b);
    EXPECT_TRUE(aprs::to_string(symbol) == "digi_green");

    EXPECT_TRUE(aprs::detail::try_parse_uncompressed_symbol('/', '-', symbol, symbol_overlay));
    EXPECT_TRUE(symbol == aprs::symbol::home);
    EXPECT_TRUE(symbol_overlay == aprs::symbol_overlay::none);
    EXPECT_TRUE(aprs::to_string(symbol) == "home");

    EXPECT_TRUE(aprs::detail::try_parse_uncompressed_symbol('/', '1', symbol, symbol_overlay));
    EXPECT_TRUE(symbol == aprs::symbol::circle_1);
    EXPECT_TRUE(symbol_overlay == aprs::symbol_overlay::none);
    EXPECT_TRUE(aprs::to_string(symbol) == "circle_1");

    EXPECT_TRUE(aprs::detail::try_parse_compressed_symbol('d', '>', symbol, symbol_overlay));
    EXPECT_TRUE(symbol == aprs::symbol::car2);
    EXPECT_TRUE(symbol_overlay == aprs::symbol_overlay::overlay_3);
    EXPECT_TRUE(aprs::to_string(symbol) == "car2");

    symbol = aprs::symbol::church;
    aprs::symbol_info symbol_info = aprs::get_symbol_info(symbol);
    EXPECT_TRUE(symbol_info.name == "church");
    EXPECT_TRUE(symbol_info.index == 11);
    EXPECT_TRUE(symbol_info.description == "Church");
    EXPECT_TRUE(symbol_info.value == '+');
    EXPECT_TRUE(symbol_info.table == '\\');
    EXPECT_TRUE(symbol_info.overlayable == true);
    EXPECT_TRUE(symbol_info.destination_address == "OL");

    EXPECT_TRUE(aprs::try_parse_symbol("church", symbol));
    EXPECT_TRUE(symbol == aprs::symbol::church);
}

TEST(aprs_detail, symbol_map)
{
    aprs::symbol s;
    aprs::symbol_info si;
    aprs::detail::symbol_map& map0 = aprs::detail::symbol_map::instance();
    aprs::detail::symbol_map& map1 = aprs::detail::symbol_map::instance();
    EXPECT_TRUE(&map0 == &map1);
    aprs::detail::symbol_map::instance().try_get_symbol_by_value('I', s);
    EXPECT_TRUE(s == aprs::symbol::tcp_ip);
    aprs::detail::symbol_map::instance().try_get_symbol_by_value('!', s);    
    EXPECT_TRUE(s == aprs::symbol::police_station);
    aprs::detail::symbol_map::instance().try_get_symbol_by_value('&', s);
    EXPECT_TRUE(s == aprs::symbol::hf_gateway);
    si = aprs::detail::symbol_map::instance().get_symbol_info(s);
    aprs::detail::symbol_map::instance().try_get_symbol_by_value('!' + 200, s);
    aprs::detail::symbol_map::instance().try_get_symbol_by_destination_address("BN", s);
    si = aprs::detail::symbol_map::instance().get_symbol_info(s);
    si = aprs::detail::symbol_map::instance().get_symbol_info(aprs::symbol::no_symbol);
}

TEST(ax25, try_decode_frame)
{
    ax25::frame frame;
    std::string_view frame_str("\202\240\234fpd`\224\252\240\222\250\244`\256\222\210\212f@g\003\360!4741.70NB12258.05W# MT. JUPITER   K7IDX", 63);
    EXPECT_TRUE(ax25::try_decode_frame(frame_str, frame));
    EXPECT_TRUE(frame.source_address == "JUPITR");
    EXPECT_TRUE(frame.source_address_ssid == 0);
    EXPECT_TRUE(frame.destination_address == "APN382");
    EXPECT_TRUE(frame.destination_address_ssid == 0);
    EXPECT_TRUE(frame.digipeater_addresses.size() == 1);
    EXPECT_TRUE(frame.digipeater_addresses[0].first == "WIDE3");
    EXPECT_TRUE(frame.digipeater_addresses[0].second == 3);
    EXPECT_TRUE(frame.info_field == "!4741.70NB12258.05W# MT. JUPITER   K7IDX");
}

TEST(kiss, kiss_packet_decoder)
{
    kiss::kiss_frame_decoder decoder;

    // decode twice or more in a row to test sticky state
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0foo\xC0", 6)) == true);
    EXPECT_TRUE(decoder.count() == 1);
    EXPECT_TRUE(decoder.data()[0] == "foo");
    // decode twice or more in a row to test sticky state
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0bar\xC0", 6)) == true);
    EXPECT_TRUE(decoder.count() == 2);
    EXPECT_TRUE(decoder.data()[1] == "bar");
    // decode twice or more in a row to test sticky state
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0zebra\xC0", 8)) == true);
    EXPECT_TRUE(decoder.count() == 3);
    EXPECT_TRUE(decoder.data()[2] == "zebra");

    // parse multiple packets in one go
    decoder = kiss::kiss_frame_decoder();
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0foo\xC0""\xC0""\0bar\xC0", 12)) == true);
    EXPECT_TRUE(decoder.count() == 2);
    EXPECT_TRUE(decoder.data()[0] == "foo");
    EXPECT_TRUE(decoder.data()[1] == "bar");

    // parse incomplete chunks
    decoder = kiss::kiss_frame_decoder();
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0foo", 5)) == false);
    EXPECT_TRUE(decoder.count() == 0);
    EXPECT_TRUE(decoder.decode(" bar") == false);
    EXPECT_TRUE(decoder.count() == 0);
    EXPECT_TRUE(decoder.decode(" zebra") == false);
    EXPECT_TRUE(decoder.count() == 0);
    EXPECT_TRUE(decoder.decode("\xC0") == true);
    EXPECT_TRUE(decoder.count() == 1);
    EXPECT_TRUE(decoder.data()[0] == "foo bar zebra");

    // parse more incomplete chunks
    decoder = kiss::kiss_frame_decoder();
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0foo", 5)) == false);
    EXPECT_TRUE(decoder.count() == 0);
    EXPECT_TRUE(decoder.decode(" bar") == false);
    EXPECT_TRUE(decoder.count() == 0);
    EXPECT_TRUE(decoder.decode(" zebra") == false);
    EXPECT_TRUE(decoder.decode(std::string_view(" tar\xC0""\xC0""\0foo", 10)) == false); // incompletely decoded packets
    EXPECT_TRUE(decoder.count() == 1);
    EXPECT_TRUE(decoder.data()[0] == "foo bar zebra tar");
    EXPECT_TRUE(decoder.decode(" bar\xC0") == true);
    EXPECT_TRUE(decoder.count() == 2);
    EXPECT_TRUE(decoder.data()[1] == "foo bar");

    // escape sequences 
    // use decode.clear
    decoder.clear();
    // we want a frame end marker in between "foo" and "bar"
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0foo""\xDB""\xDC""bar""\xC0", 11)) == true);
    EXPECT_TRUE(decoder.count() == 1);
    // have to compare using memcmp as the std::string comparison is sensitive to null terminators in the middle of a string    
    EXPECT_TRUE(std::memcmp(decoder.data()[0].c_str(), "foo\xC0""bar", 7) == 0);

    // we want to make sure that we can have 0xDB 0xDC 
    decoder = kiss::kiss_frame_decoder();
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0foo""\xDB\xDD\xDC""bar""\xC0", 12)) == true);
    EXPECT_TRUE(decoder.count() == 1);
    EXPECT_TRUE(std::memcmp(decoder.data()[0].c_str(), "foo\xDB\xDC""bar", 8) == 0);

    decoder = kiss::kiss_frame_decoder();
    // we want a frame escape marker in between "foo" and "bar"
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0foo""\xDB\xDD""bar""\xC0", 11)) == true);
    EXPECT_TRUE(decoder.count() == 1);
    EXPECT_TRUE(decoder.data()[0] == "foo\xDB""bar");

    decoder = kiss::kiss_frame_decoder();
    // we want to make sure that we can have 0xDB 0xDD bytes in the data stream
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0foo""\xDB\xDD\xDD""bar""\xC0", 12)) == true);
    EXPECT_TRUE(decoder.count() == 1);
    EXPECT_TRUE(decoder.data()[0] == "foo\xDB\xDD""bar");

    decoder = kiss::kiss_frame_decoder();
    // make sure we can insert 0xDC and 0xDD in the data stream
    EXPECT_TRUE(decoder.decode(std::string_view("\xC0""\0foo\xDC\xDD""bar\xC0", 11)) == true);
    EXPECT_TRUE(decoder.count() == 1);
    EXPECT_TRUE(decoder.data()[0] == "foo\xDC\xDD""bar");
}

TEST(aprs_detail, try_parse_mic_e_lat)
{
    float lat = -1.0;
    aprs::detail::try_parse_mic_e_lat("T7SWPZ", lat); // latitude: 47.6175°, position ambiguity
    EXPECT_TRUE(lat >= 47.616 && lat <= 47.617);
    aprs::detail::try_parse_mic_e_lat("T7SWZZ", lat); // latitude: 47.625°, position ambiguity
    EXPECT_TRUE(lat >= 47.616 && lat <= 47.617);
    aprs::detail::try_parse_mic_e_lat("T7ZZZZ", lat); // latitude: 47.5°, position ambiguity
    EXPECT_TRUE(lat >= 47 && lat <= 47.5);
    aprs::detail::try_parse_mic_e_lat("APK004", lat); // latitude: 0°
    EXPECT_TRUE(lat >= -0.001 && lat <= 0.001);
    aprs::detail::try_parse_mic_e_lat("TY0YSP", lat); // latitude: 49.155°
    EXPECT_TRUE(lat >= 49.154 && lat <= 49.155);
    aprs::detail::try_parse_mic_e_lat("3Y0P0P", lat); // latitude: 39°
    EXPECT_TRUE(lat >= 39 && lat <= 39.001);
    aprs::detail::try_parse_mic_e_lat("SX3STP", lat); // latitude: 38.556666666667°    
    EXPECT_TRUE(lat >= 38.5566 && lat <= 38.5567);
    aprs::detail::try_parse_mic_e_lat("S5PRY5", lat); // latitude: 35.049166666667°
    EXPECT_TRUE(lat >= 35.049 && lat <= 35.0492);
    aprs::detail::try_parse_mic_e_lat("SX16R6", lat); // latitude: -38.271°
    EXPECT_TRUE(lat >= -38.271 && lat <= -38.27);
    aprs::detail::try_parse_mic_e_lat("TSR9Q0", lat); // latitude: -43.485°
    EXPECT_TRUE(lat >= -43.48501 && lat <= -43.485);
    aprs::detail::try_parse_mic_e_lat("SX04Y5", lat); // latitude: -38.0825°
    EXPECT_TRUE(lat >= -38.08251 && lat <= -38.082);
}

TEST(aprs_detail, try_parse_compression_type)
{
    aprs::compression_origin o;
    aprs::nmea_source n;
    bool old_or_new;
    aprs::detail::parse_compression_type(0b00000000, o, n, old_or_new);
    aprs::detail::parse_compression_type(0b00001000, o, n, old_or_new);
    aprs::detail::parse_compression_type(0b00010000, o, n, old_or_new);
    aprs::detail::parse_compression_type(0b00011000, o, n, old_or_new);
}

TEST(aprs_detail, try_parse_mic_e_lon)
{
    float lon = -1.0;
    aprs::detail::try_parse_mic_e_lon("SX04Y5", "h'4", lon); // latitude: -38.0825°, longitude: 176.18733333333°
    EXPECT_TRUE(lon >= 176.187 && lon <= 176.1874);
    aprs::detail::try_parse_mic_e_lon("TW3TUU", "2D ", lon); // latitude: 47.575833333333°, longitude: -122.66733333333°
    EXPECT_TRUE(lon >= -122.6674 && lon <= -122.667);
    aprs::detail::try_parse_mic_e_lon("S8US3R", "iYc", lon); // latitude: 38.888666666667°, longitude: -77.0285°
    EXPECT_TRUE(lon >= -77.02851 && lon <= -77.0285);
    aprs::detail::try_parse_mic_e_lon("SUSQQ0", "C=g", lon); // latitude: 35.518333333333°, longitude: 139.5625°
    EXPECT_TRUE(lon >= 139.5625 && lon <= 139.56251);
    aprs::detail::try_parse_mic_e_lon("QV5TXL", "lH0", lon); // latitude: 16.914166666667°, longitude: 100.7375°
    EXPECT_TRUE(lon >= 100.7366 && lon <= 100.7367);
}

TEST(aprs, try_decode_packet_as_try_parse_mic_e)
{  
    aprs::packet packet;
    aprs::mic_e mic_e;
    packet.destination_address = "T7SXUY";
    packet.data = "`2.kl\"`k/]\"4!}146.520MHz Toff=";    
    EXPECT_TRUE(aprs::try_decode_packet_as(packet, mic_e));
    EXPECT_TRUE(mic_e.status == aprs::mic_e_status::in_service);
}

TEST(aprs_detail, try_parse_mic_e_altitude)
{  
   float alt;
   EXPECT_TRUE(aprs::detail::try_parse_mic_e_altitude("\"4T}", alt));
   EXPECT_TRUE(alt == 10061);
}

TEST(aprs_detail, try_parse_area_object)
{
   EXPECT_TRUE(aprs::detail::try_parse_area_object("710/310"));
   EXPECT_TRUE(aprs::detail::try_parse_area_object("8101310"));
}

TEST(aprs, try_decode_packet_as_try_parse_mic_e_status)
{  
    aprs::packet packet;
    aprs::mic_e mic_e;
    packet.destination_address = "T7SWPZ";
    packet.data = "`2(5l!?[/>\"4E}^";    
    EXPECT_TRUE(aprs::try_decode_packet_as(packet, mic_e));
    EXPECT_TRUE(mic_e.status == aprs::mic_e_status::in_service);

    packet = aprs::packet();
    mic_e = aprs::mic_e();
    packet.destination_address = "VP1T21";
    packet.data = "`4QDl\x1C>/`CHR/DST-EFEK_#";
    EXPECT_TRUE(aprs::try_decode_packet_as(packet, mic_e));
    EXPECT_TRUE(mic_e.status == aprs::mic_e_status::en_route);

    packet = aprs::packet();
    mic_e = aprs::mic_e();
    packet.destination_address = "TWSUSS";
    packet.data = "`2]#o+Vj/]\"49}441.625MHz T100 +500Chris's Jeep JT=\x0d";
    EXPECT_TRUE(aprs::try_decode_packet_as(packet, mic_e));
    EXPECT_TRUE(mic_e.status == aprs::mic_e_status::off_duty);
}

TEST(aprs, try_decode_packet_as_try_parse_mic_e_telemetry)
{  
    aprs::packet packet;
    aprs::mic_e mic_e;

    packet = aprs::packet();
    mic_e = aprs::mic_e();
    packet.destination_address = "TW3WYQ";
    packet.data = "`2Ajl \x1Cv/]\"3r}MONITORING 146.520=";
    aprs::try_decode_packet_as(packet, mic_e);

    packet = aprs::packet();
    mic_e = aprs::mic_e();
    packet.destination_address = "TW3WYQ";
    packet.data = "`2(5l!?[/'7200007100";
    aprs::try_decode_packet_as(packet, mic_e);
    EXPECT_TRUE(mic_e.telemetry_channels.size() == 5);
    EXPECT_TRUE(mic_e.telemetry_channels[0] == 114);
    EXPECT_TRUE(mic_e.telemetry_channels[1] == 0);
    EXPECT_TRUE(mic_e.telemetry_channels[2] == 0);
    EXPECT_TRUE(mic_e.telemetry_channels[3] == 113);
    EXPECT_TRUE(mic_e.telemetry_channels[4] == 0);

    packet = aprs::packet();
    mic_e = aprs::mic_e();
    packet.destination_address = "TW3WYQ";
    packet.data = "`2(5l!?[/\x1d""1 2 3 4 5 ";
    aprs::try_decode_packet_as(packet, mic_e);
    EXPECT_TRUE(mic_e.telemetry_channels.size() == 5);
    EXPECT_TRUE(mic_e.telemetry_channels[0] == 1);
    EXPECT_TRUE(mic_e.telemetry_channels[1] == 2);
    EXPECT_TRUE(mic_e.telemetry_channels[2] == 3);
    EXPECT_TRUE(mic_e.telemetry_channels[3] == 4);
    EXPECT_TRUE(mic_e.telemetry_channels[4] == 5);
    
    packet = aprs::packet();
    mic_e = aprs::mic_e();
    packet.destination_address = "TW3WYQ";
    packet.data = "`2(5l!?[/`FEFE";
    aprs::try_decode_packet_as(packet, mic_e);
    EXPECT_TRUE(mic_e.telemetry_channels.size() == 2);
    EXPECT_TRUE(mic_e.telemetry_channels[0] == 254);
    EXPECT_TRUE(mic_e.telemetry_channels[1] == 254);
}

TEST(aprs_detail, try_parse_test_data)
{
    aprs::test_data test;

    EXPECT_TRUE(aprs::core::try_parse_test_data(",191146,V,4214.2466,N,07303.5181,W,417.238,114.5,091099,14.7,W/GPS FIX", test));
    EXPECT_TRUE(test.data == "191146,V,4214.2466,N,07303.5181,W,417.238,114.5,091099,14.7,W/GPS FIX");
}

TEST(aprs_detail, try_parse_user_defined)
{
    aprs::user_defined ud;

    EXPECT_TRUE(aprs::core::try_parse_user_defined("{Q1qwerty", ud));
    EXPECT_TRUE(ud.user_id == 'Q');
    EXPECT_TRUE(ud.packet_type == '1');
    EXPECT_TRUE(ud.data == "qwerty");
}

TEST(aprs_detail, try_parse_bulletin)
{
    aprs::bulletin bln;

    // bulletin
    EXPECT_TRUE(aprs::core::try_parse_bulletin(":BLN3     :Snow expected in Tampa RSN", bln));
    EXPECT_TRUE(bln.id == '3');
    EXPECT_TRUE(bln.name == "");
    EXPECT_TRUE(bln.text == "Snow expected in Tampa RSN");

    // announcement
    EXPECT_TRUE(aprs::core::try_parse_bulletin(":BLNQ     :Mt St Helen digi will be QRT this weekend", bln));
    EXPECT_TRUE(bln.id == 'Q');
    EXPECT_TRUE(bln.name == "");
    EXPECT_TRUE(bln.text == "Mt St Helen digi will be QRT this weekend");

    EXPECT_TRUE(aprs::core::try_parse_bulletin(":BLN0WXA  :FROST ADVISORY IN EFFECT FROM 2AM TO 8AM WED", bln));
    EXPECT_TRUE(bln.id == '0');
    EXPECT_TRUE(bln.name == "WXA");
    EXPECT_TRUE(bln.text == "FROST ADVISORY IN EFFECT FROM 2AM TO 8AM WED");

    // No text
    EXPECT_TRUE(aprs::core::try_parse_bulletin(":BLN0WXA  :", bln));
    EXPECT_TRUE(bln.id == '0');
    EXPECT_TRUE(bln.name == "WXA");
    EXPECT_TRUE(bln.text == "");

    // shorter than 11 characters
    EXPECT_FALSE(aprs::core::try_parse_bulletin(":BLN0WXA  ", bln));

    bln = aprs::bulletin();
    // missing ':' at position 10
    EXPECT_FALSE(aprs::core::try_parse_bulletin(":BLN3     Snow expected in Tampa RSN", bln));
    EXPECT_TRUE(bln.id == '\0');
    EXPECT_TRUE(bln.name == "");
    EXPECT_TRUE(bln.text == "");

    aprs::nws_bulletin nws_bln;

    EXPECT_TRUE(aprs::core::try_parse_nws_bulletin(":NWS_WARN :130730z,Flood,NDC017{C1T00", nws_bln));
    EXPECT_TRUE(nws_bln.callsign == "NWS_WARN");
    EXPECT_TRUE(nws_bln.text == "130730z,Flood,NDC017{C1T00");
}

TEST(aprs_detail, try_parse_timestamp)
{
    aprs::position p;
    aprs::detail::try_parse_timestamp("020240z", p);
    EXPECT_TRUE(p.date_time_minute == 40);
    EXPECT_TRUE(p.date_day == 2);
    EXPECT_TRUE(p.date_time_hour == 2);
    aprs::detail::try_parse_timestamp("084706z", p);
    EXPECT_TRUE(p.date_time_minute == 6);
    EXPECT_TRUE(p.date_day == 8);
    EXPECT_TRUE(p.date_time_hour == 47);
    aprs::detail::try_parse_timestamp("084657h", p);
    EXPECT_TRUE(p.date_time_minute == 46);
    EXPECT_TRUE(p.date_time_hour == 8);
    aprs::detail::try_parse_timestamp("170100/", p);
    EXPECT_TRUE(p.date_time_minute == 0);
    EXPECT_TRUE(p.date_day == 17);
    EXPECT_TRUE(p.date_time_hour == 1);    
    aprs::detail::try_parse_timestamp("210358z", p);
    EXPECT_TRUE(p.date_time_minute == 58);
    EXPECT_TRUE(p.date_day == 21);
    EXPECT_TRUE(p.date_time_hour == 3); 
    aprs::detail::try_parse_timestamp("171325z", p);
    EXPECT_TRUE(p.date_time_minute == 25);
    EXPECT_TRUE(p.date_day == 17);
    EXPECT_TRUE(p.date_time_hour == 13); 
    aprs::detail::try_parse_timestamp("234517h", p);
    EXPECT_TRUE(p.date_time_minute == 45);
    EXPECT_TRUE(p.date_time_hour == 23); 
    aprs::detail::try_parse_timestamp("092345z", p);
    EXPECT_TRUE(p.date_time_minute == 45);
    EXPECT_TRUE(p.date_day == 9);
    EXPECT_TRUE(p.date_time_hour == 23); 
    aprs::detail::try_parse_timestamp("210933z", p);
    EXPECT_TRUE(p.date_time_minute == 33);
    EXPECT_TRUE(p.date_day == 21);
    EXPECT_TRUE(p.date_time_hour == 9); 
    aprs::detail::try_parse_timestamp("120183z", p);
    EXPECT_TRUE(p.date_time_minute == 83); // an TH-D74 radio sending incorrect time
    EXPECT_TRUE(p.date_day == 12);
    EXPECT_TRUE(p.date_time_hour == 1); 
}

TEST(aprs, try_decode_data_as_try_parse_position)
{
    std::string packet_data = "@110647z4855.05N/12208.34W_131/002g004t043r000p000P000h80b10237L000AmbientCWOP.com";
    aprs::data_type type = aprs::get_data_type(packet_data);
    if (type == aprs::data_type::position_with_timestamp)
    {
        aprs::position position;
        aprs::try_decode_data_as(packet_data, position);
    }
}

TEST(aprs, basic_position_and_mic_e_position)
{
    std::string packet_data = "!4903.50N/07201.75W-Test 001234";
    EXPECT_TRUE(aprs::get_data_type(packet_data) == aprs::data_type::position);
    aprs::position position;
    EXPECT_TRUE(aprs::try_decode_data_as(packet_data, position));
    EXPECT_TRUE(position.lat >= 49.0638 && position.lat < 49.06389);
    EXPECT_TRUE(position.lon >= -72.03751 && position.lon < -72.03750);
    EXPECT_TRUE(position.comment == "Test 001234");
    EXPECT_TRUE(position.symbol_table == '/');
    EXPECT_TRUE(position.symbol_code == '-');

    packet_data = "!49  .  N/072  .  W-";
    EXPECT_TRUE(aprs::get_data_type(packet_data) == aprs::data_type::position);
    position = aprs::position();
    EXPECT_TRUE(aprs::try_decode_data_as(packet_data, position));
    EXPECT_TRUE(position.lat == 49);
    EXPECT_TRUE(position.lon == -72);
    EXPECT_TRUE(position.comment == "");
    EXPECT_TRUE(position.symbol_table == '/');
    EXPECT_TRUE(position.symbol_code == '-');

    packet_data = "/092345z4903.50N/07201.75W>Test1234";
    EXPECT_TRUE(aprs::get_data_type(packet_data) == aprs::data_type::position);
    position = aprs::position();
    EXPECT_TRUE(aprs::try_decode_data_as(packet_data, position));
    EXPECT_TRUE(position.lat >= 49.0638 && position.lat < 49.06389);
    EXPECT_TRUE(position.lon >= -72.03751 && position.lon < -72.03750);
    EXPECT_TRUE(position.comment == "Test1234");
    EXPECT_TRUE(position.symbol_table == '/');
    EXPECT_TRUE(position.symbol_code == '>');
    EXPECT_TRUE(position.date_day == 9);
    EXPECT_TRUE(position.date_time_hour == 23);
    EXPECT_TRUE(position.date_time_minute == 45);

    packet_data = "@092345/4903.50N/07201.75W>Test1234";
    EXPECT_TRUE(aprs::get_data_type(packet_data) == aprs::data_type::position);
    position = aprs::position();
    EXPECT_TRUE(aprs::try_decode_data_as(packet_data, position));
    EXPECT_TRUE(position.lat >= 49.0638 && position.lat < 49.06389);
    EXPECT_TRUE(position.lon >= -72.03751 && position.lon < -72.03750);
    EXPECT_TRUE(position.comment == "Test1234");
    EXPECT_TRUE(position.symbol_table == '/');
    EXPECT_TRUE(position.symbol_code == '>');
    EXPECT_TRUE(position.date_day == 9);
    EXPECT_TRUE(position.date_time_hour == 23);
    EXPECT_TRUE(position.date_time_minute == 45);

    // Mic-E position
    aprs::packet packet;
    packet.destination_address = "T7SVVP";
    packet.data = "`2C1l>\x1cu/]\"3f}=\x0d";
    aprs::mic_e mic_e;
    EXPECT_TRUE(aprs::try_decode_packet_as(packet, mic_e));
    EXPECT_TRUE(mic_e.symbol_table == '/');
    EXPECT_TRUE(mic_e.symbol_code == 'u');
    EXPECT_TRUE(mic_e.lat >= 47.61 && mic_e.lat < 47.610001);
    EXPECT_TRUE(mic_e.lon >= -122.65351 && mic_e.lon < -122.6535);
    EXPECT_TRUE(mic_e.status == aprs::mic_e_status::in_service);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}