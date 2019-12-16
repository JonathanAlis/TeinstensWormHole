
#ifndef PAREDE_H_
#define PAREDE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include "Vector2.h"
#include "Sprite.h"
#define W_TELA 1350
#define H_TELA 650
 class Parede
   {
   private:
      
          
   public:
	  Vector2 inicio;
	  Vector2 fim;
	  Sprite *sprite;
	  bool portavel;
      Parede(Vector2, Vector2, int,int);
      int tipo;	// De 0 a 3. Sendo 0 = Teto, 1 = Chao; 2 = Parede Esquerda e 3 = Parede Direita
	  int tipo2; //0 eh normal, 1 nao pode por portal, 2 morre ao encostar
   };
   
   #endif
