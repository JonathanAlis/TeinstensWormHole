#ifndef COLISIONSTATE_H_
#define COLISIONSTATE_H_

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>
#include "Sprite.h"
#include "State.h"
#include <string>
#include <cmath>
#include "Teinstein.h"
#include "PongBall.h"
#include "FallingBall.h"

 class ColisionState:public State
   {
       
   public:
    ColisionState(InputManager*);
    InputManager* input;
    int Update(int dt);
    void Render(SDL_Surface* tela);
	void Unload();
	Audio *audio1;
Sprite *fundo;
Audio *audio2;
PongBall *bola;
PongBall *bola1;
PongBall *bola2;
PongBall *bola3;
PongBall *bola4;
PongBall *bola5;
PongBall *bola6;

FallingBall *bolaQcai;
std::list<GameObject*> objetos;
	  
   };
   void colisao(std::list<GameObject*> objetos);
#endif
