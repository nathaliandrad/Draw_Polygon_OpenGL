#pragma once

#include "game_object.h"

class Polygon : public Game_Object
{
public:
	Polygon(const char* id);
	~Polygon();


	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;

private:
	double _total_time_s;
};

