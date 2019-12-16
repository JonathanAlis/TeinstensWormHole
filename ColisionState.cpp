#include "ColisionState.h"


	ColisionState::ColisionState(InputManager* input):State(){
		printf("estado 2\n");
	this->input=input;
	
	fundo=new Sprite("fundo.jpg", 0, 0);
	audio1=new Audio("music01.mp3",1);
	audio2=new Audio("sfx01.wav",0);
	//audio1->play(-1);
	fundo = new Sprite("fundo.jpg", 0, 0);
	bola = new PongBall("redball.png", 300,100, Vector2(0.3,2), 20,input);
	bola1 = new PongBall("redball.png", 200,100, Vector2(-0.1,0.1), 20,input);
	bola2 = new PongBall("redball.png", 100,100, Vector2(-0.1,-0.1), 20,input);
	bola3 = new PongBall("greenball.png", 400,100, Vector2(-0.1,0.1), 5,input);
	bola4 = new PongBall("greenball.png", 100,400, Vector2(-0.1,-0.1), 5,input);
	bola5 = new PongBall("greenball.png", 200,400, Vector2(-0.1,0.1), 5,input);
	bola6 = new PongBall("greenball.png", 400,300, Vector2(-0.1,-0.1), 5,input);
	bolaQcai = new FallingBall("blueball.png", 300,0,20);


	objetos.push_back(bola);
	objetos.push_back(bola1);
	objetos.push_back(bola2);
	objetos.push_back(bola3);
	objetos.push_back(bola4);
	objetos.push_back(bola5);
	objetos.push_back(bola6);

	objetos.push_back(bolaQcai);

	}
	
	
	int ColisionState::Update(int dt){
		colisao(objetos);
		bola->Update(dt);
		bola1->Update(dt);
		bola2->Update(dt);
		bola3->Update(dt);
		bola4->Update(dt);
		bola5->Update(dt);
		bola6->Update(dt);
		bolaQcai->Update(dt);
		if(input->isKeyDown(SDLK_RETURN))return 3;
		return 0;
	}
	
	void ColisionState::Render(SDL_Surface* tela){
	fundo->Render(tela);
	bola->Render(tela);
	bola1->Render(tela);
	bola2->Render(tela);
	bola3->Render(tela);
	bola4->Render(tela);
	bola5->Render(tela);
	bola6->Render(tela);
	bolaQcai->Render(tela);


	 }

	void ColisionState::Unload(){//audio1->stop();
	}
	
	
void colisao(std::list<GameObject*> objetos){
	//
	for(std::list<GameObject*>::iterator it = objetos.begin();
			it != objetos.end(); ++it) {
				std::list<GameObject*>::iterator aux= it;
				for(std::list<GameObject*>::iterator it2 = aux++;
					it2 != objetos.end(); ++it2) {
						GameObject* obj1=*it;
						GameObject* obj2=*it2;
				
						obj1->colidiu(obj2);
						obj1->aproxima(obj2);
						if(obj1->colidiu(obj2)&&obj1->aproxima(obj2)){
							obj1->aplica_colisao(obj2);
							//audio2->play(-1);
						}
				}
	}
}
