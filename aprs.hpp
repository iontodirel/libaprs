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

#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <type_traits>
#include <concepts>
#include <cmath>
#include <deque>
#include <unordered_map>

#ifndef APRS_LIB_APRS_NAMESPACE
#define APRS_LIB_APRS_NAMESPACE aprs
#endif
#ifndef APRS_LIB_APRS_DETAIL_NAMESPACE
#define APRS_LIB_APRS_DETAIL_NAMESPACE detail
#endif
#ifndef APRS_LIB_APRS_CORE_NAMESPACE
#define APRS_LIB_APRS_CORE_NAMESPACE core
#endif
#ifndef APRS_LIB_APRS_NAMESPACE_BEGIN
#define APRS_LIB_APRS_NAMESPACE_BEGIN namespace APRS_LIB_APRS_NAMESPACE {
#endif
#ifndef APRS_LIB_APRS_DETAIL_NAMESPACE_BEGIN
#define APRS_LIB_APRS_DETAIL_NAMESPACE_BEGIN namespace APRS_LIB_APRS_DETAIL_NAMESPACE {
#endif
#ifndef APRS_LIB_APRS_CORE_NAMESPACE_BEGIN
#define APRS_LIB_APRS_CORE_NAMESPACE_BEGIN namespace APRS_LIB_APRS_CORE_NAMESPACE {
#endif
#ifndef APRS_LIB_APRS_DETAIL_NAMESPACE_END
#define APRS_LIB_APRS_DETAIL_NAMESPACE_END }
#endif
#ifndef APRS_LIB_APRS_CORE_NAMESPACE_END
#define APRS_LIB_APRS_CORE_NAMESPACE_END }
#endif
#ifndef APRS_LIB_NAMESPACE_END
#define APRS_LIB_NAMESPACE_END }
#endif
#ifndef APRS_LIB_APRS_DETAIL_NAMESPACE_USE
#define APRS_LIB_APRS_DETAIL_NAMESPACE_USE using namespace APRS_LIB_APRS_DETAIL_NAMESPACE;
#endif
#ifndef APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE
#define APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE APRS_LIB_APRS_DETAIL_NAMESPACE ::
#endif
#ifndef APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE
#define APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE APRS_LIB_APRS_CORE_NAMESPACE ::
#endif
#ifndef APRS_LIB_INLINE
#define APRS_LIB_INLINE inline
#endif
#ifndef APRS_LIB_KISS_NAMESPACE
#define APRS_LIB_KISS_NAMESPACE kiss
#endif
#ifndef APRS_LIB_KISS_NAMESPACE_BEGIN
#define APRS_LIB_KISS_NAMESPACE_BEGIN namespace APRS_LIB_KISS_NAMESPACE {
#endif
#ifndef APRS_LIB_KISS_NAMESPACE_END
#define APRS_LIB_KISS_NAMESPACE_END }
#endif
#ifndef APRS_LIB_AX25_NAMESPACE
#define APRS_LIB_AX25_NAMESPACE ax25
#endif
#ifndef APRS_LIB_AX25_NAMESPACE_BEGIN
#define APRS_LIB_AX25_NAMESPACE_BEGIN namespace APRS_LIB_AX25_NAMESPACE {
#endif
#ifndef APRS_LIB_AX25_NAMESPACE_END
#define APRS_LIB_AX25_NAMESPACE_END }
#endif
#ifndef APRS_LIB_AX25_DETAIL_NAMESPACE
#define APRS_LIB_AX25_DETAIL_NAMESPACE detail
#endif
#ifndef APRS_LIB_AX25_DETAIL_NAMESPACE_REFERENCE
#define APRS_LIB_AX25_DETAIL_NAMESPACE_REFERENCE APRS_LIB_AX25_DETAIL_NAMESPACE :: 
#endif
#ifndef APRS_LIB_AX25_DETAIL_NAMESPACE_BEGIN
#define APRS_LIB_AX25_DETAIL_NAMESPACE_BEGIN namespace APRS_LIB_AX25_DETAIL_NAMESPACE {
#endif
#ifndef APRS_LIB_AX25_DETAIL_NAMESPACE_END
#define APRS_LIB_AX25_DETAIL_NAMESPACE_END }
#endif
#ifndef APRS_LIB_PUBLIC_FORWARD_DECLARATIONS_ONLY
// Intentionally left empty
#endif
#define APRS_LIB_SYMBOL_INFO

APRS_LIB_APRS_NAMESPACE_BEGIN

// **************************************************************** //
//                                                                  //
// CONCEPTS                                                         //
//                                                                  //
// **************************************************************** //

APRS_LIB_APRS_DETAIL_NAMESPACE_BEGIN

template<typename T, typename ... U>
concept IsAnyOf = (std::same_as<T, U> || ...);

#ifndef APRS_LIB_PUBLIC_FORWARD_DECLARATIONS_ONLY

template <typename T>
concept DateTimeSpec = requires(T t)
{
    requires std::same_as<decltype(t.date_year), int>;
    requires std::same_as<decltype(t.date_month), int>;
    requires std::same_as<decltype(t.date_day), int>;
    requires std::same_as<decltype(t.date_time_hour), int>;
    requires std::same_as<decltype(t.date_time_minute), int>;
};

template <typename T>
concept PositionSpec = requires(T t)
{
    requires std::same_as<decltype(t.lat), float>;
    requires std::same_as<decltype(t.lon), float>;
};

template <typename T>
concept PacketWithSymbolSpec = requires(T t)
{
    requires std::same_as<decltype(t.symbol_table), char>;
    requires std::same_as<decltype(t.symbol_code), char>;
};

template<typename Enum>
concept AliveDeadEnumSpec = requires(Enum e)
{
    requires std::is_enum_v<Enum>;
    { Enum::live };
    { Enum::killed };
};

template <typename T>
concept PacketSpec = requires(T t)
{    
    requires std::same_as<decltype(t.destination_address), std::string>;
    requires std::same_as<decltype(t.data), std::string>;
};

#endif

APRS_LIB_NAMESPACE_END
    
// **************************************************************** //
//                                                                  //
//                                                                  //
// TYPES                                                            //
//                                                                  //
//                                                                  //
// **************************************************************** //

enum class data_type : int
{
    unknown, 
    position,
    position_with_timestamp,
    position_without_timestamp,
    position_compressed_with_timestamp,
    position_compressed_without_timestamp,
    object,
    object_with_data_ext,
    object_without_data_ext,
    object_with_compressed_position,
    item,
    item_with_compressed_position,
    message,
    message_ack,
    mic_e,
    mic_e_with_telemetry,
    bulletin,
    user_defined,
    test_data
};

struct packet
{
    std::string source_address;
    int source_address_ssid = -1;
    std::string destination_address;
    int destination_address_ssid = -1;
    std::vector<std::string> path;
    std::string data;
};

struct message
{
    std::string addressee;
    std::string text;
    std::string message_no;
};

struct position
{ 
    float lat = -1.0;
    float lon = -1.0;
    std::string comment;
    char symbol_table = '\0';
    char symbol_code = '\0';
    int date_year = -1;
    int date_month = -1;
    int date_day = -1;
    int date_time_hour = -1;
    int date_time_minute = -1;
};

enum class object_state
{
    live,
    killed,
    other
};

enum class item_state
{
    live,
    killed,
    other
};

struct object
{
    std::string name;
    std::string comment;
    object_state state = object_state::other;
    char symbol_table = '\0';
    char symbol_code = '\0';
    float lat = -1.0;
    float lon = -1.0;
    int date_year = -1;
    int date_month = -1;
    int date_day = -1;
    int date_time_hour = -1;
    int date_time_minute = -1;
};

struct item
{
    std::string name;
    std::string comment;
    item_state state = item_state::other;
    char symbol_table = '\0';
    char symbol_code = '\0';
    float lat = -1.0;
    float lon = -1.0;
};

enum class mic_e_status
{
    off_duty,
    en_route,
    in_service,
    returning,
    commited,
    special,
    priority,
    emergency,
    custom0,
    custom1,
    custom2,
    custom3,
    custom4,
    custom5,
    custom6,
    uknown
};

struct mic_e
{
    char symbol_table = '\0';
    char symbol_code = '\0';
    float lat = -1.0;
    float lon = -1.0;
    mic_e_status status = mic_e_status::uknown;
    std::vector<int> telemetry_channels;
};

struct bulletin
{
    char id = '\0';
    std::string name;
    std::string text;
};

struct nws_bulletin
{
    std::string callsign;
    std::string text;
};

struct user_defined
{
    char user_id = '\0';
    char packet_type = '\0';
    std::string data;
};

struct test_data
{
    std::string data;
};

enum class data_extension_type
{
    course_speed,
    wind_direction_and_speed,
    power_and_antenna,
    radio_range,
    signal_strength,
    course_speed_bearing,
    area_object_descriptor
};

enum class symbol : int
{
    police_station,
    digi,
    phone,
    dx_cluster,
    hf_gateway,
    aircraft_small,
    mobile_satellite_station,
    wheelchair,
    snowmobile,
    red_cross,
    boy_scout,
    home,
    x,
    red_dot,
    circle_0,
    circle_1,
    circle_2,
    circle_3,
    circle_4,
    circle_5,
    circle_6,
    circle_7,
    circle_8,
    circle_9,
    fire,
    campground_tent,
    motorcycle,
    railroad_engine,
    car,
    file_server,
    hc_future,
    aid_station,
    bbs,
    canoe,
    eyeball,
    tractor,
    grid_square_3x3,
    hotel,
    tcp_ip,
    school,
    pc_user,
    mac_aprs,
    nts_station,
    balloon,
    police,
    tbd,
    rv,
    shuttle_space,
    sstv,
    bus,
    atv,
    national_wx,
    helicopter,
    yacht_sail_boat,
    win_aprs,
    jogger,
    triangle,
    pbbs,
    aircraft_large,
    wx,
    dish_antenna,
    ambulance,
    bicycle,
    icp,
    fire_station,
    horse,
    fire_truck,
    glider,
    hospital,
    iota,
    jeep,
    truck,
    laptop,
    mic_e_repeater,
    node,
    eoc,
    rover_dog,
    grid_square_2x2,
    antenna,
    power_boat,
    truck_stop,
    truck_18_wheeler,
    van,
    water_station,
    x_aprs,
    yagi,
    shelter,
    tnc_stream_sw1,
    tnc_stream_sw2,
    emergency,
    digi_green,
    atm,
    hf_gateway_diamond,
    crash_site,
    cloudy,
    firenet_meo_modis,
    snow,
    church,
    girl_scouts,
    house_hf,
    uknown_position,
    circle,
    wifi,
    gas_station_blue,
    hail,
    park_picnic,
    nws_advisory_gale_flag,
    car2,
    info_kiosk_blue_box_q,
    huricane,
    box,
    blowing_snow,
    coastguard,
    drizzle,
    smoke,
    feezing_rain,
    snow_shower,
    haze,
    rain_shower,
    lightning,
    kenwood,
    ligthouse,
    nav_buoy,
    rocket,
    parking,
    earthquake,
    restaurant,
    satellite_pac_sat,
    thunderstorm,
    sunny,
    vortac_nav_aid,
    nws_site,
    pharmacy_rx,
    wall_cloud,
    aircraft,
    wx_station_with_digi_green,
    rain,
    arrl,
    red_diamond,
    races,
    blowing_dust,
    civil_defence_races,
    dx_spot,
    sleet,
    funnel_cloud,
    gale_flags,
    ham_store,
    indoor_short_range_digi,
    work_zone,
    suv_atv,
    area_symbols,
    value_signpost,
    triangle_df,
    small_circle,
    partly_cloudy,
    restrooms,
    ship_boat_top_view,
    tornado,
    truck2,
    van2,
    flooding,
    skywarn,
    shelter2,
    fog,
    none,
    no_symbol,
};

enum class symbol_overlay : char
{
    none = 0,
    overlay_a = 'A',
    overlay_b = 'B',
    overlay_c = 'C',
    overlay_d = 'D',
    overlay_e = 'E',
    overlay_f = 'F',
    overlay_g = 'G',
    overlay_h = 'H',
    overlay_i = 'I',
    overlay_j = 'J',
    overlay_k = 'K',
    overlay_l = 'L',
    overlay_m = 'M',
    overlay_n = 'N',
    overlay_o = 'O',
    overlay_p = 'P',
    overlay_q = 'Q',
    overlay_r = 'R',
    overlay_s = 'S',
    overlay_t = 'T',
    overlay_u = 'U',
    overlay_v = 'V',
    overlay_w = 'W',
    overlay_x = 'X',
    overlay_y = 'Y',
    overlay_z = 'Z',
    overlay_0 = '0',
    overlay_1 = '1',
    overlay_2 = '2',
    overlay_3 = '3',
    overlay_4 = '4',
    overlay_5 = '5',
    overlay_6 = '6',
    overlay_7 = '7',
    overlay_8 = '8',
    overlay_9 = '9',
};

#ifdef APRS_LIB_SYMBOL_INFO

struct symbol_info
{
    int index = -1;
    std::string name;
    std::string description;
    char value = 0;
    char table = 0;
    bool overlayable = false;
    std::string destination_address;
    int ssid = -1;
};

#endif

enum class compression_origin : int
{
    compressed = 0,
    tnc_btext = 1,
    software = 2,
    tbd = 3,
    kpc3 = 4,
    pico = 5,
    other = 6,
    digipeater = 7
};

enum class nmea_source : int
{
    other = 0,
    GLL = 1,
    GGA = 2,
    RMC = 3
};

enum class decoder_hint
{
    do_not_parse_telemetry,
    parse_mic_e_altitude,
    handle_misformatted_packet,
    alternate_parse_position_packet
};

enum class area_object_type : uint
{
    open_circle = '0',
    line_offset_down_right = '1',
    open_ellipse = '2',
    open_triage = '3',
    open_box = '4',
    color_filled_circle = '5',
    line_offset_down_left = '6',
    color_filled_ellipse = '7',
    color_filled_triangle = '8',
    color_filled_box = '9'
};

enum class area_object_color_intensity : uint
{
    black_high = '0',
    blue_high = '1',
    green_high = '2',
    cyan_high = '3',
    red_high = '4',
    violet_high = '5',
    yellow_high = '6',
    gray_high = '7',
    black_low = '8',
    blue_low = '9',
    green_low = 10,
    cyan_low,
    red_low,
    violet_low,
    yellow_low,
    gray_low,
    uknown = 100
};

enum class client_id
{
    aprsdroid,
    icom_ic2820,
    icom_id31,
    icom_id4100,
    icom_id51,
    icom_id5100,
    icom_ic7100,
    icom_ic80,
    icom_id880,
    icom_ic9100,
    icom_ic92,
    icom_ic9700,
    pinpoint,
    kenwood_thd7,
    kenwood_thd72,
    kenwood_thd74,
    kenwood_d700,
    kenwood_d710,
    kantronics_kpc3,
    kantronics_kam8,
    kantronics_kamplus,
    kantronics_kamxl,
    uidigi,
    xastir,
    yaesu_vx8,
    yaesu_ft1d,
    yaesu_ft2d,
    yaesu_ft3d,
    yaesu_ft5d,
    yaesu_ftm100d,
    yaesu_ftm300d,
    yaesu_ftm350,
    yaesu_ftm400,
    picoaprs
};

// **************************************************************** //
//                                                                  //
//                                                                  //
//                                                                  //
//                                                                  //
// FORWARD DECLARATIONS                                             //
//                                                                  //
//                                                                  //
//                                                                  //
//                                                                  //
// **************************************************************** //

// **************************************************************** //
// TYPE SUPPORT                                                     //
// **************************************************************** //

APRS_LIB_INLINE bool operator==(data_type first,  data_type second);
APRS_LIB_INLINE std::string to_string(const data_type& t);
APRS_LIB_INLINE std::string to_string(const packet& m);
APRS_LIB_INLINE std::string to_string(const symbol& s);
APRS_LIB_INLINE bool try_parse_symbol(const std::string& symbol_name, symbol& symbol);

// **************************************************************** //
// SYMBOLS                                                          //
// **************************************************************** //

#ifdef APRS_LIB_SYMBOL_INFO
APRS_LIB_INLINE symbol_info& get_symbol_info(const symbol& s);
#endif

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE PacketWithSymbolSpec P>
APRS_LIB_INLINE bool try_parse_symbol(const P& data, symbol& symbol, symbol_overlay& symbol_overlay);

APRS_LIB_INLINE bool try_parse_symbol(char symbol_table, char symbol_code, symbol& symbol, symbol_overlay& symbol_overlay);

APRS_LIB_APRS_CORE_NAMESPACE_BEGIN

#ifndef APRS_LIB_PUBLIC_FORWARD_DECLARATIONS_ONLY

