#include "draws.h"
#include "memory.h"
#include <windows.h>

draws::draws()
{
	this->ctrl = control::instance();
}

bool draws::initialize(services* service, mappers* mapper)
{
	this->serivce = service;
	this->mapper = mapper;
	return this->serivce != nullptr && mapper != nullptr ? true : false;
}

bool draws::draw()
{
	static attackcolors attack_colors{};
	static affectcolors affected_colors{};
	static bool display_p1 = false;
	static bool display_p2 = false;
	ImGui::Checkbox("p1", &display_p1);
	ImGui::SameLine();
	ImGui::Checkbox("p2", &display_p2);

	static bool thratk_boxs_display = false;
	static bool thratk_selector = false;
	static ImColor thratk_boxs_color{ 127,255,127 };
	ctrl->box_color(u8"投技框", &thratk_boxs_display, u8"投技框颜色", &thratk_selector, &thratk_boxs_color);
	attack_colors.thratk = thratk_boxs_color;
	attack_colors.thratk_display = thratk_boxs_display;

	static bool body_boxs_display = false;
	static bool body_selector = false;
	static ImColor body_boxs_color{ 255, 165, 0 };
	ctrl->box_color(u8"身位框", &body_boxs_display, u8"身位框颜色", &body_selector, &body_boxs_color);

	static bool normal_boxs_display = false;
	static bool normal_selector = false;
	static ImColor normal_boxs_color{ 255, 255, 0 };
	ctrl->box_color(u8"受击框", &normal_boxs_display, u8"受击框颜色", &normal_selector, &normal_boxs_color);
	affected_colors.normal = normal_boxs_color;
	affected_colors.normal_display = normal_boxs_display;

	static bool cast_boxs_display = false;
	static bool cast_selector = false;
	static ImColor cast_boxs_color{ 127, 255, 255 };
	ctrl->box_color(u8"被投框", &cast_boxs_display, u8"被投框颜色", &cast_selector, &cast_boxs_color);
	affected_colors.cast = cast_boxs_color;
	affected_colors.cast_display = cast_boxs_display;

	static bool gurad_boxs_display = false;
	static bool gurad_selector = false;
	static ImColor gurad_boxs_color{ 0, 255, 0 };
	ctrl->box_color(u8"防御框", &cast_boxs_display, u8"防御框颜色", &cast_selector, &cast_boxs_color);
	affected_colors.gurad = gurad_boxs_color;
	affected_colors.gurad_display = gurad_boxs_display;

	static bool down_boxs_display = false;
	static bool down_selector = false;
	static ImColor down_boxs_color{ 0, 255, 255 };
	ctrl->box_color(u8"追加框", &down_boxs_display, u8"追加框颜色", &down_selector, &down_boxs_color);
	affected_colors.down = down_boxs_color;
	affected_colors.down_display = down_boxs_display;

	static bool tyrant_boxs_display = false;
	static bool tyrant_selector = false;
	static ImColor tyrant_boxs_color{ 0, 0, 255 };
	ctrl->box_color(u8"霸体框", &tyrant_boxs_display, u8"霸体框颜色", &tyrant_selector, &tyrant_boxs_color);
	affected_colors.tyants = tyrant_boxs_color;
	affected_colors.tyants_display = tyrant_boxs_display;

	static bool gp_boxs_display = false;
	static bool gp_selector = false;
	static ImColor gp_boxs_color{ 139, 0, 255 };
	ctrl->box_color(u8"当身框", &gp_boxs_display, u8"当身框颜色", &gp_selector, &gp_boxs_color);
	affected_colors.guradex = gp_boxs_color;
	affected_colors.guradex_display = gp_boxs_display;

	static bool noratk_boxs_display = false;
	static bool noratk_selector = false;
	static ImColor attack_boxs_color{ 255, 0, 0 };
	ctrl->box_color(u8"普通攻击框", &noratk_boxs_display, u8"普通攻击框颜色", &noratk_selector, &attack_boxs_color);
	attack_colors.noratk = attack_boxs_color;
	attack_colors.noratk_display = noratk_boxs_display;

	static bool cgatk_boxs_display = false;
	static bool cgatk_selector = false;
	static ImColor cgatk_boxs_color{ 127,255,127 };
	ctrl->box_color(u8"引发防御框", &cgatk_boxs_display, u8"引发防御框颜色", &cgatk_selector, &cgatk_boxs_color);
	attack_colors.cgatk = cgatk_boxs_color;
	attack_colors.cgatk_display = cgatk_boxs_display;

	static bool floatk_boxs_display = false;
	static ImColor floatk_boxs_color{ 127,127,255 };
	static bool floatk_selector = false;
	ctrl->box_color(u8"飞行道具攻击框", &floatk_boxs_display, u8"飞行道具攻击框颜色", &floatk_selector, &floatk_boxs_color);
	attack_colors.floatk = floatk_boxs_color;
	attack_colors.floatk_display = floatk_boxs_display;

	static bool ofo_boxs_display = false;
	static bool ofo_seleoctor = false;
	static ImColor ofo_boxs_color{ 255, 127, 255 };
	ctrl->box_color(u8"抵消飞行道具框", &ofo_boxs_display, u8"抵消飞行道具框颜色", &ofo_seleoctor, &ofo_boxs_color);
	affected_colors.ofo = ofo_boxs_color;
	affected_colors.ofo_display = ofo_boxs_display;

	static bool rfo_boxs_display = false;
	static bool rfo_selector = false;
	static ImColor rfo_boxs_color{ 127, 255, 255 };
	ctrl->box_color(u8"抵消飞行道具框", &rfo_boxs_display, u8"抵消飞行道具框颜色", &rfo_selector, &rfo_boxs_color);
	affected_colors.rfo = rfo_boxs_color;
	affected_colors.rfo_display = rfo_boxs_display;

	auto objects = *mapper->objects;

	if (objects == nullptr) {
		return false;
	}
	if (objects->complete != 2) {
		return false;
	}
	if (objects->ready <= 2) {
		return false;
	}

	auto p1 = objects->p1;
	if (p1 == nullptr) {
		return false;
	}
	if (p1->acts == nullptr) {
		return false;
	}
	if (p1->acts->entry == nullptr) {
		return false;
	}

	auto p2 = objects->p2;
	if (p2 == nullptr) {
		return false;
	}
	if (p2->acts == nullptr) {
		return false;
	}
	if (p2->acts->entry == nullptr) {
		return false;
	}

	Actions_Entry entry = p1->acts->entry[p1->number];
	for (int i = 0; i < entry.capacity && entry.actcs != nullptr && IsBadReadPtr(&entry.actcs[i], sizeof(Actions_Entry)) == 0; i++) {
		Action_Collections 	actcs = entry.actcs[i];

		switch (actcs.types) {
		case Action_Types::AttackBoxs: {
			attack_boxs(p1, actcs, attack_colors, display_p1);
			break;
		}
		case Action_Types::BodyBoxs: {
			body_boxs(p1, actcs, body_boxs_color, display_p1 && body_boxs_display);
			break;
		}
		case Action_Types::AffectedBoxs: {
			affected_boxs(p1, actcs, affected_colors, display_p1);
			break;
		}
		default: {
			break;
		}
		}
	}

	entry = p2->acts->entry[p2->number];
	for (int i = 0; i < entry.capacity && entry.actcs != nullptr && IsBadReadPtr(&entry.actcs[i], sizeof(Actions_Entry)) == 0; i++) {
		Action_Collections 	actcs = entry.actcs[i];
		switch (actcs.types) {
		case Action_Types::AttackBoxs: {
			attack_boxs(p2, actcs, attack_colors, display_p2);
			break;
		}
		case Action_Types::BodyBoxs: {
			body_boxs(p2, actcs, body_boxs_color, display_p2 && body_boxs_display);
			break;
		}
		case Action_Types::AffectedBoxs: {
			affected_boxs(p2, actcs, affected_colors, display_p2);
			break;
		}
		default: {
			break;
		}
		}
	}

	auto list = objects->props_list->list;
	for (; list != nullptr; list = list->next) {
		auto props = list->props;
		auto props_entry = props->acts->entry[props->number];
		for (int i = 0; i < props_entry.capacity; i++) {
			Action_Collections 	actcs = props_entry.actcs[i];
			switch (actcs.types) {
			case Action_Types::AttackBoxs: {
				attack_boxs((Player*)props, actcs, attack_colors, display_p1);
				attack_boxs((Player*)props, actcs, attack_colors, display_p2);
				break;
			}
			case Action_Types::AffectedBoxs: {
				affected_boxs((Player*)props, actcs, affected_colors, display_p1);
				affected_boxs((Player*)props, actcs, affected_colors, display_p2);
				break;
			}
			default: {
				break;
			}
			}
		}
	}
	return true;
}

