#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

namespace KlaoudeEngine
{
	TextureCache::TextureCache()
	{
	}

	TextureCache::~TextureCache()
	{
	}

	GLTexture TextureCache::getTexture(std::string texturePath)
	{
		auto mit = m_textureMap.find(texturePath);

		if (mit == m_textureMap.end())
		{
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);

			m_textureMap.insert(make_pair(texturePath, newTexture));

			return newTexture;
		}

		return mit->second;
	}
}