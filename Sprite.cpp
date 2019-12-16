#include "Sprite.h"
#include <SDL/SDL_rotozoom.h>
Sprite::Sprite(std::string nome_arq, int x, int y){
	surface=IMG_Load(nome_arq.c_str());
	if (surface == NULL)
	{
		printf("Nao carregou a imagem:%s \n", nome_arq.c_str());
		exit(0);
	}

	this->x = x;
	this->y = y;
	angle=0;
	zoom=1;
	atualizaRect();
	surfaceRotoZoom=NULL;

}

Sprite::Sprite(Vector2 inicio,Vector2 fim){

	x = (int) inicio.x;
	y = (int) inicio.y;
	angle=0;
	zoom=1;
	retangulo.x = x;
	retangulo.y = y;
	
	if(fim.x > inicio.x){
		retangulo.w = (int) (fim.x - inicio.x);
	}
	else {
		retangulo.w = (int) (inicio.x - fim.x);
	}

	if(fim.y > inicio.y) {
		retangulo.h = (int) (fim.y - inicio.y);
	}
	else {
		retangulo.h = (int) (inicio.y - fim.y);
	}

	if(retangulo.w == 0) {retangulo.w = 1;}
	if(retangulo.h == 0) {retangulo.h = 1;}

	surfaceRotoZoom=NULL;
	//printf("retangulo w = %d\tretangulo h = %d\n",retangulo.w,retangulo.h);
}

void Sprite::Render(SDL_Surface* tela){

	atualizaRect();
	if(zoom==1&&angle==0)
		SDL_BlitSurface(surface,NULL, tela, &retangulo);
	else SDL_BlitSurface(surfaceRotoZoom,NULL, tela, &retanguloRot);

}

void Sprite::UpdatePos(int xis, int ysilon){
	x=xis;
	y=ysilon;
}

SDL_Rect Sprite::GetRect(){
	atualizaRect();
	return retangulo;
}

SDL_Rect Sprite::GetRectRot(){
	atualizaRect();
	return retanguloRot;
}

void Sprite::setZoom(double zoom){
	if(surfaceRotoZoom!=NULL)
		SDL_FreeSurface(surfaceRotoZoom);
	this->zoom=zoom;
	surfaceRotoZoom = rotozoomSurface(surface, angle, zoom, 1);
	atualizaRect();

}

void Sprite::setAngle(double angle){
	if(surfaceRotoZoom!=NULL)
		SDL_FreeSurface(surfaceRotoZoom);
	this->angle=angle;
	surfaceRotoZoom = rotozoomSurface(surface, angle, zoom, 1);
	atualizaRect();
}

void Sprite::atualizaRect(void){
	retangulo.x = x;
	retangulo.y = y;
	retanguloRot.x = x;
	retanguloRot.y = y;

	if(zoom == 1 && angle == 0){
		retangulo.w = surface->w;
		retangulo.h = surface->h;
	}
	else{
		retanguloRot.w = surfaceRotoZoom->w;
		retanguloRot.h = surfaceRotoZoom->h;
		retanguloRot.x = retanguloRot.x - (surfaceRotoZoom->w - surface->w)/2;
		retanguloRot.y = retanguloRot.y - (surfaceRotoZoom->h - surface->h)/2;
	}
}
