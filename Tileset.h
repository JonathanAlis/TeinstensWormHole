/*
 * Classe de Tileset. Possui um array de tiles.
 */

#ifndef TILESET_H_
#define TILESET_H_

#include <SDL/SDL.h>
#include <vector>
#include <string>

class Tileset {
public:
	Tileset(int tileSize);
	Tileset(std::string bmpFile, int nx, int ny);
	
	virtual ~Tileset();

	void addBMPTile(std::string bmpFile);
	
	std::vector<SDL_Surface*> tiles;
	int tileSize;
};

#endif /* TILESET_H_ */
