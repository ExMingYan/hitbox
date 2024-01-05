#include "mappers.h"
#include "searcher.h"
#include "signatures.hpp"

bool mappers::initliaze()
{
	searcher* instance = searcher::instance();

	this->uworld = *reinterpret_cast<UWorld**>(instance->transform(instance->search(".text", signatures::uworld)));
	if (this->uworld == nullptr) {
		return false;
	}

	this->objects = reinterpret_cast<Objects**>(instance->transform(instance->search(".text", signatures::objects)));
	if (this->objects == nullptr) {
		return false;
	}

	return true;
}