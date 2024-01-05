#pragma once

#include "imgui/imgui.h"

#include "control.h"
#include "mappers.h"
#include "services.h"
#include "singleton.hpp"
#include "structs/objects.h"

struct colors {
	ImColor normal;
	ImColor gurad;
	ImColor down;
	ImColor tyants;
	ImColor guradex;
	bool normal_display;
	bool gurad_display;
	bool down_display;
	bool tyants_display;
	bool guradex_display;
};

class draws : public singleton<draws>
{
private:
	services* serivce;
	mappers* mapper;
	control* ctrl;

private:
	bool left(float x, float y, float w, float h, ImColor color);
	bool right(float x, float y, float w, float h, ImColor color);
	bool attack_boxs(Player* player, Action_Collections actcs, ImColor color, bool display);
	bool body_boxs(Player* player, Action_Collections actcs, ImColor color, bool display);
	bool affected_boxs(Player* player, Action_Collections actcs, colors& cs, bool display);

public:
	draws();
	bool initialize(services* service, mappers* mapper);
	bool draw();
};
