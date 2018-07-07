//
// Created by capi1500 on 07/07/18.
//

#ifndef PLATFORM_PLAYER_HPP
#define PLATFORM_PLAYER_HPP

#include <Entity/entity.hpp>

class Player : public Entity{
	private:
		std::map<std::string, unsigned> collected;
	public:
		ObjectPassResult pass(sf::Time elapsedTime);
		void handleEvent();
		unsigned getCollectible(std::string name);
		
		Player(b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath = "");
};

#endif //PLATFORM_PLAYER_HPP
