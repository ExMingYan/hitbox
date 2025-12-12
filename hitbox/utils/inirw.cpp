#include "inirw.h"
#include "logger.hpp"

static fs::path inipath = fs::current_path() / "hitbox.ini";

static bool parse_rgb(const std::string& s, Rgb& out) {
    std::istringstream iss(s);
    std::string token;
    int parts[3] = { 0, 0, 0 };
    for (int i = 0; i < 3; ++i) {
        if (!std::getline(iss, token, ',')) {
            return false;
        }
        try {
            int v = std::stoi(token);
            if (v < 0) v = 0;
            if (v > 255) v = 255;
            parts[i] = v;
        }
        catch (...) {
            return false;
        }
    }
    out = { static_cast<std::uint8_t>(parts[0]),
            static_cast<std::uint8_t>(parts[1]),
            static_cast<std::uint8_t>(parts[2]) };
    return true;
}

static std::string to_string_rgb(const Rgb& c) {
    std::ostringstream oss;
    oss << static_cast<int>(c[0]) << "," << static_cast<int>(c[1]) << "," << static_cast<int>(c[2]);
    return oss.str();
}

std::vector<Rgb> ini_read_colors(std::vector<description>& descriptions, const std::string& section) {
    std::vector<Rgb> result;

    if (!fs::exists(inipath)) {
        return result;
    }

    char buf[256] = { 0 };
    for (auto desc : descriptions) {
        DWORD len = GetPrivateProfileStringA(section.c_str(), desc.title, "", buf, static_cast<DWORD>(sizeof(buf)), inipath.string().c_str());
        if (len == 0) {
            break;
        }
        Rgb c{};
        if (parse_rgb(std::string(buf, len), c)) {
            result.push_back(c);
        }
        else {
            result.push_back({ 0, 0, 0 });
        }
    }

    return result;
}

bool ini_write_colors(const std::vector<Rgb>& colors, std::vector<description> &descriptions, const std::string& section) {
    if (colors.empty()) {
        return true;
    }
    bool ok = true;
    for (int i = 0; i < static_cast<int>(colors.size()); ++i) {
        std::string val = to_string_rgb(colors[i]);
        if (!WritePrivateProfileStringA(section.c_str(), descriptions[i].title, val.c_str(), inipath.string().c_str())) {
            ok = false;
        }
    }
    return ok;
}

bool ini_read_int(const std::string& key, int& out_value, const std::string& section) {
    char buf[32] = { 0 };
    DWORD len = GetPrivateProfileStringA(section.c_str(), key.c_str(), "", buf, static_cast<DWORD>(sizeof(buf)), inipath.string().c_str());
    if (len == 0) {
        return false;
    }
    try {
        out_value = std::stoi(std::string(buf, len));
    }
    catch (...) {
        return false;
    }
    return true;
}

bool ini_write_int(const std::string& key, int value, const std::string& section) {
    std::string val = std::to_string(value);
    if (!WritePrivateProfileStringA(section.c_str(), key.c_str(), val.c_str(), inipath.string().c_str())) {
        return false;
    }
    return true;
}

bool ini_read_float(const std::string& key, float& out_value, const std::string& section) {
    char buf[64] = { 0 };
    DWORD len = GetPrivateProfileStringA(section.c_str(), key.c_str(), "", buf, static_cast<DWORD>(sizeof(buf)), inipath.string().c_str());
    if (len == 0) {
        return false;
    }
    try {
        out_value = std::stof(std::string(buf, len));
    }
    catch (...) {
        return false;
    }
    return true;
}

bool ini_write_float(const std::string& key, float value, const std::string& section) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value;
    std::string val = ss.str();
    if (!WritePrivateProfileStringA(section.c_str(), key.c_str(), val.c_str(), inipath.string().c_str())) {
        return false;
    }
    return true;
}

bool ini_read_color(const char* key, Rgb& out_color, const std::string& section) {
    char buf[256] = { 0 };
    DWORD len = GetPrivateProfileStringA(section.c_str(), key, "", buf, static_cast<DWORD>(sizeof(buf)), inipath.string().c_str());
    if (len == 0) {
        return false;
    }
    if (!parse_rgb(std::string(buf, len), out_color)) {
        return false;
    }
    return true;
}

bool ini_write_color(const Rgb& color, const char* key, const std::string& section) {
    std::string val = to_string_rgb(color);
    if (!WritePrivateProfileStringA(section.c_str(), key, val.c_str(), inipath.string().c_str())) {
        return false;
    }
    return true;
}
