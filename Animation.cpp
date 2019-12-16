#include "Animation.h"
#include <SDL/SDL_rotozoom.h>
Animation::Animation(std::string nome_arq, int x, int y, int nx,int ny,int framet):Sprite(nome_arq, x, y){
	frameTime = framet;
	this->nx = nx;
	this->ny = ny;
	srcrect.x = 0;
	srcrect.y = 0;
	atualizaRect();
	atualizaSrcRect();
	tempo = 0;
}

void Animation::update(int dt){
	tempo += dt;
	saltoFrames = tempo/frameTime;
	tempo = tempo % frameTime;
	srcrect.x += srcrect.w * saltoFrames;
	if( srcrect.x >= surface->w){
		srcrect.x =((srcrect.x - surface->w) % surface->w);}
}

void Animation::Render(SDL_Surface* tela){
	atualizaRect();
	atualizaSrcRect();
	if(zoom == 1 && angle==0)
		SDL_BlitSurface(surface,&srcrect, tela, &retangulo);
	else SDL_BlitSurface(surfaceRotoZoom,&srcrect, tela, &retangulo);

}

void Animation::setY(int n){
	if (1){//n<=ny){
		atualizaSrcRect();
		srcrect.y = srcrect.h * n;
	}
}

void Animation::atualizaSrcRect(void){
	if(zoom==1&&angle==0){
		srcrect.w = surface->w/nx;
		srcrect.h = surface->h/ny;
	}else{
		srcrect.w = surfaceRotoZoom->w;
		srcrect.h = surfaceRotoZoom->h;
	}
}

SDL_Rect Animation::GetRect(){
	atualizaRect();
	return retangulo;
}


void Animation::atualizaRect(void){
	retangulo.x = x;
	retangulo.y = y;
	if(zoom==1&&angle==0){
		retangulo.w = surface->w/nx;
		retangulo.h = surface->h/ny;
	}else{
		retangulo.w = surfaceRotoZoom->w/nx;
		retangulo.h = surfaceRotoZoom->h/ny;
	}

}