// **************************************************************** //
//                                                                  //
//                                                                  //
// CORE PARSING                                                     //
//                                                                  //
//                                                                  //
// **************************************************************** //

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE PacketSpec P>
APRS_LIB_INLINE bool try_parse_mic_e(const P& packet, mic_e& mic_e);
APRS_LIB_INLINE bool try_parse_mic_e(std::string_view destination_address, std::string_view data, mic_e& mic_e);
APRS_LIB_INLINE bool try_parse_item_with_compressed_position(std::string_view destination_address, item& item);
APRS_LIB_INLINE bool try_parse_item(std::string_view data, item& item);
APRS_LIB_INLINE bool try_parse_message_with_acknowledgment(std::string_view data, message& message);
APRS_LIB_INLINE bool try_parse_message(std::string_view data, message& message);
APRS_LIB_INLINE bool try_parse_object_with_compressed_position(std::string_view data, object& object);
APRS_LIB_INLINE bool try_parse_object_without_data_ext(std::string_view data, object& object);
APRS_LIB_INLINE bool try_parse_object_with_data_ext(std::string_view data, object& object);
APRS_LIB_INLINE bool try_parse_compressed_position_with_timestamp(std::string_view data, position& position);
APRS_LIB_INLINE bool try_parse_compressed_position_without_timestamp(std::string_view data, position& position);
APRS_LIB_INLINE bool try_parse_position_with_timestamp(std::string_view data, position& position);
APRS_LIB_INLINE bool try_parse_position_without_timestamp(std::string_view data, position& position);
APRS_LIB_INLINE bool try_parse_bulletin(std::string_view data, bulletin& bulletin);
APRS_LIB_INLINE bool try_parse_nws_bulletin(std::string_view data, nws_bulletin& bulletin);
APRS_LIB_INLINE bool try_parse_user_defined(std::string_view data, user_defined& user_defined);
APRS_LIB_INLINE bool try_parse_test_data(std::string_view data, test_data& test_data);

#endif

APRS_LIB_APRS_CORE_NAMESPACE_END

APRS_LIB_APRS_DETAIL_NAMESPACE_BEGIN

// **************************************************************** //
//                                                                  //
//                                                                  //
// SYMBOLS                                                          //
//                                                                  //
//                                                                  //
// **************************************************************** //

struct symbol_map
{
    static symbol_map& instance()
    {
        static symbol_map instance;
        instance.populate();
        return instance;
    }

    bool try_get_symbol_by_destination_address(std::string destination_address, symbol& symbol);
    bool try_get_symbol_by_value(int value, symbol& symbol);
    bool try_get_symbol_by_name(const std::string& name, symbol& symbol);

#ifdef APRS_LIB_SYMBOL_INFO
    symbol_info& get_symbol_info(symbol symbol);
#endif

private:
    symbol_map() = default;
    ~symbol_map() = default;

    void populate();

    std::unordered_map<int, int> symbol_code_map;
    std::unordered_map<std::string, int> symbol_name_map;
    std::unordered_map<std::string, int> destination_address_map;
#ifdef APRS_LIB_SYMBOL_INFO
    std::vector<symbol_info> symbols;
    symbol_info no_symbol;
#endif
    bool populated = false;
};

#ifndef APRS_LIB_PUBLIC_FORWARD_DECLARATIONS_ONLY

// **************************************************************** //
// COORDINATE PARSING                                               //
// **************************************************************** //

APRS_LIB_INLINE bool try_get_coordinate_ambiguity(std::string_view pos_str, int& lat_ambiguity, int& lon_ambiguity);
APRS_LIB_INLINE bool try_parse_coordinates(std::string_view lat_str, std::string_view lon_str, float& lat, float& lon);
APRS_LIB_INLINE bool try_parse_compressed_coordinates(std::string_view pos_str, float& lat, float& lon);
APRS_LIB_INLINE bool try_parse_compressed_lat(std::string_view pos_str, float& lat);
APRS_LIB_INLINE bool try_parse_compressed_lon(std::string_view pos_str, float& lon);
APRS_LIB_INLINE bool try_parse_lat(std::string_view lat_str, float& lat);
APRS_LIB_INLINE bool try_parse_lon(std::string_view lon_str, float& lon);
APRS_LIB_INLINE bool try_parse_coordinate(std::string_view degrees_str, std::string_view minutes_str, std::string_view seconds_str, char direction, float& coordinate);
APRS_LIB_INLINE bool try_parse_mic_e_lat(std::string_view dest_str, float& lat);
APRS_LIB_INLINE bool try_parse_mic_e_lon(std::string_view dest_str, std::string_view lon_str, float& lon);
APRS_LIB_INLINE bool try_parse_mic_e_altitude(std::string_view alt_str, float& alt);

// **************************************************************** //
// UTILS                                                            //
// **************************************************************** //

APRS_LIB_INLINE bool try_parse_number(std::string_view number_str, int& number);
APRS_LIB_INLINE std::string trim(const std::string& str);

// **************************************************************** //
// TIME PARSING                                                     //
// **************************************************************** //

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE DateTimeSpec T>
APRS_LIB_INLINE bool try_parse_timestamp(std::string_view timestamp, T& t_with_datetime);

// **************************************************************** //
// QUERIES                                                          //
// **************************************************************** //

APRS_LIB_INLINE bool try_get_position_with_timestamp_is_compressed(std::string_view data, bool& compressed);
APRS_LIB_INLINE bool try_get_position_without_timestamp_is_compressed(std::string_view data, bool& compressed);
APRS_LIB_INLINE bool try_get_object_is_compressed(std::string_view data, bool& compressed);
APRS_LIB_INLINE bool try_get_item_is_compressed(std::string_view data, bool& compressed);

#endif

APRS_LIB_APRS_DETAIL_NAMESPACE_END

APRS_LIB_APRS_DETAIL_NAMESPACE_BEGIN

// **************************************************************** //
// PARSING SUPPORT                                                  //
// **************************************************************** //

APRS_LIB_INLINE bool try_parse_mic_e_telemetry(std::string_view data, mic_e& mic_e);
APRS_LIB_INLINE bool try_get_mic_e_has_telemetry(std::string_view data, bool& has_telemetry);
APRS_LIB_INLINE bool try_parse_mic_e_message_abc(char ch, int& d, bool& custom);
APRS_LIB_INLINE bool try_parse_mic_e_status(std::string_view data, mic_e_status& status);
APRS_LIB_INLINE bool try_parse_area_object(std::string_view area_object_str);
APRS_LIB_INLINE bool try_parse_area_object_color_intensity(std::string_view object_color_intensity, area_object_color_intensity& color_intensity);
APRS_LIB_INLINE void parse_compression_type(const char t, int& compression_origin, int& nmea_source, bool& old_or_current);
APRS_LIB_INLINE void parse_compression_type(const char t, compression_origin& compression_origin, nmea_source& nmea_source, bool& old_or_current);
APRS_LIB_INLINE bool try_parse_symbol_no_overlay(char symbol_table, char symbol_code, symbol& symbol_);
APRS_LIB_INLINE bool try_parse_uncompressed_symbol(char symbol_table, char symbol_code, symbol& symbol, symbol_overlay& symbol_overlay);
APRS_LIB_INLINE bool try_parse_compressed_symbol(char symbol_table, char symbol_code, symbol& symbol_, symbol_overlay& symbol_overlay_);
APRS_LIB_INLINE bool try_parse_pri_table_symbol(char symbol_code, symbol& symbol);
APRS_LIB_INLINE bool try_parse_alt_table_symbol(char symbol_code, symbol& symbol);
APRS_LIB_INLINE bool try_parse_ar_symbol(char symbol_table, symbol& symbol);
APRS_LIB_INLINE bool try_parse_overlayable_uncompressed_symbol(char symbol_table, char symbol_code, symbol& symbol_, symbol_overlay& symbol_overlay_);
APRS_LIB_INLINE bool try_parse_overlayable_compressed_symbol(char symbol_table, char symbol_code, symbol& symbol_, symbol_overlay& symbol_overlay_);
APRS_LIB_INLINE bool try_parse_uncompressed_symbol_overlay(char symbol_table, symbol_overlay& symbol_overlay_);
APRS_LIB_INLINE bool try_parse_compressed_symbol_overlay(char symbol_table, symbol_overlay& symbol_overlay_);

// **************************************************************** //
// QUERIES                                                          //
//                                                                  //
// Use to disambiguate                                              //
// **************************************************************** //

APRS_LIB_INLINE bool try_get_position_with_timestamp_is_compressed(std::string_view data, bool& compressed);
APRS_LIB_INLINE bool try_get_position_without_timestamp_is_compressed(std::string_view data, bool& compressed);
APRS_LIB_INLINE bool try_get_object_is_compressed(std::string_view data, bool& compressed);
APRS_LIB_INLINE bool try_get_item_is_compressed(std::string_view data, bool& compressed);
APRS_LIB_INLINE bool try_get_mic_e_is_kenwood_tmd700(std::string_view data, bool& result);
APRS_LIB_INLINE bool is_supported_pri_table_symbol(char symbol_code);
APRS_LIB_INLINE bool is_supported_alt_table_symbol(char symbol_code);
APRS_LIB_INLINE bool is_overlayable_symbol(char symbol_code);
APRS_LIB_INLINE bool is_symbol_overlayable_with_uncompressed_overlay(char symbol_table);
APRS_LIB_INLINE bool is_symbol_overlayable_with_compressed_overlay(char symbol_table);

// **************************************************************** //
// TESTS                                                            //
// **************************************************************** //

APRS_LIB_INLINE bool test_is_position(std::string_view data);
APRS_LIB_INLINE bool test_is_mic_e(std::string_view data);

APRS_LIB_APRS_CORE_NAMESPACE_END

// **************************************************************** //
//                                                                  //
//                                                                  //
// TYPE IMPLEMENTATION AND SUPPORT                                  //
//                                                                  //
//                                                                  //
// **************************************************************** //

APRS_LIB_INLINE bool operator==(data_type first, data_type second)
{
    if ((int)first == (int)data_type::position)
    {
        if ((int)second == (int)data_type::position_with_timestamp ||
            (int)second == (int)data_type::position_without_timestamp ||
            (int)second == (int)data_type::position_compressed_without_timestamp ||
            (int)second == (int)data_type::position_compressed_with_timestamp)
        {
            return true;
        }
    }
    else if ((int)second == (int)data_type::position)
    {
        if ((int)first == (int)data_type::position_with_timestamp ||
            (int)first == (int)data_type::position_without_timestamp ||
            (int)first == (int)data_type::position_compressed_without_timestamp ||
            (int)first == (int)data_type::position_compressed_with_timestamp)
        {
            return true;
        }
    }
    if ((int)first == (int)data_type::object)
    {
        if ((int)second == (int)data_type::object_with_compressed_position ||
            (int)second == (int)data_type::object_with_data_ext ||
            (int)second == (int)data_type::object_without_data_ext)
        {
            return true;
        }
    }
    else if ((int)second == (int)data_type::object)
    {
        if ((int)first == (int)data_type::object_with_compressed_position ||
            (int)first == (int)data_type::object_with_data_ext ||
            (int)first == (int)data_type::object_without_data_ext)
        {
            return true;
        }
    }
    return (int)first == (int)second;
}

APRS_LIB_INLINE std::string to_string(const packet& packet)
{
    std::string result = packet.source_address + ">" + packet.destination_address;
    for (const auto& a : packet.path)
        result += "," + a;
    result += ":" + packet.data;
    return result;
}

APRS_LIB_INLINE std::string to_string(const data_type& t)
{
    switch (t)
    {
        case aprs::data_type::position_with_timestamp:
            return "position_with_timestamp";
        case aprs::data_type::position_without_timestamp:
            return "position_without_timestamp";
        case aprs::data_type::position_compressed_with_timestamp:
            return "position_compressed_with_timestamp";
        case aprs::data_type::position_compressed_without_timestamp:
            return "position_compressed_without_timestamp";
        case aprs::data_type::item_with_compressed_position:
            return "item_with_compressed_position";
        case aprs::data_type::position:
            return "position";
        case aprs::data_type::item:
            return "item";
        case aprs::data_type::object_with_data_ext:
            return "object_with_data_ext";
        case aprs::data_type::object_without_data_ext:
            return "object_without_data_ext";
        case aprs::data_type::object_with_compressed_position:
            return "object_with_compressed_position";
        case aprs::data_type::object:
            return "object";
        case aprs::data_type::message_ack:
            return "message_ack";
        case aprs::data_type::message:
            return "message";
        case aprs::data_type::mic_e_with_telemetry:
            return "mic_e_with_telemetry";
        case aprs::data_type::mic_e:
            return "mic_e";
        case aprs::data_type::bulletin:
            return "bulletin";
        case aprs::data_type::user_defined:
            return "user_defined";
        case aprs::data_type::test_data:
            return "test_data";
        default:
            break;
    }
    return "unknown";
}

#ifdef APRS_LIB_SYMBOL_INFO

APRS_LIB_INLINE std::string to_string(const symbol& s)
{
    symbol_info& symbol_info = APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE symbol_map::instance().get_symbol_info(s);
    return symbol_info.name;
}

APRS_LIB_INLINE symbol_info& get_symbol_info(const symbol& s)
{
    return APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE symbol_map::instance().get_symbol_info(s);
}

APRS_LIB_INLINE bool try_parse_symbol(const std::string& symbol_name, symbol& symbol)
{
    return APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE symbol_map::instance().try_get_symbol_by_name(symbol_name, symbol);
}

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE PacketWithSymbolSpec P>
APRS_LIB_INLINE bool try_parse_symbol(const P& data, symbol& symbol, symbol_overlay& symbol_overlay)
{
     return false;
}

APRS_LIB_INLINE bool try_parse_symbol(char symbol_table, char symbol_code, symbol& symbol, symbol_overlay& symbol_overlay)
{
    return false;
}

#endif

// **************************************************************** //
//                                                                  //
//                                                                  //
// MAIN FUNCTIONS                                                   //
//                                                                  //
//                                                                  //
// **************************************************************** //

APRS_LIB_INLINE data_type get_data_type(std::string_view data)
{
    //
    // Message types:
    // 
    //     position: !, =, /, @
    //         with timestamp: /, @
    //         without timestamp: =, !
    //     telemetry: T
    //     status report: >
    //     object: ;
    //     message: :
    //     MicE: `, ' 
    //     Query: ?
    //     Weather: _
    //     Item: )
    //

    char message_type = data[0];

    if (message_type == '!' || message_type == '=')    
    {
        bool compressed = false;
        if (APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_get_position_without_timestamp_is_compressed(data, compressed) && compressed)
            return data_type::position_compressed_without_timestamp;
        return data_type::position_without_timestamp;
    }
    else if (message_type== '/' || message_type == '@')
    {
        bool compressed = false;
        if (APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_get_position_with_timestamp_is_compressed(data, compressed) && compressed)
            return data_type::position_compressed_with_timestamp;
        return data_type::position_with_timestamp;
    }
    else if (message_type == ';')
    {
        bool compressed = false;
        if (APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_get_object_is_compressed(data, compressed) && compressed)
            return data_type::object_with_compressed_position;        
        return data_type::object;
    }
    else if (message_type == ')')
    {
        return data_type::item;
    }
    else if (message_type == ':')
    {
        return data_type::message;
    }
    else if (message_type == '`' || message_type == '\'')
    {
        return data_type::mic_e;
    }
    else if (message_type == '{')
    {
        return data_type::user_defined;
    }
    else if (message_type == ',')
    {
        return data_type::test_data;
    }

    return data_type::unknown;
}

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE PacketSpec T>
APRS_LIB_INLINE data_type get_packet_type(const T& packet)
{
    return get_data_type(packet.data);
}

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE IsAnyOf<position, object, item, message> T>
APRS_LIB_INLINE bool try_decode_data_as(std::string_view data, T& packet)
{
    //
    // Message types:
    // 
    //     position: !, =, /, @
    //         with timestamp: /, @
    //         without timestamp: =, !
    //     telemetry: T
    //     status report: >
    //     object: ;
    //     message: :
    //     MicE: `, ' 
    //     Query: ?
    //     Weather: _
    //

    data_type message_type = get_data_type(data);

    if constexpr (std::is_same_v<T, position>)
    {
        if (message_type == data_type::position_without_timestamp)    
        {
            return APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE try_parse_position_without_timestamp(data, packet);
        }
        if (message_type == data_type::position_compressed_without_timestamp)    
        {
            return APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE try_parse_compressed_position_without_timestamp(data, packet);
        }
        else if (message_type == data_type::position_with_timestamp)
        {
            return APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE try_parse_position_with_timestamp(data, packet);
        }
        else if (message_type == data_type::position_compressed_with_timestamp)
        {
            return APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE try_parse_compressed_position_with_timestamp(data, packet);
        }
    }
    else if constexpr (std::is_same_v<T, object>)
    {       
        if (message_type == data_type::object_with_compressed_position)
        {
            return APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE try_parse_object_with_compressed_position(data, packet);
        }
        else if (message_type == data_type::object)
        {
            return APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE try_parse_object_without_data_ext(data, packet);
        }
    }
    else if constexpr (std::is_same_v<T, message>)
    {
        if (message_type == data_type::message)
        {
            return APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE try_parse_message(data, packet);
        }
    }
    else if constexpr (std::is_same_v<T, item>)
    {
        if (message_type == data_type::item)
        {
            return APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE try_parse_item(data, packet);
        }
    }

    return false;
}

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE IsAnyOf<position, object, item, message, mic_e> T>
APRS_LIB_INLINE bool try_decode_data_as(std::string_view destination_address, std::string_view data, T& packet)
{
    data_type message_type = get_data_type(data);

    if constexpr (std::is_same_v<T, position> ||
                  std::is_same_v<T, object> ||
                  std::is_same_v<T, message> ||
                  std::is_same_v<T, item>)
    {
        return try_decode_data_as(data, packet);
    }
    if constexpr (std::is_same_v<T, mic_e>)
    {
        if (message_type == data_type::mic_e)
        {
            return APRS_LIB_APRS_CORE_NAMESPACE_REFERENCE try_parse_mic_e(destination_address, data, packet);
        }
    }

    return false;
}

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE PacketSpec P, APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE IsAnyOf<position, object, item, message, mic_e> T>
APRS_LIB_INLINE bool try_decode_packet_as(const P& packet, T& data)
{
    return try_decode_data_as(packet.destination_address, packet.data, data);
}

