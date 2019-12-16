
#ifndef ACCMOVIMENTOBJECT_H_
#define ACCMOVIMENTOBJECT_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include "GameObject.h"
#include "Vector2.h"
#include <SDL/SDL_mixer.h>
#include "Audio.h"
#define W_TELA 640
#define H_TELA 480
using namespace std;
class AccMovimentObject:public GameObject{
	public:
	
	Vector2 aceleracao;
	Uint8 *KeyState;
	Audio *somBatidaParede;
	AccMovimentObject(std::string nome_arq, int x, int y, float massa,Uint8* k_state,Audio* audio);
	//void setVel(Vector2);
	~AccMovimentObject();
	void Update(int dt);
	};
	
	#endif
