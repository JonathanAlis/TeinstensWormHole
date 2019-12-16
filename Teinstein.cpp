#include "Teinstein.h"
#include "GameManager.h"
#include <cmath>
#include <iostream>
Teinstein::Teinstein(std::string nome_arq, float massa,InputManager* k_state, Fase *f):GameObject(nome_arq,x,y){

	this->portalAmarelo = new Portal("portalAmareloTeto.png","portalAmareloChao.png","portalAmareloEsquerda.png","portalAmareloDireita.png");
	this->portalVermelho = new Portal("portalVermelhoTeto.png","portalVermelhoChao.png","portalVermelhoEsquerda.png","portalVermelhoDireita.png");
	
	this->mortoDireita = new Sprite("morreuDireita.png",0,0);
	this->mortoEsquerda = new Sprite("morreuEsquerda.png",0,0);

	this->velocidade = Vector2(0,0);
	this->aceleracao = Vector2(0,0);
	this->input = k_state;
	this->somTiro = new Audio("warple.wav", 1);
    this->somPulo = new Audio("jump.wav", 1);
    this->somMorto = new Audio("dududududu.wav", 1);
    this->musica = new Audio("theme.wav",0);
    this->musica->play(1);
	this->massa = massa;
	this->noChao = false;
	this->portalAma = true;
	this->morreu = false;

	this->fase = f;
	this->animacao = new Animation(nome_arq, this->fase->x_inicial, this->fase->y_inicial, 4,2, 43);

	this->posicao = Vector2(this->fase->x_inicial, this->fase->y_inicial);

	this->bracoDireitoAma = new Sprite("arma_amarela_dir.png",animacao->x + animacao->GetRect().w/2,animacao->y + animacao->GetRect().h/2);
	this->bracoEsquerdoAma = new Sprite("arma_amarela_esq.png",animacao->x + animacao->GetRect().w/2,animacao->y + animacao->GetRect().h/2);

	this->bracoDireitoVer = new Sprite("arma_vermelha_dir.png",animacao->x + animacao->GetRect().w/2,animacao->y + animacao->GetRect().h/2);
	this->bracoEsquerdoVer = new Sprite("arma_vermelha_esq.png",animacao->x + animacao->GetRect().w/2,animacao->y + animacao->GetRect().h/2);

	this->tiroAni = new Animation ("tiro.png",animacao->x + animacao->GetRect().w/2,animacao->y + animacao->GetRect().h/2, 6, 1,100);
	this->tiroObj = new GameObject("tiro.png",animacao->x + animacao->GetRect().w/2,animacao->y + animacao->GetRect().h/2 );
	// Nao esta atirando no momento, para atualizar o tiro
	this->atirando = false;
	this->tempoMorto=-1;
}

