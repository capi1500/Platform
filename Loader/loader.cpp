//
// Created by capi1500 on 06/07/18.
//

#include "loader.hpp"
#include <fstream>
#include <iostream>
#include <Entity/entity.hpp>
#include <GroundObject/groundObject.hpp>
#include <Player/player.hpp>
#include <Collectible/collectible.hpp>

void Loader::loadProperties(){
	properties.rect = sf::FloatRect(0, 0, 0, 0);
	properties.friction = 0;
	properties.density = 0;
	properties.dynamic = false;
	properties.isEntity = false;
	properties.kinematic = false;
	properties.name = "default";
	file >> text;
	while(text != "}"){
		if(text == "position"){
			file >> properties.rect.left;
			file >> properties.rect.top;
		}
		else if(text == "size"){
			file >> properties.rect.width;
			file >> properties.rect.height;
		}
		else if(text == "type"){
			file >> text;
			if(text == "dynamic"){
				properties.dynamic = true;
			}
			else if(text == "static"){
				properties.dynamic = false;
			}
			else if(text == "kinematic"){
				properties.kinematic = true;
			}
		}
		else if(text == "name"){
			file >> properties.name;
		}
		else if(text == "friction"){
			file >> properties.friction;
		}
		else if(text == "density"){
			file >> properties.density;
		}
		else if(text == "shape"){
			file >> text;
			if(text == "box"){
				properties.type = PhysicObjectType::Box;
			}
			else if(text == "circle"){
				properties.type = PhysicObjectType::Circle;
			}
		}
		else if(text == "texture"){
			file >> texturePath;
		}
		file >> text;
	}
}

void Loader::loadObject(){
	loadProperties();
	object.push_back(new PhysicObject(world, object, properties, texturePath));
}

void Loader::loadGround(){
	loadProperties();
	properties.dynamic = false;
	object.push_back(new GroundObject(world, object, properties, texturePath));
}

void Loader::loadEntity(){
	loadProperties();
	properties.isEntity = true;
	properties.dynamic = true;
	object.push_back(new Entity(world, object, properties, texturePath));
}

void Loader::loadPlayer(){
	loadProperties();
	properties.isEntity = true;
	properties.dynamic = true;
	object.push_back(new Player(world, object, properties, texturePath));
}

void Loader::loadCollectible(){
	loadProperties();
	object.push_back(new Collectible(world, object, properties, texturePath));
}

bool Loader::load(std::string path){
	// clean everything
	for(auto* i : object){
		i->getBody()->DestroyFixture(i->getBody()->GetFixtureList());
		world.DestroyBody(i->getBody());
	}
	object.erase(object.begin(), object.end());
	// load new
	file.open(path);
	if(not file.is_open()){
		log.error = "Error while opening file";
		return false;
	}
	while(file >> text){
		if(text == "ObjectNumber"){
			file >> number;
			objectNumber = number;
		}
		else if(text == "Object{"){
			loadObject();
		}
		else if(text == "Entity{"){
			loadEntity();
		}
		else if(text == "Ground{"){
			loadGround();
		}
		else if(text == "Player{"){
			loadPlayer();
		}
		else if(text == "Collectible{"){
			loadCollectible();
		}
	}
	file.close();
	log.error = "";
	return true;
}

Loader::Loader(b2World& worldRef, std::vector<PhysicObject*>& objectRef) : world(worldRef),
		object(objectRef),
		properties(sf::FloatRect(0, 0, 0, 0)){
}