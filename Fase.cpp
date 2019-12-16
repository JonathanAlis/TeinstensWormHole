#include "Fase.h"

Fase::Fase(std::list<Parede*> paredes, std::string molde,int fase, int x, int y, Sprite* fim, Audio* musica){
	this->numFase = fase;
	this->paredes = paredes;
	x_inicial=x;
	y_inicial=y;
	this->fim=fim;
	this->molde=new Sprite(molde, 0,0);
	if(musica==NULL)this->musica=NULL;
	else this->musica=musica;
}
void Fase::Render(SDL_Surface* tela){
        this->molde->Render(tela);/*
	for(std::list<Parede*>::iterator it = paredes.begin();it != paredes.end(); ++it) {

		Parede *parede = *it;

		if(parede->tipo2==0)
			lineRGBA(tela, (int)parede->inicio.x, (int)parede->inicio.y, (int)parede->fim.x, (int)parede->fim.y, 0, 255, 0, 255);

		if(parede->tipo2==1)
			lineRGBA(tela, (int)parede->inicio.x, (int)parede->inicio.y, (int)parede->fim.x, (int)parede->fim.y, 0, 0, 0, 255);

		if(parede->tipo2==2)
			lineRGBA(tela, (int)parede->inicio.x, (int)parede->inicio.y, (int)parede->fim.x, (int)parede->fim.y, 255, 0, 0, 255);
        }
*/
}
