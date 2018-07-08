//
// Created by capi1500 on 08/07/18.
//

#ifndef PLATFORM_LABEL_HPP
#define PLATFORM_LABEL_HPP

#include <Object/object.hpp>
#include <GraphicString/graphicString.hpp>

class Label : public GraphicString{
	public:
		void draw();
		sf::FloatRect getTextRect();
		
		Label(sf::RenderWindow& window, std::string texturePath, sf::Vector2f rect, Alphabet& alphabet, std::string text = "", std::string name = "default");
};

#endif //PLATFORM_LABEL_HPP
