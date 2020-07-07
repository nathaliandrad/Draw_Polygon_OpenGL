#pragma once

#include "game_object.h"

class Background : public Game_Object
{
public:
	Background(const char* id);
	~Background();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
};