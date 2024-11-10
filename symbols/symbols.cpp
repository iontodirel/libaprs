enum class symbol_staggered : int
{
    police_station = '!',             emergency = '!' + 200,
    digi = '#',                       digi_green = '#' + 200,
    phone = '$',                      atm = '$' + 200,
    dx_cluster = '%',
    hf_gateway = '&',                 hf_gateway_diamond = '&' + 200,
    aircraft_small = '\'',            crash_site = '\'' + 200,
    mobile_satellite_station = '(',   cloudy = '(' + 200,
    wheelchair = ')',                 firenet_meo_modis = ')' + 200,
    snowmobile = '*',                 snow = '*' + 200,
    red_cross = '+',                  church = '+' + 200,
    boy_scout = ',',                  girl_scouts = ',' + 200,
    home = '-',                       house_hf = '-' + 200,
    x = '.',                          uknown_position = '.' + 200,
    red_dot = '/',
    circle_0 = '0',                   circle = '0' + 200,
    circle_1 = '1',
    circle_2 = '2',
    circle_3 = '3',
    circle_4 = '4',
    circle_5 = '5',
    circle_6 = '6',
    circle_7 = '7',
    circle_8 = '8',                   wifi = '8' + 200,
    circle_9 = '9',                   gas_station_blue = '9' + 200,
    fire = ':',                       hail = ':' + 200,
    campground_tent = ';',            park_picnic = ';' + 200,
    motorcycle = '<',                 nws_advisory_gale_flag = '<' + 200,
    railroad_engine = '=',
    car = '>',                        car2 = '>' + 200,
    file_server = '?',                info_kiosk_blue_box_q = '?' + 200,
    hc_future = '@',                  huricane = '@' + 200,
    aid_station = 'A',                box = 'A' + 200,
    bbs = 'B',                        blowing_snow = 'B' + 200,
    canoe = 'C',                      coastguard = 'C' + 200,
                                      drizzle = 'D' + 200,
    eyeball = 'E',                    smoke = 'E' + 200,
    tractor = 'F',                    feezing_rain = 'F' + 200,
    grid_square_3x3 = 'G',            snow_shower = 'G' + 200,
    hotel = 'H',                      haze = 'H' + 200,
    tcp_ip = 'I',                     rain_shower = 'I' + 200,
                                      lightning = 'J' + 200,
    school = 'K',                     kenwood = 'K' + 200,
    pc_user = 'L',                    ligthouse = 'L' + 200,
    mac_aprs = 'M',
    nts_station = 'N',                nav_buoy = 'N' + 200,
    balloon = 'O',                    rocket = 'O' + 200,
    police = 'P',                     parking = 'P' + 200,
    tbd = 'Q',                        earthquake = 'Q' + 200,
    rv = 'R',                         restaurant = 'R' + 200,
    shuttle_space = 'S',              satellite_pac_sat = 'S' + 200,
    sstv = 'T',                       thunderstorm = 'T' + 200,
    bus = 'U',                        sunny = 'U' + 200,
    atv = 'V',                        vortac_nav_aid = 'V' + 200,
    national_wx = 'W',                nws_site = 'W' + 200,
    helicopter = 'X',                 pharmacy_rx = 'X' + 200,
    yacht_sail_boat = 'Y',
    win_aprs = 'Z',
    jogger = '[',                     wall_cloud = '[' + 200,
    triangle = '\\',
    pbbs = ']',
    aircraft_large = '^',             aircraft = '^' + 200,
    wx = '_',                         wx_station_with_digi_green = '_' + 200,
    dish_antenna = '`',               rain = '`' + 200,
    ambulance = 'a',                  arrl = 'a' + 200,
                                      red_diamond = 'a' + 200,
                                      races = 'a' + 200,
    bicycle = 'b',                    blowing_dust = 'b' + 200,
    icp = 'c',                        civil_defence_races = 'c' + 200,
    fire_station = 'd',               dx_spot = 'd' + 200,
    horse = 'e',                      sleet = 'e' + 200,
    fire_truck = 'f',                 funnel_cloud = 'f' + 200,
    glider = 'g',                     gale_flags = 'g' + 200,
    hospital = 'h',                   ham_store = 'h' + 200,
    iota = 'i',                       indoor_short_range_digi = 'i' + 200,
    jeep = 'j',                       work_zone = 'j' + 200,
    truck = 'k',                      suv_atv = 'k' + 200,
    laptop = 'l',                     area_symbols = 'l' + 200,
    mic_e_repeater = 'm',             value_signpost = 'm' + 200,
    node = 'n',                       triangle_df = 'n' + 200,
    eoc = 'o',                        small_circle = 'o' + 200,
    rover_dog = 'p',                  partly_cloudy = 'p' + 200,
    grid_square_2x2 = 'q',
    antenna = 'r',                    restrooms = 'r' + 200,
    power_boat = 's',                 ship_boat_top_view = 's' + 200,
    truck_stop = 't',                 tornado = 't' + 200,
    truck_18_wheeler = 'u',           truck2 = 'u' + 200,
    van = 'v',                        van2 = 'v' + 200,
    water_station = 'w',              flooding = 'w' + 200,
    x_aprs = 'x',
    yagi = 'y',                       skywarn = 'y' + 200,
    shelter = 'z',                    shelter2 = 'z' + 200,
                                      fog = '{' + 200,
    tnc_stream_sw1 = '|',
    tnc_stream_sw2 = '~',
};

