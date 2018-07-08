//
// Created by capi1500 on 08/07/18.
//

#include "label.hpp"

void Label::draw(){
	Object::draw();
	sf::Vector2f position = getPosition();
	setStartCoord(getCentre());
	setPosition(getCentre());
	GraphicString::draw();
	setPosition(position);
}

sf::FloatRect Label::getTextRect(){
	sf::FloatRect out;
	out.height = properties.lines * alphabet.getHeight();
	for(auto i : properties.length){
		out.width = std::max(static_cast<unsigned>(out.width), i * alphabet.getWidth());
	}
	out.left = getCentre().x - out.width / 2;
	out.top = getCentre().y - out.height / 2;
	return out;
}

Label::Label(sf::RenderWindow& window, std::string texturePath, sf::Vector2f rect, Alphabet& alphabet, std::string text, std::string name) : GraphicString(window, alphabet, rect, text, texturePath, name){
	objectType = ObjectType::Label;
}