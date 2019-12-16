
#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include "Sprite.h"
#include "InputManager.h"
#define W_TELA 1350
#define H_TELA 650
 class GameObject 
   {
   private:
      
          
   public:
	  std::string file_name;
      int x;
      int y;  
      Sprite *sprite;
      float massa;
      Vector2 posicao;
	  Vector2 velocidade;
	  GameObject(std::string nome_arq, int x, int y);
	  bool colidiu(GameObject*);
	  bool colidiu(Sprite *coliSprite);
	  bool aproxima(GameObject* b);
	  void aplica_colisao(GameObject*);
	  void Render(SDL_Surface* superficie);
	  void Update(int dt);
	  void setVel(Vector2);
	  void setX(int x);
	  void setY(int y);
	  void setMassa(float m);
   };
   
   #endif
