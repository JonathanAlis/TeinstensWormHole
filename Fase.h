
#ifndef FASE_H_
#define FASE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include "Sprite.h"
#include "Parede.h"
#include "Audio.h"

class Fase
{

public:
	int numFase;
	std::list<Parede*> paredes;
	Fase(std::list<Parede*> paredes, std::string molde,int fase, int, int, Sprite*, Audio*);
	void Render(SDL_Surface* superficie);
	void Update(int dt);
	int x_inicial;
	int y_inicial;
	Sprite* fim;
	Sprite* molde;
	Audio* musica;
};

#endif
