//
// Created by capi1500 on 6/28/18.
//

#include <config.h>
#include "object.hpp"

ObjectPassResult Object::pass(sf::Time elapsedTime){
	localTime += elapsedTime;
}

void Object::draw(){
	window.draw(*this);
}

void Object::handleEvent(sf::Event event){

}

void Object::handleEvent(){

}

void Object::playSound(std::string name){
	if(soundIDs.find(name) != soundIDs.end()){
		sounds[soundIDs[name]].play();
	}
}

void Object::pauseSound(std::string name){
	if(soundIDs.find(name) != soundIDs.end()){
		sounds[soundIDs[name]].pause();
	}
}

bool Object::addSound(std::vector<std::string>& list){
	unsigned added = 0;
	for(auto i : list){
		if(not addSound(i)){
			while(added--){
				soundIDs.erase(soundNames[soundNames.size() - 1]);
				sounds.pop_back();
				soundNames.pop_back();
			}
			return false;
		}
		added++;
	}
	return true;
}

bool Object::addSound(std::string path){
	try{
		soundIDs[path] = sounds.size();
		sounds.push_back(Sound(path));
		soundNames.push_back(path);
	} catch(std::string s){
		printf("ERROR: %s\n", s.c_str());
		return false;
	}
	return true;
}

std::vector<std::string>& Object::getSoundList(){
	return soundNames;
}

std::string Object::getName(){
	return name;
}

sf::Vector2f Object::getCentre(){
	return getPosition() + sf::Vector2f(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
}

void Object::setCentre(sf::Vector2f centre){
	setPosition(centre.x - getGlobalBounds().width / 2, centre.y - getGlobalBounds().height / 2);
}

void Object::setCentre(float x, float y){
	setCentre(sf::Vector2f(x, y));
}

ObjectType Object::getObjectType(){
	return objectType;
}

std::string Object::getTexturePath(){
	return texturePath;
}

Object::Object(sf::RenderWindow& window, std::string texturePath, sf::Vector2f rect, std::string name) : window(window){
	this->texturePath = texturePath;
	texture.loadFromFile(texturePath);
	setTexture(texture);
	setPosition(rect);
	this->name = name;
	objectType = ObjectType::Object;
}

Object::~Object(){
	sounds.erase(sounds.begin(), sounds.end());
	soundIDs.erase(soundIDs.begin(), soundIDs.end());
	soundNames.erase(soundNames.begin(), soundNames.end());
}