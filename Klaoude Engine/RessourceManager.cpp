#include "RessourceManager.h"

namespace KlaoudeEngine
{
	TextureCache RessourceManager::_textureCache;

	GLTexture RessourceManager::getTexture(std::string texturePath)
	{
		return _textureCache.getTexture(texturePath);
	}
}