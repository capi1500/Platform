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
		b2World& world;
		std::vector<PhysicObject*>& object;
		unsigned objectNumber;
		
		std::ifstream file;
		std::string text;
		int number;
		PhysicObjectProperties properties;
		std::string texturePath;
		
		void loadProperties();
		void loadPlayer();
		void savePlayer();
		void loadEntity();
		void saveEntity();
		void loadGround();
		void saveGround();
		void loadCollectible();
		void saveCollectible();
		void loadObject();
		void saveObject();
	public:
		LoaderLog log;
		
		bool load(std::string path);
		bool save(std::string path);
		
		Loader(b2World& worldRef, std::vector<PhysicObject*>& objectRef);
};

#endif //PLATFORM_LOADER_HPP
