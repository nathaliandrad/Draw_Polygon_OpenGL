#include "polygon_mesh.h"

Polygon_Mesh::Polygon_Mesh()
	: Mesh("Mesh.Polygon")
{
	
	_verticies.insert(_verticies.end(), { -0.8f, -0.5f });  
	_verticies.insert(_verticies.end(), { -0.6f, 0.3f }); 
	_verticies.insert(_verticies.end(), { 0.0f, -0.5f });
	
	_verticies.insert(_verticies.end(), { -0.6f, 0.3f });
	_verticies.insert(_verticies.end(), { 0.0f, 0.6f });
	_verticies.insert(_verticies.end(), { 0.0f, -0.5f });

	_verticies.insert(_verticies.end(), { 0.6f, 0.3f }); 
	_verticies.insert(_verticies.end(), { 0.0f, 0.6f }); 
	_verticies.insert(_verticies.end(), { 0.0f, -0.5f });

	_verticies.insert(_verticies.end(), { 0.8f, -0.5f });
	_verticies.insert(_verticies.end(), { 0.6f, 0.3f });
	_verticies.insert(_verticies.end(), { 0.0f, -0.5f });



}
Polygon_Mesh::~Polygon_Mesh()
{
}