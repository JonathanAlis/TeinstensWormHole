#ifndef TILESTATE_H_
#define TILESTATE_H_

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>
//#include "Sprite.h"
#include "State.h"
#include <string>
#include <cmath>
#include "Teinstein.h"
#include "Tileset.h"
#include "Tilemap.h"

 class TileState:public State
   {
       
   public:
   
   Tileset *tileset;
   Tilemap *tilemap;
	int x, y;
	
    TileState(InputManager*);
    InputManager* input;
    int Update(int dt);
    void Render(SDL_Surface* tela);
	//void Unload();
	int chao; 
	
   };
   
#endif
