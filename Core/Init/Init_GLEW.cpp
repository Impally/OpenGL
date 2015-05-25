#include "Init_GLEW.h"

using namespace Core;
using namespace Core::Init;

void Init_GLEW::Init()
{
	glewExperimental = true;
	if (glewInit() == GLEW_OK)
	{
		std::cout << "GLEW: Initialize" << std::endl;
	}

	if (glewIsSupported("GL_VERSION_4_2"))
	{
		std::cout << "GLEW GL_VERSION_4_2 is 4.2\n";
	}
	else
	{
		std::cout << "GLEW GL_VERSION_4_2 is not supported\n";
	}
}