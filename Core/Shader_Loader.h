#pragma once

#include "../Dependencies/glew.h"
#include "../Dependencies/freeglut.h"
#include <iostream>

namespace Core
{
	class Shader_Loader
	{
	private:

		std::string ReadShader(char *filename);
		GLuint CreateShader(GLenum shaderType, std::string source, char* ShaderName);

	public:

		Shader_Loader(void);
		~Shader_Loader(void);
		GLuint CreateProgram(char* VertexShaderFilename, char* FragmentShaderFilename);

	};

}