int Teinstein::Update(int dt){
	
	if(animacao->retangulo.w == 0)
		this->animacao = new Animation("teinstein.png", x, y, 4,2, 43);
	// Se morreu reinicia a fase
	//morreu
		if(this->morreu){
		if(tempoMorto==-1){musica->stop();
		somMorto->play(0);
		this->mortoDireita->x = this->animacao->x;
		this->mortoEsquerda->x = this->animacao->x;
		this->mortoDireita->y = this->animacao->y;
		this->mortoEsquerda->y = this->animacao->y;
		}
		this->tempoMorto += dt;
		

		// Calcula rotacao do teinstein morto
		this->mortoDireita->setAngle(180/3.141592*atan(tempoMorto*10.0/2000.0));
		this->mortoEsquerda->setAngle(180/3.141592*atan(-tempoMorto*10.0/2000.0));

		if(this->tempoMorto <= 2000){return 0;}
		else{
		this->tempoMorto = -1;
cout<<posicao.y<<" e "<<posicao.x;
		this->posicao.x = this->fase->x_inicial;
		this->posicao.y = this->fase->y_inicial;
cout<<" antes, "<<posicao.y<<" e "<<posicao.x<<endl;
		this->velocidade.x = 0;
		this->velocidade.y = -1;
		this->portalAmarelo->superficie = -1;
		this->portalVermelho->superficie = -1;
		this->atirando = false;
		this->morreu = false;
		musica->play(1);
	}
	}

	this->aceleracao.x = 0.00;
	this->aceleracao.y = 0.00;

	if(this->input->isKeyPressed(SDLK_RIGHT)&&!input->isKeyPressed(SDLK_LEFT)&&noChao){this->aceleracao.x = 0.001;}
if(this->input->isKeyPressed(SDLK_RIGHT)&&!input->isKeyPressed(SDLK_LEFT)&&!noChao){this->aceleracao.x = 0.0008;}

	if(this->input->isKeyPressed(SDLK_LEFT)&&!input->isKeyPressed(SDLK_RIGHT)) {this->aceleracao.x = -0.001;}

	if(this->input->isKeyDown(SDLK_UP) && !input->isKeyDown(SDLK_DOWN) && noChao){
		this->aceleracao.y = -0.005;
		this->noChao = false;
		this->somPulo->play(0);
	}

	if(noChao && abs(this->velocidade.x) < 1) {this->velocidade.x = this->velocidade.x * 0.9;}
	else {
		this->velocidade.x = this->velocidade.x * 0.9;
		this->velocidade.y = this->velocidade.y * 1.005;
	}


	if(abs(this->velocidade.x) < 0.01) {this->velocidade.x = 0;}
	if(abs(this->velocidade.y) < 0.01) {this->velocidade.y = 0;}

	if(!this->noChao) {
		this->aceleracao.y += 0.001;
	}

	this->velocidade.x += this->aceleracao.x * dt;
	this->velocidade.y += this->aceleracao.y * dt;
	if(abs(this->velocidade.y)>2)this->velocidade.y*=2/abs(this->velocidade.y);
	this->posicao.x += this->velocidade.x * dt;
	this->posicao.y += this->velocidade.y * dt;
	this->noChao = false;
	 bool end=false;
	for(std::list<Parede*>::iterator it = this->fase->paredes.begin();it != this->fase->paredes.end()||end; ++it) {

		Parede *parede = *it;
		
		if(this->colidiu(parede->sprite)) {
			//printf("teto portal amarelo superficie=%d\n",portalAmarelo->superficie);
			switch(parede->tipo) {
				case 0: {	// Teto
					if(this->velocidade.y <= 0)  {
						if(this->portalAmarelo->parede == parede && this->colidiuPortal(portalAmarelo)){ this->teleporte(portalAmarelo, portalVermelho);}
						else if(this->portalVermelho->parede == parede && this->colidiuPortal(portalVermelho)){this->teleporte(portalVermelho,portalAmarelo);}
						else{if(this->velocidade.y>0)break;
							this->velocidade.y *= -0.1;
							this->posicao.y = (int) (parede->inicio.y);
							//	somBatidaParede->play(0);
						}
					}
					//end=true;
					break;
				}

				case 1: {	// Chao
					if(this->velocidade.y >= 0)	{
						if(this->portalAmarelo->parede == parede && this->colidiuPortal(portalAmarelo)) {this->teleporte(portalAmarelo, portalVermelho);}
						else if(this->portalVermelho->parede == parede && this->colidiuPortal(portalVermelho)) {this->teleporte(portalVermelho,portalAmarelo);}
						else{if(this->velocidade.y<0)break;
							this->velocidade.y = 0;
							this->posicao.y = (int) ((parede->inicio.y)-animacao->GetRect().h);
							this->noChao = true;
							//	somBatidaParede->play(-1);
							if(parede->tipo2==2) {if(this->morreu==false)this->morreu=true;}
						}
					}
					//end=true;
					break;
				}

				case 2: {	// Esquerda
					if(this->velocidade.x <= 0)  {
						if(this->portalAmarelo->parede == parede && this->colidiuPortal(portalAmarelo)) {this->teleporte(portalAmarelo, portalVermelho);}
						else if(this->portalVermelho->parede == parede && this->colidiuPortal(portalVermelho)) {this->teleporte(portalVermelho,portalAmarelo);}
						else{if(this->velocidade.x>0)break;
							this->velocidade.x *= -0.1;
							this->posicao.x = (int) (parede->inicio.x);
							//somBatidaParede->play(0);
							if(parede->tipo2==2) {this->morreu=true;}
						}
					}
					//end=true;
					break;
				}

				case 3: {	// Direita
					if(this->velocidade.x >= 0)	{
						if(this->portalAmarelo->parede == parede && colidiuPortal(portalAmarelo)) {this->teleporte(portalAmarelo, portalVermelho);}
						else if(this->portalVermelho->parede == parede && colidiuPortal(portalVermelho)) {this->teleporte(portalVermelho,portalAmarelo);}
						else{if(this->velocidade.x<0)break;
							this->velocidade.x *= -0.1;
							this->posicao.x = (int) (parede->inicio.x-animacao->GetRect().w);
							//	somBatidaParede->play(1);
							//pause();
							if(parede->tipo2==2) {this->morreu=true;}
						}
					}
					//end=true;
					break;
				}
			} // Fim do switch

		}
		//printf("%d,%d\n",tiroObj->sprite->retangulo.w, tiroObj->sprite->retangulo.h );
		Vector2 *v = new Vector2(colidiuTiro(parede));
//		v = &this->colidiuTiro(parede);
		
		if(v->x != -1) {	// tipo2 = 1, quer dizer preta, nao eh portavel

			if(parede->tipo2 == 1 || v->x == -2) {
				if(portalAma)portalAma=false;
									else portalAma=true;
				atirando = false;
				break;
			}
			
			if(this->portalAma){
				this->portalVermelho->superficie = parede->tipo;
				this->portalVermelho->parede = parede;
			}
			else{
				this->portalAmarelo->superficie = parede->tipo;
				this->portalAmarelo->parede = parede;
			}
			
			this->atirando = false;
			switch(parede->tipo) {
				case 0: {	// Teto
					if(!this->portalAma){
						this->portalAmarelo->portalTeto->x = v->x - this->portalAmarelo->portalTeto->GetRect().w/2;
						this->portalAmarelo->portalTeto->y = v->y;
						this->portalAmarelo->parede = parede;
					}
					else{
						this->portalVermelho->portalTeto->x = v->x - this->portalVermelho->portalTeto->GetRect().w/2;
						this->portalVermelho->portalTeto->y = v->y;
						this->portalVermelho->parede = parede;
					}
					break;
				}

				case 1: {	// Chao
					if(!this->portalAma){
						this->portalAmarelo->portalChao->x = v->x - this->portalAmarelo->portalChao->GetRect().w/2;
						this->portalAmarelo->portalChao->y = v->y - this->portalAmarelo->portalChao->GetRect().h;
						this->portalAmarelo->parede = parede;
					}
					else{
						this->portalVermelho->portalChao->x = v->x - this->portalVermelho->portalChao->GetRect().w/2;
						this->portalVermelho->portalChao->y = v->y - this->portalVermelho->portalChao->GetRect().h;
						this->portalVermelho->parede = parede;
					}
					break;
				}

				case 2: {	// Esquerda
					if(!this->portalAma){
						this->portalAmarelo->portalEsquerda->x = v->x;
						this->portalAmarelo->portalEsquerda->y = v->y - this->portalAmarelo->portalEsquerda->GetRect().h/2;
						this->portalAmarelo->parede = parede;
					}
					else{
						this->portalVermelho->portalEsquerda->x = v->x;
						this->portalVermelho->portalEsquerda->y = v->y - this->portalVermelho->portalEsquerda->GetRect().h/2;
						this->portalVermelho->parede = parede;
					}
					break;
				}

				case 3: {	// Direita
					if(!this->portalAma){
						this->portalAmarelo->portalDireita->x = v->x - this->portalAmarelo->portalDireita->GetRect().w;
						this->portalAmarelo->portalDireita->y = v->y - this->portalAmarelo->portalDireita->GetRect().h/2;
						this->portalAmarelo->parede = parede;
					}
					else{	
						this->portalVermelho->portalDireita->x = v->x - this->portalVermelho->portalDireita->GetRect().w;
						this->portalVermelho->portalDireita->y = v->y - this->portalVermelho->portalDireita->GetRect().h/2;
						this->portalVermelho->parede = parede;
					}
					break;
				}
				break;
			}

		}
		else if(this->tiroObj->x >= 1351 || this->tiroObj->y >= 651 || this->tiroObj->x <= 0 || this->tiroObj->y <= 0) {
			this->atirando = false;
		}

	}

	// Terminou a fase
	if(this->colidiu(fase->fim)){
		this->posicao.x = this->fase->x_inicial;
		this->posicao.y = this->fase->y_inicial;
		return 1;
	}

	if(this->posicao.y > 830){this->morreu = true;}

	

	this->x = (int) posicao.x;
	this->y = (int) posicao.y;
	
	this->animacao->x = x;
	this->animacao->y = y;

	if(this->input->MousePosX() > this->x + this->animacao->GetRect().w/2) {
		this->animacao->setY(0);
		this->mouseAdireita = true;
	}
	else {
		this->animacao->setY(1);
		this->mouseAdireita = false;
	}

	if(this->noChao){animacao->frameTime=(int)(10/abs(velocidade.x))+1;}

	// Rotacao do braco
	this->bracoDireitoAma->x = this->animacao->x + this->animacao->GetRect().w*2/10;
	this->bracoDireitoAma->y = this->animacao->y + this->animacao->GetRect().h/12;
	this->bracoDireitoVer->x = this->animacao->x + this->animacao->GetRect().w*2/10;
	this->bracoDireitoVer->y = this->animacao->y + this->animacao->GetRect().h/12;

	this->bracoEsquerdoAma->x = this->animacao->x + this->animacao->GetRect().w*1/10;
	this->bracoEsquerdoAma->y = this->animacao->y + this->animacao->GetRect().h/10;
	this->bracoEsquerdoVer->x = this->animacao->x + this->animacao->GetRect().w*1/10;
	this->bracoEsquerdoVer->y = this->animacao->y + this->animacao->GetRect().h/10;

	// Calcula rotacao do braco em relacao ao mouse
	this->bracoDireitoAma->setAngle(180/3.141592*atan2(this->input->MousePosX()- (this->animacao->x + this->animacao->GetRect().w/2),
			this->input->MousePosY()-(this->animacao->y + this->animacao->GetRect().h/2)));
	this->bracoEsquerdoAma->setAngle(180/3.141592*atan2(this->input->MousePosX()- (this->animacao->x + this->animacao->GetRect().w/2),
			this->input->MousePosY()-(this->animacao->y + this->animacao->GetRect().h/2)));

	this->bracoDireitoVer->setAngle(180/3.141592*atan2(this->input->MousePosX()- (this->animacao->x + this->animacao->GetRect().w/2),
			this->input->MousePosY()-(this->animacao->y + this->animacao->GetRect().h/2)));
	this->bracoEsquerdoVer->setAngle(180/3.141592*atan2(this->input->MousePosX()- (this->animacao->x + this->animacao->GetRect().w/2),
			this->input->MousePosY()-(this->animacao->y + this->animacao->GetRect().h/2)));

	// Mecanica de troca de portal
	
	if(!this->atirando) {
		this->angBraco = this->bracoDireitoVer->angle-90;
		this->posicaoInicialTiro.x = this->animacao->x + this->animacao->GetRect().w/2;
		this->posicaoInicialTiro.y = this->animacao->y + this->animacao->GetRect().h/2;
	}

	if(this->atirando){
		this->tiroObj->setVel(Vector2(cos(3.141592/180*(angBraco)),-sin(3.141592/180*(this->angBraco))));
		this->tiroObj->x += this->tiroObj->velocidade.x * dt;
		this->tiroObj->y += this->tiroObj->velocidade.y * dt;
	}
	else if(this->input->isMouseDownLeft()) {
		this->somTiro->play(0);
		this->atirando = true;
		GameManager::totalPortal++;
		if(this->portalAma == true) {this->portalAma = false;}
		else {this->portalAma = true;}
	}

	// Troca de portal na arma
	if(this->input->isMouseDownRight() && !this->atirando) {
		if(this->portalAma == true) {this->portalAma = false;}
		else {this->portalAma = true;}
	}

	if(!this->atirando){
		this->tiroObj->x = this->animacao->x + this->animacao->GetRect().w/3;
		this->tiroObj->y = this->animacao->y + this->animacao->GetRect().h/3;
	}

	// Retira os portais da tela

	if(this->input->isKeyDown(SDLK_r)) {
		this->portalAmarelo->superficie = -1;
		this->portalVermelho->superficie = -1;
	}
	

	// Animacoes das Sprites
	this->tiroAni->update(dt);
	this->animacao->update(dt);

	return 0;
}

