//
// Created by capi1500 on 06/07/18.
//

#include <iostream>
#include <config.h>
#include "entity.hpp"

EntityProperties::EntityProperties(int HP){
	this->maxHP = this->HP = HP;
}

ObjectPassResult Entity::pass(sf::Time elapsedTime){
	PhysicObject::pass(elapsedTime);
	return ObjectPassResult::OK;
}

bool Entity::onGround(){
	for(auto* contact = getBody()->GetContactList(); contact; contact = contact->next){
		for(auto obj : object){
			if(contact->other == obj->getBody() and contact->contact->IsTouching()){
				if(obj->getObjectType() == ObjectType::Ground or obj->getObjectType() == ObjectType::PhysicalObject){
					sf::FloatRect o1 = getGlobalBounds(), o2 = obj->getGlobalBounds();
					if(o1.top + o1.height <= o2.top and o1.left + o1.width > o2.left and o1.left < o2.left + o2.width){
						return true;
					}
				}
			}
		}
	}
	return false;
}

Entity::Entity(b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath) : PhysicObject(world, objectRef, properties, texturePath){
	objectType = ObjectType::Entity;
}
