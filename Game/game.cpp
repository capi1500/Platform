//
// Created by capi1500 on 6/28/18.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <config.h>
#include <iostream>
#include <Player/player.hpp>
#include "game.hpp"

void Game::main(){
	sf::Event event;
	clock.restart();
	while(window.isOpen()){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			window.close();
		}
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				for(auto i : object){
					delete i;
				}
				window.close();
			}
			if(event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::R){
				loader.load("Saves/init.sv");
			}
			if(event.type == sf::Event::Resized){
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
			i->pass(elapsedTime);
			if(i->getObjectType() == ObjectType::Player){
				pointCounter.setPoints(dynamic_cast<Player*>(i)->getCollectible("Point"));
				pointCounter.setPosition(i->getCentre().x - window.getSize().x / 2 + 30, i->getCentre().y - window.getSize().y / 2 + 30);
				view.setCenter(i->getCentre());
				window.setView(view);
			}
		}
		pointCounter.pass(elapsedTime);
		
		window.clear();
		for(auto i : object){
			i->draw(window);
		}
		pointCounter.draw(window, alphabet);
		window.display();
	}
}

Game::Game() : world(b2Vec2(0.0f, 12.f)),
		resolution(screenSizeX, screenSizeY),
		settings(0, 0, ANTIALIASING, versionMajor, versionMinor),
		window(sf::VideoMode(resolution.x, resolution.y), "Platform", sf::Style::Default, settings),
		state(GameState::MainMenu),
		loader(world, object),
		pointCounter("", sf::FloatRect(50, 50, 0, 0), "point counter"){
	if(not loader.load("Saves/init.sv")){
		std::cout << loader.log.error << "\n";
	}
	view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
	pointCounter.reset();
}