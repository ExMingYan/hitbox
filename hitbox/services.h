#pragma once
#include "singleton.hpp"
#include "mappers.h"
#include "unreal_engine/World.h"

class services : public singleton<services>
{
private:
	mappers* mapping;
	UWorld* uworld;
	bool(*screen_ptr)(void* Player, const FVector& WorldPosition, FVector2D& ScreenPosition, bool bPlayerViewportRelative);

public:
	bool initliaze(mappers* mapping);

	bool screen(const FVector& WorldPosition, FVector2D& ScreenPosition);
};
