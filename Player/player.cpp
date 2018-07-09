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
				collected[i->getName()] += dynamic_cast<Collectible*>(i)->getAmmount();
			}
		}
	}
	return ObjectPassResult::OK;
}

void Player::handleEvent(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		if(onGround() and localTime >= sf::milliseconds(10)){
			jump();
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		addVelocity(sf::Vector2f(1, 0));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		addVelocity(sf::Vector2f(-1, 0));
	}
}

void Player::jump(){
	for(auto* contact = getBody()->GetContactList(); contact; contact = contact->next){
		for(auto obj : object){
			if(contact->other == obj->getBody() and contact->contact->IsTouching()){
				if(obj->getObjectType() == ObjectType::Ground or obj->getObjectType() == ObjectType::PhysicalObject){
					sf::FloatRect o1 = getGlobalBounds(), o2 = obj->getGlobalBounds();
					if(o1.top + o1.height - 1 <= o2.top and o1.left + o1.width > o2.left and o1.left < o2.left + o2.width){
						localTime = sf::milliseconds(0);
						addVelocity(sf::Vector2f(0, -playerJumpHeight));
						playSound("Audio/jump.ogg");
					}
				}
			}
		}
	}
}

unsigned Player::getCollectible(std::string name){
	return collected[name];
}

void Player::addCollectible(std::string name, int val){
	collected[name] += val;
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