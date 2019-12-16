
#include <string.h>
#include <sstream>
#include <iostream>
#include "LevelState.h"
#include "GameManager.h"
#include "Fase.h"
#include "Laser.h"

LevelState::LevelState(std::string nome_arq,std::string nome_arq2, InputManager* k_state, Timer *tempo, int id):State(){
        Audio* audio3;
        Audio* audio2;
	Audio* audio1;
	Fase* fase = NULL;
        audio3 = new Audio("warple.wav", 1);
        audio2 = new Audio("jump.wav", 1);
        audio1 = new Audio("theme.wav",0);
	stringstream buf;
	stringstream buf2;
	string res;
	string res2;
	this->fundo = new Sprite(nome_arq, 0, 0);
	this->tempo = tempo;

	switch(id) {
		case 1: {
			this->tempo->Start();
			Parede *parede01, *parede02,*parede03,*parede04,*parede05,*parede06,*parede07,*parede08,*parede09,*parede10;

			parede01 = new Parede(Vector2(50,50), Vector2(50,300), 1,2);				// Parede Esquerda Cima
			parede02 = new Parede(Vector2(50,300), Vector2(350,300), 1,1);				// Chao Esquerdo Cima
			parede03 = new Parede(Vector2(350,300), Vector2(350,600), 0,2);				// Parede Esquerda Baixo
			parede04 = new Parede(Vector2(350,600), Vector2(700,600), 0,1);				// Chao Baixo Esquerdo
			parede07 = new Parede(Vector2(700,600), Vector2(1100,600), 2,1);			// Chao Baixo Centro
			parede08 = new Parede(Vector2(1100,300), Vector2(1300,300), 0,1);			// Chao Baixo Direito
			parede09 = new Parede(Vector2(1100,300), Vector2(1100,600), 0,3);			// Parede Direita Baixa
			parede05 = new Parede(Vector2(1300,50), Vector2(1300,300), 0,3);			// Parede Direita Alta
			parede06 = new Parede(Vector2(355,50), Vector2(1300,50), 0,0);				// Teto
			parede10 = new Parede(Vector2(50,50), Vector2(355,50), 1,0);				// Teto Nao portavel


			std::list<Parede*> paredes;
			paredes.push_back(parede01);
			paredes.push_back(parede04);
			paredes.push_back(parede02);
			paredes.push_back(parede03);
			paredes.push_back(parede05);
			paredes.push_back(parede06);
			paredes.push_back(parede07);
			paredes.push_back(parede08);
			paredes.push_back(parede09);
			paredes.push_back(parede10);

			Sprite* final = new Sprite(Vector2(1200,300),Vector2(1300,300));	// Saida da Fase
			fase = new Fase(paredes,"fase_1.png",0, 100,100, final, audio1);		// paredes, id da fase, pos x e y do teinstein e sprite do final da fase
			break;
		}
		case 2: {
			Parede *parede01, *parede02,*parede03,*parede04,*parede07,*parede08,*parede09,*parede05,*parede06,*parede10;

			parede01 = new Parede(Vector2(50,50), Vector2(50,300), 1,2);				// Parede Esquerda Cima
			parede02 = new Parede(Vector2(50,300), Vector2(350,300), 1,1);				// Chao Esquerdo Cima
			parede03 = new Parede(Vector2(350,300), Vector2(350,600), 0,2);				// Parede Esquerda Baixo
			parede04 = new Parede(Vector2(350,600), Vector2(700,600), 0,1);				// Chao Baixo Esquerdo
			parede05 = new Parede(Vector2(1300,50), Vector2(1300,300), 1,3);			// Parede Direita Alta
			parede06 = new Parede(Vector2(355,50), Vector2(1300,50), 1,0);				// Teto
			parede07 = new Parede(Vector2(700,600), Vector2(1100,600), 2,1);			// Chao Baixo Centro
			parede08 = new Parede(Vector2(1100,300), Vector2(1300,300), 0,1);			// Chao Baixo Direito
			parede09 = new Parede(Vector2(1100,300), Vector2(1100,600), 1,3);			// Parede Direita Baixa
			parede10 = new Parede(Vector2(50,50), Vector2(355,50), 0,0);				// Teto Nao portavel
			//parede06 = new Parede(Vector2(50,50), Vector2(1300,50), 0,0);				// Teto

			std::list<Parede*> paredes;
			paredes.push_back(parede01);
			paredes.push_back(parede04);
			paredes.push_back(parede02);
			paredes.push_back(parede03);
			paredes.push_back(parede05);
			paredes.push_back(parede06);
			paredes.push_back(parede07);
			paredes.push_back(parede08);
			paredes.push_back(parede09);
			paredes.push_back(parede10);


			Sprite* final = new Sprite(Vector2(1200,300),Vector2(1300,300));	// Saida da Fase
			fase = new Fase(paredes,"fase_2.png",0, 100,100, final, audio1);			// paredes, id da fase, pos x e y do teinstein e sprite do final da fase
			break;
		}

		case 3: {
			Parede *parede01, *parede02,*parede03,*parede04;

			parede01 = new Parede(Vector2(50,50), Vector2(50,600), 0,2);				// Parede Esquerda
			parede02 = new Parede(Vector2(50,600), Vector2(1300,600), 0,1);				// Chao
			parede03 = new Parede(Vector2(1300,50), Vector2(1300,600), 0,3);			// Parede Direita
			parede04 = new Parede(Vector2(50,50), Vector2(1300,50), 0,0);				// Teto


			std::list<Parede*> paredes;
			paredes.push_back(parede01);
			paredes.push_back(parede02);
			paredes.push_back(parede03);
			paredes.push_back(parede04);

			//O numero 741 Ajusta a posicao y do retangulo de blitagem da imagem para o raio ficar entre a base de cima e de baixo
			Laser *laser1 = new Laser(parede04->inicio,parede04->fim,1000,50,1000,571,1020,50,300,1,8);
			Laser *laser2 = new Laser(parede04->inicio,parede04->fim,600,50,600,571,620,50,300,-1,8);

			this->listaLasers.push_back(laser1);
			this->listaLasers.push_back(laser2);

			Sprite* final = new Sprite(Vector2(1200,300),Vector2(1300,600));	// Saida da Fase
			fase = new Fase(paredes,"fase_3.png",0, 100,100, final, audio1);			// paredes, id da fase, pos x e y do teinstein e sprite do final da fase
			break;
		}

		case 4: {

			Parede *parede01, *parede02,*parede03,*parede04,*parede05,*parede06,*parede07,*parede08,*parede09,*parede10,
			*parede11,*parede12,*parede13,*parede14;

			parede01 = new Parede(Vector2(50,50), Vector2(50,603), 0,2);				// Parede Esquerda 		ok
			parede02 = new Parede(Vector2(50,603), Vector2(219,603), 0,1);				// Chao Esquerdo 		ok
			parede03 = new Parede(Vector2(219,301), Vector2(219,603), 0,3);				// Parede Esquerda 		ok
			parede04 = new Parede(Vector2(219,301), Vector2(350,301), 1,1);				// Chao Baixo 			ok
			parede05 = new Parede(Vector2(350,301), Vector2(350,603), 0,2);				// Parede Esquerda 		ok
			parede06 = new Parede(Vector2(350,603), Vector2(561,603), 2,1);				// Chao					ok
			parede07 = new Parede(Vector2(561,310), Vector2(561,603), 0,3);				// Direta				ok
			parede08 = new Parede(Vector2(561,310), Vector2(702,310), 1,1);				// Chao					ok
			parede09 = new Parede(Vector2(702,310), Vector2(702,603), 0,2);				// Esquerda				ok
			parede10 = new Parede(Vector2(702,603), Vector2(1102,603), 2,1);			// Chao					ok
			parede11 = new Parede(Vector2(1102,300), Vector2(1102,603), 0,3);			// Direita				ok
			parede12 = new Parede(Vector2(1102,300), Vector2(1301,300), 1,1);			// Chao					ok
			parede13 = new Parede(Vector2(1301,50), Vector2(1301,300), 1,3);			// Direita				ok
			parede14 = new Parede(Vector2(50,50), Vector2(1301,50), 1,0);


			std::list<Parede*> paredes;
			paredes.push_back(parede01);
			paredes.push_back(parede04);
			paredes.push_back(parede02);
			paredes.push_back(parede03);
			paredes.push_back(parede05);
			paredes.push_back(parede06);
			paredes.push_back(parede07);
			paredes.push_back(parede08);
			paredes.push_back(parede09);
			paredes.push_back(parede10);
			paredes.push_back(parede11);
			paredes.push_back(parede12);
			paredes.push_back(parede13);
			paredes.push_back(parede14);


			Sprite* final = new Sprite(Vector2(1200,300),Vector2(1300,300));	// Saida da Fase
			fase = new Fase(paredes,"fase_4.png",0, 100,400, final, audio1);	// paredes, id da fase, pos x e y do teinstein e sprite do final da fase
			break;
		}
		case 5: {
			// int tipo;
			// De 0 a 3.
			//0 = Teto,
			//1 = Chao;
			//2 = Parede Esquerda e
			//3 = Parede Direita

			Parede *parede01, *parede02,*parede03,*parede04,*parede05,*parede06,*parede07,*parede08,*parede09,
			*parede10,*parede11,*parede12,*parede13,*parede14,*parede15,*parede16,*parede17;

			parede01 = new Parede(Vector2(50,51), Vector2(50,230), 1,2);			// Parede Esquerda 		- Nao Portavel
			parede02 = new Parede(Vector2(51,230), Vector2(213,230), 1,1);			// Chao 				- Nao Portavel
			parede03 = new Parede(Vector2(213,231), Vector2(213,600), 0,2);			// Parede Esquerda		- Portavel
			parede04 = new Parede(Vector2(213,580), Vector2(490,580), 2,1);			// Chao					- Mata
			parede05 = new Parede(Vector2(490,464), Vector2(490,600), 0,3);			// Parede Direita		- Portavel
			parede06 = new Parede(Vector2(490,464), Vector2(760,464), 0,1);			// Chao					- Portavel
			parede07 = new Parede(Vector2(760,464), Vector2(760,600), 0,2);			// Parede Esquerda		- Portavel
			parede08 = new Parede(Vector2(760,580), Vector2(1092,580), 2,1);		// Chao					- Mata
			parede09 = new Parede(Vector2(1092,231), Vector2(1092,600), 0,3);		// Parede Direita		- Portavel
			parede10 = new Parede(Vector2(1092,231), Vector2(1298,231), 0,1);		// Chao					- Portavel
			parede11 = new Parede(Vector2(1298,51), Vector2(1298,231), 0,3);		// Parede Direita		- Portavel
			parede12 = new Parede(Vector2(761,51), Vector2(1298,51), 0,0);			// Teto					- Portavel
			parede13 = new Parede(Vector2(761,51), Vector2(761,320), 0,2);			// Parede Esquerda		- Portavel
			parede14 = new Parede(Vector2(492,325), Vector2(761,325), 0,0);			// Teto					- Portavel
			parede15 = new Parede(Vector2(492,51), Vector2(492,320), 0,3);			// Parede Direita		- Portavel
			parede16 = new Parede(Vector2(50,51), Vector2(270,51), 1,0);			// Teto					- Nao Portavel
			parede17 = new Parede(Vector2(270,51), Vector2(492,51), 0,0);			// Teto					- Portavel

			std::list<Parede*> paredes;
			paredes.push_back(parede01);
			paredes.push_back(parede04);
			paredes.push_back(parede02);
			paredes.push_back(parede03);
			paredes.push_back(parede05);
			paredes.push_back(parede06);
			paredes.push_back(parede07);
			paredes.push_back(parede08);
			paredes.push_back(parede09);
			paredes.push_back(parede10);
			paredes.push_back(parede11);
			paredes.push_back(parede12);
			paredes.push_back(parede13);
			paredes.push_back(parede14);
			paredes.push_back(parede15);
			paredes.push_back(parede16);
			paredes.push_back(parede17);


			//O numero 741 Ajusta a posicao y do retangulo de blitagem da imagem para o raio ficar entre a base de cima e de baixo
			Laser *laser1 = new Laser(parede14->inicio,parede14->fim,610,325,610,435,630,350,741,1,2);

			this->listaLasers.push_back(laser1);

			Sprite* final = new Sprite(Vector2(1200,51),Vector2(1298,231));	// Saida da Fase
			fase = new Fase(paredes,"fase_5.png",0, 100,100, final, audio1);		// paredes, id da fase, pos x e y do teinstein e sprite do final da fase
			break;
		}
		case 6: {
			Parede *parede01, *parede02,*parede03,*parede04,*parede05,*parede06;

			parede01 = new Parede(Vector2(50,50), Vector2(50,600), 0,2);				// Parede Esquerda
			parede02 = new Parede(Vector2(50,600), Vector2(900,600), 0,1);				// Chao
			parede03 = new Parede(Vector2(1300,50), Vector2(1300,600), 1,3);			// Parede Direita
			parede04 = new Parede(Vector2(50,50), Vector2(900,50), 0,0);				// Teto
			parede05 = new Parede(Vector2(900,600), Vector2(1300,600), 1,1);				// teto nao
			parede06 = new Parede(Vector2(900,50), Vector2(1300,50), 1,0);				// chao nao

			std::list<Parede*> paredes;
			paredes.push_back(parede01);
			paredes.push_back(parede02);
			paredes.push_back(parede03);
			paredes.push_back(parede04);
			paredes.push_back(parede05);
			paredes.push_back(parede06);

			//O numero 741 Ajusta a posicao y do retangulo de blitagem da imagem para o raio ficar entre a base de cima e de baixo
			Laser *laser1 = new Laser(parede04->inicio,parede04->fim,1000,50,1000,571,1020,50,300,1,10);
			Laser *laser2 = new Laser(parede04->inicio,parede04->fim,600,50,600,571,620,50,300,-1,10);

			this->listaLasers.push_back(laser1);
			this->listaLasers.push_back(laser2);

			Sprite* final = new Sprite(Vector2(1200,300),Vector2(1300,600));	// Saida da Fase
			fase = new Fase(paredes,"fase_6.png",0, 100,100, final, audio1);			// paredes, id da fase, pos x e y do teinstein e sprite do final da fase
			break;
		}
	}
	//fase->musica->play(2);
        this->teinstein = new Teinstein(nome_arq2,20, k_state,fase);

	this->indicadorPortalAtualAmarelo = new Animation ("IndicadorPortalAtualAmarelo.png",1290,5,3,1,120);
	this->indicadorPortalAtualVermelho = new Animation("IndicadorPortalAtualVermelho.png",1290,5,3,1,120);
	this->textoPortalAtual = new Text("Portal Atual:","arial.ttf",Vector2(1185,14),16);
	this->idFase = id;

	// Transforma em string o inteiro getime()
	buf << this->tempo->GetTime()/1000;
	buf >> res;
	this->textoTempoTotal = new Text("Tempo Total: " + res,"arial.ttf",Vector2(500,14),16);
	buf2 << GameManager::totalPortal;
	buf2 >> res2;
	this->textoTotalPortal = new Text("N° Portais: " + res,"arial.ttf",Vector2(750,14),16);
}


