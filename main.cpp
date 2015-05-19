#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "Core\Shader_Loader.h"
#include "Core\GameModels.h"
using namespace Core;

Models::GameModels* gameModels;
GLuint program;

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.3,0.3, 1.0); 

	glBindVertexArray(gameModels->GetModel("triangle1"));
	//use the created program
	glUseProgram(program);

	//draw 3 vertices as triangles.
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}

void closeCallback()
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init()
{
	glEnable(GL_DEPTH_TEST);

	gameModels = new Models::GameModels();
	gameModels->CreateTriangleModel("triangle1");

	//load and compile shaders
	Core::Shader_Loader shaderLoader;
	program = shaderLoader.CreateProgram("Shaders\\Vertex_Shader.glsl",
		"Shaders\\Fragment_Shader.glsl");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("First Triangle");

	glewInit();
	Init();

	//register callbacks
	glutDisplayFunc(renderScene);
	glutCloseFunc(closeCallback);
	glutMainLoop();

	delete gameModels;
	glDeleteProgram(program);
	return 0;
}