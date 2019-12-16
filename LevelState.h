#ifndef LEVELSTATE_H_
#define LEVELSTATE_H_

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>
#include "Sprite.h"
#include "State.h"
#include <string>
#include "Teinstein.h"
#include "Text.h"
#include "Timer.h"
#include "Laser.h"
#include "Audio.h"
 class LevelState:public State
   {
       
   public:
    LevelState(std::string nome_arq, std::string nome2, InputManager*, Timer*, int id);
    int Update(int dt);
    void Render(SDL_Surface* tela);
	void Unload();
	Sprite *fundo;
	Teinstein *teinstein;
	Animation *indicadorPortalAtualAmarelo;
	Animation *indicadorPortalAtualVermelho;
	Text *textoPortalAtual;
	Text *textoTempoTotal;
	Text *textoTotalPortal;
	Timer *tempo;	// Ponteiro para a variavel tempoTotal da GameManager, para parar e recomecar o tempo ao trocar de fase sem zera-lo
	int idFase;
	std::list<Laser*> listaLasers;

   };
#endif
