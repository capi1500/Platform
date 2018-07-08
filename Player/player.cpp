//
// Created by capi1500 on 07/07/18.
//

#include <config.h>
#include <Collectible/collectible.hpp>
#include "player.hpp"

ObjectPassResult Player::pass(sf::Time elapsedTime){
	Entity::pass(elapsedTime);
	if(getBody()->GetLinearVelocity().x > playerVelocityMaxX){
		getBody()->SetLinearVelocity(b2Vec2(playerVelocityMaxX, getBody()->GetLinearVelocity().y));
	}
	if(getBody()->GetLinearVelocity().y > playerVelocityMaxY){
		getBody()->SetLinearVelocity(b2Vec2(getBody()->GetLinearVelocity().x, playerVelocityMaxY));
	}
	if(getBody()->GetLinearVelocity().x < -playerVelocityMaxX){
		getBody()->SetLinearVelocity(b2Vec2(-playerVelocityMaxX, getBody()->GetLinearVelocity().y));
	}
	if(getBody()->GetLinearVelocity().y < -playerVelocityMaxY){
		getBody()->SetLinearVelocity(b2Vec2(getBody()->GetLinearVelocity().x, -playerVelocityMaxY));
	}
	for(auto& i : object){
		if(i->getObjectType() == ObjectType::Collectible){
			if(dynamic_cast<Collectible*>(i)->colide(this)){
				dynamic_cast<Collectible*>(i)->collect();
				collected[i->getName()]++;
			}
		}
	}
	return ObjectPassResult::OK;
}

void Player::handleEvent(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		if(onGround() and localTime >= sf::milliseconds(10)){
			localTime = sf::milliseconds(0);
			addVelocity(sf::Vector2f(0, -playerJumpHeight));
			playSound("Audio/jump.ogg");
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		addVelocity(sf::Vector2f(1, 0));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		addVelocity(sf::Vector2f(-1, 0));
	}
}

unsigned Player::getCollectible(std::string name){
	return collected[name];
}

std::map<std::string, unsigned>& Player::getCollected(){
	return collected;
}

void Player::setCollected(std::map<std::string, unsigned>& collected){
	this->collected = collected;
}

Player::Player(sf::RenderWindow& window, b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath) : Entity(window, world, objectRef, properties, texturePath){
	objectType = ObjectType::Player;
}