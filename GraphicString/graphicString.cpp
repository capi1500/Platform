//
// Created by capi1500 on 6/20/18.
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <alphabet.hpp>
#include <config.h>
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

void GraphicString::draw(){
	unsigned h = 0;
	startCoord = getPosition();
	move(sf::Vector2f(-static_cast<float>(alphabet.getWidth()) * lettersScaling * getScale().x * properties.length[h] / 2, -static_cast<float>(alphabet.getHeight()) * lettersScaling * getScale().y * properties.lines / 2));
	for(auto it = text.begin(); it != text.end(); it++){
		alphabet.drawChar(*it, window, getPosition(), getScale(), color);
		if(*it == '\n'){
			h++;
			setPosition(sf::Vector2f(getStartCoord().x, getPosition().y));
			move(sf::Vector2f(-static_cast<float>(alphabet.getWidth()) * lettersScaling * getScale().x * properties.length[h] / 2, alphabet.getHeight() * lettersScaling * getScale().y));
		}
		else{
			move(sf::Vector2f(alphabet.getWidth() * lettersScaling * getScale().x, 0));
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

void GraphicString::setTextColor(sf::Color color){
	this->color = color;
}

GraphicString::GraphicString(sf::RenderWindow& window, Alphabet& alphabet, sf::Vector2f position, std::string text, std::string texturePath, std::string name) : alphabet(alphabet), Object(window, texturePath, position, name){
	setText(text);
	color = sf::Color(255, 255, 255);
	objectType = ObjectType::GraphicString;
}