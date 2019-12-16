#include "GameManager.h"

int GameManager::totalPortal = 0;
int GameManager::tempoFinal = 0;

GameManager::GameManager() {

	srand( time(0) );

	SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER );
	SDL_WM_SetCaption("Teinstein WormHole", 0);
	TTF_Init();
	atexit( SDL_Quit );
	screen = SDL_SetVideoMode( WIDTH, HEIGHT, 0, SDL_ANYFORMAT );
	manex = (FPSmanager*) malloc(sizeof(FPSmanager));
	SDL_initFramerate(manex);
	SDL_setFramerate(manex, TAXA_FPS);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024);

	this->tempoTotal = new Timer();
	//this->tempoTotal->Start();
	//this->tempoTotal->Stop();
	GameManager::totalPortal = 0;
	GameManager::tempoFinal = 0;
}

GameManager::~GameManager() {
	// TODO Auto-generated destructor stub
}

void GameManager::run(){

	Uint32 timer = 0, atimer, frame = 1, aux_frame;
	InputManager input = InputManager::getInstance();

	this->estadoAtual = new SplashState("telaInicial.png","botaoStart.png","botaoQuit.png","botaoRecords.png", &input);

	while(!SDL_QuitRequested()) {
		input.Update();
		Uint8 *keyState = SDL_GetKeyState(NULL);
		atimer = timer;
		timer = SDL_GetTicks();
		dt = timer - atimer;
		if(dt>20){
		switch(estadoAtual->Update(dt)) {
			case 0: {
				/* fazer nada */
				break;
			}
			case -1: {	// Tela Principal
				this->estadoAtual->Unload();
				this->estadoAtual = new SplashState("telaInicial.png","botaoStart.png","botaoQuit.png","botaoRecords.png", &input);
				break;
			}
			case -2: {	// Tela de records
				this->estadoAtual->Unload();
				this->estadoAtual = new SplashState("telaRecords.png","botaoMainMenu.png",&input);
				break;
			}
			case 1: {
				estadoAtual->Unload();
				//delete estadoAtual;
				estadoAtual = new LevelState("fundoFase1.png", "teinstein.png",&input,this->tempoTotal,1);	// 1 eh a id da fase
				//estadoAtual.Load();
				break;
			}

			case 2: {
				estadoAtual->Unload();
				//delete estadoAtual;
				estadoAtual = new LevelState("fundoFase2.png", "teinstein.png",&input,this->tempoTotal,2);	// 2 eh a id da fase
				//estadoAtual.Load();
				break;
			}
			case 3: {
				estadoAtual->Unload();
				//delete estadoAtual;
				estadoAtual = new LevelState("fundoFase3.png", "teinstein.png",&input,this->tempoTotal,3);	// 3 eh a id da fase
				//estadoAtual.Load();
				break;
			}
			case 4: {
				estadoAtual->Unload();
				//delete estadoAtual;
				estadoAtual = new LevelState("fundoFase1.png", "teinstein.png",&input,this->tempoTotal,4);	// 4 eh a id da fase
				//estadoAtual.Load();
				break;
			}
			case 5: {
				estadoAtual->Unload();
				//delete estadoAtual;
				estadoAtual = new LevelState("fundoFase4.png", "teinstein.png",&input,this->tempoTotal,5);	// 5 eh a id da fase
				//estadoAtual.Load();
				break;
			}
			case 6: {
				estadoAtual->Unload();
				//delete estadoAtual;
				estadoAtual = new LevelState("fundoFase3.png", "teinstein.png",&input,this->tempoTotal,6);	// 6 eh a id da fase
				//estadoAtual.Load();
				break;
			}
			default: {	// default eh quando o jogo termina
				GameManager::tempoFinal = this->tempoTotal->GetTime();
				this->estadoAtual->Unload();
				this->estadoAtual = new SplashState("telaRecords.png",&input);
				break;
			}

		}

		estadoAtual->Render(screen);

		SDL_Flip(screen);
		SDL_framerateDelay(manex);
		}
	}
}
