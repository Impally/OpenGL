#pragma once
#include "Core\Init\Init_GLUT.h"
using namespace Core;
using namespace Init;

int main(int argc, char **argv)
{
	WindowInfo window(std::string("in2gpu OpenGL Beginner Tutorial "),
						   400, 200,
						   800, 600,
						   true);
	ContextInfo context(4, 2, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	Init_GLUT::init(window, context, frameBufferInfo);

	Init_GLUT::run();
	return 0;
}