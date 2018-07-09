//
// Created by capi1500 on 09/07/18.
//

#include <Object/object.hpp>
#include "portal.hpp"

const std::string& Portal::getTarget() const{
	return target;
}

void Portal::setTarget(const std::string& target){
	Portal::target = target;
}

ObjectPassResult Portal::pass(sf::Time elapsedTime){
	for(auto* i : object){
		if(i->getObjectType() == ObjectType::Player){
			if(getGlobalBounds().intersects(i->getGlobalBounds())){
				return ObjectPassResult::NewLevel;
			}
		}
	}
	return ObjectPassResult::OK;
}

Portal::Portal(sf::RenderWindow& window, b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath) : PhysicObject(window, world, objectRef, properties, texturePath){
	objectType = ObjectType::Portal;
}