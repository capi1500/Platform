//
// Created by capi1500 on 08/07/18.
//

#include "button.hpp"

void Button::handleEvent(sf::Event event){
	if(event.type == sf::Event::MouseButtonPressed){
		if(getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) or getTextRect().contains(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))){
			localTime = sf::milliseconds(0);
			onClick(context);
		}
	}
}

void Button::handleEvent(){

}

ObjectPassResult Button::pass(sf::Time elapsedTime){
	Object::pass(elapsedTime);
	if(localTime <= sf::milliseconds(100)){
		setTextColor(sf::Color(128, 0, 0));
	}
	else if(getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) or getTextRect().contains(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))){
		setTextColor(sf::Color(255, 63, 63));
	}
	else{
		setTextColor(sf::Color(255, 255, 255));
	}
	ObjectPassResult::OK;
}

Button::Button(void (*fun)(void*), void* context, sf::RenderWindow& window, std::string texturePath, sf::Vector2f rect, Alphabet& alphabet, std::string text, std::string name) : onClick(fun), context(context), Label(window, texturePath, rect, alphabet, text, name){
	objectType = ObjectType::Button;
	localTime = sf::milliseconds(101);
}