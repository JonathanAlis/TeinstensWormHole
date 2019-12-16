
#ifndef TIMER_H_
#define TIMER_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <cmath>


class Timer{
	public:
	int initialTime;
	int pauseTime;
	bool paused;
	Timer();
	void Start();
	void Stop();
	void Resume();
	int GetTime();
	
	};
	
	#endif
