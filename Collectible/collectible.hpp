//
// Created by capi1500 on 07/07/18.
//

#ifndef PLATFORM_COLLECTIBLE_HPP
#define PLATFORM_COLLECTIBLE_HPP

#include <Object/object.hpp>
#include <PhysicObject/physicObject.hpp>

class Collectible : public PhysicObject{
	protected:
		bool collected;
	public:
		bool colide(PhysicObject* obj);
		void collect();
		
		void draw(sf::RenderWindow& window);
		
		Collectible(b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath = "");
};

#endif //PLATFORM_COLLECTIBLE_HPP
