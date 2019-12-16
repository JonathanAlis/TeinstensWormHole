#include "PongBall.h"
	PongBall::PongBall(std::string nome_arq, int x, int y,Vector2 vel, float massa,InputManager* input):GameObject(nome_arq,x,y){
	velocidade=vel;
	posicao=Vector2((float)(x), (float)(y));
	this->massa=massa;
	this->input=input;
	}
	
	
	void PongBall::Update(int dt){
	if(input->isKeyDown(SDLK_PAGEUP))
	zoom(sprite->zoom+0.01);
	if(input->isKeyDown(SDLK_PAGEDOWN))
	zoom(sprite->zoom-0.01);
	if(posicao.x>=(W_TELA-sprite->GetRect().w)&&velocidade.x>=0)	velocidade.x*=-1;
	if(posicao.x<0&&velocidade.x<=0)  velocidade.x*=-1;
	if(posicao.y>=(H_TELA-sprite->GetRect().h)&&velocidade.y>=0)	velocidade.y*=-0.9;
	if(posicao.y<0&&velocidade.y<=0)  velocidade.y*=-1;

	 posicao.x+=velocidade.x*dt;
	 posicao.y+=velocidade.y*dt;
	x=(int)posicao.x;
	y=(int)posicao.y;
	}

	void PongBall::zoom(double quanto){
		if(quanto>0)
		sprite->setZoom(quanto);
		//massa=massa*sprite->zoom;
		
	}
