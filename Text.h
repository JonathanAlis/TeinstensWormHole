/*
 * Classe Text, para renderização de texto (simplificada).
 */

#ifndef TEXT_H_
#define TEXT_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <iostream>

#include "Vector2.h"
class Vector2;

class Text {
public:
	Text(std::string text, std::string fontText, Vector2 pos,int tamanho);
	virtual ~Text();

	TTF_Font *font;
	std::string text;
	char *fontFile;
	int style;
	SDL_Surface *textSurface;
	SDL_Color color;
	SDL_Rect rect;
	Vector2 pos;
	int psize;


	void setText(std::string text);
	void render(SDL_Surface *screen);
	void setColor(int red, int green, int blue);

};

#endif /* TEXT_H_ */
