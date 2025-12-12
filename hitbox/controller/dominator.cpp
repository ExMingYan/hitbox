#include "dominator.h"

bool reloadcolors = true;

bool dominator::window()
{
	view::compoment hb;
	hb.ins("settings", [&] {
		control::trigger("p1", &configurs::dp1);
		control::trigger("p2", &configurs::dp2);

		configurs::GetConfigs();

		control::textfloatinput(configurs::alphaname, &configurs::alpha);
		control::textfloatinput(configurs::thicknessname, &configurs::thickness);
		});

	hb.ins("hitboxes", [&] {
		if (reloadcolors)
		{
			reload_description_colors();
			reloadcolors = false;
		}
		for (int i = 0; i < descriptions.size(); i++) {
			description* desc = &descriptions[i];
			control::label(i + 1, desc->title, &desc->open, &desc->activity, &desc->color);
		}
		});

	view::decoration decor;
	decor.insert(ICON_FA_EXPAND, hb);
	decor.icon(configurs::icon_awesmoe);
	decor.logo(configurs::icon_brands, ICON_FA_GITHUB);
	decor.show("HOTBOX");
	return true;
}