/*
 * Classe de mapa. Possui a representação, em forma de matriz,
 * de um mapa.
 */

#include "Tilemap.h"

/**
 * Construtor da tilemap. Recebe o tileset a ser utilizado no mapa,
 * e também seu tamanho.
 *
 * @param tileset o tileset a ser utilizado
 * @param mapWidth a largura do mapa (em número de tiles)
 * @param mapHeight a altura do mapa (em número de tiles)
 *
 */

Tilemap::Tilemap(Tileset *tileset, int mapWidth, int mapHeight):tileMatrix(boost::multi_array<int,3>(boost::extents[mapWidth][mapHeight][2])) {

	/*
	 * TODO: inicializar os atributos da Tilemap e inicializar cada campo
	 * do array do mapa com -1 (para isso, basta percorrer o array)
	 */

	for(int i = 0; i < mapWidth; i++){
		for(int j = 0; j < mapHeight; j++) {
			for(int k = 0; k < 2; k++)
			tileMatrix[i][j][k] = -1;
		}
	}
	camera = new Vector2();
	this->tileset = tileset;
	camera->x = 0;
	camera->y = 0;
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;

}

Tilemap::~Tilemap() {
	delete camera;
}

/**
 * Método de renderização do tilemap na tela.
 *
 * @param screen a tela do jogo
 */
void Tilemap::render(SDL_Surface *screen) {
	/*
	 * TODO: criar o método de renderização da tilemap.
	 * Desenhar cada um dos tiles (que são SDL_Surface) em suas
	 * posições corretas, inclusive de acordo com a câmera.
	 */

	SDL_Rect rect;

	for(int i = 0; i < mapWidth; i++) {
		for(int j = 0; j < mapHeight; j++) {
		  {
			if(tileMatrix[i][j][0] != -1){

				rect.x = i*tileset->tileSize + camera->x;
				rect.y = j*tileset->tileSize + camera->y;
			
				SDL_BlitSurface(tileset->tiles.at(tileMatrix[i][j][0]), NULL, screen, &rect);
			
			}
		 }
		}
	}
	
	for(int i = 0; i < mapWidth; i++) {
		for(int j = 0; j < mapHeight; j++) {
		 {
			if(tileMatrix[i][j][1] != -1)
			{

				rect.x = (i*tileset->tileSize + camera->x);
				rect.y = (j*tileset->tileSize + camera->y);
				tileset->tiles.at(tileMatrix[i][j][1])->format->alpha=255;
				SDL_BlitSurface(tileset->tiles.at(tileMatrix[i][j][1]),  NULL, screen, &rect);
			
			}
		 }
		}
	}
}
