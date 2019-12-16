#ifndef SPLASHSTATE_H_
#define SPLASHSTATE_H_

#include <fstream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>
#include "Sprite.h"
#include "State.h"
#include <string>
#include "Teinstein.h"
#include "Text.h"

class SplashState:public State   {
struct registro {
	std::string nome;
	int tempo;
	std::string numPortal;
	std::string valorTempo;
};

public:
	Sprite* botaoStart;
	Sprite* botaoQuit;
	Sprite* botaoRecords;
	Sprite* botaoMainMenu;
	Sprite *fundoMenuPrincipal;
	Sprite *fundoRecords;
	Sprite *iniciais;
	Text* textoIniciais;
	Text* posCabecalho;
	Text* nomeCabecalho;
	Text* numPortalCabecalho;
	Text* tempoCabecalho;
	Text *pos1,*pos2,*pos3,*pos4;
	Text *nome1, *nome2, *nome3, *nome4;
	Text *numPortal1, *numPortal2, *numPortal3, *numPortal4;
	Text *tempo1, *tempo2, *tempo3, *tempo4;
	registro reg[5];
	std::string texto;
	SplashState(std::string planoFundoMenu,std::string botaoStart,std::string botaoQuit,std::string botaoRecords, InputManager*);
	SplashState(std::string planoFundoRecords,std::string botaoMainMenu, InputManager*);
	SplashState(std::string planoFundoRecords, InputManager*);
	int Update(int dt);
	void Render(SDL_Surface* tela);
	void Unload();
	InputManager* input;
};
#endif
