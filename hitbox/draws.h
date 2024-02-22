#pragma once

#include "imgui/imgui.h"
#include "control.h"
#include "mappers.h"
#include "services.h"
#include "singleton.hpp"
#include "structs/objects.h"

struct displaychoose
{
	bool noratkf_display;
	bool floatkf_display;
};

struct attackcolors {
	ImColor noratk;
	ImColor floatk;
	ImColor thratk;
	ImColor cgatk;
	ImColor cratk;
	bool noratk_display;
	bool floatk_display;
	bool thratk_display;
	bool cgatk_display;
	bool cratk_display;
};

struct affectcolors {
	ImColor normal;
	ImColor cast;
	ImColor gurad;
	ImColor down;
	ImColor ofo;
	ImColor rfo;
	ImColor tyants;
	ImColor guradex;
	ImColor flyobex;
	ImColor throwex;
	bool normal_display;
	bool cast_display;
	bool gurad_display;
	bool down_display;
	bool ofo_display;
	bool rfo_display;
	bool tyants_display;
	bool guradex_display;
	bool flyobex_display;
	bool throwex_display;
};

class draws : public singleton<draws>
{
private:
	services* serivce;
	mappers* mapper;
	control* ctrl;
	float alpha;

private:
	bool drawbox(float x, float y, float w, float h, ImColor color, Action_Collections actcs, Player* player);
	bool attack_boxs(Player* player, Action_Collections actcs, attackcolors& cs, bool display);
	bool body_boxs(Player* player, Action_Collections actcs, ImColor color, bool display);
	bool affected_boxs(Player* player, Action_Collections actcs, affectcolors& cs, bool display);
	bool attack_value(Player* player, Action_Collections actcs, attackcolors& cs, displaychoose& dc, bool display);
	bool affected_value(Player* player, Action_Collections actcs, affectcolors& cs, bool display);
	bool displayvalue(Player* player, float x, float y, float w, float h, std::string values);
	int calcbalckout(Player* player);

public:
	draws();
	bool initialize(services* service, mappers* mapper);
	bool draw();
};
