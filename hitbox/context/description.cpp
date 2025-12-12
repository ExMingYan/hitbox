#include "description.h"
#include "utils/inirw.h"

std::vector<description> descriptions = {
	{u8"攻击框",			false, false, { 200, 100, 100 },	ActionLineID::Attack,	AttackTypes::normal,			},
	{u8"投技框",			false, false, { 127, 191, 191 },	ActionLineID::Attack,	AttackTypes::grasp,			},
	{u8"飞行道具",		false, false, { 127, 255, 127 },	ActionLineID::Attack,	AttackTypes::projectile,		},
	{u8"防御框",			false, false, { 0, 255, 0 },		ActionLineID::Hit, CollisionTypes::guard,			},
	{u8"霸体框",			false, false, { 64, 127, 127 },		ActionLineID::Hit, CollisionTypes::invulnerability,},
	{u8"当身框",			false, false, { 0, 0, 255 },		ActionLineID::Hit, CollisionTypes::parries,		},
	{u8"对投当身框",		false, false, { 139, 0, 255 },		ActionLineID::Hit, CollisionTypes::parriesex,		},
	{u8"身位框",			false, false, { 255, 165, 0  },		ActionLineID::Body,		CollisionTypes::body,				},
	{u8"受击框",			false, false, { 255, 255, 0 },		ActionLineID::Hit, CollisionTypes::normal,			},
	{u8"被投框",			false, false, { 127, 255, 255 },	ActionLineID::Hit, CollisionTypes::capture,		},
	{u8"追加框",			false, false, { 0, 255, 0 },		ActionLineID::Hit, CollisionTypes::ground,			},
	{u8"反弹飞行道具框",	false, false, { 255, 127, 255 },	ActionLineID::Hit, CollisionTypes::reflects,		},
	{u8"抵消飞行道具框",	false, false, { 128, 128, 255 },	ActionLineID::Hit, CollisionTypes::negative,		},
};

void reload_description_colors() {
	auto colors = ini_read_colors(descriptions, "Colors");
	if (!colors.empty()) {
		const int n = static_cast<int>(std::min<std::size_t>(colors.size(), descriptions.size()));
		for (int i = 0; i < n; ++i) {
			const auto& c = colors[i];
			descriptions[i].color = ImColor(c[0], c[1], c[2]);
		}
	}
	else {
		std::vector<Rgb> defaults;
		defaults.reserve(descriptions.size());
		for (auto& d : descriptions) {
			const ImVec4& v = d.color.Value;
			defaults.push_back({
				static_cast<std::uint8_t>(v.x * 255.0f + 0.5f),
				static_cast<std::uint8_t>(v.y * 255.0f + 0.5f),
				static_cast<std::uint8_t>(v.z * 255.0f + 0.5f)
				});
		}
		ini_write_colors(defaults, descriptions, "Colors");
	}
}
