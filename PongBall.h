
#ifndef PONGBALL_H_
#define PONGBALL_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include "GameObject.h"
#include "Vector2.h"
//#include "InputManager.h"
#define W_TELA 1350
#define H_TELA 650

class PongBall:public GameObject{
	public:
	InputManager *input;
	PongBall(std::string nome_arq, int x, int y,Vector2 vel, float massa,InputManager*);
	~PongBall();
	void Update(int dt);
	void zoom(double quanto);
	};
	
	#endif
