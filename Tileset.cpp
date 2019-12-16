/*
 * Classe de Tileset. Possui um array de tiles.
 */

#include "Tileset.h"
#include <SDL/SDL_image.h>

Tileset::Tileset(int tileSize) : tileSize(tileSize) {

}
Tileset::Tileset(std::string bmpFile, int nx, int ny){
SDL_Surface *surface = IMG_Load(bmpFile.c_str());
SDL_Rect ret;
ret.x=0;
ret.y=0;
ret.w=surface->w/nx;
ret.h=surface->h/ny;
		for (int i=0;i<nx;i++)
			for (int j=0;j<ny;j++){
				ret.x=ret.w*i;
				ret.y=ret.w*j;
				SDL_SetClipRect(surface, &ret);
				tiles.push_back(surface);
			}
tileSize=nx*ny;
}
Tileset::~Tileset() {

}

void Tileset::addBMPTile(std::string bmpFile) {
	SDL_Surface *surface = IMG_Load(bmpFile.c_str());
	tiles.push_back(surface);
}
