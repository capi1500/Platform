//
// Created by capi1500 on 06/07/18.
//

#ifndef PLATFORM_ENTITY_HPP
#define PLATFORM_ENTITY_HPP

#include <PhysicObject/physicObject.hpp>

struct EntityProperties{
	int maxHP;
	int HP;
	EntityProperties(int HP = 0);
};

class Entity : public PhysicObject{
	protected:
		EntityProperties properties;

		bool onGround();
	public:
		ObjectPassResult pass(sf::Time elapsedTime);
		
		Entity(sf::RenderWindow& window, b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath = "");
};

#endif //PLATFORM_ENTITY_HPP
