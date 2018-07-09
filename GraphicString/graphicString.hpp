//
// Created by capi1500 on 6/20/18.
//

#ifndef ONEWEEKCHALLANGE_GRAPHICSTRING_HPP
#define ONEWEEKCHALLANGE_GRAPHICSTRING_HPP

#include <object.hpp>
#include <alphabet.hpp>

struct StringProperties{
	unsigned lines;
	std::vector<unsigned> length;
	
	void reset();
};

class GraphicString : public Object{
	protected:
		sf::Vector2f startCoord;
		std::string text;
		StringProperties properties;
		Alphabet& alphabet;
		sf::Color color;
		
		void updateTextProperties();
	public:
		const sf::Vector2f& getStartCoord() const;
		void setStartCoord(const sf::Vector2f& startCoord);
		const std::string& getText() const;
		void setText(const std::string& text);
		void setTextColor(sf::Color color);
		
		void draw();
		
		GraphicString(sf::RenderWindow& window, Alphabet& alphabet, sf::Vector2f position = sf::Vector2f(0, 0), std::string text = "", std::string texturePath = "", std::string name = "default");
};

#endif //ONEWEEKCHALLANGE_GRAPHICSTRING_HPP
