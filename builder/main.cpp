#include <iostream>
#include <memory>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iomanip>
#include <vector>

int main(int arg, char** argv) {
	if (arg < 3) {
		std::cout << "usage: " << " <source> <result>\n";
		return -1;
	}

	std::ios_base::sync_with_stdio(false);

	std::filesystem::path file_path(argv[1]);
	if (!std::filesystem::exists(file_path)) {
		std::cerr << "file not exists\n";
		return -2;
	}

	std::ifstream ifs(file_path, std::ios::binary);
	if (ifs.is_open() == false) {
		std::cerr << "open file failed\n";
		return -3;
	}

	auto filesize = std::filesystem::file_size(file_path);
	std::vector<unsigned char> filebuffer(filesize);
	ifs.read(reinterpret_cast<char*>(filebuffer.data()), filesize);
	if (ifs.fail()) {
		std::cerr << "file read failed\n";
		return -4;
	}
	ifs.close();

	std::filesystem::path directory(argv[2]);
	std::filesystem::path header = directory / file_path.replace_extension(".h").filename();

	std::ofstream ofs(header, std::ios::binary);
	if (!ofs.is_open()) {
		std::cerr << "create .h failed\n";
		return -5;
	}

	std::stringstream ss;
	ss << "#pragma once\r\n";
	ss << "unsigned char " << file_path.stem().string() << "[" << filesize << "] = {" << "\r\n";
	ss << "\t";

	const char hex_chars[] = "0123456789abcdef";
	for (size_t i = 0; i < filesize; ++i) {
		unsigned char byte = filebuffer[i];
		ss << "0x" << hex_chars[byte >> 4] << hex_chars[byte & 0x0F] << ", ";
		if ((i + 1) % 20 == 0) {
			ss << "\r\n\t";
		}
	}

	ss << "\r\n};\r\n";
	ss << "unsigned int " << file_path.stem().string() << "_len = " << std::dec << filesize << ";\r\n";
	ofs << ss.str();
	ofs.close();

	std::cout << "build " << header.filename().string() << " success\n";
	return 0;
}
