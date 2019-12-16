
#ifndef FALLINGBALL_H_
#define FALLINGBALL_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include "GameObject.h"
#include "Vector2.h"
#define W_TELA 1350
#define H_TELA 650
using namespace std;
class FallingBall:public GameObject{
	public:

	Vector2 aceleracao;
	Uint8 *KeyState;
	FallingBall(std::string nome_arq, int x, int y, float massa);
	//void setVel(Vector2);
	~FallingBall();
	void Update(int dt);
	};
	
	#endif
