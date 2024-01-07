#pragma once
#include "imgui/imgui.h"
#include "singleton.hpp"
class control : public singleton<control>
{
private:

public:
	control();
	bool box_color(const char* checkbox, bool* box, const char* selector, bool* open, ImColor* color);
};
