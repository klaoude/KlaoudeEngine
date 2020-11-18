#include "InputManager.h"

namespace KlaoudeEngine
{
	InputManager::InputManager() : m_mouseCoords(0.0f)
	{

	}

	InputManager::~InputManager()
	{

	}

	void InputManager::update()
	{
		for (auto& it : m_keyMap)
			m_previusKeyMap[it.first] = it.second;
	}

	void InputManager::pressKey(unsigned int keyID)
	{
		m_keyMap[keyID] = true;
	}

	void InputManager::releaseKey(unsigned int keyID)
	{
		m_keyMap[keyID] = false;
	}

	void InputManager::setMouseCoords(float x, float y)
	{
		m_mouseCoords.x = x;
		m_mouseCoords.y = y;
	}

	bool InputManager::isKeyDown(unsigned int keyID)
	{
		auto it = m_keyMap.find(keyID);
		return it != m_keyMap.end() ? it->second : false;
	}

	bool InputManager::isKeyPressed(unsigned int keyID)
	{
		return isKeyDown(keyID) && !wasKeyDown(keyID);
	}

	bool InputManager::wasKeyDown(unsigned int keyID)
	{
		auto it = m_previusKeyMap.find(keyID);
		return it != m_previusKeyMap.end() ? it->second : false;
	}
}