// **************************************************************** //
//                                                                  //
//                                                                  //
//                                                                  //
//                                                                  //
// PARSING                                                          //
//                                                                  //
//                                                                  //
//                                                                  //
//                                                                  //
// **************************************************************** //

// **************************************************************** //
//                                                                  //
// COORDINATE PARSING                                               //
//                                                                  //
// **************************************************************** //

APRS_LIB_APRS_DETAIL_NAMESPACE_BEGIN

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE PositionSpec T>
APRS_LIB_INLINE bool try_parse_compressed_coordinates(std::string_view pos_str, T& t_with_position)
{
    return try_parse_compressed_coordinates(pos_str, t_with_position.lat, t_with_position.lon);
}

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE PositionSpec T>
APRS_LIB_INLINE bool try_parse_coordinates(std::string_view lat_str, std::string_view lon_str, T& t_with_position)
{
    return try_parse_coordinates(lat_str, lon_str, t_with_position.lat, t_with_position.lon);
}

APRS_LIB_INLINE bool try_get_coordinate_ambiguity(std::string_view pos_str, int& lat_ambiguity, int& lon_ambiguity)
{
    return true;
}

APRS_LIB_INLINE bool try_parse_coordinates(std::string_view lat_str, std::string_view lon_str, float& lat, float& lon)
{
    APRS_LIB_APRS_DETAIL_NAMESPACE_USE

    if (lat_str.length() < 8 || lon_str.length() < 9)
    {
        return false;
    }
    
    std::string norm_lat = trim(std::string(lat_str));
    std::string norm_lon = trim(std::string(lon_str));
    
    // Spaces are added for position ambiguity
    // Replace them with 0s

    std::replace(norm_lat.begin(), norm_lat.end(), ' ', '0');
    std::replace(norm_lon.begin(), norm_lon.end(), ' ', '0');

    return try_parse_lat(norm_lat, lat) && try_parse_lon(norm_lon, lon);
}

APRS_LIB_INLINE bool try_parse_compressed_coordinates(std::string_view pos_str, float& lat, float& lon)
{
    //  
    //  Compressed position format:
    //
    //      Lat         Long
    //
    //   Y1 Y2 Y3 Y4  X1 X2 X3 X4
    //  ---------------------------
    //       4            4
    //

    return try_parse_compressed_lat(pos_str, lat) && try_parse_compressed_lon(pos_str, lon);;
}

APRS_LIB_INLINE bool try_parse_compressed_lat(std::string_view pos_str, float& lat)
{
    int y1 = pos_str[0];
    int y2 = pos_str[1];
    int y3 = pos_str[2];
    int y4 = pos_str[3];
    
    // Conversion documented in official APRS spec
    lat = 90 - ((y1 - 33) * pow(91, 3) + (y2 - 33) * pow(91, 2) + (y3 - 33) * 91 + y4 - 33) / 380926;
    
    return true;
}

APRS_LIB_INLINE bool try_parse_compressed_lon(std::string_view pos_str, float& lon)
{
    int x1 = pos_str[4];
    int x2 = pos_str[5];
    int x3 = pos_str[6];
    int x4 = pos_str[7];

    // Conversion documented in official APRS spec
    lon = -180 + ((x1 - 33) * pow(91, 3) + (x2 - 33) * pow(91, 2) + (x3 - 33) * 91 + x4 - 33) / 190463;

    return true;
}

APRS_LIB_INLINE bool try_parse_lat(std::string_view lat_str, float& lat)
{
    return try_parse_coordinate(lat_str.substr(0, 2), lat_str.substr(2, 2), lat_str.substr(5, 2), lat_str[7], lat);
}

APRS_LIB_INLINE bool try_parse_lon(std::string_view lon_str, float& lon)
{
    return try_parse_coordinate(lon_str.substr(0, 3), lon_str.substr(3, 2), lon_str.substr(6, 2), lon_str[8], lon);
}

APRS_LIB_INLINE bool try_parse_coordinate(std::string_view degrees_str, std::string_view minutes_str, std::string_view seconds_str, char direction, float& coordinate)
{
    float degrees = 0.0;
    float minutes = 0.0;
    float seconds = 0.0;    

    try
    {
        degrees = std::stof(std::string(degrees_str));
        minutes = std::stof(std::string(minutes_str));
        seconds = std::stof(std::string(seconds_str));
    }
    catch (const std::invalid_argument&)
    {
        return false;
    }
    
    coordinate = degrees + (minutes / 60.0f) + (seconds / 3600.0f);

    if (direction == 'S' || direction == 'W')
    {
        coordinate = -coordinate;
    }

    return true;
}

APRS_LIB_INLINE bool try_parse_mic_e_lat(std::string_view destination_address, float& lat)
{
    int lat_d = 0;
    int lat_m = 0;
    int lat_s = 0;
 
    // Mic-E latitude format:
    //
    //   When using the Mic-E, the latitude is stored in the destination field
    //   of the packet.
    //   
    //   -  Bytes 0-5 store the degrees, minutes and seconds in the 7 bits of each byte
    //   -  Bytes 0-1 store the degrees
    //   -  Bytes 2-3 store the minutes
    //   -  Bytes 4-5 store the seconds
    //   -  Byte 3 stores North/South
    //
    // The APRS specification documents a simple table used
    // for the decoding of the individual components
    // as part of Chapter 10, MIC-E DATA FORMAT
    //
    // Examples:
    //
    //   T7SWPZ
    //   3Y0P0P
    //   SX16R6
    //   TSR9Q0

    std::string lat_str(6, '\0');

    // Apply the APRS specification latitude fixed conversion table
    // to the destination adress to extract an array of digits as characters
    for (size_t i = 0; i < 6; i++)
    {
        if (destination_address[i] >= 'A' && destination_address[i] <= 'J')
        {
            // A-J -> 0-9
            lat_str[i] = destination_address[i] - 17;
        }
        else if (destination_address[i] >= 'P' && destination_address[i] <= 'Y')
        {
            // P-Y -> 0-9
            lat_str[i] = destination_address[i] - 32;
        }
        else if (destination_address[i] == 'K' || destination_address[i] == 'L' || destination_address[i] == 'Z')
        {
            // Position ambiguity
            lat_str[i] = '0';
        }
        else
        {
            lat_str[i] = destination_address[i];
        }
    }
    
    // Convert the degrees, minutes and seconds from string to integers
    lat_d = ((lat_str[0] - '0') * 10) + (lat_str[1] - '0');
    lat_m = ((lat_str[2] - '0') * 10) + (lat_str[3] - '0');
    lat_s = ((lat_str[4] - '0') * 10) + (lat_str[5] - '0');

    // Convert DMS coordinates to DD coordinates
    lat = lat_d + lat_m / 60.0 + lat_s / 6000.0;
    
    // Determine the sign of the coordinates
    // This is documented in the APRS specification as a conversion table
    char direction_str = destination_address[3];
    if ((direction_str >= '0' && direction_str <= '9') || direction_str == 'L')
    {
        // South
        lat = -lat;
    }
    else if (direction_str >= 'P' && direction_str <= 'Z')
    {
        // North
    }

    return true;
}

APRS_LIB_INLINE bool try_parse_mic_e_lon(std::string_view destination_address, std::string_view lon_str, float& lon)
{
    int lon_d;
    int lon_d_offset = 0;
    int lon_m;
    int lon_s;
    
    // We need the destination address to decode longitude
    // Look into the destination address byte 4 (5th) 
    // for the longitude degree offset
    // This is documented in APRS spec, under Mic-E Destination Address Field Encoding
    if (destination_address[4] >= 'P' && destination_address[4] <= 'Z')
    {
        lon_d_offset = 100;
    }

    // Longitude is stored as 3 bytes in d+28, m+28 and h+28
    // and 28 has to be substracted 

    // Apply the degrees offset
    lon_d = (lon_str[0] - 28) + lon_d_offset;
    
    lon_d = (lon_d >= 180 && lon_d <= 189) ? (lon_d - 80) : lon_d;
    lon_d = (lon_d >= 190 && lon_d <= 199) ? (lon_d - 190) : lon_d;

    lon_m = lon_str[1] - 28;
    lon_m = (lon_m > 60) ? (lon_m - 60) : lon_m;

    lon_s = lon_str[2] - 28;

    // Convert DMS coordinates to DD coordinates
    lon = lon_d + (lon_m / 60.0) + (lon_s / 6000.0);

    // Determine the sign of the coordinates
    // This is documented in the APRS specification as a conversion table
    char direction_str = destination_address[5];
    if ((direction_str >= '0' && direction_str <= '9') || direction_str == 'L')
    {
        // East
    }
    else if (direction_str >= 'P' && direction_str <= 'Z')
    {
        // West
        lon = -lon;
    }

    // Note: handle ambiguity based on ambiguity specified in the
    // destination address

    return true;
}

APRS_LIB_INLINE bool try_parse_mic_e_altitude(std::string_view alt_str, float& alt)
{
    // Format encoding:
    //
    //     xxx}, where xxx is in meters relative to 10,000 below
    //
    // Example:
    //
    //     200 feet = 61 meters = 10061 meters relative to the datum
    //     10061 / 912 = 1, remainder 1780
    //     1780 / 91 = 19, remainder 51

    int r3 = alt_str[0] - 33;
    int r2 = alt_str[1] - 33;
    int r1 = alt_str[2] - 33;

    alt = r1;
    alt = alt + r2 * 91;
    alt = alt + r3 * 8281;

    return true;
}

// **************************************************************** //
//                                                                  //
// UTILS                                                            //
//                                                                  //
// **************************************************************** //

APRS_LIB_INLINE bool try_parse_number(std::string_view number_str, int& number)
{
    auto [ptr, ec] = std::from_chars(number_str.begin(), number_str.end(), number);
    return ec == std::errc();
};

#ifndef APRS_LIB_PUBLIC_FORWARD_DECLARATIONS_ONLY

APRS_LIB_INLINE std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
    {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

#endif

// **************************************************************** //
//                                                                  //
// TIME PARSING                                                     //
//                                                                  //
// **************************************************************** //

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE DateTimeSpec T>
APRS_LIB_INLINE bool try_parse_timestamp(std::string_view timestamp, T& t_with_datetime)
{
    int day_or_hour;
    int hour_or_minute;
    int minute_or_second; 

    if (!try_parse_number(timestamp.substr(0, 2), day_or_hour) ||
        !try_parse_number(timestamp.substr(2, 2), hour_or_minute) ||
        !try_parse_number(timestamp.substr(4, 2), minute_or_second))
    {
        return false;    
    }
    
    using namespace std::chrono;

    auto tp_utc = system_clock::now();
    auto dp_utc = floor<days>(tp_utc);    
    auto tp_local = zoned_time{current_zone(), system_clock::now()}.get_local_time();
    auto dp_local = floor<days>(tp_local);
    year_month_day local_date{dp_local};
    year_month_day utc_date{dp_utc};
    
    //
    // Date format:
    // 
    // 234517h is 23 hours 45 minutes and 17 seconds zulu
    // 092345z is 2345 hours zulu time on the 9th day of the month
    // 092345/ is 2345 hours local time on the 9th day of the month
    // 

    if (timestamp[6] == 'z')
    {
        t_with_datetime.date_year = (int)utc_date.year();
        t_with_datetime.date_month = (int)(unsigned)utc_date.month();
        t_with_datetime.date_day = day_or_hour;        
        t_with_datetime.date_time_hour = hour_or_minute;        
        t_with_datetime.date_time_minute = minute_or_second;
    }
    else if (timestamp[6] == 'h')
    {
        t_with_datetime.date_year = (int)utc_date.year();
        t_with_datetime.date_month = (int)(unsigned)utc_date.month();
        t_with_datetime.date_day = (int)(unsigned)utc_date.day();        
        t_with_datetime.date_time_hour = day_or_hour;
        t_with_datetime.date_time_minute = hour_or_minute;
    }
    else if (timestamp[6] == '/')
    {
        t_with_datetime.date_year = (int)local_date.year();
        t_with_datetime.date_month = (int)(unsigned)local_date.month();
        t_with_datetime.date_day = day_or_hour;        
        t_with_datetime.date_time_hour = hour_or_minute; 
        t_with_datetime.date_time_minute = minute_or_second;
    }
    else
    {
        return false;
    }

    return true;
}

// **************************************************************** //
//                                                                  //
// HELPERS                                                          //
//                                                                  //
// **************************************************************** //

APRS_LIB_INLINE void parse_data_ext(std::string_view data)
{
    //
    // Format:
    //
    //
    // Examples:
    //
    //     088/036 - course and speed
    //     220/004 - wind direction and wind speed
    //     PHG3250 - power, antenna height, gain, directivity codes
    //     RNG0050 - pre-calculated radio range
    //     DFS2360 - omni-DF signal strength
    //     088/036/270/729 - course and speed, and: bearing, number, range and quality
    //     907/215 - area object descriptor
    //
}

APRS_LIB_INLINE bool try_parse_object_state(char state_ch, object_state& state)
{
    if (state_ch == '*')
    {
        state = object_state::live;
        return true;
    }
    else if (state_ch == '_')
    {
        state = object_state::killed;
        return true;
    }
    return false;
}

APRS_LIB_INLINE bool try_parse_item_state(char state_ch, item_state& state)
{
    if (state_ch == '!')
    {
        state = item_state::live;
        return true;
    }
    else if (state_ch == '_')
    {
        state = item_state::killed;
        return true;
    }
    return false;
}

APRS_LIB_NAMESPACE_END

// **************************************************************** //
//                                                                  //
//                                                                  //
//                                                                  //
//                                                                  //
//                                                                  //
// CORE DATA PARSING                                                //
//                                                                  //
//                                                                  //
//                                                                  //
//                                                                  //
//                                                                  //
// **************************************************************** //

APRS_LIB_APRS_CORE_NAMESPACE_BEGIN

APRS_LIB_INLINE bool try_parse_position_without_timestamp(std::string_view data, position& position)
{
    if (data.length() < 20)
    {
        return false;
    }

    // 
    //  Data Format:
    // 
    //     !   Lat  Sym  Lon  Sym Code   Comment
    //     =
    //    ------------------------------------------
    //     1    8    1    9      1        0-43
    //
    //  Examples:
    //
    //    !4903.50N/07201.75W-Test 001234
    //    !4903.50N/07201.75W-Test /A=001234
    //    !49  .  N/072  .  W-
    //

    std::string_view lat = data.substr(1, 8);    
    std::string_view symbol_table = data.substr(9, 1);
    std::string_view lon = data.substr(10, 9);
    std::string_view symbol_code = data.substr(19, 1);    
    std::string_view comment = (data.length() > 20) ? data.substr(20) : std::string_view();

    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_coordinates(lat, lon, position.lat, position.lon))
    {
        return false;
    }

    position.comment = comment;
    position.symbol_table = symbol_table[0];
    position.symbol_code = symbol_code[0];    

    return true;
}

APRS_LIB_INLINE bool try_parse_position_with_timestamp(std::string_view data, position& position)
{    
    if (data.length() < 27)
    {
        return false;
    }

    // 
    //  Data Format:
    // 
    //     /   Time  Lat   Sym  Lon  Sym Code   Comment
    //     @
    //    -----------------------------------------------
    //     1    7     8     1    9      1        0-43
    //
    //  Examples:
    //
    //    /092345z4903.50N/07201.75W>Test1234
    //    @092345/4903.50N/07201.75W>Test1234
    //

    std::string_view timestamp = data.substr(1, 7);    
    std::string_view lat = data.substr(8, 8);    
    std::string_view symbol_table = data.substr(16, 1);
    std::string_view lon = data.substr(17, 9);
    std::string_view symbol_code = data.substr(26, 1);
    std::string_view comment = (data.length() > 27) ? data.substr(27) : std::string_view();

    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_coordinates(lat, lon, position) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_timestamp(timestamp, position))
    {
        return false;
    }

    position.comment = comment;
    position.symbol_table = symbol_table[0];
    position.symbol_code = symbol_code[0];

    return true;
}

APRS_LIB_INLINE bool try_parse_compressed_position_without_timestamp(std::string_view data, position& position)
{
    if (data.length() < 14)
    {
        return false;
    }

    // 
    //  Data Format:
    // 
    //     !   Sym     Comp Lat    Comp Lon     Sym Code   Compressed Speed/Range/Alt  CompType  Comment
    //     =
    //    --------------------------------------------------------------------------------------------------
    //     1    1          4           4            1                   2                  1       0-40
    //
    //  Examples:
    //  
    //    =/5L!!<*e7>7P[
    //

    std::string_view symbol_table = data.substr(1, 1);
    std::string_view compressed_pos = data.substr(2, 8);
    std::string_view symbol_code = data.substr(10, 1);
    std::string_view compressed_speed_range_alt = data.substr(11, 2);
    std::string_view compression_type = data.substr(13, 1);
    std::string_view comment = (data.length() > 14) ? data.substr(14) : std::string_view();

    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_compressed_coordinates(compressed_pos, position))
    {
        return false;
    }

    position.comment = comment;
    position.symbol_table = symbol_table[0];
    position.symbol_code = symbol_code[0];    

    return true;
}

