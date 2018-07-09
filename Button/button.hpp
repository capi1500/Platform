//
// Created by capi1500 on 08/07/18.
//

#ifndef PLATFORM_BUTTON_HPP
#define PLATFORM_BUTTON_HPP

#include <Label/label.hpp>

class Button : public Label{
	protected:
		void* context;
		void (*onClick)(void*);
		bool played;
	public:
		void handleEvent(sf::Event event);
		void handleEvent();
		ObjectPassResult pass(sf::Time elapsedTime);
		
		Button(void (*fun)(void*), void* context, sf::RenderWindow& window, std::string texturePath, sf::Vector2f rect, Alphabet& alphabet, std::string text = "", std::string name = "default");
};

#endif //PLATFORM_BUTTON_HPP
