
#ifndef TEINSTEIN_H_
#define TEINSTEIN_H_

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
#include "Portal.h"
//#include "InputManager.h"
using namespace std;
class Teinstein:public GameObject{
	public:
	Fase* fase;
	Vector2 aceleracao;
	InputManager *input;
	Audio *somPulo;
	Audio *somTiro;
	Audio *somMorto;
	Audio* musica;
	bool noChao;
	bool portalAma;
	bool atirando;
	Sprite *bracoDireitoAma;
	Sprite *bracoDireitoVer;
	Sprite *bracoEsquerdoAma;
	Sprite *bracoEsquerdoVer;
	Sprite *mortoDireita;
	Sprite *mortoEsquerda;
	Animation* animacao;
	GameObject* tiroObj;
	Animation* tiroAni;
	Portal* portalAmarelo;
	Portal* portalVermelho;
	bool mouseAdireita;
	float angBraco;
	Vector2 posicaoInicialTiro;
	Teinstein(std::string nome_arq, float massa,InputManager* k_state,Fase *fase);
	//void setVel(Vector2);
	void Render(SDL_Surface* tela);
	bool colidiu(Sprite *coliSprite);
	bool colidiuPortal(Portal*portal);
	bool cabeParede(Vector2 *pos, Parede *parede);
	Vector2 colidiuTiro(Parede *par);
	void teleporte(Portal* de, Portal* para);
	bool morreu;
	int tempoMorto;


	~Teinstein();
	int Update(int dt);
	};
	
	#endif