APRS_LIB_INLINE bool try_parse_compressed_position_with_timestamp(std::string_view data, position& position)
{
    if (data.length() < 21)
    {
        return false;
    }

    // 
    //  Data Format:
    // 
    //     /     Time   Sym     Comp Lat    Comp Lon     Sym Code   Compressed Speed/Range/Alt  CompType  Comment
    //     @
    //    --------------------------------------------------------------------------------------------------------
    //     1       7     1          4           4            1                   2                  1       0-40
    //
    //  Examples:
    //  
    //    @092345z/5L!!<*e7>{?!
    //

    std::string_view timestamp = data.substr(1, 7);
    std::string_view symbol_table = data.substr(8, 1);
    std::string_view compressed_pos = data.substr(9, 8);
    std::string_view symbol_code = data.substr(17, 1);
    std::string_view compressed_speed_range_alt = data.substr(18, 2);
    std::string_view compression_type = data.substr(20, 1);
    std::string_view comment = (data.length() > 21) ? data.substr(21) : std::string_view();

    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_timestamp(timestamp, position) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_compressed_coordinates(compressed_pos, position))
    {
        return false;
    }

    position.comment = comment;
    position.symbol_table = symbol_table[0];
    position.symbol_code = symbol_code[0];    

    return true;
}

APRS_LIB_INLINE bool try_parse_object_with_data_ext(std::string_view data, object& object)
{
    if (data.length() < 37)
    {
        return false;
    }

    // 
    //  Object data formats:
    // 
    //     ;   Name   State   Time   Lat   Sym  Lon  Sym Code   Data Ext    Comment
    //    ----------------------------------------------------------------------------
    //     1    9       1       7     8     1    9      1         7         0-36
    //
    //  Examples:
    //
    //    ;LEADER   *092345z4903.50N/07201.75W>088/036
    //

    std::string_view name = data.substr(1, 9);    
    std::string_view alive_or_dead = data.substr(10, 1);    
    std::string_view timestamp = data.substr(11, 7);
    std::string_view lat = data.substr(18, 8);
    std::string_view symbol_table = data.substr(26, 1);
    std::string_view lon = data.substr(27, 9);
    std::string_view symbol_code = data.substr(36, 1);
    std::string_view data_ext = (data.length() > 37) ? data.substr(37, 7) : std::string_view();
    std::string_view comment = (data.length() > 44) ? data.substr(44) : std::string_view();

    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_coordinates(lat, lon, object) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_timestamp(timestamp, object) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_object_state(alive_or_dead[0], object.state))
    {
        return false;
    }

    object.name = name;
    object.comment = comment;
    object.symbol_table = symbol_table[0];
    object.symbol_code = symbol_code[0];

    return true;
}

APRS_LIB_INLINE bool try_parse_object_without_data_ext(std::string_view data, object& object)
{
    if (data.length() < 37)
    {
        return false;
    }

    // 
    //  Object data format:
    //
    //     ;   Name   State   Time   Lat   Sym  Lon  Sym Code   Comment
    //    ----------------------------------------------------------------
    //     1    9       1       7     8     1    9      1         0-43
    //
    //  Examples:
    //
    //    ;LEADER   *092345z4903.50N/07201.75W>088/036
    //

    std::string_view name = data.substr(1, 9);    
    std::string_view alive_or_dead = data.substr(10, 1);    
    std::string_view timestamp = data.substr(11, 7);
    std::string_view lat = data.substr(18, 8);
    std::string_view symbol_table = data.substr(26, 1);
    std::string_view lon = data.substr(27, 9);
    std::string_view symbol_code = data.substr(36, 1);
    std::string_view comment = (data.length() > 37) ? data.substr(37) : std::string_view();
   
    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_coordinates(lat, lon, object) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_timestamp(timestamp, object) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_object_state(alive_or_dead[0], object.state))
    {
        return false;
    }

    object.name = name;
    object.comment = comment;
    object.symbol_table = symbol_table[0];
    object.symbol_code = symbol_code[0];

    return true;
}

APRS_LIB_INLINE bool try_parse_object_with_compressed_position(std::string_view data, object& object)
{
    if (data.length() < 31)
    {
        return false;
    }

    // 
    //  Object data format:
    //
    //     ;   Name   State   Time  /   Comp pos   Sym code   Comp speed/range/alt   Comp type       Comment
    //    -----------------------------------------------------------------------------------------------------
    //     1    9       1       7   1      8          1                2                 1             0-43
    //
    //  Examples:
    //
    //    ;LEADER   *092345z/5L!!<*e7>7P[
    //

    std::string_view name = data.substr(1, 9);
    std::string_view alive_or_dead = data.substr(10, 1);    
    std::string_view timestamp = data.substr(11, 7);
    std::string_view symbol_table = data.substr(18, 1);
    std::string_view compressed_pos = data.substr(19, 8);
    std::string_view symbol_code = data.substr(27, 1);
    std::string_view compressed_speed_range_alt = data.substr(28, 2);
    std::string_view compression_type = data.substr(30, 1);
    std::string_view comment = (data.length() > 31) ? data.substr(31) : std::string_view();
   
    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_compressed_coordinates(compressed_pos, object) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_timestamp(timestamp, object) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_object_state(alive_or_dead[0], object.state))
    {
        return false;
    }

    object.name = name;
    object.comment = comment;
    object.symbol_table = symbol_table[0];
    object.symbol_code = symbol_code[0];

    return true;
}

APRS_LIB_INLINE bool try_parse_message(std::string_view data, message& message)
{
    if (data.length() < 12)
    {
        return false;
    }

    // 
    //  Object data format:
    //
    //     :   Adr   :   Text   {   Message No
    //    -------------------------------------
    //     1    9    1   0-67   1      1-5
    //
    //  Examples:
    //
    //    :WU2Z     :Testing{003
    //

    message.addressee = data.substr(1, 9);
    
    size_t message_id_pos = data.find("{", 11, 1);
    if (message_id_pos != data.npos)
    {
        if ((message_id_pos + 2) > data.length())
        {
            return false;
        }

        message.text = data.substr(11, message_id_pos - 11);
        message.message_no = data.substr(message_id_pos + 1);
    }
    else
    {
        message.text = data.substr(11);
    }

    return true;
}

APRS_LIB_INLINE bool try_parse_message_with_acknowledgment(std::string_view data, message& message)
{
    if (data.length() < 15)
    {
        return false;
    }

    // 
    //  Object data format:
    //
    //     :   Adr   :   ack    Message No
    //    -------------------------------------
    //     1    9    1    3       1-5
    //
    //  Examples:
    //
    //    :KB2ICI-14:ack003
    //    :KB2ICI-14:rej003
    //

    message.addressee = data.substr(1, 9);    

    size_t message_id_pos = data.find("ack", 11);
    if (message_id_pos == data.npos)
    {
        message_id_pos = data.find("rej", 11);
    }

    if (message_id_pos != data.npos)
    {
        if ((message_id_pos + 4) > data.length())
        {
            return false;
        }

        message.text = data.substr(11, 3);
        message.message_no = data.substr(message_id_pos + 3);
    }
    else
    {
        return false;
    }

    return true;
}

APRS_LIB_INLINE bool try_parse_item(std::string_view data, item& item)
{
    if (data.length() < 24)
    {
        return false;
    }

    // 
    //  Item data format:
    //
    //                State
    //                  !
    //     )   Name     ?    Lat   Sym  Lon  Sym Code   Comment
    //    ----------------------------------------------------------
    //     1    3-9     1     8     1    9      1         0-43
    //
    //  Examples:
    //
    //    )AIDV#2!4903.50N/07201.75WA
    //

    std::size_t state_position = data.find_first_of("!?", 4, 1);

    if (state_position == data.npos || (state_position + 19) < data.length())
    {
        return false;
    }

    std::string_view name = data.substr(1, state_position - 1);    
    std::string_view alive_or_dead = data.substr(state_position, 1); 
    std::string_view lat = data.substr(state_position + 1, 8);
    std::string_view symbol_table = data.substr(state_position + 9, 1);
    std::string_view lon = data.substr(state_position + 10, 9);
    std::string_view symbol_code = data.substr(state_position + 19, 1);
    std::string_view comment = (data.length() > (state_position + 20)) ? data.substr(state_position + 20) : std::string_view();
   
    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_coordinates(lat, lon, item) ||        
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_item_state(alive_or_dead[0], item.state))
    {
        return false;
    }

    item.name = name;
    item.symbol_table = symbol_table[0];
    item.symbol_code = symbol_code[0];
    item.comment = comment;

    return true;
}

APRS_LIB_INLINE bool try_parse_item_with_compressed_position(std::string_view data, item& item)
{
    if (data.length() < 18)
    {
        return false;
    }

    // 
    //  Item data format:
    //
    //                State
    //                  !
    //     )   Name     ?    Comp Pos   Comment
    //    ----------------------------------------------------------
    //     1    3-9     1       13        0-43
    //
    //  Examples:
    //
    //    )MOBIL!\5L!!<*e79 sT
    //

    std::size_t state_position = data.find_first_of("!?", 4, 1);

    if (state_position == data.npos || (state_position + 13) < data.length())
    {
        return false;
    }

    std::string_view name = data.substr(1, state_position - 1);    
    std::string_view alive_or_dead = data.substr(state_position, 1);
    std::string_view symbol_table = data.substr(state_position + 1, 1);
    std::string_view compressed_pos = data.substr(state_position + 2, 8);
    std::string_view symbol_code = data.substr(state_position + 10, 1);
    std::string_view compressed_speed_range_alt = data.substr(state_position + 11, 2);
    std::string_view compression_type = data.substr(state_position + 13, 1);
    std::string_view comment = (data.length() > (state_position + 14)) ? data.substr(state_position + 14) : std::string_view();
   
    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_compressed_coordinates(compressed_pos, item) ||        
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_item_state(alive_or_dead[0], item.state))
    {
        return false;
    }

    item.name = name;
    item.symbol_table = symbol_table[0];
    item.symbol_code = symbol_code[0];
    item.comment = comment;

    return true;
}

template <APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE PacketSpec P>
APRS_LIB_INLINE bool try_parse_mic_e(const P& packet, mic_e& mic_e)
{
    return try_parse_mic_e(packet.destination_address, packet.data, mic_e);
}

APRS_LIB_INLINE bool try_parse_mic_e(std::string_view destination_address, std::string_view data, mic_e& mic_e)
{
    if (data.length() < 9)
    {
        return false;
    }

    std::string_view lon = data.substr(1, 3);
    std::string_view speed_and_course = data.substr(4, 3);
    std::string_view symbol_code = data.substr(7, 1);
    std::string_view symbol_table = data.substr(8, 1);
    std::string_view telemetry_or_text = data.substr(9);

    if (!APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_mic_e_lat(destination_address, mic_e.lat) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_mic_e_lon(destination_address, lon, mic_e.lon) ||
        !APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_mic_e_status(destination_address, mic_e.status))
    {
        return false;
    }

    bool has_telemetry = false;
    APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_get_mic_e_has_telemetry(data, has_telemetry);
    if (has_telemetry)
    {
        APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE try_parse_mic_e_telemetry(data, mic_e);
    }

    mic_e.symbol_code = symbol_code[0];
    mic_e.symbol_table = symbol_table[0];

    return true;
}


APRS_LIB_INLINE bool try_parse_bulletin(std::string_view data, bulletin& bulletin)
{
    if (data.length() < 11)
    {
        return false;
    }

    // 
    //  Group Bulletin Format:
    //                                             
    //     :   BLN        ID            Name      :      Text
    //    --------------------------------------------------------
    //     1    3          1              5       1      0-67
    //
    // 
    //  Announcement Format:
    //                                                 
    //     :   BLN        ID                      :      Text
    //    --------------------------------------------------------
    //     1    3          1              5       1      0-67
    //
    //  Examples:
    //
    //    :BLN3     :Snow expected in Tampa RSN
    //    :BLNQ     :Mt St Helen digi will be QRT this weekend
    //

    if (data[10] != ':')
    {
        return false;
    }

    std::string_view id = data.substr(4, 1);
    std::string_view name = data.substr(5, 5);
    std::string_view text = data.substr(11);

    bulletin.id = id[0];
    bulletin.name = APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE trim(std::string(name));
    bulletin.text = APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE trim(std::string(text));

    return true;
}

APRS_LIB_INLINE bool try_parse_nws_bulletin(std::string_view data, nws_bulletin& bulletin)
{
    if (data.length() < 11)
    {
        return false;
    }

    // 
    //  Group Bulletin Format:
    //                                             
    //     :   NWS-xxxxx      :      Text
    //    --------------------------------------------------------
    //     1       9          1       n
    //
    //  Examples:
    //
    //      :NWS_WARN :130730z,Flood,NDC017{C1T00

    if (data[10] != ':')
    {
        return false;
    }

    std::string_view callsign = data.substr(1, 9);
    std::string_view text = data.substr(11);

    bulletin.callsign = APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE trim(std::string(callsign));
    bulletin.text = APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE trim(std::string(text));

    return true;
}

APRS_LIB_INLINE bool try_parse_user_defined(std::string_view data, user_defined& user_defined)
{
    if (data.length() < 3)
    {
        return false;
    }

    //
    //  User Defined Format:
    //                                             
    //     {    User ID      Packet Type      Data
    //    --------------------------------------------------------
    //     1       1              1             n
    //
    //  Examples:
    //
    //      {Q1qwerty
    //      {{zasdfg
    //

    std::string_view user_id = data.substr(1, 1);
    std::string_view packet_type = data.substr(2, 1);
    std::string_view user_data = data.substr(3);

    user_defined.user_id = user_id[0];
    user_defined.packet_type = packet_type[0];
    user_defined.data = user_data;

    return true;
}

APRS_LIB_INLINE bool try_parse_test_data(std::string_view data, test_data& test_data)
{
    if (data.length() < 1)
    {
        return false;
    }

    //
    //  Test or invalid data:
    //                                             
    //     ,    Data
    //    --------------------------------------------------------
    //     1      n
    //
    //  Examples:
    //
    //      ,191146,V,4214.2466,N,07303.5181,W,417.238,114.5,091099,14.7,W/GPS FIX
    //

    test_data.data = data.substr(1);

    return true;
}

APRS_LIB_NAMESPACE_END

APRS_LIB_APRS_DETAIL_NAMESPACE_BEGIN

APRS_LIB_INLINE bool try_get_mic_e_has_telemetry(std::string_view data, bool& has_telemetry)
{
    if (data.length() < 10)
    {
        return false;
    }

    std::string_view telemetry = data.substr(9);
        
    if (telemetry[0] == '`' || telemetry[0] == '\'' || telemetry[0] == 0x1d)
    {
        has_telemetry = true;
    }
    else
    {
        has_telemetry = false;
    }

    return true;
}

APRS_LIB_INLINE bool try_parse_mic_e_bin_telemetry_channels(std::string_view data, std::vector<int>& channels)
{
    size_t i = 0;

    while (true)
    {
        if ((i + 1) >= data.length())
        {
            break;
        }

        if (!isdigit(data[i]))
            return false;

        std::string ch_str(data.substr(i, 1));
        long ch = strtol(ch_str.c_str(), nullptr, 16);
        channels.push_back(ch);

        i += 2;
    }

    return true;
}

APRS_LIB_INLINE bool try_parse_mic_e_hex_telemetry_channels(std::string_view data, std::vector<int>& channels)
{
    size_t i = 0;

    while (true)
    {
        if ((i + 1) >= data.length())
        {
            break;
        }

        if (!isxdigit(data[i]) || !isxdigit(data[i + 1]))
            return false;

        std::string ch_str(data.substr(i, 2));
        long ch = strtol(ch_str.c_str(), nullptr, 16);
        channels.push_back(ch);

        i += 2;
    }

    return true;
}

APRS_LIB_INLINE bool try_parse_mic_e_telemetry(std::string_view data, std::vector<int>& telemetry_channels)
{
    // Expect at least 2 bytes of telemetry

    if (data.length() < 11)
    {
        return false;
    }

    // 
    //  Optional Mic-E Telemetry Data:
    //
    //     `     Ch1   Ch2   Ch3   Ch4   Ch5
    //     '
    //    0x1d
    //    ------------------------------------
    //     1      2     2     2     2     2
    //
    //
    //           Ch1   Ch1   Ch2   Ch2   Ch3   Ch3   Ch4   Ch4   Ch5   Ch5
    //    --------------------------------------------------------------------
    //     `      1     1     1     1
    //     '      1     1     1     1     1     1     1     1     1     1 
    //    0x1d    1     x     1     x     1     x     1     x     1     x
    //
    //
    //
    //  Examples:
    //
    //    `2(5l!?[/`FEFE
    //    `2(5l!?[/'7200007100
    //
    //    Not sure: `2(5l!?[/\x1d1020304050
    //

    std::string_view telemetry = data.substr(9);
        
    if (telemetry[0] == '`')
    {
        if (data.length() < 14)
        {
            return false;
        }

        try_parse_mic_e_hex_telemetry_channels(data.substr(10, 4), telemetry_channels);
    }
    else if (telemetry[0] == '\'')
    {
        if (data.length() < 20)
        {
            return false;
        }

        try_parse_mic_e_hex_telemetry_channels(data.substr(10, 10), telemetry_channels);
    }
    else if (telemetry[0] == 0x1d)
    {
        //
        // Not sure if this works due to lack of example packets
        //

        if (data.length() < 20)
        {
            return false;
        }
        
        try_parse_mic_e_bin_telemetry_channels(data.substr(10, 10), telemetry_channels);
    }
    else
    {
        return false;
    }

    return true;
}

