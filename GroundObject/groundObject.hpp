//
// Created by capi1500 on 06/07/18.
//

#ifndef PLATFORM_GROUNDOBJECT_HPP
#define PLATFORM_GROUNDOBJECT_HPP

#include <PhysicObject/physicObject.hpp>

class GroundObject : public PhysicObject{
	public:
		GroundObject(b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath = "");
};

#endif //PLATFORM_GROUNDOBJECT_HPP
