#pragma once
#include "imgui/imgui.h"
#include "singleton.hpp"
class control : public singleton<control>
{
private:

public:
	control();
	bool color_selector(const char* label, ImColor* color, bool* show);
};
