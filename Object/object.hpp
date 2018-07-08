//
// Created by capi1500 on 6/28/18.
//

#ifndef PLATFORM_OBJECT_HPP
#define PLATFORM_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <sound.hpp>

enum class ObjectPassResult{
		OK,
		Error,
		Unexpected
};

enum class ObjectType{
		Object,
		PhysicalObject,
		Entity,
		Ground,
		Player,
		Collectible,
		GraphicString,
		Label,
		Counter,
		Button
};

class Object : public sf::Sprite{
	protected:
		sf::RenderWindow& window;
		sf::Time localTime;
		sf::Texture texture;
		std::vector<Sound> sounds;
		std::map<std::string, unsigned> soundIDs;
		std::vector<std::string> soundNames;
		ObjectType objectType;
		std::string texturePath;
		std::string name;
	public:
		void playSound(std::string name);
		void pauseSound(std::string name);
		bool addSound(std::vector<std::string>& list);
		bool addSound(std::string path);
		std::vector<std::string>& getSoundList();
		
		ObjectType getObjectType();
		std::string getName();
		sf::Vector2f getCentre();
		void setCentre(sf::Vector2f centre);
		void setCentre(float x, float y);
		std::string getTexturePath();
		
		virtual void draw();
		virtual ObjectPassResult pass(sf::Time elapsedTime);
		virtual void handleEvent(sf::Event event);
		virtual void handleEvent();
		
		Object(sf::RenderWindow& window, std::string texturePath, sf::Vector2f rect, std::string name = "default");
		~Object();
};

#endif //PLATFORM_OBJECT_HPP
