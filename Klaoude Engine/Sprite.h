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
		float _x;
		float _y;
		float _witdh;
		float _height;
		GLuint _vboID;
		GLTexture _texture;
	};
}