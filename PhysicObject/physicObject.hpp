//
// Created by capi1500 on 7/2/18.
//

#ifndef PLATFORM_PHYSICOBJECT_HPP
#define PLATFORM_PHYSICOBJECT_HPP

#include <Object/object.hpp>
#include <Box2D/Box2D.h>

enum class PhysicObjectType{
		Box,
		Circle
};

struct PhysicObjectProperties{
	bool dynamic;
	bool kinematic;
	sf::FloatRect rect;
	float density;
	float friction;
	PhysicObjectType type;
	bool isEntity;
	std::string name;
	PhysicObjectProperties(sf::FloatRect rect, bool dynamic = false, float density = 0, float friction = 0, PhysicObjectType type = PhysicObjectType::Box, bool isEntity = false);
};

class PhysicObject : public Object{
	private:
		PhysicObjectProperties properties;
		b2Body* body;
	protected:
		std::vector<PhysicObject*>& object;
	public:
		ObjectPassResult pass(sf::Time elapsedTime);
		
		void addVelocity(sf::Vector2f velocity);
		b2Body* getBody();
		
		PhysicObject(b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath = "");
};

#endif //PLATFORM_PHYSICOBJECT_HPP
