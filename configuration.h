#pragma once

struct Configuration
{
	//outline objects
	bool render_wireframe = false;
	//fill objects
	//bool render_wireframe = false;

	int screen_width      = 1600;
	int screen_height     = 800;

	//camera zoom
	int y_units = 3;
};