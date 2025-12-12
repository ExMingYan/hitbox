#include "configuration.h"
#include "utils/inirw.h"

namespace configurs {
	HWND unrealwindow = nullptr;
	ImFont* font_ali = nullptr;
	ImFont* icon_awesmoe = nullptr;
	ImFont* icon_brands = nullptr;
	bool dp1 = false;
	bool dp2 = false;
	float alpha = 0.25f;
	float thickness = 1.00f;
	const char* alphaname = u8"透明度";
	const char* thicknessname = u8"粗细";

	void GetConfigs()
	{
		if (!ini_read_float(alphaname, alpha))
			ini_write_float(alphaname, alpha);
		if (!ini_read_float(thicknessname, thickness))
			ini_write_float(thicknessname, thickness);
	}
}
