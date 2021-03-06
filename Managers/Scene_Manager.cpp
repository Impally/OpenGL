#include "Scene_Manager.h"
using namespace Managers;

Scene_Manager::Scene_Manager()
{
	glEnable(GL_DEPTH_TEST);

	shader_manager = new Shader_Manager();
	shader_manager->CreateProgram("colorShader", 
								  "Shaders\\Vertex_Shader.glsl",
								  "Shaders\\Fragment_Shader.glsl");
	models_manager = new Models_Manager();
}

Scene_Manager::~Scene_Manager()
{
	delete shader_manager;
	delete models_manager;
}

void Scene_Manager::notifyBeginFrame()
{
	//Updates moving objects for future use with models.
	models_manager->Update();
}

void Scene_Manager::notifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	models_manager->Draw();
}

void Scene_Manager::notifyEndFrame()
{
	//placeholder comment.
}

void Scene_Manager::notifyReshape(int width, int height,
								  int previous_width,
								  int previous_height)
{
	//placeholder comment.
}

