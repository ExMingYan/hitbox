#include "renderer.h"

bool renderer::render() {
	hitboxes::dispatcher dispatch;
	dispatch.dispatch();
	hitboxes::box::DrawBoxes();
	return true;
}