void Teinstein::Render(SDL_Surface* tela){

	if(!this->morreu){
		this->animacao->Render(tela);

		if(this->portalAma) {
			if(this->mouseAdireita) {this->bracoDireitoAma->Render(tela);}
			else {this->bracoEsquerdoAma->Render(tela);}
		}
		else {
			if(this->mouseAdireita) {this->bracoDireitoVer->Render(tela);}
			else {this->bracoEsquerdoVer->Render(tela);}
		}
		if(this->atirando && !this->tiroObj->colidiu(bracoDireitoVer)){
			this->tiroAni->x = this->tiroObj->x;
			this->tiroAni->y = this->tiroObj->y;
			this->tiroAni->Render(tela);
		}
	}
	else {
		if(this->mouseAdireita) {this->mortoDireita->Render(tela);}
		else {this->mortoEsquerda->Render(tela);}
	}

	this->portalAmarelo->Render(tela);
	this->portalVermelho->Render(tela);
	this->fase->Render(tela);			// LEMBRAR DE BLITAR POR ULTIMO, POIS ELA BLITA O MOLDE DA FASE, O FUNDO EH BLITADO NA LEVELSTATE
}

bool Teinstein::colidiu(Sprite *coliSprite) {
	int diffX, diffY;
	int nextX=this->animacao->x+50*this->velocidade.x;
	int nextY=this->animacao->y+50*this->velocidade.y;
	diffX = nextX - coliSprite->x;
	diffY = nextY - coliSprite->y;

	if (diffX > coliSprite->retangulo.w || (diffX * -1) > this->animacao->retangulo.w) {return false;}

	if (diffY > coliSprite->retangulo.h || (diffY * -1) > this->animacao->retangulo.h) {return false;}
	
	return true;
}


