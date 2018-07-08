//
// Created by capi1500 on 06/07/18.
//

#ifndef PLATFORM_LOADER_HPP
#define PLATFORM_LOADER_HPP

#include <string>
#include <PhysicObject/physicObject.hpp>
#include <fstream>

struct LoaderLog{
	std::string error;
};

class Loader{
	private:
		sf::RenderWindow& window;
		b2World& world;
		sf::Time& time;
		std::vector<PhysicObject*>& object;
		unsigned objectNumber;
		
		std::fstream file;
		std::string text;
		float number;
		PhysicObjectProperties properties;
		std::string texturePath;
		std::vector<std::string> sounds;
		bool collected;
		std::map<std::string, unsigned> eq;
		
		void loadProperties();
		void loadSounds();
		
		void saveObject(PhysicObject* obj);
		
		void loadPlayer();
		void loadEntity();
		void loadGround();
		void loadObject();
		void loadCollectible();
		
		void clear();
	public:
		LoaderLog log;
		
		bool load(std::string path);
		bool save(std::string path);
		
		Loader(sf::RenderWindow& window, b2World& worldRef, std::vector<PhysicObject*>& objectRef, sf::Time& time);
};

#endif //PLATFORM_LOADER_HPP
