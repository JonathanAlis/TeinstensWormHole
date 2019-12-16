
#ifndef AUDIO_H_
#define AUDIO_H_

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <string>
class Audio{
	public:
	std::string fileName;
	Mix_Music *musica;
	Mix_Chunk *som;
	Audio(std::string nome_arq, int x);
	void play(int n);
	void stop(void);
	~Audio();
	
	};
	
	#endif