bool Teinstein::colidiuPortal(Portal *portal) {
	
	if(portal->superficie==-1) return false;
	int diffX, diffY;
/*		switch(portal->superficie){
	case 0: if(!colidiu(portal->portalTeto))return false; break;
	case 1: if(!colidiu(portal->portalChao))return false; break;
	case 2: if(!colidiu(portal->portalEsquerda))return false; break;
	case 3: if(!colidiu(portal->portalDireita))return false; break;
	}*/
	switch(portal->parede->tipo) {
		case 0: //Teto
			diffX = this->animacao->x - portal->portalTeto->x ;
			if (diffX > 0 && diffX < portal->portalTeto->srcrect.w - this->animacao->retangulo.w)
				return true;
			break;

		case 1: //Chao
			diffX = this->animacao->x - portal->portalChao->x ;
			//printf("%d\n",portal->portalTeto->srcrect.w-animacao->retangulo.w);
			if (diffX > 0 && diffX < portal->portalChao->srcrect.w - this->animacao->retangulo.w)
				return true;
			break;

		case 2: //Esquerda
			diffY = this->animacao->y  - portal->portalEsquerda->y ;
			if (diffY > 0 && diffY < portal->portalEsquerda->srcrect.h - this->animacao->retangulo.h)
				return true;
			break;

		case 3: //Direita
			diffY = this->animacao->y - portal->portalDireita->y;
			if (diffY > 0 && diffY < portal->portalDireita->srcrect.h - this->animacao->retangulo.h)
				return true;
			break;
	}
	return false;
}

