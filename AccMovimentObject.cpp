#include "AccMovimentObject.h"
	 AccMovimentObject:: AccMovimentObject(std::string nome_arq, int x, int y, float massa,Uint8* k_state, Audio* audio):GameObject(nome_arq,x,y){
	
	posicao=Vector2((float)(x), (float)(y));
	velocidade=Vector2(0,0);
	aceleracao=Vector2(0,0);
	KeyState=k_state;
	somBatidaParede=audio;
	this->massa=massa;
	}
	
	void AccMovimentObject::Update(int dt){
		
	aceleracao.x=0.00;
	aceleracao.y=0.00;
	if(KeyState[SDLK_RIGHT]&&!KeyState[SDLK_LEFT]) aceleracao.x=0.001;
	if(KeyState[SDLK_LEFT]&&!KeyState[SDLK_RIGHT]) aceleracao.x=-0.001;
	if(KeyState[SDLK_UP]&&!KeyState[SDLK_DOWN]) aceleracao.y=-0.001;
	if(KeyState[SDLK_DOWN]&&!KeyState[SDLK_UP]) aceleracao.y=0.001;
	
	if(!KeyState[SDLK_RIGHT]&&!KeyState[SDLK_LEFT]&&!KeyState[SDLK_UP]&&!KeyState[SDLK_DOWN]){
		/*if(velocidade.x>0) aceleracao.x=-0.0005;
		if(velocidade.x<0) aceleracao.x=0.0005;
		if(velocidade.y>0) aceleracao.y=-0.0005;
		if(velocidade.y<0) aceleracao.y=0.0005;
		if(abs(velocidade.x)<0.1&&abs(velocidade.y)<0.1){
			velocidade.x=0; velocidade.y=0;
			aceleracao.x=0; aceleracao.y=0;
			
		}
		* 
		*/
		velocidade.x=velocidade.x*0.95;
		velocidade.y=velocidade.y*0.95;
		if(abs(velocidade.x)<0.01) velocidade.x=0;
		if(abs(velocidade.y)<0.01) velocidade.y=0;
	}
	
	
	velocidade.x+=aceleracao.x*dt;
	velocidade.y+=aceleracao.y*dt;
	
	if(velocidade.y!=0)
		sprite->setAngle(180/3.141592*atan2(velocidade.x,velocidade.y));
	else{
		if(velocidade.x>0)
			sprite->setAngle(90);
		if(velocidade.x<0)	
			sprite->setAngle(-90);
	}	
	if(posicao.x>=(W_TELA-sprite->GetRect().w)&&velocidade.x>=0)	{velocidade.x*=-1;somBatidaParede->play(1);}
	if(posicao.x<0&&velocidade.x<=0)  {velocidade.x*=-1; somBatidaParede->play(0);}
	if(posicao.y>=(H_TELA-sprite->GetRect().w)&&velocidade.y>=0)	{velocidade.y*=-1; somBatidaParede->play(-1);}
	if(posicao.y<0&&velocidade.y<=0)  {velocidade.y*=-1;somBatidaParede->play(0);}

	 posicao.x+=velocidade.x*dt;
	 posicao.y+=velocidade.y*dt;
	 x=(int)posicao.x;
	y=(int)posicao.y;
	//cout<<velocidade.x<<", " <<velocidade.y<<endl;
	}
