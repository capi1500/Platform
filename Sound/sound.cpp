//
// Created by capi1500 on 6/28/18.
//

#include "sound.hpp"

void Sound::pause(){
	sound.pause();
}

void Sound::play(){
	sound.setBuffer(buffer);
	sound.play();
	printf("played\n");
}

void Sound::setVolume(float volume){
	sound.setVolume(volume);
}

void Sound::setLoop(bool loop){
	sound.setLoop(loop);
}

Sound::Sound(std::string path = ""){
	if(not buffer.loadFromFile(path)){
		throw "error loading sound: " + path + " may not exist or use unsuported format";
	}
	sound.play();
}