Vector2 Teinstein::colidiuTiro(Parede *par) {
	switch(par->tipo) {
		case 0: {	// Teto
			if((this->tiroObj->y <= par->sprite->y && this->tiroObj->x >= par->inicio.x && this->tiroObj->x <= par->fim.x) &&
					this->tiroObj->velocidade.y<0 && this->posicaoInicialTiro.y >= par->inicio.y) {
				if((tiroObj->x - this->portalAmarelo->portalTeto->srcrect.w/2 <= par->inicio.x) ||
						(tiroObj->x + this->portalAmarelo->portalTeto->srcrect.w/2 >= par->fim.x) ){
					return Vector2(-2,-2);	// -2 o tiro some
				}
				return Vector2(this->tiroObj->x,par->sprite->y);
			}
			break;
		}

		case 1: {	// Chao
			if((this->tiroObj->y >= par->sprite->y && this->tiroObj->x >= par->inicio.x && this->tiroObj->x <= par->fim.x) &&
					this->tiroObj->velocidade.y>0 && this->posicaoInicialTiro.y <= par->inicio.y) {
				if((tiroObj->x - this->portalAmarelo->portalChao->srcrect.w/2 <= par->inicio.x) ||
						(tiroObj->x + this->portalAmarelo->portalChao->srcrect.w/2 >= par->fim.x) ){
					return Vector2(-2,-2);	// -2 o tiro some
				}
				return Vector2(this->tiroObj->x,par->sprite->y);
			}
			break;
		}

		case 2: {	// Esquerda

			if((this->tiroObj->x <= par->sprite->x && this->tiroObj->y >= par->inicio.y && this->tiroObj->y <= par->fim.y) &&
					this->tiroObj->velocidade.x<0 && this->posicaoInicialTiro.x >= par->inicio.x) {
				if((tiroObj->y - this->portalAmarelo->portalEsquerda->srcrect.h/2 <= par->inicio.y) ||
						(tiroObj->y + this->portalAmarelo->portalEsquerda->srcrect.h/2 >= par->fim.y) ){
					return Vector2(-2,-2);	// -2 o tiro some
				}
				return Vector2(par->sprite->x,this->tiroObj->y);
			}
			break;
		}

		case 3: {	// Direita
			if((this->tiroObj->x >= par->sprite->x && this->tiroObj->y >= par->inicio.y && this->tiroObj->y <= par->fim.y) &&
					this->tiroObj->velocidade.x>0 && this->posicaoInicialTiro.x <= par->inicio.x) {
				if((tiroObj->y - this->portalAmarelo->portalDireita->srcrect.h/2 <= par->inicio.y) ||
						(tiroObj->y + this->portalAmarelo->portalDireita->srcrect.h/2 >= par->fim.y) ){
					return Vector2(-2,-2);	// -2 o tiro some
				}
				return Vector2(par->sprite->x,this->tiroObj->y);
			}
			break;
		}
	}

	return Vector2(-1,-1);
}

