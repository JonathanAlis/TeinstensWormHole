#include "Audio.h"
Audio::Audio(std::string file, int n){
	fileName=file;
		if(n==0){
			som=Mix_LoadWAV(file.c_str());
			musica=NULL;
		}
		if(n==1){
			musica=Mix_LoadMUS(file.c_str());
			som=NULL;
		}
		
	}
	
	void Audio::play(int n){
		if(musica!=NULL)
		Mix_PlayMusic(musica, n);
		if(som!=NULL)
		Mix_PlayChannel(n, som, 1);	
		}	
		
		void Audio::stop(){
			Mix_Pause(-1);


		}	
