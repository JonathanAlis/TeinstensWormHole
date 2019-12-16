/*
 * g++ -L/usr/include/SDL -o lab3 main.cpp Animation.cpp Sprite.cpp Vector2.cpp GameManager.cpp State.cpp SplashState.cpp LevelState.cpp ColisionState.cpp Fase.cpp Teinstein.cpp Parede.cpp Audio.cpp GameObject.cpp InputManager.cpp PongBall.cpp FallingBall.cpp Tileset.cpp Tilemap.cpp TileState.cpp -lGL -lGLU -lSDL -lSDLmain -lSDL_image -lSDL_gfx  -lSDL_ttf -lSDL_mixer


 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_


#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <SDL/SDL_framerate.h>
#include <string>
#include <sstream>
#include "State.h"
#include "LevelState.h"
#include "SplashState.h"
#include "ColisionState.h"
#include "TileState.h"
//#include "Sprite.h"
#include "Timer.h"
#include "Text.h"
//#include "InputManager.h"

class GameManager {
public:
	GameManager();
	virtual ~GameManager();
	void run();
	static const int WIDTH             = 1351;
	static const int HEIGHT            = 651;
	static const int ICONS             = 8;
	static const int TAXA_FPS			=24;
	SDL_Surface *screen;
	FPSmanager *manex;
	State *estadoAtual;
	int dt;
	Timer *tempoTotal;				// Tempo total do jogo, na GameManager essa variavel na apaga ate o fim do jogo
	static int totalPortal;			// Numero total de portais
	static int tempoFinal;
};

#endif /* GameManager_H_ */
