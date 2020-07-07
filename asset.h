#pragma once

// NEXT: forward declarations.

class Asset
{
public:
	Asset(const char* id);
	~Asset();

	const char* id() const;

private:
	const char* _id;
};