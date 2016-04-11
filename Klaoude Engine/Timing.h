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

		float _maxFPS;
		float _fps;
		float _frameTime;
		unsigned int _startTicks;		
	};
}