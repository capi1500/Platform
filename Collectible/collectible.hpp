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
		int ammount;
	public:
		int getAmmount() const;
		
		void setAmmount(int ammount);
	
	public:
		bool colide(PhysicObject* obj);
		void collect(bool quiet = false);
		
		bool isCollected();
		
		void draw();
		
		Collectible(sf::RenderWindow& window, b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath = "");
};

#endif //PLATFORM_COLLECTIBLE_HPP
