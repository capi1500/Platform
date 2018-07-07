//
// Created by capi1500 on 6/28/18.
//

#include <config.h>
#include "object.hpp"

ObjectPassResult Object::pass(sf::Time elapsedTime){
	localTime += elapsedTime;
}

void Object::draw(sf::RenderWindow& window){
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
		if(not addSound(list)){
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

std::string Object::getName(){
	return name;
}

sf::Vector2f Object::getCentre(){
	return getPosition()/* - sf::Vector2f(getGlobalBounds().width / 2, getGlobalBounds().height / 2)*/;
}

ObjectType Object::getObjectType(){
	return objectType;
}

Object::Object(std::string texturePath, sf::FloatRect rect, std::string name){
	texture.loadFromFile(texturePath);
	setTexture(texture);
	setPosition(rect.left, rect.top);
	this->name = name;
	objectType = ObjectType::Object;
}

Object::Object(){
	objectType = ObjectType::Object;
}