APRS_LIB_INLINE bool try_parse_mic_e_telemetry(std::string_view data, mic_e& mic_e)
{
    return try_parse_mic_e_telemetry(data, mic_e.telemetry_channels);
}

APRS_LIB_INLINE bool try_parse_mic_e_message_abc(char ch, int& d, bool& custom)
{
    if (ch >= 'P' && ch <= 'Z')
    {
        d = 1;
        custom = false;
    }
    else if (ch >= 'A' && ch <= 'K')
    {
        d = 1;
        custom = true;
    }
    else
    {
        d = 0;
        custom = false;
    }
    return true;
}

APRS_LIB_INLINE bool try_parse_mic_e_status(std::string_view destination_address, mic_e_status& status)
{
    int a = 0;
    bool a_custom = false;
    int b = 0;
    bool b_custom = false;
    int c = 0;
    bool c_custom = false;
    
    if (!try_parse_mic_e_message_abc(destination_address[0], a, a_custom) ||
        !try_parse_mic_e_message_abc(destination_address[1], b, b_custom) ||
        !try_parse_mic_e_message_abc(destination_address[2], c, c_custom))
    {
        return false;
    }

    if (a_custom != b_custom || b_custom != c_custom || c_custom != a_custom)
    {
        return false;
    }

    /*

        Lookup table:

        |  a  |  b  |  c  | (a << 2) | (b << 1) |  c  | Result |  Status
        |-----|-----|-----|----------|----------|-----|--------|--------------
        |  0  |  0  |  0  |    0     |    0     |  0  |   0    |  emergency  
        |  0  |  0  |  1  |    0     |    0     |  1  |   1    |  priority
        |  0  |  1  |  0  |    0     |    2     |  0  |   2    |  special
        |  0  |  1  |  1  |    0     |    2     |  1  |   3    |  committed
        |  1  |  0  |  0  |    4     |    0     |  0  |   4    |  returning
        |  1  |  0  |  1  |    4     |    0     |  1  |   5    |  in service
        |  1  |  1  |  0  |    4     |    2     |  0  |   6    |  en route
        |  1  |  1  |  1  |    4     |    2     |  1  |   7    |  off duty

    */

    switch ((a << 2) | (b << 1) | c)
    {
        case 7:
            status = a_custom ? mic_e_status::custom0 : mic_e_status::off_duty;
            break;
        case 6:
            status = a_custom ? mic_e_status::custom1 : mic_e_status::en_route;
            break;
        case 5:
            status = a_custom ? mic_e_status::custom2 : mic_e_status::in_service;
            break;
        case 4:
            status = a_custom ? mic_e_status::custom3 : mic_e_status::returning;
            break;
        case 3:
            status = a_custom ? mic_e_status::custom4 : mic_e_status::commited;
            break;
        case 2:
            status = a_custom ? mic_e_status::custom5 : mic_e_status::special;
            break;
        case 1:
            status = a_custom ? mic_e_status::custom6 : mic_e_status::priority;
            break;
        case 0:
            status = mic_e_status::emergency;
            break;
        default:
            break;
    }

    return true;
}

APRS_LIB_INLINE bool try_parse_area_object_color_intensity(std::string_view object_color_intensity, area_object_color_intensity& color_intensity)
{
    color_intensity = area_object_color_intensity::uknown;

    if (object_color_intensity[0] == '/')
    {
        if (isdigit(object_color_intensity[1]))
        {
            color_intensity = (area_object_color_intensity)(uint)object_color_intensity[1];
        }
    }
    else
    {
        int color_intensity_int;
        if (try_parse_number(object_color_intensity, color_intensity_int) && color_intensity_int < 16)
        {
            color_intensity = (area_object_color_intensity)color_intensity_int;
        }
    }

    return color_intensity != area_object_color_intensity::uknown;
}

APRS_LIB_INLINE bool try_parse_area_object(std::string_view area_object_str)
{
    //
    // Area Object format:
    //
    // Tyy/Cxx
    //
    //     T is the type of object shape.    
    //     /C is the color of the object.
    //     yy is the square root of the latitude offset in 1/100ths of a degree.
    //     xx is the square root of the longitude offset in 1/100ths of a degree.

    std::string_view object_type = area_object_str.substr(0, 1);
    std::string_view object_color_intensity = area_object_str.substr(3, 2);
    std::string_view lat_offset = area_object_str.substr(1, 2);
    std::string_view lon_offset = area_object_str.substr(5, 2);

    area_object_type type = (area_object_type)object_type[0];
    area_object_color_intensity intensity;
    try_parse_area_object_color_intensity(object_color_intensity, intensity);

    return false;
}

APRS_LIB_INLINE void parse_compression_type(const char t, int& compression_origin, int& nmea_source, bool& old_or_current)
{
#if defined(_M_X64) || defined(__x86_64__)
    compression_origin = t & 0b00000111;
    nmea_source = (t & 0b00011000) >> 3;
    old_or_current = ((t & 0b00100000) >> 5) != 0;
#elif defined(__arm__) || defined(__aarch64__) || defined(_M_X64)
    compression_origin = (t & 0b11100000) << 5;
    nmea_source = (t & 0b00011000) << 3;
    old_or_current = ((t & 0b00000100) << 5) != 0;
#endif
}

APRS_LIB_INLINE void parse_compression_type(const char t, compression_origin& compression_origin, nmea_source& nmea_source, bool& old_or_current)
{
    parse_compression_type(t, (int&)compression_origin, (int&)nmea_source, old_or_current);
}

// **************************************************************** //
//                                                                  //
//                                                                  //
//                                                                  //
// SYMBOL PARSING                                                   //
//                                                                  //
//                                                                  //
//                                                                  //
// **************************************************************** //

APRS_LIB_INLINE bool try_parse_uncompressed_symbol(char symbol_table, char symbol_code, symbol& symbol_, symbol_overlay& symbol_overlay_)
{
    symbol_ = symbol::no_symbol;
    symbol_overlay_ = symbol_overlay::none;

    if (is_overlayable_symbol(symbol_code) && is_symbol_overlayable_with_uncompressed_overlay(symbol_table))
    {
        return try_parse_overlayable_uncompressed_symbol(symbol_table, symbol_code, symbol_, symbol_overlay_);
    }
    else
    {
        return try_parse_symbol_no_overlay(symbol_table, symbol_code, symbol_);
    }
}

APRS_LIB_INLINE bool try_parse_compressed_symbol(char symbol_table, char symbol_code, symbol& symbol_, symbol_overlay& symbol_overlay_)
{
    symbol_ = symbol::no_symbol;
    symbol_overlay_ = symbol_overlay::none;

    if (is_overlayable_symbol(symbol_code) && is_symbol_overlayable_with_compressed_overlay(symbol_table))
    {
        return try_parse_overlayable_compressed_symbol(symbol_table, symbol_code, symbol_, symbol_overlay_);
    }
    else
    {
        return try_parse_symbol_no_overlay(symbol_table, symbol_code, symbol_);
    }
}

APRS_LIB_INLINE bool try_parse_symbol_no_overlay(char symbol_table, char symbol_code, symbol& symbol_)
{
    if (symbol_table == '/')
    {
        return try_parse_pri_table_symbol(symbol_code, symbol_); 
    }
    else if (symbol_table == '\\')
    {
        return try_parse_alt_table_symbol(symbol_code, symbol_);
    }
    else if (symbol_code == 'a')
    {
        return try_parse_ar_symbol(symbol_table, symbol_);
    }

    return false;
}

APRS_LIB_INLINE bool try_parse_pri_table_symbol(char symbol_code, symbol& symbol)
{
    return is_supported_pri_table_symbol(symbol_code) && symbol_map::instance().try_get_symbol_by_value(symbol_code, symbol);
}

APRS_LIB_INLINE bool try_parse_alt_table_symbol(char symbol_code, symbol& symbol)
{
    return is_supported_alt_table_symbol(symbol_code) && symbol_map::instance().try_get_symbol_by_value(symbol_code + 200, symbol);
}

APRS_LIB_INLINE bool try_parse_ar_symbol(char symbol_table, symbol& symbol)
{
    switch (symbol_table)
    {
        case 'A':
            symbol = symbol::arrl;
            break;
        case 'R':
            symbol = symbol::races;
            break;
        default:
            return false;
    }
    return true;
}

APRS_LIB_INLINE bool try_parse_overlayable_uncompressed_symbol(char symbol_table, char symbol_code, symbol& symbol_, symbol_overlay& symbol_overlay_)
{
    return try_parse_alt_table_symbol(symbol_code, symbol_) && try_parse_uncompressed_symbol_overlay(symbol_table, symbol_overlay_);
}

APRS_LIB_INLINE bool try_parse_overlayable_compressed_symbol(char symbol_table, char symbol_code, symbol& symbol_, symbol_overlay& symbol_overlay_)
{
    return try_parse_alt_table_symbol(symbol_code, symbol_) && try_parse_compressed_symbol_overlay(symbol_table, symbol_overlay_);
    symbol_overlay_ = (symbol_overlay)(symbol_table - 'a' + '0'); // 'a' - 'j' to '0' - '9'
}

APRS_LIB_INLINE bool try_parse_uncompressed_symbol_overlay(char symbol_table, symbol_overlay& symbol_overlay_)
{
    symbol_overlay_ = (symbol_overlay)symbol_table;
    return (symbol_table >= 'A' && symbol_table <= 'Z') || (symbol_table >= '0' && symbol_table <= '9');
}

APRS_LIB_INLINE bool try_parse_compressed_symbol_overlay(char symbol_table, symbol_overlay& symbol_overlay_)
{
    symbol_overlay_ = (symbol_overlay)(symbol_table - 'a' + '0'); // 'a' - 'j' to '0' - '9'
    return (symbol_table >= 'A' && symbol_table <= 'Z') || (symbol_table >= 'a' && symbol_table <= 'j');
}

APRS_LIB_INLINE bool symbol_map::try_get_symbol_by_destination_address(std::string destination_address, symbol& symbol)
{
    if (destination_address_map.count(destination_address) == 1)
    {
        symbol = (enum symbol)destination_address_map[destination_address];
        return true;
    }
    return false;
}

APRS_LIB_INLINE bool symbol_map::try_get_symbol_by_value(int symbol_value, symbol& symbol)
{
    if (symbol_code_map.count(symbol_value) == 1)
    {
        symbol = (enum symbol)symbol_code_map[symbol_value];
        return true;
    }
    return false;
}

APRS_LIB_INLINE bool symbol_map::try_get_symbol_by_name(const std::string& name, symbol& symbol)
{
    if (symbol_name_map.count(name) == 1)
    {
        symbol = (enum symbol)symbol_name_map[name];
        return true;
    }
    return false;
}

#ifdef APRS_LIB_SYMBOL_INFO

APRS_LIB_INLINE symbol_info& symbol_map::get_symbol_info(symbol symbol)
{ 
    size_t index = (size_t)symbol;
    if (index < 0 || index >= symbols.size())
    {
        return no_symbol;
    }
    return symbols[index];
}

#endif

