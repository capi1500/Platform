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
	private:
		sf::Vector2f startCoord;
		std::string text;
		StringProperties properties;
		
		void updateTextProperties();
	public:
		const sf::Vector2f& getStartCoord() const;
		void setStartCoord(const sf::Vector2f& startCoord);
		const std::string& getText() const;
		void setText(const std::string& text);
		
		void draw(sf::RenderWindow& targetWindow, Alphabet& alphabet);
		
		GraphicString(std::string texturePath, sf::FloatRect rect, std::string name = "default");
};

#endif //ONEWEEKCHALLANGE_GRAPHICSTRING_HPP
