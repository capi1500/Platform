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
#include <Button/button.hpp>
#include <Menu/menu.hpp>
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
		
		std::vector<PhysicObject*> object;
		Counter pointCounter;
		std::vector<Menu> menu;
		
		void play();
		void pause();
		void mainMenu();
		
		Menu* getMenu(std::string name);
		PhysicObject* getObject(std::string name);
	public:
		void main();
		
		void playButtonClicked();
		void resumeButtonClicked();
		void mainMenuButtonClicked();
		void exitButtonClicked();
		
		Game();
};

#endif //PLATFORM_GAME_HPP