APRS_LIB_INLINE void symbol_map::populate()
{
    if (populated)
    {
        return;
    }
    populated = true;

#ifdef APRS_LIB_SYMBOL_INFO
    symbols.reserve(164);
    symbols.push_back({ 1, "police_station", "Police, Sheriff", '!', '/', false, "BB", -1 });
    symbols.push_back({ 3, "digi", "Digi (green star with white center)", '#', '/', false, "BD", -1 });
    symbols.push_back({ 4, "phone", "Phone", '$', '/', false, "BE", -1 });
    symbols.push_back({ 5, "dx_cluster", "DX Cluster", '%', '/', false, "BF", -1 });
    symbols.push_back({ 6, "hf_gateway", "HF Gateway", '&', '/', false, "BG", -1 });
    symbols.push_back({ 7, "aircraft_small", "Small Aircraft", '\'', '/', false, "BH", 7 });
    symbols.push_back({ 8, "mobile_satellite_station", "Mobile Satellite Groundstation", '(', '/', false, "BI", -1 });
    symbols.push_back({ 9, "wheelchair", "Wheelchair, Handicapped", ')', '/', false, "BJ", -1 });
    symbols.push_back({ 10, "snowmobile", "Snowmobile", '*', '/', false, "BK", -1 });
    symbols.push_back({ 11, "red_cross", "Red Cross", '+', '/', false, "BL", -1 });
    symbols.push_back({ 12, "boy_scout", "Boy Scouts", ',', '/', false, "BM", -1 });
    symbols.push_back({ 13, "home", "House QTH (VHF)", '-', '/', false, "BN", -1 });
    symbols.push_back({ 14, "x", "X", '.', '/', false, "BO", -1 });
    symbols.push_back({ 15, "red_dot", "Dot", '/', '/', false, "BP", -1 });
    symbols.push_back({ 16, "circle_0", "Numbered circle: 0", '0', '/', false, "P0", -1 });
    symbols.push_back({ 17, "circle_1", "Numbered circle: 1", '1', '/', false, "P1", -1 });
    symbols.push_back({ 18, "circle_2", "Numbered circle: 2", '2', '/', false, "P2", -1 });
    symbols.push_back({ 19, "circle_3", "Numbered circle: 3", '3', '/', false, "P3", -1 });
    symbols.push_back({ 20, "circle_4", "Numbered circle: 4", '4', '/', false, "P4", -1 });
    symbols.push_back({ 21, "circle_5", "Numbered circle: 5", '5', '/', false, "P5", -1 });
    symbols.push_back({ 22, "circle_6", "Numbered circle: 6", '6', '/', false, "P6", -1 });
    symbols.push_back({ 23, "circle_7", "Numbered circle: 7", '7', '/', false, "P7", -1 });
    symbols.push_back({ 24, "circle_8", "Numbered circle: 8", '8', '/', false, "P8", -1 });
    symbols.push_back({ 25, "circle_9", "Numbered circle: 9", '9', '/', false, "P9", -1 });
    symbols.push_back({ 26, "fire", "Fire", ':', '/', false, "MR", -1 });
    symbols.push_back({ 27, "campground_tent", "Campground, Tent", ';', '/', false, "MS", -1 });
    symbols.push_back({ 28, "motorcycle", "Motorcycle", '<', '/', false, "MT", 10 });
    symbols.push_back({ 29, "railroad_engine", "Railroad Engine", '=', '/', false, "MU", -1 });
    symbols.push_back({ 30, "car", "Car", '>', '/', false, "MV", 9 });
    symbols.push_back({ 31, "file_server", "File Server", '?', '/', false, "MW", -1 });
    symbols.push_back({ 32, "hc_future", "Hurricane Future Prediction", '@', '/', false, "MX", -1 });
    symbols.push_back({ 33, "aid_station", "Aid Station", 'A', '/', false, "PA", -1 });
    symbols.push_back({ 34, "bbs", "BBS", 'B', '/', false, "PB", -1 });
    symbols.push_back({ 35, "canoe", "Canoe", 'C', '/', false, "PC", -1 });
    symbols.push_back({ 37, "eyeball", "Eyeball (eye catcher)", 'E', '/', false, "PE", -1 });
    symbols.push_back({ 38, "tractor", "Farm vehicle, Tractor", 'F', '/', false, "PF", -1 });
    symbols.push_back({ 39, "grid_square_3x3", "Grid square (6-character)", 'G', '/', false, "PG", -1 });
    symbols.push_back({ 40, "hotel", "Hotel", 'H', '/', false, "PH", -1 });
    symbols.push_back({ 41, "tcp_ip", "TCP/IP Network Station", 'I', '/', false, "PI", -1 });
    symbols.push_back({ 43, "school", "School", 'K', '/', false, "PK", -1 });
    symbols.push_back({ 44, "pc_user", "PC User", 'L', '/', false, "PL", -1 });
    symbols.push_back({ 45, "mac_aprs", "MacAPRS", 'M', '/', false, "PM", -1 });
    symbols.push_back({ 46, "nts_station", "NTS Station", 'N', '/', false, "PN", -1 });
    symbols.push_back({ 47, "balloon", "Balloon", 'O', '/', false, "PO", 11 });
    symbols.push_back({ 48, "police", "Police Car", 'P', '/', false, "PP", -1 });
    symbols.push_back({ 49, "tbd", "", 'Q', '/', false, "", -1 });
    symbols.push_back({ 50, "rv", "Recreational Vehicle", 'R', '/', false, "PR", 13 });
    symbols.push_back({ 51, "shuttle_space", "Space Shuttle", 'S', '/', false, "PS", -1 });
    symbols.push_back({ 52, "sstv", "SSTV", 'T', '/', false, "PT", -1 });
    symbols.push_back({ 53, "bus", "Bus", 'U', '/', false, "PU", -1 });
    symbols.push_back({ 54, "atv", "ATV, Amateur Television", 'V', '/', false, "PV", -1 });
    symbols.push_back({ 55, "national_wx", "National Weather Service Site", 'W', '/', false, "PW", -1 });
    symbols.push_back({ 56, "helicopter", "Helicopter", 'X', '/', false, "PX", 6 });
    symbols.push_back({ 57, "yacht_sail_boat", "Yacht (sail boat)", 'Y', '/', false, "PY", 5 });
    symbols.push_back({ 58, "win_aprs", "WinAPRS", 'Z', '/', false, "PZ", -1 });
    symbols.push_back({ 59, "jogger", "Jogger", '[', '/', false, "HS", -1 });
    symbols.push_back({ 60, "triangle", "Triangle (DF)", '\\', '/', false, "HT", -1 });
    symbols.push_back({ 61, "pbbs", "Mailbox, Post Office", ']', '/', false, "HU", -1 });
    symbols.push_back({ 62, "aircraft_large", "Large Aircraft", '^', '/', false, "HV", -1 });
    symbols.push_back({ 63, "wx", "Weather Station", '_', '/', false, "HW", -1 });
    symbols.push_back({ 64, "dish_antenna", "Satellite Dish Antenna", '`', '/', false, "HX", -1 });
    symbols.push_back({ 65, "ambulance", "Ambulance", 'a', '/', false, "LA", 1 });
    symbols.push_back({ 66, "bicycle", "Bicycle", 'b', '/', false, "LB", 4 });
    symbols.push_back({ 67, "icp", "Incident Command Post", 'c', '/', false, "LC", -1 });
    symbols.push_back({ 68, "fire_station", "Fire Station", 'd', '/', false, "LD", -1 });
    symbols.push_back({ 69, "horse", "Horse (equestrian)", 'e', '/', false, "LE", -1 });
    symbols.push_back({ 70, "fire_truck", "Fire Truck", 'f', '/', false, "LF", 3 });
    symbols.push_back({ 71, "glider", "Glider", 'g', '/', false, "LG", -1 });
    symbols.push_back({ 72, "hospital", "Hospital", 'h', '/', false, "LH", -1 });
    symbols.push_back({ 73, "iota", "Islands On The Air", 'i', '/', false, "LI", -1 });
    symbols.push_back({ 74, "jeep", "Jeep", 'j', '/', false, "LJ", 12 });
    symbols.push_back({ 75, "truck", "Truck", 'k', '/', false, "LK", 14 });
    symbols.push_back({ 76, "laptop", "Laptop", 'l', '/', false, "LL", -1 });
    symbols.push_back({ 77, "mic_e_repeater", "Mic-E Repeater", 'm', '/', false, "LM", -1 });
    symbols.push_back({ 78, "node", "Node, Black Bulls-eye", 'n', '/', false, "LN", -1 });
    symbols.push_back({ 79, "eoc", "Emergency Operations Center", 'o', '/', false, "LO", -1 });
    symbols.push_back({ 80, "rover_dog", "Dog", 'p', '/', false, "LP", -1 });
    symbols.push_back({ 81, "grid_square_2x2", "Grid square, 2 by 2", 'q', '/', false, "LQ", -1 });
    symbols.push_back({ 82, "antenna", "Repeater Tower", 'r', '/', false, "LR", -1 });
    symbols.push_back({ 83, "power_boat", "Ship (power boat)", 's', '/', false, "LS", 8 });
    symbols.push_back({ 84, "truck_stop", "Truck Stop", 't', '/', false, "LT", -1 });
    symbols.push_back({ 85, "truck_18_wheeler", "Semi-trailer Truck, 18-wheeler", 'u', '/', false, "LU", -1 });
    symbols.push_back({ 86, "van", "Van", 'v', '/', false, "LV", 15 });
    symbols.push_back({ 87, "water_station", "Water Station", 'w', '/', false, "LW", -1 });
    symbols.push_back({ 88, "x_aprs", "X / Unix APRS", 'x', '/', false, "LX", -1 });
    symbols.push_back({ 89, "yagi", "House, Yagi Antenna", 'y', '/', false, "LY", -1 });
    symbols.push_back({ 91, "shelter", "Shelter", 'z', '/', false, "LZ", -1 });
    symbols.push_back({ 92, "tnc_stream_sw1", "", '|', '/', false, "", -1 });
    symbols.push_back({ 94, "tnc_stream_sw2", "", '~', '/', false, "", -1 });
    symbols.push_back({ 1, "emergency", "Emergency", '!', '\\', true, "OB", -1 });
    symbols.push_back({ 3, "digi_green", "Digipeater (green star)", '#', '\\', true, "OD", -1 });
    symbols.push_back({ 4, "atm", "Bank or ATM", '$', '\\', true, "OE", -1 });
    symbols.push_back({ 6, "hf_gateway_diamond", "Gateway Station", '&', '\\', true, "OG", -1 });
    symbols.push_back({ 7, "crash_site", "Crash Site", '\'', '\\', true, "OH", -1 });
    symbols.push_back({ 8, "cloudy", "Cloudy", '(', '\\', true, "OI", -1 });
    symbols.push_back({ 9, "firenet_meo_modis", "Firenet MEO, MODIS Earth Observation", ')', '\\', true, "OJ", -1 });
    symbols.push_back({ 10, "snow", "Snow", '*', '\\', true, "OK", -1 });
    symbols.push_back({ 11, "church", "Church", '+', '\\', true, "OL", -1 });
    symbols.push_back({ 12, "girl_scouts", "Girl Scouts", ',', '\\', true, "OM", -1 });
    symbols.push_back({ 13, "house_hf", "House, HF Antenna", '-', '\\', true, "ON", -1 });
    symbols.push_back({ 14, "uknown_position", "Ambiguous, Question mark inside circle", '.', '\\', true, "OO", -1 });
    symbols.push_back({ 16, "circle", "Circle, IRLP / Echolink/WIRES", '0', '\\', true, "A0", -1 });
    symbols.push_back({ 24, "wifi", "802.11 WiFi or other network node", '8', '\\', true, "A8", -1 });
    symbols.push_back({ 25, "gas_station_blue", "Gas Station", '9', '\\', true, "A9", -1 });
    symbols.push_back({ 26, "hail", "Hail", ':', '\\', true, "NR", -1 });
    symbols.push_back({ 27, "park_picnic", "Park, Picnic area", ';', '\\', true, "NS", -1 });
    symbols.push_back({ 28, "nws_advisory_gale_flag", "Advisory, Single Red Flag", '<', '\\', true, "NT", -1 });
    symbols.push_back({ 30, "car2", "Red Car", '>', '\\', true, "NV", -1 });
    symbols.push_back({ 31, "info_kiosk_blue_box_q", "Info Kiosk", '?', '\\', true, "NW", -1 });
    symbols.push_back({ 32, "huricane", "Hurricane, Tropical storm", '@', '\\', true, "NX", -1 });
    symbols.push_back({ 33, "box", "White Box", 'A', '\\', true, "AA", -1 });
    symbols.push_back({ 34, "blowing_snow", "Blowing Snow", 'B', '\\', true, "AB", -1 });
    symbols.push_back({ 35, "coastguard", "Coast Guard", 'C', '\\', true, "AC", -1 });
    symbols.push_back({ 36, "drizzle", "Drizzling Rain", 'D', '\\', true, "AD", -1 });
    symbols.push_back({ 37, "smoke", "Smoke, Chimney", 'E', '\\', true, "AE", -1 });
    symbols.push_back({ 38, "feezing_rain", "Freezing Rain", 'F', '\\', true, "AF", -1 });
    symbols.push_back({ 39, "snow_shower", "Snow Shower", 'G', '\\', true, "AG", -1 });
    symbols.push_back({ 40, "haze", "Haze", 'H', '\\', true, "AH", -1 });
    symbols.push_back({ 41, "rain_shower", "Rain Shower", 'I', '\\', true, "AI", -1 });
    symbols.push_back({ 42, "lightning", "Lightning", 'J', '\\', true, "AJ", -1 });
    symbols.push_back({ 43, "kenwood", "Kenwood HT", 'K', '\\', true, "AK", -1 });
    symbols.push_back({ 44, "ligthouse", "Lighthouse", 'L', '\\', true, "AL", -1 });
    symbols.push_back({ 46, "nav_buoy", "Navigation Buoy", 'N', '\\', true, "AN", -1 });
    symbols.push_back({ 47, "rocket", "Rocket", 'O', '\\', true, "AO", -1 });
    symbols.push_back({ 48, "parking", "Parking", 'P', '\\', true, "AP", -1 });
    symbols.push_back({ 49, "earthquake", "Earthquake", 'Q', '\\', true, "AQ", -1 });
    symbols.push_back({ 50, "restaurant", "Restaurant", 'R', '\\', true, "AR", -1 });
    symbols.push_back({ 51, "satellite_pac_sat", "Satellite", 'S', '\\', true, "AS", -1 });
    symbols.push_back({ 52, "thunderstorm", "Thunderstorm", 'T', '\\', true, "AT", -1 });
    symbols.push_back({ 53, "sunny", "Sunny", 'U', '\\', true, "AU", -1 });
    symbols.push_back({ 54, "vortac_nav_aid", "VORTAC, Navigational Aid", 'V', '\\', true, "AV", -1 });
    symbols.push_back({ 55, "nws_site", "NWS site", 'W', '\\', true, "AW", -1 });
    symbols.push_back({ 56, "pharmacy_rx", "Pharmacy", 'X', '\\', true, "AX", -1 });
    symbols.push_back({ 59, "wall_cloud", "Wall Cloud", '[', '\\', true, "DS", -1 });
    symbols.push_back({ 62, "aircraft", "Aircraft", '^', '\\', true, "DV", -1 });
    symbols.push_back({ 63, "wx_station_with_digi_green", "Weather Site", '_', '\\', true, "DW", -1 });
    symbols.push_back({ 64, "rain", "Rain", '`', '\\', true, "DX", -1 });
    symbols.push_back({ 65, "arrl", "AARL", 'a', 'A', false, "SAA", -1 });
    symbols.push_back({ 65, "red_diamond", "Red Diamond", 'a', '\\', true, "SA", -1 });
    symbols.push_back({ 65, "races", "RACES", 'a', 'R', false, "SAR", -1 });
    symbols.push_back({ 66, "blowing_dust", "Blowing Dust, Sand", 'b', '\\', true, "SB", -1 });
    symbols.push_back({ 67, "civil_defence_races", "CD Triangle, RACES, CERTS, SATERN", 'c', '\\', true, "SC", -1 });
    symbols.push_back({ 68, "dx_spot", "DX Spot", 'd', '\\', true, "SD", -1 });
    symbols.push_back({ 69, "sleet", "Sleet", 'e', '\\', true, "SE", -1 });
    symbols.push_back({ 70, "funnel_cloud", "Funnel Cloud", 'f', '\\', true, "SF", -1 });
    symbols.push_back({ 71, "gale_flags", "Gale (two red flags)", 'g', '\\', true, "SG", -1 });
    symbols.push_back({ 72, "ham_store", "Store", 'h', '\\', true, "SH", -1 });
    symbols.push_back({ 73, "indoor_short_range_digi", "Black Box, Point Of Interest", 'i', '\\', true, "SI", -1 });
    symbols.push_back({ 74, "work_zone", "Work Zone, Excavating Machine", 'j', '\\', true, "SJ", -1 });
    symbols.push_back({ 75, "suv_atv", "SUV, ATV", 'k', '\\', true, "SK", -1 });
    symbols.push_back({ 76, "area_symbols", "", 'l', '\\', true, "", -1 });
    symbols.push_back({ 77, "value_signpost", "", 'm', '\\', true, "", -1 });
    symbols.push_back({ 78, "triangle_df", "Red Triangle", 'n', '\\', true, "SN", -1 });
    symbols.push_back({ 79, "small_circle", "Small Circle", 'o', '\\', true, "SO", -1 });
    symbols.push_back({ 80, "partly_cloudy", "Partly Cloudy", 'p', '\\', true, "SP", -1 });
    symbols.push_back({ 82, "restrooms", "Restrooms", 'r', '\\', true, "SR", -1 });
    symbols.push_back({ 83, "ship_boat_top_view", "Ship, Boat", 's', '\\', true, "SS", -1 });
    symbols.push_back({ 84, "tornado", "Tornado", 't', '\\', true, "ST", -1 });
    symbols.push_back({ 85, "truck2", "Truck", 'u', '\\', true, "SU", -1 });
    symbols.push_back({ 86, "van2", "Van", 'v', '\\', true, "SV", -1 });
    symbols.push_back({ 87, "flooding", "Flooding", 'w', '\\', true, "SW", -1 });
    symbols.push_back({ 88, "skywarn", "Skywarn", 'y', '\\', true, "SY", -1 });
    symbols.push_back({ 89, "shelter2", "Shelter", 'z', '\\', true, "SZ", -1 });
    symbols.push_back({ 90, "fog", "Fog", '{', '\\', true, "Q1", -1 });
#endif

    destination_address_map["BB"] = 0;
    destination_address_map["BD"] = 1;
    destination_address_map["BE"] = 2;
    destination_address_map["BF"] = 3;
    destination_address_map["BG"] = 4;
    destination_address_map["BH"] = 5;
    destination_address_map["BI"] = 6;
    destination_address_map["BJ"] = 7;
    destination_address_map["BK"] = 8;
    destination_address_map["BL"] = 9;
    destination_address_map["BM"] = 10;
    destination_address_map["BN"] = 11;
    destination_address_map["BO"] = 12;
    destination_address_map["BP"] = 13;
    destination_address_map["P0"] = 14;
    destination_address_map["P1"] = 15;
    destination_address_map["P2"] = 16;
    destination_address_map["P3"] = 17;
    destination_address_map["P4"] = 18;
    destination_address_map["P5"] = 19;
    destination_address_map["P6"] = 20;
    destination_address_map["P7"] = 21;
    destination_address_map["P8"] = 22;
    destination_address_map["P9"] = 23;
    destination_address_map["MR"] = 24;
    destination_address_map["MS"] = 25;
    destination_address_map["MT"] = 26;
    destination_address_map["MU"] = 27;
    destination_address_map["MV"] = 28;
    destination_address_map["MW"] = 29;
    destination_address_map["MX"] = 30;
    destination_address_map["PA"] = 31;
    destination_address_map["PB"] = 32;
    destination_address_map["PC"] = 33;
    destination_address_map["PE"] = 34;
    destination_address_map["PF"] = 35;
    destination_address_map["PG"] = 36;
    destination_address_map["PH"] = 37;
    destination_address_map["PI"] = 38;
    destination_address_map["PK"] = 39;
    destination_address_map["PL"] = 40;
    destination_address_map["PM"] = 41;
    destination_address_map["PN"] = 42;
    destination_address_map["PO"] = 43;
    destination_address_map["PP"] = 44;
    destination_address_map["PR"] = 46;
    destination_address_map["PS"] = 47;
    destination_address_map["PT"] = 48;
    destination_address_map["PU"] = 49;
    destination_address_map["PV"] = 50;
    destination_address_map["PW"] = 51;
    destination_address_map["PX"] = 52;
    destination_address_map["PY"] = 53;
    destination_address_map["PZ"] = 54;
    destination_address_map["HS"] = 55;
    destination_address_map["HT"] = 56;
    destination_address_map["HU"] = 57;
    destination_address_map["HV"] = 58;
    destination_address_map["HW"] = 59;
    destination_address_map["HX"] = 60;
    destination_address_map["LA"] = 61;
    destination_address_map["LB"] = 62;
    destination_address_map["LC"] = 63;
    destination_address_map["LD"] = 64;
    destination_address_map["LE"] = 65;
    destination_address_map["LF"] = 66;
    destination_address_map["LG"] = 67;
    destination_address_map["LH"] = 68;
    destination_address_map["LI"] = 69;
    destination_address_map["LJ"] = 70;
    destination_address_map["LK"] = 71;
    destination_address_map["LL"] = 72;
    destination_address_map["LM"] = 73;
    destination_address_map["LN"] = 74;
    destination_address_map["LO"] = 75;
    destination_address_map["LP"] = 76;
    destination_address_map["LQ"] = 77;
    destination_address_map["LR"] = 78;
    destination_address_map["LS"] = 79;
    destination_address_map["LT"] = 80;
    destination_address_map["LU"] = 81;
    destination_address_map["LV"] = 82;
    destination_address_map["LW"] = 83;
    destination_address_map["LX"] = 84;
    destination_address_map["LY"] = 85;
    destination_address_map["LZ"] = 86;
    destination_address_map["OB"] = 89;
    destination_address_map["OD"] = 90;
    destination_address_map["OE"] = 91;
    destination_address_map["OG"] = 92;
    destination_address_map["OH"] = 93;
    destination_address_map["OI"] = 94;
    destination_address_map["OJ"] = 95;
    destination_address_map["OK"] = 96;
    destination_address_map["OL"] = 97;
    destination_address_map["OM"] = 98;
    destination_address_map["ON"] = 99;
    destination_address_map["OO"] = 100;
    destination_address_map["A0"] = 101;
    destination_address_map["A8"] = 102;
    destination_address_map["A9"] = 103;
    destination_address_map["NR"] = 104;
    destination_address_map["NS"] = 105;
    destination_address_map["NT"] = 106;
    destination_address_map["NV"] = 107;
    destination_address_map["NW"] = 108;
    destination_address_map["NX"] = 109;
    destination_address_map["AA"] = 110;
    destination_address_map["AB"] = 111;
    destination_address_map["AC"] = 112;
    destination_address_map["AD"] = 113;
    destination_address_map["AE"] = 114;
    destination_address_map["AF"] = 115;
    destination_address_map["AG"] = 116;
    destination_address_map["AH"] = 117;
    destination_address_map["AI"] = 118;
    destination_address_map["AJ"] = 119;
    destination_address_map["AK"] = 120;
    destination_address_map["AL"] = 121;
    destination_address_map["AN"] = 122;
    destination_address_map["AO"] = 123;
    destination_address_map["AP"] = 124;
    destination_address_map["AQ"] = 125;
    destination_address_map["AR"] = 126;
    destination_address_map["AS"] = 127;
    destination_address_map["AT"] = 128;
    destination_address_map["AU"] = 129;
    destination_address_map["AV"] = 130;
    destination_address_map["AW"] = 131;
    destination_address_map["AX"] = 132;
    destination_address_map["DS"] = 133;
    destination_address_map["DV"] = 134;
    destination_address_map["DW"] = 135;
    destination_address_map["DX"] = 136;
    destination_address_map["SAA"] = 137;
    destination_address_map["SA"] = 138;
    destination_address_map["SAR"] = 139;
    destination_address_map["SB"] = 140;
    destination_address_map["SC"] = 141;
    destination_address_map["SD"] = 142;
    destination_address_map["SE"] = 143;
    destination_address_map["SF"] = 144;
    destination_address_map["SG"] = 145;
    destination_address_map["SH"] = 146;
    destination_address_map["SI"] = 147;
    destination_address_map["SJ"] = 148;
    destination_address_map["SK"] = 149;
    destination_address_map["SN"] = 152;
    destination_address_map["SO"] = 153;
    destination_address_map["SP"] = 154;
    destination_address_map["SR"] = 155;
    destination_address_map["SS"] = 156;
    destination_address_map["ST"] = 157;
    destination_address_map["SU"] = 158;
    destination_address_map["SV"] = 159;
    destination_address_map["SW"] = 160;
    destination_address_map["SY"] = 161;
    destination_address_map["SZ"] = 162;
    destination_address_map["Q1"] = 163;

    symbol_code_map['!'] = 0;
    symbol_code_map['#'] = 1;
    symbol_code_map['$'] = 2;
    symbol_code_map['%'] = 3;
    symbol_code_map['&'] = 4;
    symbol_code_map['\''] = 5;
    symbol_code_map['('] = 6;
    symbol_code_map[')'] = 7;
    symbol_code_map['*'] = 8;
    symbol_code_map['+'] = 9;
    symbol_code_map[','] = 10;
    symbol_code_map['-'] = 11;
    symbol_code_map['.'] = 12;
    symbol_code_map['/'] = 13;
    symbol_code_map['0'] = 14;
    symbol_code_map['1'] = 15;
    symbol_code_map['2'] = 16;
    symbol_code_map['3'] = 17;
    symbol_code_map['4'] = 18;
    symbol_code_map['5'] = 19;
    symbol_code_map['6'] = 20;
    symbol_code_map['7'] = 21;
    symbol_code_map['8'] = 22;
    symbol_code_map['9'] = 23;
    symbol_code_map[':'] = 24;
    symbol_code_map[';'] = 25;
    symbol_code_map['<'] = 26;
    symbol_code_map['='] = 27;
    symbol_code_map['>'] = 28;
    symbol_code_map['?'] = 29;
    symbol_code_map['@'] = 30;
    symbol_code_map['A'] = 31;
    symbol_code_map['B'] = 32;
    symbol_code_map['C'] = 33;
    symbol_code_map['E'] = 34;
    symbol_code_map['F'] = 35;
    symbol_code_map['G'] = 36;
    symbol_code_map['H'] = 37;
    symbol_code_map['I'] = 38;
    symbol_code_map['K'] = 39;
    symbol_code_map['L'] = 40;
    symbol_code_map['M'] = 41;
    symbol_code_map['N'] = 42;
    symbol_code_map['O'] = 43;
    symbol_code_map['P'] = 44;
    symbol_code_map['Q'] = 45;
    symbol_code_map['R'] = 46;
    symbol_code_map['S'] = 47;
    symbol_code_map['T'] = 48;
    symbol_code_map['U'] = 49;
    symbol_code_map['V'] = 50;
    symbol_code_map['W'] = 51;
    symbol_code_map['X'] = 52;
    symbol_code_map['Y'] = 53;
    symbol_code_map['Z'] = 54;
    symbol_code_map['['] = 55;
    symbol_code_map['\\'] = 56;
    symbol_code_map[']'] = 57;
    symbol_code_map['^'] = 58;
    symbol_code_map['_'] = 59;
    symbol_code_map['`'] = 60;
    symbol_code_map['a'] = 61;
    symbol_code_map['b'] = 62;
    symbol_code_map['c'] = 63;
    symbol_code_map['d'] = 64;
    symbol_code_map['e'] = 65;
    symbol_code_map['f'] = 66;
    symbol_code_map['g'] = 67;
    symbol_code_map['h'] = 68;
    symbol_code_map['i'] = 69;
    symbol_code_map['j'] = 70;
    symbol_code_map['k'] = 71;
    symbol_code_map['l'] = 72;
    symbol_code_map['m'] = 73;
    symbol_code_map['n'] = 74;
    symbol_code_map['o'] = 75;
    symbol_code_map['p'] = 76;
    symbol_code_map['q'] = 77;
    symbol_code_map['r'] = 78;
    symbol_code_map['s'] = 79;
    symbol_code_map['t'] = 80;
    symbol_code_map['u'] = 81;
    symbol_code_map['v'] = 82;
    symbol_code_map['w'] = 83;
    symbol_code_map['x'] = 84;
    symbol_code_map['y'] = 85;
    symbol_code_map['z'] = 86;
    symbol_code_map['|'] = 87;
    symbol_code_map['~'] = 88;
    symbol_code_map['!' + 200] = 89;
    symbol_code_map['#' + 200] = 90;
    symbol_code_map['$' + 200] = 91;
    symbol_code_map['&' + 200] = 92;
    symbol_code_map['\'' + 200] = 93;
    symbol_code_map['(' + 200] = 94;
    symbol_code_map[')' + 200] = 95;
    symbol_code_map['*' + 200] = 96;
    symbol_code_map['+' + 200] = 97;
    symbol_code_map[',' + 200] = 98;
    symbol_code_map['-' + 200] = 99;
    symbol_code_map['.' + 200] = 100;
    symbol_code_map['0' + 200] = 101;
    symbol_code_map['8' + 200] = 102;
    symbol_code_map['9' + 200] = 103;
    symbol_code_map[':' + 200] = 104;
    symbol_code_map[';' + 200] = 105;
    symbol_code_map['<' + 200] = 106;
    symbol_code_map['>' + 200] = 107;
    symbol_code_map['?' + 200] = 108;
    symbol_code_map['@' + 200] = 109;
    symbol_code_map['A' + 200] = 110;
    symbol_code_map['B' + 200] = 111;
    symbol_code_map['C' + 200] = 112;
    symbol_code_map['D' + 200] = 113;
    symbol_code_map['E' + 200] = 114;
    symbol_code_map['F' + 200] = 115;
    symbol_code_map['G' + 200] = 116;
    symbol_code_map['H' + 200] = 117;
    symbol_code_map['I' + 200] = 118;
    symbol_code_map['J' + 200] = 119;
    symbol_code_map['K' + 200] = 120;
    symbol_code_map['L' + 200] = 121;
    symbol_code_map['N' + 200] = 122;
    symbol_code_map['O' + 200] = 123;
    symbol_code_map['P' + 200] = 124;
    symbol_code_map['Q' + 200] = 125;
    symbol_code_map['R' + 200] = 126;
    symbol_code_map['S' + 200] = 127;
    symbol_code_map['T' + 200] = 128;
    symbol_code_map['U' + 200] = 129;
    symbol_code_map['V' + 200] = 130;
    symbol_code_map['W' + 200] = 131;
    symbol_code_map['X' + 200] = 132;
    symbol_code_map['[' + 200] = 133;
    symbol_code_map['^' + 200] = 134;
    symbol_code_map['_' + 200] = 135;
    symbol_code_map['`' + 200] = 136;
    symbol_code_map['a' + 400] = 137;
    symbol_code_map['a' + 200] = 138;
    symbol_code_map['a' + 500] = 139;
    symbol_code_map['b' + 200] = 140;
    symbol_code_map['c' + 200] = 141;
    symbol_code_map['d' + 200] = 142;
    symbol_code_map['e' + 200] = 143;
    symbol_code_map['f' + 200] = 144;
    symbol_code_map['g' + 200] = 145;
    symbol_code_map['h' + 200] = 146;
    symbol_code_map['i' + 200] = 147;
    symbol_code_map['j' + 200] = 148;
    symbol_code_map['k' + 200] = 149;
    symbol_code_map['l' + 200] = 150;
    symbol_code_map['m' + 200] = 151;
    symbol_code_map['n' + 200] = 152;
    symbol_code_map['o' + 200] = 153;
    symbol_code_map['p' + 200] = 154;
    symbol_code_map['r' + 200] = 155;
    symbol_code_map['s' + 200] = 156;
    symbol_code_map['t' + 200] = 157;
    symbol_code_map['u' + 200] = 158;
    symbol_code_map['v' + 200] = 159;
    symbol_code_map['w' + 200] = 160;
    symbol_code_map['y' + 200] = 161;
    symbol_code_map['z' + 200] = 162;
    symbol_code_map['{' + 200] = 163;

    symbol_name_map["police_station"] = 0;
    symbol_name_map["digi"] = 1;
    symbol_name_map["phone"] = 2;
    symbol_name_map["dx_cluster"] = 3;
    symbol_name_map["hf_gateway"] = 4;
    symbol_name_map["aircraft_small"] = 5;
    symbol_name_map["mobile_satellite_station"] = 6;
    symbol_name_map["wheelchair"] = 7;
    symbol_name_map["snowmobile"] = 8;
    symbol_name_map["red_cross"] = 9;
    symbol_name_map["boy_scout"] = 10;
    symbol_name_map["home"] = 11;
    symbol_name_map["x"] = 12;
    symbol_name_map["red_dot"] = 13;
    symbol_name_map["circle_0"] = 14;
    symbol_name_map["circle_1"] = 15;
    symbol_name_map["circle_2"] = 16;
    symbol_name_map["circle_3"] = 17;
    symbol_name_map["circle_4"] = 18;
    symbol_name_map["circle_5"] = 19;
    symbol_name_map["circle_6"] = 20;
    symbol_name_map["circle_7"] = 21;
    symbol_name_map["circle_8"] = 22;
    symbol_name_map["circle_9"] = 23;
    symbol_name_map["fire"] = 24;
    symbol_name_map["campground_tent"] = 25;
    symbol_name_map["motorcycle"] = 26;
    symbol_name_map["railroad_engine"] = 27;
    symbol_name_map["car"] = 28;
    symbol_name_map["file_server"] = 29;
    symbol_name_map["hc_future"] = 30;
    symbol_name_map["aid_station"] = 31;
    symbol_name_map["bbs"] = 32;
    symbol_name_map["canoe"] = 33;
    symbol_name_map["eyeball"] = 34;
    symbol_name_map["tractor"] = 35;
    symbol_name_map["grid_square_3x3"] = 36;
    symbol_name_map["hotel"] = 37;
    symbol_name_map["tcp_ip"] = 38;
    symbol_name_map["school"] = 39;
    symbol_name_map["pc_user"] = 40;
    symbol_name_map["mac_aprs"] = 41;
    symbol_name_map["nts_station"] = 42;
    symbol_name_map["balloon"] = 43;
    symbol_name_map["police"] = 44;
    symbol_name_map["tbd"] = 45;
    symbol_name_map["rv"] = 46;
    symbol_name_map["shuttle_space"] = 47;
    symbol_name_map["sstv"] = 48;
    symbol_name_map["bus"] = 49;
    symbol_name_map["atv"] = 50;
    symbol_name_map["national_wx"] = 51;
    symbol_name_map["helicopter"] = 52;
    symbol_name_map["yacht_sail_boat"] = 53;
    symbol_name_map["win_aprs"] = 54;
    symbol_name_map["jogger"] = 55;
    symbol_name_map["triangle"] = 56;
    symbol_name_map["pbbs"] = 57;
    symbol_name_map["aircraft_large"] = 58;
    symbol_name_map["wx"] = 59;
    symbol_name_map["dish_antenna"] = 60;
    symbol_name_map["ambulance"] = 61;
    symbol_name_map["bicycle"] = 62;
    symbol_name_map["icp"] = 63;
    symbol_name_map["fire_station"] = 64;
    symbol_name_map["horse"] = 65;
    symbol_name_map["fire_truck"] = 66;
    symbol_name_map["glider"] = 67;
    symbol_name_map["hospital"] = 68;
    symbol_name_map["iota"] = 69;
    symbol_name_map["jeep"] = 70;
    symbol_name_map["truck"] = 71;
    symbol_name_map["laptop"] = 72;
    symbol_name_map["mic_e_repeater"] = 73;
    symbol_name_map["node"] = 74;
    symbol_name_map["eoc"] = 75;
    symbol_name_map["rover_dog"] = 76;
    symbol_name_map["grid_square_2x2"] = 77;
    symbol_name_map["antenna"] = 78;
    symbol_name_map["power_boat"] = 79;
    symbol_name_map["truck_stop"] = 80;
    symbol_name_map["truck_18_wheeler"] = 81;
    symbol_name_map["van"] = 82;
    symbol_name_map["water_station"] = 83;
    symbol_name_map["x_aprs"] = 84;
    symbol_name_map["yagi"] = 85;
    symbol_name_map["shelter"] = 86;
    symbol_name_map["tnc_stream_sw1"] = 87;
    symbol_name_map["tnc_stream_sw2"] = 88;
    symbol_name_map["emergency"] = 89;
    symbol_name_map["digi_green"] = 90;
    symbol_name_map["atm"] = 91;
    symbol_name_map["hf_gateway_diamond"] = 92;
    symbol_name_map["crash_site"] = 93;
    symbol_name_map["cloudy"] = 94;
    symbol_name_map["firenet_meo_modis"] = 95;
    symbol_name_map["snow"] = 96;
    symbol_name_map["church"] = 97;
    symbol_name_map["girl_scouts"] = 98;
    symbol_name_map["house_hf"] = 99;
    symbol_name_map["uknown_position"] = 100;
    symbol_name_map["circle"] = 101;
    symbol_name_map["wifi"] = 102;
    symbol_name_map["gas_station_blue"] = 103;
    symbol_name_map["hail"] = 104;
    symbol_name_map["park_picnic"] = 105;
    symbol_name_map["nws_advisory_gale_flag"] = 106;
    symbol_name_map["car2"] = 107;
    symbol_name_map["info_kiosk_blue_box_q"] = 108;
    symbol_name_map["huricane"] = 109;
    symbol_name_map["box"] = 110;
    symbol_name_map["blowing_snow"] = 111;
    symbol_name_map["coastguard"] = 112;
    symbol_name_map["drizzle"] = 113;
    symbol_name_map["smoke"] = 114;
    symbol_name_map["feezing_rain"] = 115;
    symbol_name_map["snow_shower"] = 116;
    symbol_name_map["haze"] = 117;
    symbol_name_map["rain_shower"] = 118;
    symbol_name_map["lightning"] = 119;
    symbol_name_map["kenwood"] = 120;
    symbol_name_map["ligthouse"] = 121;
    symbol_name_map["nav_buoy"] = 122;
    symbol_name_map["rocket"] = 123;
    symbol_name_map["parking"] = 124;
    symbol_name_map["earthquake"] = 125;
    symbol_name_map["restaurant"] = 126;
    symbol_name_map["satellite_pac_sat"] = 127;
    symbol_name_map["thunderstorm"] = 128;
    symbol_name_map["sunny"] = 129;
    symbol_name_map["vortac_nav_aid"] = 130;
    symbol_name_map["nws_site"] = 131;
    symbol_name_map["pharmacy_rx"] = 132;
    symbol_name_map["wall_cloud"] = 133;
    symbol_name_map["aircraft"] = 134;
    symbol_name_map["wx_station_with_digi_green"] = 135;
    symbol_name_map["rain"] = 136;
    symbol_name_map["arrl"] = 137;
    symbol_name_map["red_diamond"] = 138;
    symbol_name_map["races"] = 139;
    symbol_name_map["blowing_dust"] = 140;
    symbol_name_map["civil_defence_races"] = 141;
    symbol_name_map["dx_spot"] = 142;
    symbol_name_map["sleet"] = 143;
    symbol_name_map["funnel_cloud"] = 144;
    symbol_name_map["gale_flags"] = 145;
    symbol_name_map["ham_store"] = 146;
    symbol_name_map["indoor_short_range_digi"] = 147;
    symbol_name_map["work_zone"] = 148;
    symbol_name_map["suv_atv"] = 149;
    symbol_name_map["area_symbols"] = 150;
    symbol_name_map["value_signpost"] = 151;
    symbol_name_map["triangle_df"] = 152;
    symbol_name_map["small_circle"] = 153;
    symbol_name_map["partly_cloudy"] = 154;
    symbol_name_map["restrooms"] = 155;
    symbol_name_map["ship_boat_top_view"] = 156;
    symbol_name_map["tornado"] = 157;
    symbol_name_map["truck2"] = 158;
    symbol_name_map["van2"] = 159;
    symbol_name_map["flooding"] = 160;
    symbol_name_map["skywarn"] = 161;
    symbol_name_map["shelter2"] = 162;
    symbol_name_map["fog"] = 163;
}

