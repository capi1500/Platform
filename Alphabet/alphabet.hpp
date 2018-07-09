//
// Created by capi1500 on 6/20/18.
//

#ifndef ONEWEEKCHALLANGE_ALPHABET_HPP
#define ONEWEEKCHALLANGE_ALPHABET_HPP

#include <SFML/Graphics/Rect.hpp>
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Alphabet{
	private:
		sf::Image image;
		std::map<char, sf::IntRect> charRectangles;
		unsigned width;
		unsigned height;
		
		void init();
	public:
		void drawChar(char val, sf::RenderWindow& renderWindow, sf::Vector2f coord, sf::Vector2f localScale, sf::Color color = sf::Color(255, 255, 255));
		unsigned int getHeight() const;
		unsigned int getWidth() const;
		
		Alphabet();
};

#endif //ONEWEEKCHALLANGE_ALPHABET_HPP
