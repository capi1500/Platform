//
// Created by capi1500 on 09/07/18.
//

#ifndef PLATFORM_PORTAL_HPP
#define PLATFORM_PORTAL_HPP

#include <PhysicObject/physicObject.hpp>

class Portal : public PhysicObject{
	private:
		std::string target;
	public:
		const std::string& getTarget() const;
		void setTarget(const std::string& target);
		
		ObjectPassResult pass(sf::Time elapsedTime);
		
		Portal(sf::RenderWindow& window, b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath = "");
};

#endif //PLATFORM_PORTAL_HPP
