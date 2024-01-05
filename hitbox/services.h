#pragma once
#include "singleton.hpp"
#include "unreal_engine/World.h"

class services : public singleton<services>
{
private:
	bool(*screen_ptr)(void* Player, const FVector& WorldPosition, FVector2D& ScreenPosition, bool bPlayerViewportRelative);
	UWorld* uworld;

public:
	bool initliaze();

	bool screen(const FVector& WorldPosition, FVector2D& ScreenPosition);
};
