

#include "Portal.h"

Portal::Portal(std:: string imgTeto,string imgChao, string imgEsq, string imgDir) {
	//std::string nome_arq, int x, int y, int nx,int ny,int frame
	portalTeto = new Animation(imgTeto,1,1,1,1,1);
	portalChao = new Animation(imgChao,1,1,1,1,1);
	portalDireita = new Animation(imgDir,1,1,1,1,1);
	portalEsquerda = new Animation(imgEsq,1,1,1,1,1);
	superficie=-1;
	parede=NULL;
}
float Portal::angPortal(){
	if(this==NULL) return -1;
	int angGraus=(superficie/2*90+180*superficie+90)%360;
	return angGraus*3.1415926/180.0;
}
void Portal::Render(SDL_Surface *tela){
switch(superficie){
	case 0: portalTeto->Render(tela); break;
	case 1: portalChao->Render(tela); break;
	case 2: portalEsquerda->Render(tela); break;
	case 3: portalDireita->Render(tela); break;
	}
}
Portal::~Portal() {
	// TODO Auto-generated destructor stub
}
