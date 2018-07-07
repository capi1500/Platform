//
// Created by capi1500 on 6/17/18.
//

#include <config.h>
#include "counter.hpp"

void Counter::draw(sf::RenderWindow& targetWindow, Alphabet& alphabet){
	GraphicString::draw(targetWindow, alphabet);
}

void Counter::updateText(){
	setText(std::to_string(points));
}

void Counter::increment(){
	points++;
	updateText();
}

void Counter::setPoints(int val){
	points = val;
	updateText();
}

void Counter::reset(){
	points = 0;
	updateText();
}

unsigned int Counter::getPoints() const{
	return points;
}


Counter::Counter(std::string texturePath, sf::FloatRect rect, std::string name) : GraphicString(texturePath, rect, name){
	setPosition(sf::Vector2f(rect.left, rect.top));
	setStartCoord(getPosition());
	reset();
	objectType = ObjectType::Counter;
}