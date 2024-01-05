#include "control.h"

control::control()
{
}

bool control::color_selector(const char* label, ImColor* color, bool* show)
{
	if (ImGui::Button(label)) {
		*show = !(*show);
	}

	if (*show) {
		ImGui::Begin("color", show);
		ImGui::ColorPicker3("color selector", (float*)color);
		ImGui::End();
	}
	return false;
}