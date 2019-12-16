#ifndef STATE_H_
#define STATE_H_

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "Vector2.h"

 class State
   {
       
   public:
   State();
   virtual void Load();
   virtual void Unload();
   virtual int Update(int dt);
   virtual void Render(SDL_Surface* screen) ;
	  
   };
#endif
