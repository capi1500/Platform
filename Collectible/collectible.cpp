//
// Created by capi1500 on 07/07/18.
//

#include "collectible.hpp"

bool Collectible::colide(PhysicObject* obj){
	sf::FloatRect o1 = obj->getGlobalBounds(), o2 = getGlobalBounds();
	if(not collected and o1.top + o1.height > o2.top and o1.top < o2.top + o2.height and o1.left + o1.width > o2.left and o1.left < o2.left + o2.width )
		return true;
	return false;
}

void Collectible::draw(sf::RenderWindow& window){
	if(not collected){
		Object::draw(window);
	}
}

void Collectible::collect(){
	collected = true;
	playSound("Audio/laser.ogg");
}

Collectible::Collectible(b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath) : PhysicObject(world, objectRef, properties, texturePath){
	objectType = ObjectType::Collectible;
	collected = false;
}