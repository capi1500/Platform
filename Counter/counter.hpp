//
// Created by capi1500 on 6/17/18.
//

#ifndef ONEWEEKCHALLANGE_COUNTER_HPP
#define ONEWEEKCHALLANGE_COUNTER_HPP

#include <object.hpp>
#include <SFML/Graphics/Text.hpp>
#include <graphicString.hpp>

class Counter : public GraphicString{
	private:
		unsigned points;
	public:
		void draw(sf::RenderWindow& targetWindow, Alphabet& alphabet);
		void reset();
		void increment();
		void updateText();
		
		unsigned int getPoints() const;
		void setPoints(int val);
		
		Counter(std::string texturePath, sf::FloatRect rect, std::string name = "default");
};

#endif //ONEWEEKCHALLANGE_COUNTER_HPP
