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
	static colors affected_colors{};
	static bool display_p1 = false;
	static bool display_p2 = false;
	ImGui::Checkbox("p1", &display_p1);
	ImGui::SameLine();
	ImGui::Checkbox("p2", &display_p2);

	static bool attack_boxs_display = false;
	static ImColor attack_boxs_color{ 255, 0, 0 };
	static bool attack_color = false;
	ImGui::Checkbox(u8"¹¥»÷¿ò", &attack_boxs_display);
	ImGui::SameLine();
	ctrl->color_selector(u8"¹¥»÷¿òÑÕÉ«", &attack_boxs_color, &attack_color);

	static bool body_boxs_display = false;
	static ImColor body_boxs_color{ 255, 165, 0 };
	static bool body_color = false;
	ImGui::Checkbox(u8"ÉíÎ»¿ò", &body_boxs_display);
	ImGui::SameLine();
	ctrl->color_selector(u8"ÉíÎ»¿òÑÕÉ«", &body_boxs_color, &body_color);

	static bool normal_boxs_display = false;
	static ImColor normal_boxs_color{ 255, 255, 0 };
	static bool normal_color = false;
	ImGui::Checkbox(u8"ÊÜ»÷¿ò", &normal_boxs_display);
	ImGui::SameLine();
	ctrl->color_selector(u8"ÊÜ»÷¿òÑÕÉ«", &normal_boxs_color, &normal_color);
	affected_colors.normal = normal_boxs_color;
	affected_colors.normal_display = normal_boxs_display;

	static bool gurad_boxs_display = false;
	static ImColor gurad_boxs_color{ 0, 255, 0 };
	static bool gurad_color = false;
	ImGui::Checkbox(u8"·ÀÓù¿ò", &gurad_boxs_display);
	ImGui::SameLine();
	ctrl->color_selector(u8"·ÀÓù¿òÑÕÉ«", &gurad_boxs_color, &gurad_color);
	affected_colors.gurad = gurad_boxs_color;
	affected_colors.gurad_display = gurad_boxs_display;

	static bool down_boxs_display = false;
	static ImColor down_boxs_color{ 0, 255, 255 };
	static bool down_color = false;
	ImGui::Checkbox(u8"×·¼Ó¿ò", &down_boxs_display);
	ImGui::SameLine();
	ctrl->color_selector(u8"×·¼Ó¿òÑÕÉ«", &down_boxs_color, &down_color);
	affected_colors.down = down_boxs_color;
	affected_colors.down_display = down_boxs_display;

	static bool tyrant_boxs_display = false;
	static ImColor tyrant_boxs_color{ 0, 0, 255 };
	static bool tyrant_color = false;
	ImGui::Checkbox(u8"°ÔÌå¿ò", &tyrant_boxs_display);
	ImGui::SameLine();
	ctrl->color_selector(u8"°ÔÌå¿òÑÕÉ«", &tyrant_boxs_color, &tyrant_color);
	affected_colors.tyants = tyrant_boxs_color;
	affected_colors.tyants_display = tyrant_boxs_display;

	static bool gp_boxs_display = false;
	static ImColor gp_boxs_color{ 139, 0, 255 };
	static bool gp_color = false;
	ImGui::Checkbox(u8"µ±Éí¿ò", &gp_boxs_display);
	ImGui::SameLine();
	ctrl->color_selector(u8"µ±Éí¿òÑÕÉ«", &gp_boxs_color, &gp_color);
	affected_colors.guradex = gp_boxs_color;
	affected_colors.guradex_display = gp_boxs_color;

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
	for (int i = 0; i < entry.capacity && entry.actcs != nullptr; i++) {
		//Action_Collections 	actcs = entry.actcs[i];
		Action_Collections 	actcs{};
		if (!ReadProcessMemory(GetCurrentProcess(), &entry.actcs[i], &actcs, sizeof(Action_Collections), 0)) {
			break;
		}
		switch (actcs.types) {
		case Action_Types::AttackBoxs: {
			attack_boxs(p1, actcs, attack_boxs_color, display_p1 && attack_boxs_display);
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
	for (int i = 0; i < entry.capacity && entry.actcs != nullptr; i++) {
		Action_Collections 	actcs{};
		if (!ReadProcessMemory(GetCurrentProcess(), &entry.actcs[i], &actcs, sizeof(Action_Collections), 0)) {
			break;
		}
		switch (actcs.types) {
		case Action_Types::AttackBoxs: {
			attack_boxs(p2, actcs, attack_boxs_color, display_p2 && attack_boxs_display);
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
			if (actcs.types == Action_Types::AttackBoxs) {
				attack_boxs((Player*)props, actcs, attack_boxs_color, display_p1 && attack_boxs_display);
				attack_boxs((Player*)props, actcs, attack_boxs_color, display_p2 && attack_boxs_display);
			}
		}
	}
	return true;
}

bool draws::left(float x, float y, float w, float h, ImColor color)
{
	//×óÉÏ½Ç
	FVector w1{};
	w1.X = x;
	w1.Z = y;
	FVector2D s1{};
	serivce->screen(w1, s1);

	//ÓÒÉÏ½Ç
	FVector w2{};
	w2.X = x + w;
	w2.Z = y;
	FVector2D s2{};
	serivce->screen(w2, s2);

	//ÓÒÏÂ½Ç
	FVector w3{};
	w3.X = x + w;
	w3.Z = y - h;
	FVector2D s3{};
	serivce->screen(w3, s3);

	//×óÏÂ½Ç
	FVector w4{};
	w4.X = x;
	w4.Z = y - h;
	FVector2D s4{};
	serivce->screen(w4, s4);

	// ×óÉÏ½Ç -> ÓÒÉÏ½Ç
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s1.X, s1.Y }, ImVec2{ s2.X, s2.Y }, color);
	// ÓÒÉÏ½Ç -> ÓÒÏÂ½Ç
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s2.X, s2.Y }, ImVec2{ s3.X, s3.Y }, color);
	// ÓÒÏÂ½Ç -> ×óÏÂ½Ç
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s3.X, s3.Y }, ImVec2{ s4.X, s4.Y }, color);
	// ×óÏÂ½Ç -> ×óÉÏ½Ç
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s4.X, s4.Y }, ImVec2{ s1.X, s1.Y }, color);

	return true;
}