bool draws::left(float x, float y, float w, float h, ImColor color)
{
	//左上角
	FVector w1{};
	w1.X = x;
	w1.Z = y;
	FVector2D s1{};
	serivce->screen(w1, s1);

	//右上角
	FVector w2{};
	w2.X = x + w;
	w2.Z = y;
	FVector2D s2{};
	serivce->screen(w2, s2);

	//右下角
	FVector w3{};
	w3.X = x + w;
	w3.Z = y - h;
	FVector2D s3{};
	serivce->screen(w3, s3);

	//左下角
	FVector w4{};
	w4.X = x;
	w4.Z = y - h;
	FVector2D s4{};
	serivce->screen(w4, s4);

	// 左上角 -> 右上角
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s1.X, s1.Y }, ImVec2{ s2.X, s2.Y }, color);
	// 右上角 -> 右下角
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s2.X, s2.Y }, ImVec2{ s3.X, s3.Y }, color);
	// 右下角 -> 左下角
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s3.X, s3.Y }, ImVec2{ s4.X, s4.Y }, color);
	// 左下角 -> 左上角
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s4.X, s4.Y }, ImVec2{ s1.X, s1.Y }, color);

	return true;
}

bool draws::right(float x, float y, float w, float h, ImColor color)
{
	//左上角
	FVector w1{};
	w1.X = x;
	w1.Z = y;
	FVector2D s1{};
	serivce->screen(w1, s1);

	//右上角
	FVector w2{};
	w2.X = x - w;
	w2.Z = y;
	FVector2D s2{};
	serivce->screen(w2, s2);

	//右下角
	FVector w3{ };
	w3.X = x - w;
	w3.Z = y - h;
	FVector2D s3{};
	serivce->screen(w3, s3);

	//左下角
	FVector w4{ };
	w4.X = x;
	w4.Z = y - h;
	FVector2D s4{};
	serivce->screen(w4, s4);

	// 左上角 -> 右上角
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s1.X, s1.Y }, ImVec2{ s2.X, s2.Y }, color);
	// 右上角 -> 右下角
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s2.X, s2.Y }, ImVec2{ s3.X, s3.Y }, color);
	// 右下角 -> 左下角
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s3.X, s3.Y }, ImVec2{ s4.X, s4.Y }, color);
	// 左下角 -> 左上角
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s4.X, s4.Y }, ImVec2{ s1.X, s1.Y }, color);
	return true;
}

