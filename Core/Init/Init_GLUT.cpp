#include "Init_GLUT.h"

using namespace Core::Init;

void Init_GLUT::init(const Core::WindowInfo& windowInfo,
				 	 const Core::ContextInfo& contextInfo,
					 const Core::FramebufferInfo& framebufferInfo)
{
	int fakeargc = 1;
	char *fakeargv[] = { "fake", NULL };
	glutInit(&fakeargc, fakeargv);

	if (contextInfo.core)
	{
		glutInitContextVersion(contextInfo.major_version,
							   contextInfo.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	//functions we are moving out of the old main.cpp
	glutInitDisplayMode(framebufferInfo.flags);
	glutInitWindowPosition(windowInfo.position_x,
						   windowInfo.position_y);
	glutInitWindowSize(windowInfo.width, windowInfo.height);

	glutCreateWindow(windowInfo.name.c_str());

	std::cout << "GLUT:initialized" << std::endl;

	//callbacks used for rendering
	glutIdleFunc(idleCallback);
	glutCloseFunc(closeCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);

	//init GLEW, could be called in main.cpp but handling here.
	Init::Init_GLEW::Init();

	//cleaning up
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
				  GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//our method to display information.
	printOpenGLInfo(windowInfo, contextInfo);
}

void Init_GLUT::run()
{
	std::cout << "GLUT:\t Start Running" << std::endl;
	glutMainLoop();
}

void Init_GLUT::close()
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init_GLUT::idleCallback(void)
{
	//does nothing just issues output again
	glutPostRedisplay();
}

void Init_GLUT::displayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1);
	glutSwapBuffers();
}

void Init_GLUT::reshapeCallback(int width, int height)
{

}

void Init_GLUT::closeCallback()
{
	close();
}

void Init_GLUT::enterFullscreen()
{
	glutFullScreen();
}

void Init_GLUT::exitFullscreen()
{
	glutLeaveFullScreen();
}

void Init_GLUT::printOpenGLInfo(const Core::WindowInfo& windowInfo,
								const Core::ContextInfo& contextInfo)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "*******************************************************" << std::endl;
	std::cout << "GLUT:Initialized" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGL version: " << version << std::endl;
}
