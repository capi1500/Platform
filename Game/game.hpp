//
// Created by capi1500 on 6/28/18.
//

#ifndef PLATFORM_GAME_HPP
#define PLATFORM_GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <Object/object.hpp>
#include <PhysicObject/physicObject.hpp>
#include <Loader/loader.hpp>
#include <Counter/counter.hpp>
#include "Box2D/Box2D.h"

enum class GameState{
		Play,
		Pause,
		MainMenu
};

class Game{
	private:
		b2World world;
		sf::ContextSettings settings;
		sf::Vector2f resolution;
		GameState state;
		
		Loader loader;
		Alphabet alphabet;
		sf::RenderWindow window;
		sf::Clock clock;
		sf::Time elapsedTime;
		sf::View view;
		
		unsigned currentLevel;
		std::vector<PhysicObject*> object;
		Counter pointCounter;
	public:
		void main();
		
		Game();
};

#endif //PLATFORM_GAME_HPP
