#ifndef LASER_H_
#define LASER_H_

#include "Animation.h"
#include "Parede.h"

class Laser {
public:
	Animation* baseLaserCima;
	Animation* baseLaserBaixo;
	Animation* laser;
	Parede* paredeBaseLaser;
	//Parede* paredeLaserEsquerda;		// Parede utilizada para colisao com o tiro
	//Parede* paredeLaserDireita;			// Parede utilizada para colisao com o tiro
	Vector2 inicioParede;
	Vector2 fimParede;
	int direcaoLaser;
	float taxaVelLaser;
	float taxaVelLaserAux;
	Laser(Vector2 inicio, Vector2 fim, int xCima, int yCima, int xBaixo, int yBaixo, int xRaio, int yRaio, int tam,int dirLaser,float txVelLaser);
	virtual ~Laser();
    void Render(SDL_Surface* tela);
    void Update(int dt);
    bool ColidiuTiroLaser(Sprite *sprite);
};

#endif /* LASER_H_ */
