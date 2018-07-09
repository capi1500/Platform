//
// Created by capi1500 on 6/28/18.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <config.h>
#include <iostream>
#include <Player/player.hpp>
#include <Portal/portal.hpp>
#include "game.hpp"

void Game::play(){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed){
			window.close();
			return;
		}
		else if(event.type == sf::Event::KeyPressed){
			if(event.key.code == sf::Keyboard::Escape){
				if(not loader.save("Saves/temp.sv")){
					std::cout << loader.log.error << "\n";
				}
				state = GameState::Pause;
				view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
				window.setView(view);
				window.setMouseCursorVisible(true);
				return;
			}
		}
		else if(event.type == sf::Event::Resized){
			view.setSize(window.getSize().x, window.getSize().y);
			view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
			window.setView(view);
		}
		for(auto i : object){
			i->handleEvent(event);
		}
	}
	for(auto i : object){
		i->handleEvent();
	}
	elapsedTime = clock.restart();
	world.Step(elapsedTime.asSeconds(), defVelocityIterations, defPositionIterations);
	world.ClearForces();
	for(auto i : object){
		if(i->pass(elapsedTime) == ObjectPassResult::NewLevel){
			std::map<std::string, unsigned> eq;
			for(auto j : object){
				if(j->getObjectType() == ObjectType::Player){
					eq = dynamic_cast<Player*>(j)->getCollected();
				}
			}
			loader.load(dynamic_cast<Portal*>(i)->getTarget());
			for(auto j : object){
				if(j->getObjectType() == ObjectType::Player){
					dynamic_cast<Player*>(j)->setCollected(eq);
				}
			}
			return;
		}
		if(i->getObjectType() == ObjectType::Player){
			pointCounter.setPoints(dynamic_cast<Player*>(i)->getCollectible("Money"));
			pointCounter.setCentre(i->getCentre().x - window.getSize().x / 2 + alphabet.getWidth() * lettersScaling * pointCounter.getScale().x * (pointCounter.getPoints() == 0 ? 1 : static_cast<int>(1 + log10(pointCounter.getPoints()))) / 2, i->getCentre().y - window.getSize().y / 2 + 30);
			view.setCenter(i->getCentre());
			window.setView(view);
		}
	}
	pointCounter.pass(elapsedTime);
	
	window.clear();
	for(auto i : object){
		i->draw();
	}
	pointCounter.draw();
	window.display();
}

void Game::pause(){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed){
			window.close();
			return;
		}
		else if(event.type == sf::Event::KeyPressed){
			if(event.key.code == sf::Keyboard::Escape){
				state = GameState::Play;
				if(not loader.load("Saves/temp.sv")){
					std::cout << loader.log.error << "\n";
				}
				window.setMouseCursorVisible(false);
				clock.restart();
				return;
			}
		}
		else if(event.type == sf::Event::Resized){
			view.setSize(window.getSize().x, window.getSize().y);
			view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
			window.setView(view);
		}
		getMenu("pause menu")->handleEvent(event);
	}
	elapsedTime = clock.restart();
	getMenu("pause menu")->pass(elapsedTime);
	
	window.clear();
	getMenu("pause menu")->draw();
	window.display();
}

void Game::mainMenu(){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed){
			window.close();
			return;
		}
		else if(event.type == sf::Event::Resized){
			view.setSize(window.getSize().x, window.getSize().y);
			view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
			window.setView(view);
		}
		getMenu("main menu")->handleEvent(event);
	}
	elapsedTime = clock.restart();
	getMenu("main menu")->pass(elapsedTime);
	
	window.clear();
	getMenu("main menu")->draw();
	window.display();
}

void Game::main(){
	clock.restart();
	while(window.isOpen()){
		if(state == GameState::Play){
			play();
		}
		else if(state == GameState::MainMenu){
			mainMenu();
		}
		else if(state == GameState::Pause){
			pause();
		}
	}
}

Menu* Game::getMenu(std::string name){
	for(auto it = menu.begin(); it != menu.end(); it++){
		if(it->getName() == name)
			return &(*it);
	}
	throw "ERROR: menu '" + name + " doesn't exist";
	return &(*menu.begin());
}

void forwarderExitButton(void* context){
	static_cast<Game*>(context)->exitButtonClicked();
}

void forwarderResumeButton(void* context){
	static_cast<Game*>(context)->resumeButtonClicked();
}

void forwarderMainMenuButton(void* context){
	static_cast<Game*>(context)->mainMenuButtonClicked();
}

void forwarderPlayButton(void* context){
	static_cast<Game*>(context)->playButtonClicked();
}

void Game::playButtonClicked(){
	state = GameState::Play;
	if(not loader.load("Saves/init.sv")){
		std::cout << loader.log.error << "\n";
	}
	clock.restart();
	window.setMouseCursorVisible(false);
}

void Game::resumeButtonClicked(){
	state = GameState::Play;
	if(not loader.load("Saves/temp.sv")){
		std::cout << loader.log.error << "\n";
	}
	clock.restart();
	window.setMouseCursorVisible(false);
}

void Game::mainMenuButtonClicked(){
	state = GameState::MainMenu;
	view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
	window.setView(view);
	window.setMouseCursorVisible(true);
}

void Game::exitButtonClicked(){
	for(auto i : object){
		i->getBody()->DestroyFixture(i->getBody()->GetFixtureList());
		world.DestroyBody(i->getBody());
	}
	object.erase(object.begin(), object.end());
	window.close();
}

Game::Game() : world(b2Vec2(0.0f, 12.f)),
		resolution(screenSizeX, screenSizeY),
		settings(0, 0, ANTIALIASING, versionMajor, versionMinor),
		window(sf::VideoMode(resolution.x, resolution.y), "Platform", sf::Style::Fullscreen, settings),
		state(GameState::MainMenu),
		loader(window, world, object, elapsedTime, alphabet),
		pointCounter(window, "", sf::Vector2f(10, 10), alphabet){
	menu.push_back(Menu(window, "", "pause menu"));
	getMenu("pause menu")->addObject(new Button(&forwarderResumeButton, this, window, "", sf::Vector2f(0, 0), alphabet, "Resume"));
	getMenu("pause menu")->addObject(new Button(&forwarderPlayButton, this, window, "", sf::Vector2f(0, 0), alphabet, "Restart"));
	getMenu("pause menu")->addObject(new Button(&forwarderMainMenuButton, this, window, "", sf::Vector2f(0, 0), alphabet, "Main menu"));
	getMenu("pause menu")->addObject(new Button(&forwarderExitButton, this, window, "", sf::Vector2f(0, 0), alphabet, "Exit game"));
	menu.push_back(Menu(window, "", "main menu"));
	getMenu("main menu")->addObject(new Button(&forwarderPlayButton, this, window, "", sf::Vector2f(0, 0), alphabet, "Play"));
	getMenu("main menu")->addObject(new Button(&forwarderExitButton, this, window, "", sf::Vector2f(0, 0), alphabet, "Exit game"));
	music.openFromFile("Audio/The\ Traveller.ogg");
	music.setLoop(true);
	music.setVolume(30);
	music.play();
}