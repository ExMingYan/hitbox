#include "object.h"
#include "props.h"

warpper::warpper() {}

warpper::warpper(AttackTypes types) :attack(types) {
	collision = CollisionTypes::none;
};

warpper::warpper(CollisionTypes types) :collision(types) {
	attack = AttackTypes::none;
};

bool warpper::operator== (warpper b) {
	if (attack == b.attack)
		return true;
	else if (collision == b.collision)
		return true;
	else
		return false;
}

bool warpper::operator!= (warpper b) {
	if (attack != b.attack)
		return true;
	else if (collision != b.collision)
		return true;
	else
		return false;
}

range::range(object* obj, HitRect rect)
{
	if (obj->left()) {
		left = (obj->x + rect.x + obj->xoff) * 10;
		right = left + rect.w * 10;
	}
	else {
		left = (obj->x - rect.x + obj->xoff) * 10;
		right = left - rect.w * 10;
	}
	top = (obj->y + rect.y + obj->yoff) * 10;
	bottom = top - rect.h * 10;
}

range::range(projectile* obj, HitRect rect)
{
	if (obj->left()) {
		left = (obj->x + rect.x + obj->xoff) * 10;
		right = left + rect.w * 10;
	}
	else {
		left = (obj->x - rect.x + obj->xoff) * 10;
		right = left - rect.w * 10;
	}
	top = (obj->y + rect.y + obj->yoff) * 10;
	bottom = top - rect.h * 10;
}
