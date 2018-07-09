//
// Created by capi1500 on 6/20/18.
//

#include <SFML/Graphics/Sprite.hpp>
#include <config.h>
#include "alphabet.hpp"

void Alphabet::drawChar(char val, sf::RenderWindow& renderWindow, sf::Vector2f coord, sf::Vector2f localScale, sf::Color color){
	if(val == ' ' or val == '\t' or val == '\n')
		return;
	sf::Texture texture;
	texture.loadFromImage(image, charRectangles[val]);
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(coord);
	sprite.setColor(color);
	sprite.setScale(lettersScaling * localScale.x, lettersScaling * localScale.y);
	renderWindow.draw(sprite);
}

void Alphabet::init(){
	if(not image.loadFromFile("Fonts/font-20x20.png")){
		throw "gupia textura sie nie laduje";
	}
	width = height = 20;
	int i = 0, j = 0;
	for(auto c : std::vector<char>{
			'\t', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.',
			'/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
			'>', '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[',
			'\\', ']', '^', '_', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
			'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
			'Z', '{', '|', '}', '~', '\n'
	}){;
		charRectangles[c] = sf::IntRect((i % 15) * width, j * height, width, height);
		i++;
		if(i % 15 == 0)
			j++;
	}
}

Alphabet::Alphabet(){
	init();
}

unsigned int Alphabet::getWidth() const{
	return width;
}

unsigned int Alphabet::getHeight() const{
	return height;
}
