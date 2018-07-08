//
// Created by capi1500 on 6/17/18.
//

#include <config.h>
#include <Label/label.hpp>
#include "counter.hpp"

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


Counter::Counter(sf::RenderWindow& window, std::string texturePath, sf::Vector2f rect, Alphabet& alphabet, std::string text, std::string name) : Label(window, texturePath, rect, alphabet, "0", name){
	reset();
	objectType = ObjectType::Counter;
}