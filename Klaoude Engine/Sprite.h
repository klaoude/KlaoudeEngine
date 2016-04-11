#pragma once
#include <glew\glew.h>
#include "GLTexture.h"
#include "RessourceManager.h"

#include <string>

namespace KlaoudeEngine
{
	class Sprite
	{
	public:
		Sprite();
		~Sprite();

		void init(float x, float y, float width, float height, std::string texturePath);

		void draw();

	private:
		float m_x;
		float m_y;
		float m_witdh;
		float m_height;
		GLuint m_vboID;
		GLTexture m_texture;
	};
}