#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <vector>
#include "imgui/imgui.h"
#include "entity/object.h"

struct description {
	const char* title;
	bool activity;
	bool open;
	ImColor color;
	ActionLineID action;
	warpper types;
};

extern std::vector<description> descriptions;
void reload_description_colors();

#endif