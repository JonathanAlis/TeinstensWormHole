#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>
#include "Sprite.h"
#include "State.h"
#include <string>

 class Animation:public Sprite   {
       
   public:
    int frameTime;
    int tempo;
    int nx;
    int ny;
    int saltoFrames;
    SDL_Rect srcrect;

   Animation(std::string nome_arq, int x, int y, int nx, int ny, int framet);
	void update(int dt);
	void Render(SDL_Surface* tela);
	void setY(int n);
	void atualizaRect(void);
	void atualizaSrcRect(void);
	SDL_Rect GetRect();
	
   };
#endif
