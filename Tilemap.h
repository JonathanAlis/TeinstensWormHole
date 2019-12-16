/*
 * Classe de mapa. Possui a representação, em forma de matriz,
 * de um mapa.
 *
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include <iostream>
#include <SDL/SDL.h>
#include <boost/multi_array.hpp>

#include "Tileset.h"
#include "Vector2.h"

class Tileset;
class Vector2;

class Tilemap {
public:
	Tilemap(Tileset *tileset, int mapWidth, int mapHeight);
	virtual ~Tilemap();

	void render(SDL_Surface *screen);


	boost::multi_array<int, 3> tileMatrix;
	Tileset *tileset;
	int mapWidth, mapHeight;
	Vector2 *camera;
};

#endif /* TILEMAP_H_ */
