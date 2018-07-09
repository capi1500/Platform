//
// Created by capi1500 on 07/07/18.
//

#include "collectible.hpp"

bool Collectible::isCollected(){
	return collected;
}

bool Collectible::colide(PhysicObject* obj){
	sf::FloatRect o1 = obj->getGlobalBounds(), o2 = getGlobalBounds();
	if(not collected and o1.top + o1.height > o2.top and o1.top < o2.top + o2.height and o1.left + o1.width > o2.left and o1.left < o2.left + o2.width )
		return true;
	return false;
}

void Collectible::draw(){
	if(not collected){
		Object::draw();
	}
}

void Collectible::collect(bool quiet){
	collected = true;
	if(not quiet){
		playSound("Audio/RPG-SFX/item_coins_04.ogg");
	}
}

Collectible::Collectible(sf::RenderWindow& window, b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath) : PhysicObject(window, world, objectRef, properties, texturePath){
	objectType = ObjectType::Collectible;
	collected = false;
}

int Collectible::getAmmount() const{
	return ammount;
}

void Collectible::setAmmount(int ammount){
	Collectible::ammount = ammount;
}
