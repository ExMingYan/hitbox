#ifndef HITBOXES_H
#define HITBOXES_H

#include <vector>

#include "view/control.h"
#include "service/runable.h"
#include "context/description.h"

struct BoxToDraw {
	ImVec2 min;
	ImVec2 max;
	ImColor color;
	float alpha;
	float thickness;
};

namespace hitboxes {
	class box {
	public:
		float thickness;
		float alpha;
		static std::vector<BoxToDraw> boxesToDraw;
		static void DrawBoxes();
	public:
		bool foreground(range& r, ImColor color);

		virtual bool resolve(object* obj, actions_entry entry, ActionLine actcs, description desc) = 0;
		virtual bool propresolve(projectile* prop, actions_entry entry, ActionLine actcs, description desc) = 0;
	};

	class attack :public box {
	public:
		bool resolve(object* obj, actions_entry entry, ActionLine actcs, description desc) override;
		bool propresolve(projectile* prop, actions_entry entry, ActionLine actcs, description desc) override;
	};

	class body : public box {
	public:
		bool resolve(object* obj, actions_entry entry, ActionLine actcs, description desc) override;
		bool propresolve(projectile* prop, actions_entry entry, ActionLine actcs, description desc) override;
	};

	class hit : public box {
	public:
		bool resolve(object* obj, actions_entry entry, ActionLine actcs, description desc) override;
		bool propresolve(projectile* prop, actions_entry entry, ActionLine actcs, description desc) override;
	};
};

#endif
