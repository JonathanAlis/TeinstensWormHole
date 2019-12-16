/* Para Compilar:
 * g++ -L/usr/include/SDL -o teintein main.cpp Animation.cpp Sprite.cpp Vector2.cpp GameManager.cpp State.cpp SplashState.cpp LevelState.cpp Fase.cpp Teinstein.cpp Parede.cpp Audio.cpp GameObject.cpp Portal.cpp InputManager.cpp Text.cpp Laser.cpp Timer.cpp -lGL -lGLU -lSDL -lSDLmain -lSDL_image -lSDL_gfx  -lSDL_ttf -lSDL_mixer
 * */
#include "GameManager.h"
int main(int argc, char **argv) {
	GameManager *gameManager;
	gameManager = new GameManager();
	gameManager->run();
	return 0;
}
