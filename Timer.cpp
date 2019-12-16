#include "Timer.h"
Timer::Timer(){
	this->paused = false;
	this->pauseTime = 0;
}
void Timer::Start(){
	this->initialTime = SDL_GetTicks();
}
void Timer::Stop(){
	this->pauseTime = SDL_GetTicks();
	this->paused = true;
}
void Timer::Resume(){
	this->initialTime += SDL_GetTicks() - this->pauseTime;
	this->paused = false;
}
int Timer::GetTime(){
	if(this->paused) return SDL_GetTicks() - this->pauseTime;
	else return SDL_GetTicks() - this->initialTime;
}

