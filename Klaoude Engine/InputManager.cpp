#include "InputManager.h"

namespace KlaoudeEngine
{
	InputManager::InputManager() : _mouseCoords(0.0f)
	{

	}

	InputManager::~InputManager()
	{

	}

	void InputManager::update()
	{
		for (auto& it : _keyMap)
			_previusKeyMap[it.first] = it.second;
	}

	void InputManager::pressKey(unsigned int keyID)
	{
		_keyMap[keyID] = true;
	}

	void InputManager::releaseKey(unsigned int keyID)
	{
		_keyMap[keyID] = false;
	}

	void InputManager::setMouseCoords(float x, float y)
	{
		_mouseCoords.x = x;
		_mouseCoords.y = y;
	}

	bool InputManager::isKeyDown(unsigned int keyID)
	{
		auto it = _keyMap.find(keyID);
		return it != _keyMap.end() ? it->second : false;
	}

	bool InputManager::isKeyPressed(unsigned int keyID)
	{
		
	}
}