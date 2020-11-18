#pragma once

namespace KlaoudeEngine
{
	class FpsLimiter {
	public:
		FpsLimiter();
		void init(float maxFPS = 60.0f);

		void setMaxFPS(float maxFPS);

		void begin();

		float end();
	private:
		void calculateFPS();

		float m_maxFPS;
		float m_fps;
		float m_frameTime;
		unsigned int m_startTicks;		
	};
}