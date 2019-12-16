#include "TileState.h"
TileState::TileState(InputManager* input){
		Tileset *tileset = new Tileset(64);
	

	tileset->addBMPTile( "grass1.bmp" );
	tileset->addBMPTile( "grass2.bmp" );
	tileset->addBMPTile( "grass3.bmp" );
	tileset->addBMPTile( "grass4.bmp" );
	tileset->addBMPTile( "roadh.bmp" );
	tileset->addBMPTile( "roadv.bmp" );
	tileset->addBMPTile( "roadtopleft.bmp" );
	tileset->addBMPTile( "roadtopright.bmp" );
	tileset->addBMPTile( "roadbottomleft.bmp" );
	tileset->addBMPTile( "roadbottomright.bmp" );
	tileset->addBMPTile( "snow1.bmp" );
	tileset->addBMPTile( "snow2.bmp" );
	tileset->addBMPTile( "snowright.bmp" );

	tilemap = new Tilemap(tileset, 30, 20);
	for(y = 0; y < tilemap->mapHeight; y++) {
		for(x = 0; x < (tilemap->mapWidth); x++) {
			tilemap->tileMatrix[x][y][0] = rand() % 4;
			
		}
	}
tilemap->tileMatrix[0][0][0] = 11;
this->input=input;
x=0;
y=0;
chao=4;
};
int TileState::Update(int dt){
		
		if(input->isKeyDown(SDLK_UP)){y=(y-1);if(y<0)y+=tilemap->mapHeight;}
		if(input->isKeyDown(SDLK_DOWN))y=(y+1)%tilemap->mapHeight;
		if(input->isKeyDown(SDLK_RIGHT))x=(x+1)%tilemap->mapWidth;
		if(input->isKeyDown(SDLK_LEFT)){x=(x-1);if(x<0)x+=tilemap->mapWidth;}
		if(input->isKeyDown(SDLK_SPACE))chao=(chao+1)%(13);
		if(chao!=12)tilemap->tileMatrix[x][y][0] = chao;
		else tilemap->tileMatrix[x][y][1] = chao;
		if(input->isKeyDown(SDLK_RETURN)) return 1;
		return 0;
	}

	void TileState::Render(SDL_Surface* tela){
				SDL_FillRect(tela, NULL, SDL_MapRGBA( tela->format, 0, 0, 0 , 255) );

		// desenha o tilemap
		tilemap->render(tela);

		// atualiza a tela inteira
		SDL_UpdateRect( tela, 0, 0, 0, 0 );

		
	 }
