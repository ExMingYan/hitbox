#include "box.h"

namespace hitboxes {
	std::vector<BoxToDraw> box::boxesToDraw;

	void box::DrawBoxes() {
		if (!boxesToDraw.empty())
		{
			for (const auto& box : boxesToDraw) {
				control::draw_box(box.min, box.max, box.alpha, box.thickness, box.color);
			}
			boxesToDraw.clear();
		}
	}

	bool box::foreground(range& r, ImColor color)
	{
		runable* invoke = runable::instance();

		FVector w1{ r.left, 0.0f, r.top };
		FVector2D s1{};
		invoke->screen(w1, s1);

		FVector w3{ r.right, 0.0f, r.bottom };
		FVector2D s3{};
		invoke->screen(w3, s3);

		ImVec2 rect_min(s1.X, s1.Y);
		ImVec2 rect_max(s3.X, s3.Y);

		boxesToDraw.push_back(BoxToDraw{ rect_min, rect_max, color, alpha, thickness });
		return true;
	}

	bool attack::resolve(object* obj, actions_entry entry, ActionLine pLine, description desc) {
		for (uint32_t i = 0; i < pLine.capacity; i++) {
			ActionStructure action = pLine.actions[i];
			if (action.frame != obj->now)
				continue;

			Attack box = action.attack;
			attack_collections atccs = obj->atcs->atccs[box.DataID];
			if (desc.types.attack != atccs.types)
				continue;

			range r(obj, box.rect);
			foreground(r, desc.color);
		}
		return true;
	}

	bool body::resolve(object* obj, actions_entry entry, ActionLine pLine, description desc) {
		for (uint32_t i = 0; i < pLine.capacity; i++) {
			ActionStructure action = pLine.actions[i];
			if (action.frame != obj->now)
				continue;

			range r(obj, action.collision.rect);
			foreground(r, desc.color);
		}
		return true;
	}

	bool hit::resolve(object* obj, actions_entry entry, ActionLine pLine, description desc) {
		for (uint32_t i = 0; i < pLine.capacity; i++) {
			ActionStructure action = pLine.actions[i];
			Collision box = action.collision;
			if (desc.types.collision != box.Type || action.frame != obj->now)
				continue;

			if (box.Type == CollisionTypes::normal)
			{
				if (entry.CategoryID == CategoryID::OnAir && entry.SubCategoryID == SubCategoryID::BeAttack && obj->onairhitframe == 0)
					continue;
				if (obj->avoidhitframe)
					continue;
			}

			if (box.Type == CollisionTypes::ground && obj->fallenhitframe == 0)
				continue;

			if (box.Type == CollisionTypes::capture && obj->avoidthrowframe)
				continue;

			range r(obj, box.rect);
			foreground(r, desc.color);
		}
		return true;
	}

	bool attack::propresolve(projectile* obj, actions_entry entry, ActionLine pLine, description desc) {
		for (uint32_t i = 0; i < pLine.capacity; i++) {
			ActionStructure action = pLine.actions[i];
			if (action.frame != obj->now)
				continue;

			Attack box = action.attack;
			attack_collections atccs = obj->atcs->atccs[box.DataID];
			if (desc.types.attack != atccs.types)
				continue;

			range r(obj, box.rect);
			foreground(r, desc.color);
		}
		return true;
	}

	bool body::propresolve(projectile* obj, actions_entry entry, ActionLine pLine, description desc) {
		for (uint32_t i = 0; i < pLine.capacity; i++) {
			ActionStructure action = pLine.actions[i];
			if (action.frame != obj->now)
				continue;

			range r(obj, action.collision.rect);
			foreground(r, desc.color);
		}
		return true;
	}

	bool hit::propresolve(projectile* obj, actions_entry entry, ActionLine pLine, description desc) {
		for (uint32_t i = 0; i < pLine.capacity; i++) {
			ActionStructure action = pLine.actions[i];
			Collision box = action.collision;
			if (desc.types.collision != box.Type || action.frame != obj->now)
				continue;

			range r(obj, box.rect);
			foreground(r, desc.color);
		}
		return true;
	}
};
