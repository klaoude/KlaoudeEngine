#pragma once
#include <vector>

namespace KlaoudeEngine
{
	class SpriteBatch;
	class ParticleBatch2D;

	class ParticleEngine2D
	{
	public:
		ParticleEngine2D();
		~ParticleEngine2D();

		void addParticleBatch(ParticleBatch2D* particleBatch);

		void update(float delatTime);

		void draw(SpriteBatch* spriteBatch);
	private:
		std::vector<ParticleBatch2D*> m_batches;
	};
}
