#include "dispatcher.h"

namespace hitboxes {
	context contexts[] = {
		{act_types::body, new body},
		{act_types::affected, new affected},
		{act_types::attack, new attack},
	};

	bool dispatcher::dispatch() {
		auto mapping = mapper::instance();
		if (!mapping->checks()) {
			return false;
		}

		auto objs = *mapping->objs;
		auto p1 = objs->p1;
		auto p2 = objs->p2;

		for (description& desc : descriptions) {
			if (!desc.activity)
				continue;

			if (configurs::dp1) {
				actions_entry entry = p1->acts->entry[p1->number];
				for (int i = 0; i < entry.capacity && entry.actcs != nullptr && IsBadReadPtr(&entry.actcs[i], sizeof(actions_entry)) == 0; i++) {
					action_collections actcs = entry.actcs[i];
					if (actcs.types != desc.action)
						continue;

					int index = (int)actcs.types - 3;
					if (index < 0 or index > 3)
						continue;

					hitboxes::box* b = contexts[index].instance;
					b->alpha = configurs::alpha;
					b->thickness = configurs::thickness;
					b->resolve(p1, entry, actcs, desc);
				}
			}

			if (configurs::dp2) {
				actions_entry entry = p2->acts->entry[p2->number];
				for (int i = 0; i < entry.capacity && entry.actcs != nullptr && IsBadReadPtr(&entry.actcs[i], sizeof(actions_entry)) == 0; i++) {
					action_collections actcs = entry.actcs[i];
					if (actcs.types != desc.action)
						continue;

					int index = (int)actcs.types - 3;
					if (index < 0 or index > 3)
						continue;

					hitboxes::box* b = contexts[index].instance;
					b->alpha = configurs::alpha;
					b->thickness = configurs::thickness;
					b->resolve(p2, entry, actcs, desc);
				}
			}

			auto list = objs->props_list->list;
			for (; list != nullptr; list = list->next) {
				projectile* props = list->props;
				actions_entry props_entry = props->acts->entry[props->number];
				if (props->isInvalidate)
					continue;
				for (int i = 0; i < props_entry.capacity; i++) {
					action_collections actcs = props_entry.actcs[i];
					if (actcs.types != desc.action)
						continue;

					int index = (int)actcs.types - 3;
					if (index < 0 or index > 3)
						continue;

					if (configurs::dp1) {
						hitboxes::box* b = contexts[index].instance;
						b->alpha = configurs::alpha;
						b->thickness = configurs::thickness;
						b->propresolve(props, props_entry, actcs, desc);
					}

					if (configurs::dp2) {
						hitboxes::box* b = contexts[index].instance;
						b->alpha = configurs::alpha;
						b->thickness = configurs::thickness;
						b->propresolve(props, props_entry, actcs, desc);
					}
				}
			}
		}
		return true;
	}
}