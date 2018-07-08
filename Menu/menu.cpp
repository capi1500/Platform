//
// Created by capi1500 on 08/07/18.
//

#include <Label/label.hpp>
#include "menu.hpp"

void Menu::addObject(Object * newObj){
	object.push_back(newObj);
	if(newObj->getObjectType() == ObjectType::Button or newObj->getObjectType() == ObjectType::Label){
		rect.height += dynamic_cast<Label*>(newObj)->getTextRect().height;
	}
	else{
		rect.height += newObj->getGlobalBounds().height;
	}
}

void Menu::draw(){
	Object::draw();
	sf::Vector2f position = getPosition();
	setPosition(window.getView().getCenter());
	move(0, -rect.height / 2);
	for(auto i : object){
		i->setCentre(getPosition());
		i->draw();
		if(i->getObjectType() == ObjectType::Button or i->getObjectType() == ObjectType::Label){
			move(sf::Vector2f(0, dynamic_cast<Label*>(i)->getTextRect().height));
		}
		else{
			move(sf::Vector2f(0, i->getGlobalBounds().height));
		}
	}
	setPosition(position);
}

void Menu::handleEvent(sf::Event event){
	for(auto i : object){
		i->handleEvent(event);
	}
}

ObjectPassResult Menu::pass(sf::Time elapsedTime){
	for(auto i : object){
		i->pass(elapsedTime);
	}
	return ObjectPassResult::OK;
}

Menu::Menu(sf::RenderWindow& window, std::string texturePath, std::string name, sf::Vector2f position) : Object(window, texturePath, position, name){
}