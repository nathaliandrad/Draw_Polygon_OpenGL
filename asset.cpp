#include "asset.h"


Asset::Asset(const char* id)
	: _id(id)
{
}
Asset::~Asset()
{
}

const char* Asset::id() const
{
	return _id;
}