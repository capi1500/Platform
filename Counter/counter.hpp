//
// Created by capi1500 on 6/17/18.
//

#ifndef ONEWEEKCHALLANGE_COUNTER_HPP
#define ONEWEEKCHALLANGE_COUNTER_HPP

#include <object.hpp>
#include <SFML/Graphics/Text.hpp>
#include <graphicString.hpp>
#include <Label/label.hpp>

class Counter : public Label{
	private:
		unsigned points;
	public:
		void reset();
		void increment();
		void updateText();
		
		unsigned int getPoints() const;
		void setPoints(int val);
		
		Counter(sf::RenderWindow& window, std::string texturePath, sf::Vector2f rect, Alphabet& alphabet, std::string text = "", std::string name = "default");
};

#endif //ONEWEEKCHALLANGE_COUNTER_HPP