enum class symbol_encoded : int
{
    police_station = '!',
    digi = '#',
    phone = '$',
    dx_cluster = '%',
    hf_gateway = '&',
    aircraft_small = '\'',
    mobile_satellite_station = '(',
    wheelchair = ')',
    snowmobile = '*',
    red_cross = '+',
    boy_scout = ',',
    home = '-',
    x = '.',
    red_dot = '/',
    circle_0 = '0',
    circle_1 = '1',
    circle_2 = '2',
    circle_3 = '3',
    circle_4 = '4',
    circle_5 = '5',
    circle_6 = '6',
    circle_7 = '7',
    circle_8 = '8',
    circle_9 = '9',
    fire = ':',
    campground_tent = ';',
    motorcycle = '<',
    railroad_engine = '=',
    car = '>',
    file_server = '?',
    hc_future = '@',
    aid_station = 'A',
    bbs = 'B',
    canoe = 'C',
    eyeball = 'E',
    tractor = 'F',
    grid_square_3x3 = 'G',
    hotel = 'H',
    tcp_ip = 'I',
    school = 'K',
    pc_user = 'L',
    mac_aprs = 'M',
    nts_station = 'N',
    balloon = 'O',
    police = 'P',
    tbd = 'Q',
    rv = 'R',
    shuttle_space = 'S',
    sstv = 'T',
    bus = 'U',
    atv = 'V',
    national_wx = 'W',
    helicopter = 'X',
    yacht_sail_boat = 'Y',
    win_aprs = 'Z',
    jogger = '[',
    triangle = '\\',
    pbbs = ']',
    aircraft_large = '^',
    wx = '_',
    dish_antenna = '`',
    ambulance = 'a',
    bicycle = 'b',
    icp = 'c',
    fire_station = 'd',
    horse = 'e',
    fire_truck = 'f',
    glider = 'g',
    hospital = 'h',
    iota = 'i',
    jeep = 'j',
    truck = 'k',
    laptop = 'l',
    mic_e_repeater = 'm',
    node = 'n',
    eoc = 'o',
    rover_dog = 'p',
    grid_square_2x2 = 'q',
    antenna = 'r',
    power_boat = 's',
    truck_stop = 't',
    truck_18_wheeler = 'u',
    van = 'v',
    water_station = 'w',
    x_aprs = 'x',
    yagi = 'y',
    shelter = 'z',
    tnc_stream_sw1 = '|',
    tnc_stream_sw2 = '~',
    emergency = '!' + 200,
    digi_green = '#' + 200,
    atm = '$' + 200,
    hf_gateway_diamond = '&' + 200,
    crash_site = '\'' + 200,
    cloudy = '(' + 200,
    firenet_meo_modis = ')' + 200,
    snow = '*' + 200,
    church = '+' + 200,
    girl_scouts = ',' + 200,
    house_hf = '-' + 200,
    uknown_position = '.' + 200,
    circle = '0' + 200,
    wifi = '8' + 200,
    gas_station_blue = '9' + 200,
    hail = ':' + 200,
    park_picnic = ';' + 200,
    nws_advisory_gale_flag = '<' + 200,
    car2 = '>' + 200,
    info_kiosk_blue_box_q = '?' + 200,
    huricane = '@' + 200,
    box = 'A' + 200,
    blowing_snow = 'B' + 200,
    coastguard = 'C' + 200,
    drizzle = 'D' + 200,
    smoke = 'E' + 200,
    feezing_rain = 'F' + 200,
    snow_shower = 'G' + 200,
    haze = 'H' + 200,
    rain_shower = 'I' + 200,
    lightning = 'J' + 200,
    kenwood = 'K' + 200,
    ligthouse = 'L' + 200,
    nav_buoy = 'N' + 200,
    rocket = 'O' + 200,
    parking = 'P' + 200,
    earthquake = 'Q' + 200,
    restaurant = 'R' + 200,
    satellite_pac_sat = 'S' + 200,
    thunderstorm = 'T' + 200,
    sunny = 'U' + 200,
    vortac_nav_aid = 'V' + 200,
    nws_site = 'W' + 200,
    pharmacy_rx = 'X' + 200,
    wall_cloud = '[' + 200,
    aircraft = '^' + 200,
    wx_station_with_digi_green = '_' + 200,
    rain = '`' + 200,
    arrl = 'a' + 400,
    red_diamond = 'a' + 200,
    races = 'a' + 500,
    blowing_dust = 'b' + 200,
    civil_defence_races = 'c' + 200,
    dx_spot = 'd' + 200,
    sleet = 'e' + 200,
    funnel_cloud = 'f' + 200,
    gale_flags = 'g' + 200,
    ham_store = 'h' + 200,
    indoor_short_range_digi = 'i' + 200,
    work_zone = 'j' + 200,
    suv_atv = 'k' + 200,
    area_symbols = 'l' + 200,
    value_signpost = 'm' + 200,
    triangle_df = 'n' + 200,
    small_circle = 'o' + 200,
    partly_cloudy = 'p' + 200,
    restrooms = 'r' + 200,
    ship_boat_top_view = 's' + 200,
    tornado = 't' + 200,
    truck2 = 'u' + 200,
    van2 = 'v' + 200,
    flooding = 'w' + 200,
    skywarn = 'y' + 200,
    shelter2 = 'z' + 200,
    fog = '{' + 200,
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

#include <vector>
#include <string>
#include <unordered_map>

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
    std::string image;
    int row = -1;
    int column = -1;
};

