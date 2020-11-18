#include "Camera2D.h"

namespace KlaoudeEngine
{
	Camera2D::Camera2D() : m_position(0.0f, 0.0f),
		m_cameraMatrix(1.0f),
		m_orthoMatrix(1.0f),
		m_scale(1.0f),
		m_needsMatrixUpdate(true),
		m_screenWidth(500),
		m_screenHeight(500)
	{}

	Camera2D::~Camera2D()
	{
	}

	void Camera2D::init(int screenWidth, int screenHeight)
	{
		m_screenWidth = screenWidth;
		m_screenHeight = screenHeight;
		m_orthoMatrix = glm::ortho(0.0f, (float)m_screenWidth, 0.0f, (float)m_screenHeight);
	}

	void Camera2D::update()
	{
		if (m_needsMatrixUpdate)
		{
			glm::vec3 translate(-m_position.x + m_screenWidth / 2, -m_position.y + m_screenHeight / 2, 0.0f);
			m_cameraMatrix = glm::translate(m_orthoMatrix, translate);
			glm::vec3 scale(m_scale, m_scale, 0.0f);
			m_cameraMatrix = glm::scale(m_cameraMatrix, scale);
			m_needsMatrixUpdate = false;
		}
	}

	glm::vec2 Camera2D::convertScreenToWorld(glm::vec2 screenCoords)
	{
		screenCoords.y = m_screenHeight - screenCoords.y;

		screenCoords -= glm::vec2(m_screenWidth / 2, m_screenHeight / 2);
		screenCoords /= m_scale;

		screenCoords += m_position;
		return screenCoords;
	}

	bool Camera2D::isBoxInView(const glm::vec2 & position, const glm::vec2 dim)
	{
		glm::vec2 scaledScreenDim = glm::vec2(m_screenWidth, m_screenHeight) / m_scale;

		const float MIN_DIST_X = dim.x / 2.0f + scaledScreenDim.x / 2.0f;
		const float MIN_DIST_Y = dim.y / 2.0f + scaledScreenDim.y / 2.0f;

		glm::vec2 centerPos = position + dim / 2.0f;
		glm::vec2 centerCamPos = m_position;
		glm::vec2 distVec = centerPos - centerCamPos;

		float xdepth = MIN_DIST_X - abs(distVec.x);
		float ydepth = MIN_DIST_Y - abs(distVec.y);

		return xdepth > 0 && ydepth > 0;
	}
}