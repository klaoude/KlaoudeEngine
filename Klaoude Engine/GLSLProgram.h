#pragma once

#include <string>
#include <glew\glew.h>

namespace KlaoudeEngine {

	class GLSLProgram
	{
	public:
		GLSLProgram();
		~GLSLProgram();

		void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragementShaderFilePath);

		void compileShadersFromSource(const char* vertexSource, const char* fragmentSource);

		void linkShaders();

		void addAttribute(const std::string& attributeName);

		GLint getUniformLocation(const std::string& uniformName);

		void use();
		void unUse();

		void dispose();
	private:
		int m_numAttributes;

		void compileShader(const char* source, const std::string& name, GLuint id);

		GLuint m_programID;

		GLuint m_vertexShaderID;
		GLuint m_fragmentShaderID;
	};

}