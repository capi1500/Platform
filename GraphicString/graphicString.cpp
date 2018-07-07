//
// Created by capi1500 on 6/20/18.
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <alphabet.hpp>
#include "graphicString.hpp"

void StringProperties::reset(){
	lines = 0;
	length.resize(0);
}

void GraphicString::updateTextProperties(){
	properties.reset();
	unsigned h = 0;
	for(auto i : text){
		if(i == '\n'){
			properties.lines++;
			properties.length.push_back(h);
			h = 0;
		}
		else{
			h++;
		}
	}
	if(text[text.size() - 1] != '\n'){
		properties.lines++;
		properties.length.push_back(h);
	}
}

void GraphicString::draw(sf::RenderWindow& targetWindow, Alphabet& alphabet){
	unsigned h = 0;
	move(sf::Vector2f(-static_cast<float>(alphabet.getWidth()) * properties.length[h] / 2, -static_cast<float>(alphabet.getHeight()) * properties.lines / 2));
	for(auto it = text.begin(); it != text.end(); it++){
		alphabet.drawChar(*it, targetWindow, getPosition());
		if(*it == '\n'){
			h++;
			setPosition(sf::Vector2f(getStartCoord().x, getPosition().y));
			move(sf::Vector2f(-static_cast<float>(alphabet.getWidth()) * properties.length[h] / 2, alphabet.getHeight()));
		}
		else{
			move(sf::Vector2f(alphabet.getWidth(), 0));
		}
	}
	setPosition(getStartCoord());
}

const sf::Vector2f& GraphicString::getStartCoord() const{
	return startCoord;
}

void GraphicString::setStartCoord(const sf::Vector2f& startCoord){
	GraphicString::startCoord = startCoord;
}

const std::string& GraphicString::getText() const{
	return text;
}

void GraphicString::setText(const std::string& text){
	GraphicString::text = text;
	updateTextProperties();
}

GraphicString::GraphicString(std::string texturePath, sf::FloatRect rect, std::string name){
	objectType = ObjectType::GraphicString;
}