APRS_LIB_APRS_DETAIL_NAMESPACE_END

// **************************************************************** //
//                                                                  //
//                                                                  //
// CORE QUERIES                                                     //
//                                                                  //
//                                                                  //
// **************************************************************** //

APRS_LIB_APRS_DETAIL_NAMESPACE_BEGIN

APRS_LIB_INLINE bool try_get_position_with_timestamp_is_compressed(std::string_view data, bool& compressed)
{
    compressed = (data[8] == '/' || data[8] == '\\' || !std::isdigit(data[8]));
    return true;
}

APRS_LIB_INLINE bool try_get_position_without_timestamp_is_compressed(std::string_view data, bool& compressed)
{
    compressed = (data[1] == '/' || data[1] == '\\' || !std::isdigit(data[1]));
    return true;
}

APRS_LIB_INLINE bool try_get_object_is_compressed(std::string_view data, bool& compressed)
{
    compressed = (data[18] == '/' || data[18] == '\\' || !std::isdigit(data[18]));
    return true;
}

APRS_LIB_INLINE bool try_get_item_is_compressed(std::string_view data, bool& compressed)
{
    return false;
}

APRS_LIB_INLINE bool try_get_mic_e_is_kenwood_tmd700(std::string_view data, bool& result)
{
    // Note: The Kenwood TM-D700 radio uses the ' (apostrophe) instead of the ‘
    // (grave) APRS Data Type Identifier to represent current GPS data. A
    // suggested way of detecting this situation is to examine the first and 10th
    // characters of the Information field; if they are ' and ] respectively, then the
    // packet is almost certainly from a TM-D700.

    return true;
}

