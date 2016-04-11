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

		void linkShaders();

		void addAttribute(const std::string& attributeName);

		GLint getUniformLocation(const std::string& uniformName);

		void use();
		void unUse();

	private:
		int m_numAttributes;

		void compileShader(const std::string& filePath, GLuint id);

		GLuint m_programID;

		GLuint m_vertexShaderID;
		GLuint m_fragmentShaderID;
	};

}