/*
 * Classe Text, para renderização de texto.
 */

#include "Text.h"

Text::Text(std::string text, std::string fontText, Vector2 pos, int tamanho) {

	if(font = TTF_OpenFont(fontText.c_str(), tamanho))
		TTF_SetFontStyle(font, TTF_STYLE_BOLD);
	else{
		printf("nao deu pra iniciar o texto\n");
		//	exit(0);
	}	
	color.r = 0;
	color.g = 0;
	color.b = 0;

	this->text = text;
	this->pos = pos;

	if(this->text.empty()) {
		this->text = std::string(" ");
	}
	if(font)
		textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), color);

	rect.x = pos.x;
	rect.y = pos.y;
	if(textSurface){
		rect.w = textSurface->w;
		rect.h = textSurface->h;
	}

}

Text::~Text() {
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);
}

void Text::setText(std::string text) {
	this->text = text;

	if(this->text.empty()) {
		this->text = std::string(" ");
	}

	SDL_FreeSurface(textSurface);
	textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), color);

	rect.x = pos.x;
	rect.y = pos.y;
	rect.w = textSurface->w;
	rect.h = textSurface->h;
}

void Text::render(SDL_Surface *screen) {
	rect.x = pos.x;
	rect.y = pos.y;
	SDL_BlitSurface(textSurface, NULL, screen, &rect);
}

void Text::setColor(int r, int g, int b) {
	color.r = r;
	color.g = g;
	color.b = b;
}
