#include "draws.h"
#include "memory.h"
#include <windows.h>
#include <string>
#include <iostream>

draws::draws()
{
	this->ctrl = control::instance();
	this->alpha = 0.5f;
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
	ImGui::SameLine();
	static float temp = 0.2f;
	ImGui::SetNextItemWidth(50);
	ImGui::InputFloat(u8"透明度", &temp, 0.0f, 0.0f, "%.2f");
	this->alpha = temp;

	static bool noratk_boxs_display = false;
	static bool noratk_selector = false;
	static bool noratkf_selector = false;
	static ImColor attack_boxs_color{ 255, 0, 0 };
	ctrl->box_color(u8"普通攻击框", &noratk_boxs_display, u8"普通攻击框颜色", &noratk_selector, &attack_boxs_color);
	attack_colors.noratk = attack_boxs_color;
	attack_colors.noratk_display = noratk_boxs_display;

	static bool floatk_boxs_display = false;
	static bool floatk_selector = false;
	static bool floatkf_selector = false;
	static ImColor floatk_boxs_color{ 128,160,255 };
	ctrl->box_color(u8"飞行道具攻击框", &floatk_boxs_display, u8"飞行道具攻击框颜色", &floatk_selector, &floatk_boxs_color);
	attack_colors.floatk = floatk_boxs_color;
	attack_colors.floatk_display = floatk_boxs_display;

	static bool thratk_boxs_display = false;
	static bool thratk_selector = false;
	static ImColor thratk_boxs_color{ 127,255,127 };
	ctrl->box_color(u8"投技框", &thratk_boxs_display, u8"投技框颜色", &thratk_selector, &thratk_boxs_color);
	attack_colors.thratk = thratk_boxs_color;
	attack_colors.thratk_display = thratk_boxs_display;

	static bool cgatk_boxs_display = false;
	static bool cgatk_selector = false;
	static ImColor cgatk_boxs_color{ 127,191,191 };
	ctrl->box_color(u8"引发防御框", &cgatk_boxs_display, u8"引发防御框颜色", &cgatk_selector, &cgatk_boxs_color);
	attack_colors.cgatk = cgatk_boxs_color;
	attack_colors.cgatk_display = cgatk_boxs_display;

	static bool cratk_boxs_display = false;
	static bool cratk_selector = false;
	static ImColor cratk_boxs_color = { 0,127,255 };
	ctrl->box_color(u8"触发攻击框", &cratk_boxs_display, u8"触发攻击框颜色", &cratk_selector, &cratk_boxs_color);
	attack_colors.cratk = cratk_boxs_color;
	attack_colors.cratk_display = cratk_boxs_display;

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
	ctrl->box_color(u8"防御框", &gurad_boxs_display, u8"防御框颜色", &cast_selector, &cast_boxs_color);
	affected_colors.gurad = gurad_boxs_color;
	affected_colors.gurad_display = gurad_boxs_display;

	static bool down_boxs_display = false;
	static bool down_selector = false;
	static ImColor down_boxs_color{ 128, 128, 255 };
	ctrl->box_color(u8"倒地受击框", &down_boxs_display, u8"倒地受击框颜色", &down_selector, &down_boxs_color);
	affected_colors.down = down_boxs_color;
	affected_colors.down_display = down_boxs_display;

	static bool ofo_boxs_display = false;
	static bool ofo_selector = false;
	static bool ofof_selector = false;
	static ImColor ofo_boxs_color{ 255, 127, 255 };
	ctrl->box_color(u8"抵消飞行道具框", &ofo_boxs_display, u8"抵消飞行道具框颜色", &ofo_selector, &ofo_boxs_color);
	affected_colors.ofo = ofo_boxs_color;
	affected_colors.ofo_display = ofo_boxs_display;

	static bool rfo_boxs_display = false;
	static bool rfo_selector = false;
	static bool rfof_selector = false;
	static ImColor rfo_boxs_color{ 64, 127, 127 };
	ctrl->box_color(u8"反弹飞行道具框", &rfo_boxs_display, u8"反弹飞行道具框颜色", &rfo_selector, &rfo_boxs_color);
	affected_colors.rfo = rfo_boxs_color;
	affected_colors.rfo_display = rfo_boxs_display;

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

	static bool fp_boxs_display = false;
	static ImColor fp_boxs_color{ 193,0,193 };
	static bool fp_color = false;
	ctrl->box_color(u8"对飞行道具当身框", &fp_boxs_display, u8"对飞行道具当身框颜色", &fp_color, &fp_boxs_color);
	affected_colors.flyobex = fp_boxs_color;
	affected_colors.flyobex_display = fp_boxs_display;

	static bool tp_boxs_display = false;
	static ImColor tp_boxs_color{ 193,255,193 };
	static bool tp_color = false;
	ctrl->box_color(u8"对投当身框", &tp_boxs_display, u8"对投当身框颜色", &tp_color, &tp_boxs_color);
	affected_colors.throwex = tp_boxs_color;
	affected_colors.throwex_display = tp_boxs_display;

	auto objects = *mapper->objs;

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

	Actions_Entry entry = p1->acts->entry[p1->action];
	for (int i = 0; i < entry.capacity && entry.actcs != nullptr && IsBadReadPtr(&entry.actcs[i], sizeof(Action_Collections)) == 0; i++) {
		Action_Collections 	actcs = entry.actcs[i];

		switch (actcs.types) {
		case ACT_Types::AttackBoxs: {
			attack_boxs(p1, actcs, attack_colors, display_p1);
			break;
		}
		case ACT_Types::BodyBoxs: {
			body_boxs(p1, actcs, body_boxs_color, display_p1 && body_boxs_display);
			break;
		}
		case ACT_Types::AffectedBoxs: {
			affected_boxs(p1, actcs, affected_colors, display_p1);
			break;
		}
		default: {
			break;
		}
		}
	}

	entry = p2->acts->entry[p2->action];
	for (int i = 0; i < entry.capacity && entry.actcs != nullptr && IsBadReadPtr(&entry.actcs[i], sizeof(Action_Collections)) == 0; i++) {
		Action_Collections 	actcs = entry.actcs[i];
		switch (actcs.types) {
		case ACT_Types::AttackBoxs: {
			attack_boxs(p2, actcs, attack_colors, display_p2);
			break;
		}
		case ACT_Types::BodyBoxs: {
			body_boxs(p2, actcs, body_boxs_color, display_p2 && body_boxs_display);
			break;
		}
		case ACT_Types::AffectedBoxs: {
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
		auto props_entry = props->acts->entry[props->action];
		for (int i = 0; i < props_entry.capacity; i++) {
			if (props->propsflag >> 8 & 1) {
				continue;
			}
			Action_Collections 	actcs = props_entry.actcs[i];
			switch (actcs.types) {
			case ACT_Types::AttackBoxs: {
				attack_boxs(props, actcs, attack_colors, display_p1);
				attack_boxs(props, actcs, attack_colors, display_p2);
				break;
			}
			case ACT_Types::AffectedBoxs: {
				affected_boxs(props, actcs, affected_colors, display_p1);
				affected_boxs(props, actcs, affected_colors, display_p2);
				break;
			}
			default: {
				break;
			}
			}
		}
	}

	auto b1 = objects->b1;
	while (b1 != nullptr) {
		if (b1->acts == nullptr) {
			break;
		}
		if (b1->acts->entry == nullptr) {
			break;
		}
		entry = b1->acts->entry[b1->action];
		for (int i = 0; i < entry.capacity && entry.actcs != nullptr && IsBadReadPtr(&entry.actcs[i], sizeof(Action_Collections)) == 0; i++) {
			Action_Collections actcs = entry.actcs[i];
			switch (actcs.types)
			{
			case ACT_Types::AttackBoxs: {
				attack_boxs(b1, actcs, attack_colors, display_p1);
				break;
				}
			case ACT_Types::AffectedBoxs: {
				affected_boxs(b1, actcs, affected_colors, display_p1);
				break;
			}
			default:
				break;
			}
		}
		break;
	}

	auto b2 = objects->b2;
	while (b2 != nullptr) {
		if (b2->acts == nullptr) {
			break;
		}
		if (b2->acts->entry == nullptr) {
			break;
		}
		entry = b2->acts->entry[b2->action];
		for (int i = 0; i < entry.capacity && entry.actcs != nullptr && IsBadReadPtr(&entry.actcs[i], sizeof(Action_Collections)) == 0; i++) {
			Action_Collections actcs = entry.actcs[i];
			switch (actcs.types)
			{
			case ACT_Types::AttackBoxs: {
				attack_boxs(b2, actcs, attack_colors, display_p1);
				break;
			}
			case ACT_Types::AffectedBoxs: {
				affected_boxs(b2, actcs, affected_colors, display_p2);
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	return true;
}

bool draws::drawbox(float x, float y, float w, float h, ImColor color, Action_Collections actcs, Player* player)
{
	//左上角
	FVector w1{};
	w1.X = x;
	w1.Z = y;
	FVector2D s1{};
	serivce->screen(w1, s1);

	//右下角
	FVector w3{};
	if (player->toward) {
		w3.X = x - w;
	}
	else{
		w3.X = x + w;
	}
	w3.Z = y - h;
	FVector2D s3{};
	serivce->screen(w3, s3);

	ImVec2 rect_min(s1.X, s1.Y);
	ImVec2 rect_max(s3.X, s3.Y);
	ImGui::GetForegroundDrawList()->AddRect(rect_min, rect_max, ImGui::ColorConvertFloat4ToU32(color.Value));

	color.Value.w = this->alpha;
	ImGui::GetForegroundDrawList()->AddRectFilled(rect_min, rect_max, ImGui::ColorConvertFloat4ToU32(color.Value));

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

	for (int i = 0; i < actcs.capacity; i++) {
		auto box = actcs.attack[i];
		auto px = player->x * 10;
		auto py = player->y * 10;
		auto x = box.x * 10;
		auto y = box.y * 10;
		auto w = box.w * 10;
		auto h = box.h * 10;
		ATK_Collections atkcs = player->atks->atkcs[box.atk];

		ImColor color{ 255,255,0 };

		if (box.frame != player->nowframe) {
			continue;
		}
		if ((box.flag & 1 && (player->flag2 & 6) == 0) || (box.flag & 2 && (player->flag2 & 4) == 0) || (box.flag & 4 && (player->flag2 & 2) == 0)) {
			continue;
		}
		if ((box.flag & 8) && (player->flag2 & 6) != 0 || (box.flag & 0x10 && (player->flag & 2) == 0) || (box.flag & 0x20 && (player->flag & 4) == 0)) {
			continue;
		}
		if ((box.flag & 0x40 && (player->flag & 8) == 0) || (box.flag & 0x80 && (player->flag & 0x10) == 0) || (box.flag & 0x100 && (player->flag3 >> 0x3E & 1) == 0)) {
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
		case Attack_Types::Crawl: {
			color = cs.cratk;
			display = cs.cratk_display;
			break;
		}
		default:
			display = false;
			break;
		}
		if (display) {
			if (player->toward) {
				drawbox(px - x + player->xoff * 10, py + y + player->yoff * 10, w, h, color, actcs, player);
			}
			else{
				drawbox(px + x + player->xoff * 10, py + y + player->yoff * 10, w, h, color, actcs, player);
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

	for (int i = 0; i < actcs.capacity; i++) {
		auto box = actcs.body[i];
		auto px = player->x * 10;
		auto py = player->y * 10;
		auto x = box.x * 10;
		auto y = box.y * 10;
		auto w = box.w * 10;
		auto h = box.h * 10;

		if (box.frame != player->nowframe) {
			continue;
		}
		if (box.isaddoffset <= 0) {
			px += player->xoff * 10;
			py += player->yoff * 10;
		}
		if (player->toward) {
			drawbox(px - x, py + y, w, h, color, actcs, player);
		}
		else {
			drawbox(px + x, py + y, w, h, color, actcs, player);
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

	for (int i = 0; i < actcs.capacity; i++) {
		auto box = actcs.affected[i];
		auto px = player->x * 10;
		auto py = player->y * 10;
		auto x = box.x * 10;
		auto y = box.y * 10;
		auto w = box.w * 10;
		auto h = box.h * 10;

		if (box.frame != player->nowframe) {
			continue;
		}
		if (box.isaddoffset <= 0) {
			px += player->xoff * 10;
			py += player->yoff * 10;
		}

		switch (box.types) {
		case Affected_Types::NormalHitBox: {
			if (player->avoidhit) {
				display = false;
			};
			color = cs.normal;
			display &= cs.normal_display;
			break;
		}
		case Affected_Types::CastBox: {
			if (player->avoidthrow) {
				display = false;
			};
			color = cs.cast;
			display &= cs.cast_display;
			break;
		}
		case Affected_Types::GuardBox: {
			color = cs.gurad;
			display &= cs.gurad_display;
			break;
		}
		case Affected_Types::DownHitBox: {
			if (player->avoidhit) {
				display = false;
			};
			color = cs.down;
			display &= cs.down_display;
			break;
		}
		case Affected_Types::OFOB: {
			color = cs.ofo;
			display &= cs.ofo_display;
			break;
		}
		case Affected_Types::RFOB: {
			color = cs.rfo;
			display &= cs.rfo_display;
			break;
		}
		case Affected_Types::TyrantsBox: {
			color = cs.tyants;
			display &= cs.tyants_display;
			break;
		}
		case Affected_Types::GuardPointBox: {
			color = cs.guradex;
			display &= cs.guradex_display;
			break;
		}
		case Affected_Types::FlyObPointBox: {
			color = cs.flyobex;
			display &= cs.flyobex_display;
			break;
		}
		case Affected_Types::ThrowPointBox: {
			color = cs.throwex;
			display &= cs.throwex_display;
			break;
		}
		default: {
			display = false;
			break;
		}
		}

		if (display) {
			if (player->toward) {
				drawbox(px - x, py + y, w, h, color, actcs, player);
			}
			else{
				drawbox(px + x, y + py, w, h, color, actcs, player);
			}
		}
	}
	return true;
}