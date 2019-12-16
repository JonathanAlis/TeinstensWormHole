
#ifndef PORTAL_H_
#define PORTAL_H_

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
#include "Fase.h"
#include "Animation.h"
using namespace std;

class Portal {
public:
	Animation *portalTeto;
	Animation *portalChao;
	Animation *portalDireita;
	Animation *portalEsquerda;
	int superficie;//// De 0 a 3. Sendo 0 = Teto, 1 = Chao; 2 = Parede Esquerda e 3 = Parede Direita
	Parede* parede;
	Portal(std:: string imgTeto,string imgChao, string imgEsq, string imgDir);
	float angPortal();
	void Render(SDL_Surface*);
	void atualiza();
	virtual ~Portal();
};

#endif /* PORTAL_H_ */