struct symbol_map
{
    void populate()
    {
        symbols.reserve(164);
        symbols.push_back({ 1, "police_station", "Police, Sheriff", '!', '/', false, "BB", -1, "aprs-symbols-24-0.png", 1, 1 });
        symbols.push_back({ 3, "digi", "Digi (green star with white center)", '#', '/', false, "BD", -1, "aprs-symbols-24-0.png", 1, 3 });
        symbols.push_back({ 4, "phone", "Phone", '$', '/', false, "BE", -1, "aprs-symbols-24-0.png", 1, 4 });
        symbols.push_back({ 5, "dx_cluster", "DX Cluster", '%', '/', false, "BF", -1, "aprs-symbols-24-0.png", 1, 5 });
        symbols.push_back({ 6, "hf_gateway", "HF Gateway", '&', '/', false, "BG", -1, "aprs-symbols-24-0.png", 1, 6 });
        symbols.push_back({ 7, "aircraft_small", "Small Aircraft", '\'', '/', false, "BH", 7, "aprs-symbols-24-0.png", 1, 7 });
        symbols.push_back({ 8, "mobile_satellite_station", "Mobile Satellite Groundstation", '(', '/', false, "BI", -1, "aprs-symbols-24-0.png", 1, 8 });
        symbols.push_back({ 9, "wheelchair", "Wheelchair, Handicapped", ')', '/', false, "BJ", -1, "aprs-symbols-24-0.png", 1, 9 });
        symbols.push_back({ 10, "snowmobile", "Snowmobile", '*', '/', false, "BK", -1, "aprs-symbols-24-0.png", 1, 10 });
        symbols.push_back({ 11, "red_cross", "Red Cross", '+', '/', false, "BL", -1, "aprs-symbols-24-0.png", 1, 11 });
        symbols.push_back({ 12, "boy_scout", "Boy Scouts", ',', '/', false, "BM", -1, "aprs-symbols-24-0.png", 1, 12 });
        symbols.push_back({ 13, "home", "House QTH (VHF)", '-', '/', false, "BN", -1, "aprs-symbols-24-0.png", 1, 13 });
        symbols.push_back({ 14, "x", "X", '.', '/', false, "BO", -1, "aprs-symbols-24-0.png", 1, 14 });
        symbols.push_back({ 15, "red_dot", "Dot", '/', '/', false, "BP", -1, "aprs-symbols-24-0.png", 1, 15 });
        symbols.push_back({ 16, "circle_0", "Numbered circle: 0", '0', '/', false, "P0", -1, "aprs-symbols-24-0.png", 1, 16 });
        symbols.push_back({ 17, "circle_1", "Numbered circle: 1", '1', '/', false, "P1", -1, "aprs-symbols-24-0.png", 2, 1 });
        symbols.push_back({ 18, "circle_2", "Numbered circle: 2", '2', '/', false, "P2", -1, "aprs-symbols-24-0.png", 2, 2 });
        symbols.push_back({ 19, "circle_3", "Numbered circle: 3", '3', '/', false, "P3", -1, "aprs-symbols-24-0.png", 2, 3 });
        symbols.push_back({ 20, "circle_4", "Numbered circle: 4", '4', '/', false, "P4", -1, "aprs-symbols-24-0.png", 2, 4 });
        symbols.push_back({ 21, "circle_5", "Numbered circle: 5", '5', '/', false, "P5", -1, "aprs-symbols-24-0.png", 2, 5 });
        symbols.push_back({ 22, "circle_6", "Numbered circle: 6", '6', '/', false, "P6", -1, "aprs-symbols-24-0.png", 2, 6 });
        symbols.push_back({ 23, "circle_7", "Numbered circle: 7", '7', '/', false, "P7", -1, "aprs-symbols-24-0.png", 2, 7 });
        symbols.push_back({ 24, "circle_8", "Numbered circle: 8", '8', '/', false, "P8", -1, "aprs-symbols-24-0.png", 2, 8 });
        symbols.push_back({ 25, "circle_9", "Numbered circle: 9", '9', '/', false, "P9", -1, "aprs-symbols-24-0.png", 2, 9 });
        symbols.push_back({ 26, "fire", "Fire", ':', '/', false, "MR", -1, "aprs-symbols-24-0.png", 2, 10 });
        symbols.push_back({ 27, "campground_tent", "Campground, Tent", ';', '/', false, "MS", -1, "aprs-symbols-24-0.png", 2, 11 });
        symbols.push_back({ 28, "motorcycle", "Motorcycle", '<', '/', false, "MT", 10, "aprs-symbols-24-0.png", 2, 12 });
        symbols.push_back({ 29, "railroad_engine", "Railroad Engine", '=', '/', false, "MU", -1, "aprs-symbols-24-0.png", 2, 13 });
        symbols.push_back({ 30, "car", "Car", '>', '/', false, "MV", 9, "aprs-symbols-24-0.png", 2, 14 });
        symbols.push_back({ 31, "file_server", "File Server", '?', '/', false, "MW", -1, "aprs-symbols-24-0.png", 2, 15 });
        symbols.push_back({ 32, "hc_future", "Hurricane Future Prediction", '@', '/', false, "MX", -1, "aprs-symbols-24-0.png", 2, 16 });
        symbols.push_back({ 33, "aid_station", "Aid Station", 'A', '/', false, "PA", -1, "aprs-symbols-24-0.png", 3, 1 });
        symbols.push_back({ 34, "bbs", "BBS", 'B', '/', false, "PB", -1, "aprs-symbols-24-0.png", 3, 2 });
        symbols.push_back({ 35, "canoe", "Canoe", 'C', '/', false, "PC", -1, "aprs-symbols-24-0.png", 3, 3 });
        symbols.push_back({ 37, "eyeball", "Eyeball (eye catcher)", 'E', '/', false, "PE", -1, "aprs-symbols-24-0.png", 3, 5 });
        symbols.push_back({ 38, "tractor", "Farm vehicle, Tractor", 'F', '/', false, "PF", -1, "aprs-symbols-24-0.png", 3, 6 });
        symbols.push_back({ 39, "grid_square_3x3", "Grid square (6-character)", 'G', '/', false, "PG", -1, "aprs-symbols-24-0.png", 3, 7 });
        symbols.push_back({ 40, "hotel", "Hotel", 'H', '/', false, "PH", -1, "aprs-symbols-24-0.png", 3, 8 });
        symbols.push_back({ 41, "tcp_ip", "TCP/IP Network Station", 'I', '/', false, "PI", -1, "aprs-symbols-24-0.png", 3, 9 });
        symbols.push_back({ 43, "school", "School", 'K', '/', false, "PK", -1, "aprs-symbols-24-0.png", 3, 11 });
        symbols.push_back({ 44, "pc_user", "PC User", 'L', '/', false, "PL", -1, "aprs-symbols-24-0.png", 3, 12 });
        symbols.push_back({ 45, "mac_aprs", "MacAPRS", 'M', '/', false, "PM", -1, "aprs-symbols-24-0.png", 3, 13 });
        symbols.push_back({ 46, "nts_station", "NTS Station", 'N', '/', false, "PN", -1, "aprs-symbols-24-0.png", 3, 14 });
        symbols.push_back({ 47, "balloon", "Balloon", 'O', '/', false, "PO", 11, "aprs-symbols-24-0.png", 3, 15 });
        symbols.push_back({ 48, "police", "Police Car", 'P', '/', false, "PP", -1, "aprs-symbols-24-0.png", 3, 16 });
        symbols.push_back({ 49, "tbd", "", 'Q', '/', false, "", -1, "", 3, 16 });
        symbols.push_back({ 50, "rv", "Recreational Vehicle", 'R', '/', false, "PR", 13, "aprs-symbols-24-0.png", 4, 2 });
        symbols.push_back({ 51, "shuttle_space", "Space Shuttle", 'S', '/', false, "PS", -1, "aprs-symbols-24-0.png", 4, 3 });
        symbols.push_back({ 52, "sstv", "SSTV", 'T', '/', false, "PT", -1, "aprs-symbols-24-0.png", 4, 4 });
        symbols.push_back({ 53, "bus", "Bus", 'U', '/', false, "PU", -1, "aprs-symbols-24-0.png", 4, 5 });
        symbols.push_back({ 54, "atv", "ATV, Amateur Television", 'V', '/', false, "PV", -1, "aprs-symbols-24-0.png", 4, 6 });
        symbols.push_back({ 55, "national_wx", "National Weather Service Site", 'W', '/', false, "PW", -1, "aprs-symbols-24-0.png", 4, 7 });
        symbols.push_back({ 56, "helicopter", "Helicopter", 'X', '/', false, "PX", 6, "aprs-symbols-24-0.png", 4, 8 });
        symbols.push_back({ 57, "yacht_sail_boat", "Yacht (sail boat)", 'Y', '/', false, "PY", 5, "aprs-symbols-24-0.png", 4, 9 });
        symbols.push_back({ 58, "win_aprs", "WinAPRS", 'Z', '/', false, "PZ", -1, "aprs-symbols-24-0.png", 4, 10 });
        symbols.push_back({ 59, "jogger", "Jogger", '[', '/', false, "HS", -1, "aprs-symbols-24-0.png", 4, 11 });
        symbols.push_back({ 60, "triangle", "Triangle (DF)", '\\', '/', false, "HT", -1, "aprs-symbols-24-0.png", 4, 12 });
        symbols.push_back({ 61, "pbbs", "Mailbox, Post Office", ']', '/', false, "HU", -1, "aprs-symbols-24-0.png", 4, 13 });
        symbols.push_back({ 62, "aircraft_large", "Large Aircraft", '^', '/', false, "HV", -1, "aprs-symbols-24-0.png", 4, 14 });
        symbols.push_back({ 63, "wx", "Weather Station", '_', '/', false, "HW", -1, "aprs-symbols-24-0.png", 4, 15 });
        symbols.push_back({ 64, "dish_antenna", "Satellite Dish Antenna", '`', '/', false, "HX", -1, "aprs-symbols-24-0.png", 4, 16 });
        symbols.push_back({ 65, "ambulance", "Ambulance", 'a', '/', false, "LA", 1, "aprs-symbols-24-0.png", 5, 1 });
        symbols.push_back({ 66, "bicycle", "Bicycle", 'b', '/', false, "LB", 4, "aprs-symbols-24-0.png", 5, 2 });
        symbols.push_back({ 67, "icp", "Incident Command Post", 'c', '/', false, "LC", -1, "aprs-symbols-24-0.png", 5, 3 });
        symbols.push_back({ 68, "fire_station", "Fire Station", 'd', '/', false, "LD", -1, "aprs-symbols-24-0.png", 5, 4 });
        symbols.push_back({ 69, "horse", "Horse (equestrian)", 'e', '/', false, "LE", -1, "aprs-symbols-24-0.png", 5, 5 });
        symbols.push_back({ 70, "fire_truck", "Fire Truck", 'f', '/', false, "LF", 3, "aprs-symbols-24-0.png", 5, 6 });
        symbols.push_back({ 71, "glider", "Glider", 'g', '/', false, "LG", -1, "aprs-symbols-24-0.png", 5, 7 });
        symbols.push_back({ 72, "hospital", "Hospital", 'h', '/', false, "LH", -1, "aprs-symbols-24-0.png", 5, 8 });
        symbols.push_back({ 73, "iota", "Islands On The Air", 'i', '/', false, "LI", -1, "aprs-symbols-24-0.png", 5, 9 });
        symbols.push_back({ 74, "jeep", "Jeep", 'j', '/', false, "LJ", 12, "aprs-symbols-24-0.png", 5, 10 });
        symbols.push_back({ 75, "truck", "Truck", 'k', '/', false, "LK", 14, "aprs-symbols-24-0.png", 5, 11 });
        symbols.push_back({ 76, "laptop", "Laptop", 'l', '/', false, "LL", -1, "aprs-symbols-24-0.png", 5, 12 });
        symbols.push_back({ 77, "mic_e_repeater", "Mic-E Repeater", 'm', '/', false, "LM", -1, "aprs-symbols-24-0.png", 5, 13 });
        symbols.push_back({ 78, "node", "Node, Black Bulls-eye", 'n', '/', false, "LN", -1, "aprs-symbols-24-0.png", 5, 14 });
        symbols.push_back({ 79, "eoc", "Emergency Operations Center", 'o', '/', false, "LO", -1, "aprs-symbols-24-0.png", 5, 15 });
        symbols.push_back({ 80, "rover_dog", "Dog", 'p', '/', false, "LP", -1, "aprs-symbols-24-0.png", 5, 16 });
        symbols.push_back({ 81, "grid_square_2x2", "Grid square, 2 by 2", 'q', '/', false, "LQ", -1, "aprs-symbols-24-0.png", 6, 1 });
        symbols.push_back({ 82, "antenna", "Repeater Tower", 'r', '/', false, "LR", -1, "aprs-symbols-24-0.png", 6, 2 });
        symbols.push_back({ 83, "power_boat", "Ship (power boat)", 's', '/', false, "LS", 8, "aprs-symbols-24-0.png", 6, 3 });
        symbols.push_back({ 84, "truck_stop", "Truck Stop", 't', '/', false, "LT", -1, "aprs-symbols-24-0.png", 6, 4 });
        symbols.push_back({ 85, "truck_18_wheeler", "Semi-trailer Truck, 18-wheeler", 'u', '/', false, "LU", -1, "aprs-symbols-24-0.png", 6, 5 });
        symbols.push_back({ 86, "van", "Van", 'v', '/', false, "LV", 15, "aprs-symbols-24-0.png", 6, 6 });
        symbols.push_back({ 87, "water_station", "Water Station", 'w', '/', false, "LW", -1, "aprs-symbols-24-0.png", 6, 7 });
        symbols.push_back({ 88, "x_aprs", "X / Unix APRS", 'x', '/', false, "LX", -1, "aprs-symbols-24-0.png", 6, 8 });
        symbols.push_back({ 89, "yagi", "House, Yagi Antenna", 'y', '/', false, "LY", -1, "aprs-symbols-24-0.png", 6, 9 });
        symbols.push_back({ 91, "shelter", "Shelter", 'z', '/', false, "LZ", -1, "aprs-symbols-24-0.png", 6, 10 });
        symbols.push_back({ 92, "tnc_stream_sw1", "", '|', '/', false, "", -1, "aprs-symbols-24-0.png", 6, 12 });
        symbols.push_back({ 94, "tnc_stream_sw2", "", '~', '/', false, "", -1, "aprs-symbols-24-0.png", 6, 14 });
        symbols.push_back({ 1, "emergency", "Emergency", '!', '\\', true, "OB", -1, "aprs-symbols-24-1.png", 1, 1 });
        symbols.push_back({ 3, "digi_green", "Digipeater (green star)", '#', '\\', true, "OD", -1, "aprs-symbols-24-1.png", 1, 3 });
        symbols.push_back({ 4, "atm", "Bank or ATM", '$', '\\', true, "OE", -1, "aprs-symbols-24-1.png", 1, 4 });
        symbols.push_back({ 6, "hf_gateway_diamond", "Gateway Station", '&', '\\', true, "OG", -1, "aprs-symbols-24-1.png", 1, 6 });
        symbols.push_back({ 7, "crash_site", "Crash Site", '\'', '\\', true, "OH", -1, "aprs-symbols-24-1.png", 1, 7 });
        symbols.push_back({ 8, "cloudy", "Cloudy", '(', '\\', true, "OI", -1, "aprs-symbols-24-1.png", 1, 8 });
        symbols.push_back({ 9, "firenet_meo_modis", "Firenet MEO, MODIS Earth Observation", ')', '\\', true, "OJ", -1, "aprs-symbols-24-1.png", 1, 9 });
        symbols.push_back({ 10, "snow", "Snow", '*', '\\', true, "OK", -1, "aprs-symbols-24-1.png", 1, 10 });
        symbols.push_back({ 11, "church", "Church", '+', '\\', true, "OL", -1, "aprs-symbols-24-1.png", 1, 11 });
        symbols.push_back({ 12, "girl_scouts", "Girl Scouts", ',', '\\', true, "OM", -1, "aprs-symbols-24-1.png", 1, 12 });
        symbols.push_back({ 13, "house_hf", "House, HF Antenna", '-', '\\', true, "ON", -1, "aprs-symbols-24-1.png", 1, 13 });
        symbols.push_back({ 14, "uknown_position", "Ambiguous, Question mark inside circle", '.', '\\', true, "OO", -1, "aprs-symbols-24-1.png", 1, 14 });
        symbols.push_back({ 16, "circle", "Circle, IRLP / Echolink/WIRES", '0', '\\', true, "A0", -1, "aprs-symbols-24-1.png", 1, 16 });
        symbols.push_back({ 24, "wifi", "802.11 WiFi or other network node", '8', '\\', true, "A8", -1, "aprs-symbols-24-1.png", 1, 16 });
        symbols.push_back({ 25, "gas_station_blue", "Gas Station", '9', '\\', true, "A9", -1, "", 2, 9 });
        symbols.push_back({ 26, "hail", "Hail", ':', '\\', true, "NR", -1, "aprs-symbols-24-1.png", 2, 9 });
        symbols.push_back({ 27, "park_picnic", "Park, Picnic area", ';', '\\', true, "NS", -1, "aprs-symbols-24-1.png", 2, 11 });
        symbols.push_back({ 28, "nws_advisory_gale_flag", "Advisory, Single Red Flag", '<', '\\', true, "NT", -1, "aprs-symbols-24-1.png", 2, 12 });
        symbols.push_back({ 30, "car2", "Red Car", '>', '\\', true, "NV", -1, "aprs-symbols-24-1.png", 2, 14 });
        symbols.push_back({ 31, "info_kiosk_blue_box_q", "Info Kiosk", '?', '\\', true, "NW", -1, "aprs-symbols-24-1.png", 2, 15 });
        symbols.push_back({ 32, "huricane", "Hurricane, Tropical storm", '@', '\\', true, "NX", -1, "aprs-symbols-24-1.png", 2, 16 });
        symbols.push_back({ 33, "box", "White Box", 'A', '\\', true, "AA", -1, "aprs-symbols-24-1.png", 3, 1 });
        symbols.push_back({ 34, "blowing_snow", "Blowing Snow", 'B', '\\', true, "AB", -1, "aprs-symbols-24-1.png", 3, 2 });
        symbols.push_back({ 35, "coastguard", "Coast Guard", 'C', '\\', true, "AC", -1, "aprs-symbols-24-1.png", 3, 3 });
        symbols.push_back({ 36, "drizzle", "Drizzling Rain", 'D', '\\', true, "AD", -1, "aprs-symbols-24-1.png", 3, 4 });
        symbols.push_back({ 37, "smoke", "Smoke, Chimney", 'E', '\\', true, "AE", -1, "aprs-symbols-24-1.png", 3, 5 });
        symbols.push_back({ 38, "feezing_rain", "Freezing Rain", 'F', '\\', true, "AF", -1, "aprs-symbols-24-1.png", 3, 6 });
        symbols.push_back({ 39, "snow_shower", "Snow Shower", 'G', '\\', true, "AG", -1, "aprs-symbols-24-1.png", 3, 7 });
        symbols.push_back({ 40, "haze", "Haze", 'H', '\\', true, "AH", -1, "aprs-symbols-24-1.png", 3, 8 });
        symbols.push_back({ 41, "rain_shower", "Rain Shower", 'I', '\\', true, "AI", -1, "aprs-symbols-24-1.png", 3, 9 });
        symbols.push_back({ 42, "lightning", "Lightning", 'J', '\\', true, "AJ", -1, "aprs-symbols-24-1.png", 3, 10 });
        symbols.push_back({ 43, "kenwood", "Kenwood HT", 'K', '\\', true, "AK", -1, "aprs-symbols-24-1.png", 3, 11 });
        symbols.push_back({ 44, "ligthouse", "Lighthouse", 'L', '\\', true, "AL", -1, "aprs-symbols-24-1.png", 3, 12 });
        symbols.push_back({ 46, "nav_buoy", "Navigation Buoy", 'N', '\\', true, "AN", -1, "aprs-symbols-24-1.png", 3, 14 });
        symbols.push_back({ 47, "rocket", "Rocket", 'O', '\\', true, "AO", -1, "aprs-symbols-24-1.png", 3, 15 });
        symbols.push_back({ 48, "parking", "Parking", 'P', '\\', true, "AP", -1, "aprs-symbols-24-1.png", 3, 16 });
        symbols.push_back({ 49, "earthquake", "Earthquake", 'Q', '\\', true, "AQ", -1, "aprs-symbols-24-1.png", 4, 1 });
        symbols.push_back({ 50, "restaurant", "Restaurant", 'R', '\\', true, "AR", -1, "aprs-symbols-24-1.png", 4, 2 });
        symbols.push_back({ 51, "satellite_pac_sat", "Satellite", 'S', '\\', true, "AS", -1, "aprs-symbols-24-1.png", 4, 3 });
        symbols.push_back({ 52, "thunderstorm", "Thunderstorm", 'T', '\\', true, "AT", -1, "aprs-symbols-24-1.png", 4, 4 });
        symbols.push_back({ 53, "sunny", "Sunny", 'U', '\\', true, "AU", -1, "aprs-symbols-24-1.png", 4, 5 });
        symbols.push_back({ 54, "vortac_nav_aid", "VORTAC, Navigational Aid", 'V', '\\', true, "AV", -1, "aprs-symbols-24-1.png", 4, 6 });
        symbols.push_back({ 55, "nws_site", "NWS site", 'W', '\\', true, "AW", -1, "aprs-symbols-24-1.png", 4, 7 });
        symbols.push_back({ 56, "pharmacy_rx", "Pharmacy", 'X', '\\', true, "AX", -1, "aprs-symbols-24-1.png", 4, 8 });
        symbols.push_back({ 59, "wall_cloud", "Wall Cloud", '[', '\\', true, "DS", -1, "aprs-symbols-24-1.png", 4, 11 });
        symbols.push_back({ 62, "aircraft", "Aircraft", '^', '\\', true, "DV", -1, "aprs-symbols-24-1.png", 4, 14 });
        symbols.push_back({ 63, "wx_station_with_digi_green", "Weather Site", '_', '\\', true, "DW", -1, "aprs-symbols-24-1.png", 4, 15 });
        symbols.push_back({ 64, "rain", "Rain", '`', '\\', true, "DX", -1, "aprs-symbols-24-1.png", 4, 16 });
        symbols.push_back({ 65, "arrl", "AARL", 'a', 'A', false, "SAA", -1, "", 4, 16 });
        symbols.push_back({ 65, "red_diamond", "Red Diamond", 'a', '\\', true, "SA", -1, "aprs-symbols-24-1.png", 5, 1 });
        symbols.push_back({ 65, "races", "RACES", 'a', 'R', false, "SAR", -1, "", 4, 16 });
        symbols.push_back({ 66, "blowing_dust", "Blowing Dust, Sand", 'b', '\\', true, "SB", -1, "aprs-symbols-24-1.png", 5, 2 });
        symbols.push_back({ 67, "civil_defence_races", "CD Triangle, RACES, CERTS, SATERN", 'c', '\\', true, "SC", -1, "aprs-symbols-24-1.png", 5, 3 });
        symbols.push_back({ 68, "dx_spot", "DX Spot", 'd', '\\', true, "SD", -1, "aprs-symbols-24-1.png", 5, 4 });
        symbols.push_back({ 69, "sleet", "Sleet", 'e', '\\', true, "SE", -1, "aprs-symbols-24-1.png", 5, 5 });
        symbols.push_back({ 70, "funnel_cloud", "Funnel Cloud", 'f', '\\', true, "SF", -1, "aprs-symbols-24-1.png", 5, 6 });
        symbols.push_back({ 71, "gale_flags", "Gale (two red flags)", 'g', '\\', true, "SG", -1, "aprs-symbols-24-1.png", 5, 7 });
        symbols.push_back({ 72, "ham_store", "Store", 'h', '\\', true, "SH", -1, "aprs-symbols-24-1.png", 5, 8 });
        symbols.push_back({ 73, "indoor_short_range_digi", "Black Box, Point Of Interest", 'i', '\\', true, "SI", -1, "aprs-symbols-24-1.png", 5, 9 });
        symbols.push_back({ 74, "work_zone", "Work Zone, Excavating Machine", 'j', '\\', true, "SJ", -1, "aprs-symbols-24-1.png", 5, 10 });
        symbols.push_back({ 75, "suv_atv", "SUV, ATV", 'k', '\\', true, "SK", -1, "aprs-symbols-24-1.png", 5, 11 });
        symbols.push_back({ 76, "area_symbols", "", 'l', '\\', true, "", -1, "", 5, 11 });
        symbols.push_back({ 77, "value_signpost", "", 'm', '\\', true, "", -1, "aprs-symbols-24-1.png", 5, 13 });
        symbols.push_back({ 78, "triangle_df", "Red Triangle", 'n', '\\', true, "SN", -1, "aprs-symbols-24-1.png", 5, 14 });
        symbols.push_back({ 79, "small_circle", "Small Circle", 'o', '\\', true, "SO", -1, "aprs-symbols-24-1.png", 5, 15 });
        symbols.push_back({ 80, "partly_cloudy", "Partly Cloudy", 'p', '\\', true, "SP", -1, "aprs-symbols-24-1.png", 5, 16 });
        symbols.push_back({ 82, "restrooms", "Restrooms", 'r', '\\', true, "SR", -1, "aprs-symbols-24-1.png", 6, 2 });
        symbols.push_back({ 83, "ship_boat_top_view", "Ship, Boat", 's', '\\', true, "SS", -1, "aprs-symbols-24-1.png", 6, 3 });
        symbols.push_back({ 84, "tornado", "Tornado", 't', '\\', true, "ST", -1, "aprs-symbols-24-1.png", 6, 4 });
        symbols.push_back({ 85, "truck2", "Truck", 'u', '\\', true, "SU", -1, "aprs-symbols-24-1.png", 6, 5 });
        symbols.push_back({ 86, "van2", "Van", 'v', '\\', true, "SV", -1, "aprs-symbols-24-1.png", 6, 6 });
        symbols.push_back({ 87, "flooding", "Flooding", 'w', '\\', true, "SW", -1, "aprs-symbols-24-1.png", 6, 7 });
        symbols.push_back({ 88, "skywarn", "Skywarn", 'y', '\\', true, "SY", -1, "aprs-symbols-24-1.png", 6, 8 });
        symbols.push_back({ 89, "shelter2", "Shelter", 'z', '\\', true, "SZ", -1, "aprs-symbols-24-1.png", 6, 9 });
        symbols.push_back({ 90, "fog", "Fog", '{', '\\', true, "Q1", -1, "aprs-symbols-24-1.png", 6, 10 });

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

    std::vector<symbol_info> symbols;
    std::unordered_map<int, int> symbol_code_map;
    std::unordered_map<std::string, int> destination_address_map;
    std::unordered_map<std::string, int> symbol_name_map;
};




