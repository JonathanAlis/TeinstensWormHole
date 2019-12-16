#include "Parede.h"

Parede::Parede(Vector2 i, Vector2 f, int t2, int t1){
	inicio = i;
	fim = f;
	tipo2 = t2;
	tipo = t1;
	sprite = new Sprite(i,f);
}
