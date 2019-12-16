#include <fstream>
#include <iostream>
#include "SplashState.h"
#include "GameManager.h"

SplashState::SplashState(std::string planoFundoMenu,std::string botaoStart,std::string botaoQuit,std::string botaoRecords, InputManager* input):State(){
	this->fundoMenuPrincipal = new Sprite(planoFundoMenu, 0, 0);
	this->botaoStart = new Sprite(botaoStart,90,360);
	this->botaoRecords = new Sprite(botaoRecords,90,440);
	this->botaoQuit = new Sprite(botaoQuit,90,520);
	this->botaoMainMenu = NULL;
	this->fundoRecords = NULL;
	this->input = input;
}

SplashState::SplashState(std::string planoFundoRecords,std::string botaoMainMenu, InputManager* input):State(){
	this->fundoMenuPrincipal = NULL;
	this->botaoStart = NULL;
	this->botaoRecords = NULL;
	this->botaoQuit = NULL;
	this->input = input;
	this->fundoRecords = new Sprite(planoFundoRecords,0,0);
	this->botaoMainMenu = new Sprite(botaoMainMenu,1000,560);
	this->posCabecalho = new Text("Pos.","arial.ttf",Vector2(235,155),40);
	this->nomeCabecalho = new Text("Name","arial.ttf",Vector2(440,155),40);
	this->tempoCabecalho = new Text("Time","arial.ttf",Vector2(685,155),40);
	this->numPortalCabecalho = new Text("N° Portal","arial.ttf",Vector2(910,155),40);

	this->reg[0].tempo = 100000000;
	this->reg[1].tempo = 100000000;
	this->reg[2].tempo = 100000000;
	this->reg[3].tempo = 100000000;

}

SplashState::SplashState(std::string planoFundoRecords, InputManager* input):State(){
	this->fundoMenuPrincipal = NULL;
	this->botaoStart = NULL;
	this->botaoRecords = NULL;
	this->botaoQuit = NULL;
	this->botaoMainMenu = NULL;
	this->input = input;
	this->iniciais = new Sprite("painelIniciais.png",320,250);
	this->textoIniciais = new Text(" ","arial.ttf",Vector2(550,390),60);
	this->fundoRecords = new Sprite(planoFundoRecords,0,0);
}

int SplashState::Update(int dt){
	if(this->botaoMainMenu != NULL) {
		if(this->input->isMouseInside(this->botaoMainMenu) && this->input->isMouseDownLeft()){return -1;}
	}

	if(this->botaoQuit != NULL) {
		if(this->input->isMouseInside(this->botaoQuit) && this->input->isMouseDownLeft()){exit(0);}
		if(this->input->isMouseInside(this->botaoRecords) && this->input->isMouseDownLeft()){return -2;}
		if(this->input->isMouseInside(this->botaoStart) && this->input->isMouseDownLeft()){return 1;}
	}

	if(this->botaoMainMenu == NULL && this->botaoQuit == NULL) {
		stringstream buf;
		stringstream buf2;
		string res;
		string res2;

		if(this->texto.length() < 3) {
			if(input->isKeyDown(SDLK_a)){this->texto.append("A");}
			if(input->isKeyDown(SDLK_b)){this->texto.append("B");}
			if(input->isKeyDown(SDLK_c)){this->texto.append("C");}
			if(input->isKeyDown(SDLK_d)){this->texto.append("D");}
			if(input->isKeyDown(SDLK_e)){this->texto.append("E");}
			if(input->isKeyDown(SDLK_f)){this->texto.append("F");}
			if(input->isKeyDown(SDLK_g)){this->texto.append("G");}
			if(input->isKeyDown(SDLK_h)){this->texto.append("H");}
			if(input->isKeyDown(SDLK_i)){this->texto.append("I");}
			if(input->isKeyDown(SDLK_j)){this->texto.append("J");}
			if(input->isKeyDown(SDLK_k)){this->texto.append("K");}
			if(input->isKeyDown(SDLK_l)){this->texto.append("L");}
			if(input->isKeyDown(SDLK_m)){this->texto.append("M");}
			if(input->isKeyDown(SDLK_n)){this->texto.append("N");}
			if(input->isKeyDown(SDLK_o)){this->texto.append("O");}
			if(input->isKeyDown(SDLK_p)){this->texto.append("P");}
			if(input->isKeyDown(SDLK_q)){this->texto.append("Q");}
			if(input->isKeyDown(SDLK_r)){this->texto.append("R");}
			if(input->isKeyDown(SDLK_s)){this->texto.append("S");}
			if(input->isKeyDown(SDLK_t)){this->texto.append("T");}
			if(input->isKeyDown(SDLK_u)){this->texto.append("U");}
			if(input->isKeyDown(SDLK_v)){this->texto.append("V");}
			if(input->isKeyDown(SDLK_x)){this->texto.append("X");}
			if(input->isKeyDown(SDLK_w)){this->texto.append("W");}
			if(input->isKeyDown(SDLK_y)){this->texto.append("Y");}
			if(input->isKeyDown(SDLK_z)){this->texto.append("Z");}
		}

		if(input->isKeyDown(SDLK_BACKSPACE) && this->texto.length() > 0){
			this->texto.erase(this->texto.length()-1,1);
			if(this->texto.length() == 0) {this->textoIniciais->setText(" ");}
		}

		if(input->isKeyDown(SDLK_RETURN) && this->texto.compare(" ")) {
			while(this->texto.length() < 3) {
				this->texto.append(" ");
			}
			buf << GameManager::tempoFinal/1000;
			buf >> res;
			buf2 << GameManager::totalPortal;
			buf2 >> res2;

			/*fstream arquivo;
			arquivo.open("scoreTeintein.txt", fstream::in | fstream::out | fstream::app);
			arquivo.write(this->texto.c_str(),3);
			arquivo.write("*",1);
			arquivo.write(res.c_str(),res.length());
			arquivo.write("*",1);
			arquivo.write(res2.c_str(),res2.length());
			arquivo.write("\n",1);
			arquivo.close();*/

			registro reg;
			reg.nome = this->texto;
			reg.tempo = GameManager::tempoFinal/1000;
			reg.valorTempo = res;
			reg.numPortal = res2;
			this->reg[4] = reg;

			for(int i = 0; i < 5; i++) {
				for(int j = 0; j < 5; j++) {
					if(j < 4 && this->reg[j].tempo > this->reg[j+1].tempo) {
						reg = this->reg[i+1];
						this->reg[j+1] = this->reg[j];
						this->reg[j] = reg;
					}
				}
			}

			return -2;
		}

		if(this->texto.length() > 0) {this->textoIniciais->setText(this->texto);}

	}

	return 0;
}

void SplashState::Render(SDL_Surface* tela){
	if(this->botaoMainMenu != NULL) {
		this->fundoRecords->Render(tela);
		this->botaoMainMenu->Render(tela);
		this->posCabecalho->render(tela);
		this->nomeCabecalho->render(tela);
		this->tempoCabecalho->render(tela);
		this->numPortalCabecalho->render(tela);
	}

	if(this->botaoQuit != NULL) {
		this->fundoMenuPrincipal->Render(tela);
		this->botaoQuit->Render(tela);
		this->botaoRecords->Render(tela);
		this->botaoStart->Render(tela);
	}

	if(this->botaoMainMenu == NULL && this->botaoQuit == NULL) {
		this->fundoRecords->Render(tela);
		this->iniciais->Render(tela);
		this->textoIniciais->render(tela);
	}
}

void SplashState::Unload(){}