void Teinstein::teleporte(Portal* de, Portal* para){
	Animation* destino;

	if(de->superficie == -1|| para->superficie == -1) {return;}

	if(de->superficie == 0 || de->superficie == 1) {this->velocidade.y *= -1;}
	if(de->superficie == 2 || de->superficie == 3) {this->velocidade.x *= -1;}

	float ang = de->angPortal()-para->angPortal();
	this->velocidade.x = this->velocidade.x * cos(ang) - velocidade.y * sin(ang);
	this->velocidade.y = this->velocidade.x * sin(ang) + velocidade.y * cos(ang);

	switch(para->superficie){
	case 0: destino = para->portalTeto;
	this->posicao.x=destino->x+destino->retangulo.w/2-(animacao->retangulo.w)/2;
	this->posicao.y=destino->y;
	break;
	case 1: destino = para->portalChao;
	this->posicao.x=destino->x+destino->retangulo.w/2-(animacao->retangulo.w)/2;
	this->posicao.y=destino->y-animacao->retangulo.h;
	break;
	case 2: destino = para->portalEsquerda;
	this->posicao.x=destino->x;
	this->posicao.y=destino->y;
	break;
	case 3: destino = para->portalDireita;
	this->posicao.x=destino->x-animacao->retangulo.w;
	this->posicao.y=destino->y;
	break;
	}

}