bool draws::attack_boxs(Player* player, Action_Collections actcs, attackcolors& cs, bool display)
{
	if (display == false) {
		return true;
	}

	if (actcs.attack == nullptr) {
		return false;
	}

	for (unsigned int i = 0; i < actcs.capacity; i++) {
		auto box = actcs.attack[i];
		auto px = player->x * 10;
		auto py = player->y * 10;
		auto x = box.x * 10;
		auto y = box.y * 10;
		auto w = box.w * 10;
		auto h = box.h * 10;
		Attack_Type_Collections atkcs = player->atks->atkcs[box.atk];

		ImColor color{ 255,255,0 };

		if (box.frame != player->now) {
			continue;
		}

		switch (atkcs.types) {
		case Attack_Types::NormalAttack: {
			color = cs.noratk;
			display = cs.noratk_display;
			break;
		}
		case Attack_Types::FlyingObject: {
			color = cs.floatk;
			display = cs.floatk_display;
			break;
		}
		case Attack_Types::ThrowSkill: {
			color = cs.thratk;
			display = cs.thratk_display;
			break;
		}
		case Attack_Types::CauseGuard: {
			color = cs.cgatk;
			display = cs.cgatk_display;
			break;
		}
		default:
			display = false;
			break;
		}
		if (display) {
			if (player->toward == 0) {
				left(px + x + player->xoff * 10, y + py + player->yoff * 10, w, h, color);
			}
			else {
				right(px - x + player->xoff * 10, y + py + player->yoff * 10, w, h, color);
			}
		}
	}
	return true;
}

