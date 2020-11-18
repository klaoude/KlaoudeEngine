#pragma once
#include "TextureCache.h"

#include <string>
namespace KlaoudeEngine
{
	class RessourceManager
	{
	public:
		static GLTexture getTexture(std::string texturePath);


	private:
		static TextureCache m_textureCache;
	};
}