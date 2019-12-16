#include "Laser.h"

Laser::Laser(Vector2 inicio, Vector2 fim, int xCima, int yCima, int xBaixo, int yBaixo, int xRaio, int yRaio, int tam,int direLaser,float txVelLaser) {
	this->inicioParede = inicio;
	this->fimParede = fim;
	this->baseLaserBaixo = new Animation("baseRaioBaixo.png",xBaixo,yBaixo,2,1,300);
	this->baseLaserCima = new Animation("baseRaioCima.png",xCima,yCima,2,1,300);
	this->laser = new Animation("raio.png",xRaio,yRaio,2,1,150);
	this->laser->srcrect.y = tam;
	this->direcaoLaser = direLaser;
	this->taxaVelLaser = txVelLaser;
	this->taxaVelLaserAux = txVelLaser;
	//this->paredeLaserEsquerda = new Parede(Vector2(xRaio,yRaio),Vector2(xRaio,yBaixo),0,2);
	//this->paredeLaserDireita = new Parede(Vector2(xRaio,yRaio),Vector2(xRaio, yBaixo),0,3);
}

Laser::~Laser() {
	// TODO Auto-generated destructor stub
}

void Laser::Update(int dt) {


	// Dobra o valor da taxa da velocidade e verifica se passou de 1, em caso positivo entao incrementa o x do laser

		// Verifica em qual direcao o laser esta andando no momento e incrementa ou decrementa a direcao dele
		if(this->direcaoLaser < 0) {
                        this->baseLaserCima->x-=this->taxaVelLaserAux;
                        this->baseLaserBaixo->x-=this->taxaVelLaserAux;
                        this->laser->x-=this->taxaVelLaserAux;
			//this->paredeLaserDireita->inicio.x--;
			//this->paredeLaserDireita->fim.x--;
			//this->paredeLaserEsquerda->inicio.x--;
			//this->paredeLaserEsquerda->fim.x--;
			this->taxaVelLaserAux = this->taxaVelLaser;
		}
		else {
                        this->baseLaserCima->x+=this->taxaVelLaserAux;
                        this->baseLaserBaixo->x+=this->taxaVelLaserAux;
                        this->laser->x+=this->taxaVelLaserAux;
			//this->paredeLaserDireita->inicio.x++;
			//this->paredeLaserDireita->fim.x++;
			//this->paredeLaserEsquerda->inicio.x++;
			//this->paredeLaserEsquerda->fim.x++;
			this->taxaVelLaserAux = this->taxaVelLaser;
		}


	// Inverte a direcao do laser
	if((int) this->inicioParede.x > this->baseLaserCima->x) {
		this->direcaoLaser = 1;
	}

	// Inverte a direcao do laser
	if((int) this->fimParede.x < (this->baseLaserCima->x + this->baseLaserCima->srcrect.w)) {
		this->direcaoLaser = -1;
	}
	this->baseLaserCima->update(dt);
	this->baseLaserBaixo->update(dt);
	this->laser->update(dt);
}

void Laser::Render(SDL_Surface* tela){
	this->laser->Render(tela);

	//lineRGBA(tela, (int)this->paredeLaserDireita->inicio.x, (int)this->paredeLaserDireita->inicio.y, (int)this->paredeLaserDireita->fim.x, (int)this->paredeLaserDireita->fim.y, 0, 255, 0, 255);
	//lineRGBA(tela, (int)this->paredeLaserEsquerda->inicio.x, (int)this->paredeLaserEsquerda->inicio.y, (int)this->paredeLaserEsquerda->fim.x, (int)this->paredeLaserEsquerda->fim.y, 0, 255, 0, 255);

	this->baseLaserCima->Render(tela);
	this->baseLaserBaixo->Render(tela);
}
