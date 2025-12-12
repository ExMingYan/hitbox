#pragma once
#include <array>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>

#include "context/configuration.h"
#include "context/description.h"

namespace fs = std::filesystem;

using Rgb = std::array<std::uint8_t, 3>;

std::vector<Rgb> ini_read_colors(std::vector<description>& descriptions, const std::string& section = "Colors");
bool ini_write_colors(const std::vector<Rgb>& colors, std::vector<description> &descriptions, const std::string& section = "Colors");
bool ini_read_int(const std::string& key, int& out_value, const std::string& section = "Configs");
bool ini_write_int(const std::string& key, int value, const std::string& section = "Configs");
bool ini_read_float(const std::string& key, float& out_value, const std::string& section = "Configs");
bool ini_write_float(const std::string& key, float value, const std::string& section = "Configs");
bool ini_read_color(const char* key, Rgb& out_color, const std::string& section = "Colors");
bool ini_write_color(const Rgb& color, const char* key, const std::string& section = "Colors");