bool draws::body_boxs(Player* player, Action_Collections actcs, ImColor color, bool display)
{
	if (display == false) {
		return true;
	}

	if (actcs.body == nullptr) {
		return false;
	}

	for (unsigned int i = 0; i < actcs.capacity; i++) {
		auto box = actcs.body[i];
		auto px = player->x * 10;
		auto py = player->y * 10;
		auto x = box.x * 10;
		auto y = box.y * 10;
		auto w = box.w * 10;
		auto h = box.h * 10;

		if (box.frame != player->now) {
			continue;
		}

		if (player->toward == 0) {
			left(px + x + player->xoff * 10, y + py + player->yoff * 10, w, h, color);
		}
		else {
			right(px - x + player->xoff * 10, y + py + player->yoff * 10, w, h, color);
		}
	}

	return true;
}

bool draws::affected_boxs(Player* player, Action_Collections actcs, affectcolors& cs, bool display)
{
	if (display == false) {
		return true;
	}

	if (actcs.affected == nullptr) {
		return false;
	}

	ImColor color{ 255,255,0 };

	for (unsigned int i = 0; i < actcs.capacity; i++) {
		auto box = actcs.affected[i];
		auto px = player->x * 10;
		auto py = player->y * 10;
		auto x = box.x * 10;
		auto y = box.y * 10;
		auto w = box.w * 10;
		auto h = box.h * 10;

		if (box.frame != player->now) {
			continue;
		}

		switch (box.types) {
		case Affected_Types::NormalHitBox: {
			color = cs.normal;
			display = display && cs.normal_display;
			break;
		}
		case Affected_Types::CastBox: {
			color = cs.cast;
			display = display && cs.cast_display;
			break;
		}
		case Affected_Types::GuardBox: {
			color = cs.gurad;
			display = display && cs.gurad_display;
			break;
		}
		case Affected_Types::DownHitBox: {
			color = cs.down;
			display = display && cs.down_display;
			break;
		}
		case Affected_Types::OffsetFlyingObjectBox: {
			color = cs.ofo;
			display = display && cs.ofo_display;
			break;
		}
		case Affected_Types::ReboundFlyingObjectBox: {
			color = cs.rfo;
			display = cs.rfo_display;
			break;
		}
		case Affected_Types::TyrantsBox: {
			color = cs.tyants;
			display = display && cs.tyants_display;
			break;
		}
		case Affected_Types::GuardPointBox: {
			color = cs.guradex;
			display = display && cs.guradex_display;
			break;
		}
		default: {
			display = false;
			break;
		}
		}

		if (display) {
			if (player->toward == 0) {
				left(px + x + player->xoff * 10, y + py + player->yoff * 10, w, h, color);
			}
			else {
				right(px - x + player->xoff * 10, y + py + player->yoff * 10, w, h, color);
			}
		}
	}

	return true;
}