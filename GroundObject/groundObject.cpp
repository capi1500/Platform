//
// Created by capi1500 on 06/07/18.
//

#include "groundObject.hpp"

GroundObject::GroundObject(b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath) : PhysicObject(world, objectRef, properties, texturePath){
	objectType = ObjectType::Ground;
}