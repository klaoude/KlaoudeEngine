#pragma once

#include "GLTexture.h"

#include <string>

namespace KlaoudeEngine 
{
	class ImageLoader
	{
	public:
		static GLTexture loadPNG(std::string filePath);
	};
}