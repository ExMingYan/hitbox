#pragma once
#include <mutex>
#include "singleton.hpp"
#include "structs/objects.h"
#include "unreal_engine/World.h"

class mappers : public singleton<mappers>
{
public:
	UWorld** uworld;
	Objects** objs;

public:
	bool initliaze();
};
