#include "RessourceManager.h"

namespace KlaoudeEngine
{
	TextureCache RessourceManager::m_textureCache;

	GLTexture RessourceManager::getTexture(std::string texturePath)
	{
		return m_textureCache.getTexture(texturePath);
	}
}