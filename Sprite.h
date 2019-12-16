#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>

#include "Vector2.h"

 class Sprite 
   {
   public:
      std::string file_name;
      SDL_Surface *surface;
      SDL_Rect retangulo;
      SDL_Surface *surfaceRotoZoom;
      SDL_Rect retanguloRot;
      int x;
      int y;      
   	  Sprite(std::string nome_arq, int x, int y);
   	  Sprite(Vector2 inicio,Vector2 fim);
	  void Render(SDL_Surface* superficie);
	  void UpdatePos(int x, int y);
	  void setAngle(double angle);
	  void setZoom(double zoom);
	  void atualizaRect();
	  SDL_Rect GetRectRot();
	  SDL_Rect GetRect();
	  double angle;
      double zoom;
	  ~Sprite();
   };
#endif
