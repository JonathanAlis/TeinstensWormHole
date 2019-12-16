#include "FallingBall.h"
	 FallingBall:: FallingBall(std::string nome_arq, int x, int y, float massa):GameObject(nome_arq,x,y){
	
	posicao=Vector2((float)(x), (float)(y));
	velocidade=Vector2(0,0);
	aceleracao=Vector2(0,0.001);
	this->massa=massa;
	}
	
	void FallingBall::Update(int dt){
		
	
	velocidade.x+=aceleracao.x*dt;
	velocidade.y+=aceleracao.y*dt;
	
	if(posicao.x>=(W_TELA-sprite->GetRect().w)&&velocidade.x>=0)	velocidade.x*=-1;
	if(posicao.x<0&&velocidade.x<=0)  velocidade.x*=-1;
	if(posicao.y>=(H_TELA-sprite->GetRect().w)&&velocidade.y>=0)	velocidade.y*=-0.90;
	if(posicao.y<0&&velocidade.y<=0)  velocidade.y*=-1;

	 posicao.x+=velocidade.x*dt;
	 posicao.y+=velocidade.y*dt;
	 x=(int)posicao.x;
	y=(int)posicao.y;
	//cout<<velocidade.x<<", " <<velocidade.y<<endl;
	}
