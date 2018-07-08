//
// Created by capi1500 on 08/07/18.
//

#ifndef PLATFORM_MENU_HPP
#define PLATFORM_MENU_HPP

#include <vector>
#include <Object/object.hpp>

class Menu : public Object{
	protected:
		sf::FloatRect rect;
		std::vector<Object*> object;
	public:
		void addObject(Object* newObj);
		
		void draw();
		ObjectPassResult pass(sf::Time elapsedTime);
		void handleEvent(sf::Event event);
		
		Menu(sf::RenderWindow& window, std::string texturePath, std::string name = "default", sf::Vector2f position = sf::Vector2f(0, 0));
};

#endif //PLATFORM_MENU_HPP
