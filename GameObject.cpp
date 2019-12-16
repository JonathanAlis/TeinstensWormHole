#include "GameObject.h"

GameObject::GameObject(std::string nome_arq, int x, int y){
	sprite = new Sprite(nome_arq, x, y);
	this->x = x;
	this->y = y;
	massa=0;
	 }


void GameObject::Render(SDL_Surface* tela){
		sprite->UpdatePos(x,y);
		sprite->Render(tela);

	 }

void GameObject::Update(int dt){
	 return ;
	 }
	 
void GameObject::setX(int x){
	this->x = x;
	}


void GameObject::setY(int y){
	this->y = y;
	}	 
	
void GameObject::setMassa(float m){
	this->massa=m;
}
	
void GameObject::setVel(Vector2 vel){
		velocidade=vel;
	}

bool GameObject::colidiu(GameObject* b){
	if(this->massa==0 || b->massa==0)return false;
	if(sqrt((this->x-b->x)*(this->x-b->x)+(this->y-b->y)*(this->y-b->y))<=(this->sprite->GetRect().w/2+b->sprite->GetRect().w/2))
	return true;
	else return false;
}

bool GameObject::aproxima(GameObject* b){

	float x=(this->posicao.x+this->velocidade.x)-(b->posicao.x+b->velocidade.x);
	float y=(this->posicao.y+this->velocidade.y)-(b->posicao.y+b->velocidade.y);
	if((x*x+y*y)<(this->x-b->x)*(this->x-b->x)+(this->y-b->y)*(this->y-b->y))return true;
	return false;
}

void GameObject::aplica_colisao(GameObject* b){

	float xa=((this->massa-b->massa)/(this->massa+b->massa))*this->velocidade.x+((2*b->massa)/(this->massa+b->massa))*b->velocidade.x;
	float ya=((this->massa-b->massa)/(this->massa+b->massa))*this->velocidade.y+((2*b->massa)/(this->massa+b->massa))*b->velocidade.y;
	float xb=((b->massa-this->massa)/(b->massa+this->massa))*b->velocidade.x+((2*this->massa)/(b->massa+this->massa))*this->velocidade.x;
	float yb=((b->massa-this->massa)/(b->massa+this->massa))*b->velocidade.y+((2*this->massa)/(b->massa+this->massa))*this->velocidade.y;
	this->setVel(Vector2(xa,ya));
	b->setVel(Vector2(xb,yb));
}

bool GameObject::colidiu(Sprite *coliSprite) {
	int diffX, diffY;

	diffX = x - coliSprite->x;
	diffY = y - coliSprite->y;

	if (diffX > coliSprite->retangulo.w || (diffX * -1) > sprite->retangulo.w) {return false;}

	if (diffY > coliSprite->retangulo.h || (diffY * -1) > sprite->retangulo.h) {return false;}
	
	return true;

}
