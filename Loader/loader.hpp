//
// Created by capi1500 on 06/07/18.
//

#ifndef PLATFORM_LOADER_HPP
#define PLATFORM_LOADER_HPP

#include <string>
#include <PhysicObject/physicObject.hpp>
#include <fstream>
#include <Alphabet/alphabet.hpp>

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
		Alphabet& alphabet;
		
		std::fstream file;
		std::string text, text2;
		float number;
		PhysicObjectProperties properties;
		std::string texturePath;
		std::vector<std::string> sounds;
		bool collected;
		int ammount;
		std::map<std::string, unsigned> eq;
		std::map<std::string, std::string> talks;
		bool playerNearby;
		bool playerMovedAway;
		bool questStarted;
		bool questDone;
		bool afterQuest;
		bool rewardGiven;
		std::string nowTalking;
		std::string questTarget;
		std::string reward;
		int rewardAmmount;
		
		void loadProperties();
		void loadSounds();
		
		void saveObject(PhysicObject* obj);
		
		void loadPlayer();
		void loadEntity();
		void loadGround();
		void loadObject();
		void loadCollectible();
		void loadNPC();
		void loadPortal();
		
		void clear();
	public:
		LoaderLog log;
		
		bool load(std::string path);
		bool save(std::string path);
		
		Loader(sf::RenderWindow& window, b2World& worldRef, std::vector<PhysicObject*>& objectRef, sf::Time& time, Alphabet& alphabet);
};

#endif //PLATFORM_LOADER_HPP