// **************************************************************** //
// SYMBOLS                                                          //
// **************************************************************** //

APRS_LIB_INLINE bool is_supported_pri_table_symbol(char symbol_code)
{
    switch (symbol_code)
    {
        case '\"':
        case ')':
        case 'D':
        case 'F':
        case 'J':
        case 'L':
        case 'Q':
        case 'c':
        case 'l':   
        case 'z':
        case '{':
        case '|':
        case '}':
        case '~':
            // unsupported or reserved
            return false;
            break;
    }
    return true;
}

APRS_LIB_INLINE bool is_supported_alt_table_symbol(char symbol_code)
{
    switch (symbol_code)
    {
        case '\"':
        case '%':
        case ')':
        case '/':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '=':
        case 'M':
        case 'O':
        case 'Y':
        case 'Z':
        case '\\':
        case ']':
        case 'K':
        case 'q':
        case 'x':
        case 'y':
        case 'z':
        case '|':
        case '~':
            // unsupported or reserved
            return false;
            break;
    }
    return true;
}

APRS_LIB_INLINE bool is_overlayable_symbol(char symbol_code)
{
    // a is overlayable only with A and R
    // m is special handled

    switch (symbol_code)
    {
        case '#':
        case '&':
        case '0':
        case '>':
        case 'A':
        case 'W':
        case '^':
        case '_':
        case 'a':
        case 'c':
        case 'i':
        case 'n':
        case 's':
        case 'u':
        case 'v':
            return true;
            break;
    }
    return false;
}

APRS_LIB_INLINE bool is_symbol_overlayable_with_uncompressed_overlay(char symbol_table)
{
    return (symbol_table >= '0' && symbol_table <= '9') ||
        (symbol_table >= 'A' && symbol_table <= 'Z');
}

APRS_LIB_INLINE bool is_symbol_overlayable_with_compressed_overlay(char symbol_table)
{
    return (symbol_table >= 'a' && symbol_table <= 'j') ||
        (symbol_table >= 'A' && symbol_table <= 'Z');
}

APRS_LIB_APRS_DETAIL_NAMESPACE_END

APRS_LIB_NAMESPACE_END

APRS_LIB_KISS_NAMESPACE_BEGIN

// **************************************************************** //
//                                                                  //
//                                                                  //
// KISS                                                             //
//                                                                  //
//                                                                  //
// **************************************************************** //

// **************************************************************** //
//                                                                  //
// FORWARD DECLARATIONS                                             //
//                                                                  //
// **************************************************************** //

struct kiss_frame_decoder
{
    const std::vector<std::string>& data();
    int count();
    bool decode(std::string_view);
    void clear();

private:
    std::vector<std::string> data_;
    std::deque<char> buffer;
    std::string current_data;
    bool in_kiss_frame = false;
    bool in_escape_mode = false;
    bool skip_command_byte = true;
};

APRS_LIB_APRS_DETAIL_NAMESPACE_BEGIN

enum class kiss_frame_marker : uint8_t
{
    fend = 0xC0,
    fesc = 0xDB,
    tfend = 0xDC,
    tfesc = 0xDD
};

enum class kiss_command : uint8_t
{
    data_frame = 0,
    tx_delay = 1,
    p = 2,
    slot_time = 3,
    tx_tail = 4,
    full_duplex = 5,
    set_hw = 6,
    ret = 0xff
};

// **************************************************************** //
//                                                                  //
// TYPE IMPLEMENTATION                                              //
//                                                                  //
// **************************************************************** //

#ifndef APRS_LIB_PUBLIC_FORWARD_DECLARATIONS_ONLY

APRS_LIB_INLINE bool operator==(uint8_t left, kiss_frame_marker right)
{
    return left == (uint8_t)right;
}

#endif

APRS_LIB_APRS_DETAIL_NAMESPACE_END

#ifndef APRS_LIB_PUBLIC_FORWARD_DECLARATIONS_ONLY

APRS_LIB_INLINE const std::vector<std::string>& kiss_frame_decoder::data()
{
    return data_;
}

APRS_LIB_INLINE int kiss_frame_decoder::count()
{
    return (int)data_.size();
}

APRS_LIB_INLINE void kiss_frame_decoder::clear()
{
    data_.clear();
    buffer.clear();
    current_data.clear();
    in_kiss_frame = false;
    in_escape_mode = false;
    skip_command_byte = true;
}

APRS_LIB_INLINE bool kiss_frame_decoder::decode(std::string_view chunk)
{
    // 
    // KISS frame structure:
    //
	// --------------------------------------------------------------------
	// Frame End (FEND)   1 byte (0xc0)  <------------ frame begin  <------------ frame 1
	// data                                                               |
	// Frame End (FEND)   1 byte (0xc0)  <------------ frame end    <-----
    // Frame End (FEND)   1 byte (0xc0)  <------------ frame begin  <------------ frame 2
    // data                                                               |
    // Frame End (FEND)   1 byte (0xc0)  <------------ frame end    <-----
	// --------------------------------------------------------------------
    //
    //
    //
    // KISS frame escaping
    //
    // So say you want to store a 0xc0 byte somewhere in your data,
    // but that byte is also a magic byte and used to mark frames,
    // what do you do? We use 0xDC (TFEND), which has special meaning to 
    // insert 0xc0 in the stream when encountered, but only when
    // prefixed by 0xDB (FESC), so that in normal circumstances we
    // can also have 0xDB bytes in the data stream.
    // 
    // --------------------------------------------------------------------
    // Frame End (FEND)   1 byte (0xc0)  <------------ frame begin
	// data
    // ...
    // 0xDB   <--------------------------------------- frame escape, escapes the next 1 byte, giving it special meaning   ------- |  0xc0
    // 0xDC   <--------------------------------------- insert the 0xc0 byte in the data stream  --------------------------------- |
    // ...
    // data
    // ...
    // 0xDC   <--------------------------------------- just a normal 0xDC byte
    // ....
	// Frame End (FEND)   1 byte (0xc0)  <------------ frame end
    // --------------------------------------------------------------------
    //
    //
    // But now what if we want a 0xDB byte in the data stream?
    // Then we have an escape for 0xDB by prefixing 0xDD with 0xDB
    //
    //
    // data
    // ...
    // 0xDB   <--------------------------------------- frame escape, escapes the next 1 byte, giving it special meaning ------- |  0xDB
    // 0xDD   <--------------------------------------- insert the 0xDB byte in the data stream ---------------------------------|
    // ...
    // 0xDD   <--------------------------------------- just a normal 0xDD byte
    // ...
    // data
    //
    //
    // KISS frame stream:
    // 
    //     FEND bytes FESC TFEND bytes FESC TFESC bytes FEND
    //

    buffer.insert(buffer.end(), chunk.begin(), chunk.end());

    size_t current_data_count = data_.size();
    
    while (!buffer.empty())
    {
        uint8_t b = buffer.front();

        buffer.pop_front();

        if (in_kiss_frame)
        {
            if (in_escape_mode)
            {
                if (b == APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE kiss_frame_marker::tfend)
                {
                    current_data.push_back((char)APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE kiss_frame_marker::fend);
                }
                if (b == APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE kiss_frame_marker::tfesc)
                {
                    current_data.push_back((char)APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE kiss_frame_marker::fesc);
                }
                in_escape_mode = false;
                continue;
            }
            
            if (b == APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE kiss_frame_marker::fend)
            {
                data_.push_back(current_data);
                current_data.clear();
                in_kiss_frame = false;
                skip_command_byte = true;
            }
            else if (b == APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE kiss_frame_marker::fesc)
            {
                in_escape_mode = true;
            }
            else
            {
                // Skip command byte
                if (skip_command_byte)
                {
                    skip_command_byte = false;
                    continue;
                }
                current_data.push_back((char)b);
            }     
        }
        else
        {
            if (b == APRS_LIB_APRS_DETAIL_NAMESPACE_REFERENCE kiss_frame_marker::fend)
            {
                in_kiss_frame = true;
            }
        }
    }

    // True if new packets were decoded and we do not have incomplete data
    return (current_data_count < data_.size()) && buffer.empty() && !in_kiss_frame;
}

#endif

APRS_LIB_KISS_NAMESPACE_END

APRS_LIB_AX25_NAMESPACE_BEGIN

// **************************************************************** //
//                                                                  //
// FORWARD DECLARATIONS                                             //
//                                                                  //
// **************************************************************** //

enum class protocol_id
{
    ax25_layer3,
    iso_8208_ccitt_x25_plt,
    compressed_tcp_ip,
    uncompressed_tcp_ip,
    segmentation_fragment,
    texnet_datagram,
    link_quality_protocol,
    appletalk,
    appletalk_arp,
    arpa_ip,
    arpa_address_resolution,
    flexnet,
    netrom,
    no_layer3_protocol,
    escape
};

struct frame
{
    std::string source_address;
    int source_address_ssid = 0;
    std::string destination_address;
    int destination_address_ssid = 0;
    std::vector<std::pair<std::string, int>> digipeater_addresses;    
    std::string info_field;
};

enum class decoder_hint : uint8_t
{
    none = 0,
    no_flag = 1,
    no_fcs = 2,
    no_flag_no_fcs = no_flag | no_fcs
};

enum class frame_type : uint8_t
{
    i_frame,
    s_frame = 0x01,
    u_frame = 0x03
};

APRS_LIB_INLINE decoder_hint operator&(decoder_hint a, decoder_hint b)
{
    return (decoder_hint)((uint8_t)a & (uint8_t)b);
}

APRS_LIB_INLINE bool try_decode_frame(std::string_view data, frame& frame, decoder_hint hint = decoder_hint::no_flag_no_fcs);

APRS_LIB_AX25_DETAIL_NAMESPACE_BEGIN

APRS_LIB_INLINE bool try_decode_ui_frame(std::string_view data, frame& frame, decoder_hint hint);

APRS_LIB_INLINE int ax25_flag = 0x7e;

APRS_LIB_INLINE void parse_address(std::string_view data, std::string& address, int& ssid);
APRS_LIB_INLINE void parse_addresses(std::string_view data, std::vector<std::pair<std::string, int>>& addresses);

APRS_LIB_AX25_DETAIL_NAMESPACE_END

// **************************************************************** //
//                                                                  //
//                                                                  //
// IMPLEMENTATION                                                   //
//                                                                  //
//                                                                  //
// **************************************************************** //

APRS_LIB_INLINE bool try_decode_frame(std::string_view data, frame& frame, decoder_hint hint)
{
    return APRS_LIB_AX25_DETAIL_NAMESPACE_REFERENCE try_decode_ui_frame(data, frame, hint);
}

APRS_LIB_AX25_DETAIL_NAMESPACE_BEGIN

APRS_LIB_INLINE bool try_decode_ui_frame(std::string_view data, frame& frame, decoder_hint hint)
{
    if (data.length() < 18)
    {
        return false;
    }

    //
    // AX.25 UI Frame Format:
    //
    //   (Optional)                                                                                                                        (Optional)
    //      Flag                                                         Control Field                                     (Optional)         Flag
    //      0x7E      Dest Addr     Source Addr     Digipeater Addrs         0x03         Protocol ID      Info Field         FCS             0x7E
    //    ------------------------------------------------------------------------------------------------------------------------------------------------
    //       1            7              7                0-56                 1               1             1-256             2               1 
    // 
    // When transmitted over KISS, the Flag and FCS can be optional
    //

    size_t destination_address_start = 0;

    size_t info_field_length = 0;

    // The first and last byte is the 0x7E flag
    // This is not typically included in an AX25 frame when encapsulated in KISS frames

    if (hint == decoder_hint::none || (hint & decoder_hint::no_flag) == decoder_hint::none)
    {
        if (data[0] != APRS_LIB_AX25_DETAIL_NAMESPACE_REFERENCE ax25_flag && data[data.size() - 1] != APRS_LIB_AX25_DETAIL_NAMESPACE_REFERENCE ax25_flag)
        {
            return false;
        }
        destination_address_start = 1;
        info_field_length = -1;  // have the Flag field
    }
    if ((hint & decoder_hint::no_fcs) == decoder_hint::none)
    {
        info_field_length = info_field_length - 2; // have the FCS field
    }

    // The first 7 bytes is the destination address
    // The next 7 bytes (7 to 14) is the source address

    std::string_view destination_address = data.substr(destination_address_start, 7);
    std::string_view source_address = data.substr(7, 7);

    // The digipeater addresses, each 7 bytes, continue from byte 14 to the control byte 0x03

    size_t digipeater_addresses_start = 14;
    size_t digipeater_addresses_end = data.find_first_of((char)frame_type::u_frame, digipeater_addresses_start);    
    size_t digipeater_addresses_length = digipeater_addresses_end - digipeater_addresses_start;

    if (digipeater_addresses_end == data.npos)
    {
        return false;
    }

    std::string_view digipeater_addresses = data.substr(digipeater_addresses_start, digipeater_addresses_length);

    size_t info_field_start = digipeater_addresses_end + 2; // skip the Control Field byte and the Protocol ID byte
    
    info_field_length = info_field_length + data.length() - info_field_start; // skip the FCS and Flag bytes, if needed

    if ((info_field_start + info_field_length) > data.length())
    {
        return false;
    }

    std::string_view info_field = data.substr(info_field_start, info_field_length);

    APRS_LIB_AX25_DETAIL_NAMESPACE_REFERENCE parse_address(destination_address, frame.destination_address, frame.destination_address_ssid);
    APRS_LIB_AX25_DETAIL_NAMESPACE_REFERENCE parse_address(source_address, frame.source_address, frame.source_address_ssid);
    APRS_LIB_AX25_DETAIL_NAMESPACE_REFERENCE parse_addresses(digipeater_addresses, frame.digipeater_addresses);

    frame.info_field = info_field;

    return true;
}

APRS_LIB_INLINE void parse_address(std::string_view data, std::string& address, int& ssid)
{
    address = std::string(6, '\0'); // addresses are 6 characters long

    for (size_t i = 0; i < 6; i++)
    {
        address[i] = ((uint8_t)data[i]) >> 1; // data is organized in 7 bits
    }
    
    ssid = (data[6] >> 1) & 0xf; // 0b00001111

    address = APRS_LIB_APRS_NAMESPACE :: APRS_LIB_APRS_DETAIL_NAMESPACE :: trim(address);
}

APRS_LIB_INLINE void parse_addresses(std::string_view data, std::vector<std::pair<std::string, int>>& addresses)
{
    for (size_t i = 0; i < data.size(); i+=7)
    {
        std::string address;
        int ssid;
        parse_address(data.substr(i, 7), address, ssid);
        addresses.push_back(std::make_pair(address, ssid));
    }
}

APRS_LIB_AX25_DETAIL_NAMESPACE_END

APRS_LIB_AX25_NAMESPACE_END