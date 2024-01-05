#include "services.h"
#include "mappers.h"
#include "searcher.h"
#include "signatures.hpp"

bool services::initliaze()
{
	searcher* instance = searcher::instance();
	this->screen_ptr = instance->search<bool(*)(void* Player, const FVector & WorldPosition, FVector2D & ScreenPosition, bool bPlayerViewportRelative)>(".text", signatures::screen);
	if (screen_ptr == nullptr) {
		return false;
	}

	mappers* mapping = mappers::instance();
	this->uworld = mapping->uworld;
	if (this->uworld == nullptr) {
		return false;
	}

	return true;
}

bool services::screen(const FVector& WorldPosition, FVector2D& ScreenPosition)
{
	if (uworld->OwningGameInstance == nullptr) {
		return false;
	}
	if (uworld->OwningGameInstance->LocalPlayers.ArrayNum == 0) {
		return false;
	}
	if (uworld->OwningGameInstance->LocalPlayers.AllocatorInstance == nullptr) {
		return false;
	}
	if (uworld->OwningGameInstance->LocalPlayers.AllocatorInstance[0]->PlayerController == nullptr) {
		return false;
	}
	return screen_ptr(uworld->OwningGameInstance->LocalPlayers.AllocatorInstance[0]->PlayerController, WorldPosition, ScreenPosition, false);
}