bool draws::right(float x, float y, float w, float h, ImColor color)
{
	//×óÉÏ½Ç
	FVector w1{};
	w1.X = x;
	w1.Z = y;
	FVector2D s1{};
	serivce->screen(w1, s1);

	//ÓÒÉÏ½Ç
	FVector w2{};
	w2.X = x - w;
	w2.Z = y;
	FVector2D s2{};
	serivce->screen(w2, s2);

	//ÓÒÏÂ½Ç
	FVector w3{ };
	w3.X = x - w;
	w3.Z = y - h;
	FVector2D s3{};
	serivce->screen(w3, s3);

	//×óÏÂ½Ç
	FVector w4{ };
	w4.X = x;
	w4.Z = y - h;
	FVector2D s4{};
	serivce->screen(w4, s4);

	// ×óÉÏ½Ç -> ÓÒÉÏ½Ç
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s1.X, s1.Y }, ImVec2{ s2.X, s2.Y }, color);
	// ÓÒÉÏ½Ç -> ÓÒÏÂ½Ç
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s2.X, s2.Y }, ImVec2{ s3.X, s3.Y }, color);
	// ÓÒÏÂ½Ç -> ×óÏÂ½Ç
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s3.X, s3.Y }, ImVec2{ s4.X, s4.Y }, color);
	// ×óÏÂ½Ç -> ×óÉÏ½Ç
	ImGui::GetForegroundDrawList()->AddLine(ImVec2{ s4.X, s4.Y }, ImVec2{ s1.X, s1.Y }, color);
	return true;
}

bool draws::attack_boxs(Player* player, Action_Collections actcs, ImColor color, bool display)
{
	if (display == false) {
		return true;
	}

	if (actcs.attack == nullptr) {
		return false;
	}

	auto address = memory::read(memory::read(((unsigned long long)player) + 0x68) + 0x20);

	for (unsigned int i = 0; i < actcs.capacity; i++) {
		auto box = actcs.attack[i];
		auto px = player->x * 10;
		auto py = player->y * 10;
		auto x = box.x * 10;
		auto y = box.y * 10;
		auto w = box.w * 10;
		auto h = box.h * 10;

		if (*(unsigned __int32*)(address + box.atk * 0x1c4) == 0x5) {
			return false;
		}

		if (box.flag == 0x100) {
			continue;
		}

		if (box.frame != player->now) {
			continue;
		}

		if (player->toward == 0) {
			left(px + x, y + py, w, h, color);
		}
		else {
			right(px - x, y + py, w, h, color);
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
			left(px + x, y + py, w, h, color);
		}
		else {
			right(px - x, y + py, w, h, color);
		}
	}

	return true;
}

bool draws::affected_boxs(Player* player, Action_Collections actcs, colors& cs, bool display)
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
				left(px + x, y + py, w, h, color);
			}
			else {
				right(px - x, y + py, w, h, color);
			}
		}
	}

	return true;
}