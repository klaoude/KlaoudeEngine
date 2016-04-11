#include "AudioEngine.h"
#include "Errors.h"

namespace KlaoudeEngine
{
	void SoundEffect::play(int loops)
	{
		if(Mix_PlayChannel(-1, m_chunk, loops) == -1)
			fatalError("Mix_PlayChannel error: " + std::string(Mix_GetError()));
	}

	void Music::play(int loops)
	{
		if(Mix_PlayMusic(m_music, loops) == -1)
			fatalError("Mix_PlayMusic error: " + std::string(Mix_GetError()));
	}

	void Music::pause()
	{
		Mix_PauseMusic();
	}

	void Music::stop()
	{
		Mix_HaltMusic();
	}

	void Music::resume()
	{
		Mix_ResumeMusic();
	}

	AudioEngine::AudioEngine()
	{

	}

	AudioEngine::~AudioEngine()
	{
		destroy();
	}

	void AudioEngine::init()
	{
		if (m_isInit)
			fatalError("Tried to init audio engine twice !");

		if (Mix_Init(MIX_INIT_OGG | MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3) == -1)
			fatalError("Mix_Init error: " + std::string(Mix_GetError()));

		if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
			fatalError("Mix_OpenAudio error: " + std::string(Mix_GetError()));
		
		m_isInit = true;
	}

	void AudioEngine::destroy()
	{
		if(m_isInit)
		{
			m_isInit = false;

			for (auto& it : m_effectMap)
				Mix_FreeChunk(it.second);

			for (auto& it : m_musicMap)
				Mix_FreeMusic(it.second);

			m_effectMap.clear();
			m_musicMap.clear();

			Mix_CloseAudio();

			Mix_Quit();
		}
	}

	SoundEffect AudioEngine::loadSoundEffect(const std::string & filePath)
	{
		auto it = m_effectMap.find(filePath);

		SoundEffect effect;

		if (it == m_effectMap.end())
		{
			Mix_Chunk* chunk = Mix_LoadWAV(filePath.c_str());
			if (chunk == nullptr)
				fatalError("Mix_LoadWAV error: " + std::string(Mix_GetError()));

			effect.m_chunk = chunk;
			m_effectMap[filePath] = chunk;
		}
		else
			effect.m_chunk = it->second;

		return effect;
	}

	Music AudioEngine::loadMusic(const std::string & filePath)
	{
		auto it = m_musicMap.find(filePath);

		Music music;

		if (it == m_musicMap.end())
		{
			Mix_Music* mixMusic = Mix_LoadMUS(filePath.c_str());
			if (mixMusic == nullptr)
				fatalError("Mix_LoadMUS error: " + std::string(Mix_GetError()));

			music.m_music = mixMusic;
			m_musicMap[filePath] = mixMusic;
		}
		else
			music.m_music = it->second;

		return music;
	}
}