int LevelState::Update(int dt){
        //return 10;
	stringstream buf;							// Usado para transformar inteiro em string
	stringstream buf2;
	string res;									// Usado para transformar inteiro em string
	string res2;
	int aux = this->teinstein->Update(dt);		// Variavel auxiliar para retornar se passou de fase ou nao

	for(std::list<Laser*>::iterator it = this->listaLasers.begin();it != this->listaLasers.end(); ++it) {
		Laser *laser = *it;
		if(this->teinstein->colidiu(laser->laser)){this->teinstein->morreu = true;}
		laser->Update(dt);
	}


	//this->teinstein->animacao->update(dt);	Animacao do teinteins passado para dentro do update dele
	if(this->teinstein->portalAma) {this->textoPortalAtual->setColor(252,252,0);}
	else {this->textoPortalAtual->setColor(255,0,0);}

	this->textoPortalAtual->setText("Portal Atual:");
	//this->tempo->Resume();

	// Transforma em string o inteiro gettime()
	buf << this->tempo->GetTime()/1000;
	buf >> res;
	this->textoTempoTotal->setColor(255,255,255);
	this->textoTempoTotal->setText("Tempo Total  " + res);

	buf2 << GameManager::totalPortal;
	buf2 >> res2;

	this->textoTotalPortal->setColor(255,255,255);
	this->textoTotalPortal->setText("N° Portais: " + res2);

	if(aux == 1) {aux += this->idFase;}
	this->indicadorPortalAtualAmarelo->update(dt);
	this->indicadorPortalAtualVermelho->update(dt);

	return aux;
}

void LevelState::Render(SDL_Surface* tela){
	SDL_FillRect( tela, NULL, SDL_MapRGB( tela->format, 0, 0, 0 ) );
	this->fundo->Render(tela);
	this->teinstein->Render(tela);
	this->textoPortalAtual->render(tela);
	this->textoTempoTotal->render(tela);
	this->textoTotalPortal->render(tela);
	if(this->teinstein->portalAma) {this->indicadorPortalAtualAmarelo->Render(tela);}
	else {this->indicadorPortalAtualVermelho->Render(tela);}

	for(std::list<Laser*>::iterator it = this->listaLasers.begin();it != this->listaLasers.end(); ++it) {
		Laser *laser = *it;
		laser->Render(tela);
	}
}

void LevelState::Unload(){

}
