//
// Created by capi1500 on 09/07/18.
//

#include <config.h>
#include <Player/player.hpp>
#include "NPC.hpp"

ObjectPassResult NPC::pass(sf::Time elapsedTime){
	Entity::pass(elapsedTime);
	for(auto i : object){
		if(i->getObjectType() == ObjectType::Player){
			if(50 >= sqrt((getCentre().x - i->getCentre().x) * (getCentre().x - i->getCentre().x) + (getCentre().y - i->getCentre().y) * (getCentre().y - i->getCentre().y))){
				playerNearby = true;
			}
			else{
				if(playerNearby){
					playerMovedAway = true;
				}
				playerNearby = false;
				nowTalking = "nothing";
			}
			if(not rewardGiven and afterQuest){
				dynamic_cast<Player*>(i)->addCollectible(reward, rewardAmmount);
				dynamic_cast<Player*>(i)->addCollectible(questTarget, -ammount);
				rewardGiven = true;
			}
			if(dynamic_cast<Player*>(i)->getCollectible(questTarget) >= ammount){
				questDone = true;
			}
		}
	}
	if(playerNearby and playerMovedAway){
		playerMovedAway = false;
		nowTalking = "hello";
	}
	for(auto i : object){
		if(i->getObjectType() == ObjectType::Player){
			talkDisplay.setCentre(i->getCentre().x, i->getCentre().y + window.getSize().y / 2 - 30);
		}
	}
	if(nowTalking != "nothing"){
		talkDisplay.setText(name + ": " + talks[nowTalking]);
	}
	else{
		talkDisplay.setText("");
	}
}

void NPC::handleEvent(sf::Event event){
	if(event.type == sf::Event::KeyPressed){
		if(event.key.code == sf::Keyboard::Tab){
			if(playerNearby){
				if(nowTalking == "nothing"){
					nowTalking = "hello";
				}
				else if(nowTalking == "hello"){
					if(questStarted == false){
						nowTalking = "quest1";
						questStarted = true;
					}
					else if(afterQuest){
						nowTalking = "after_quest1";
					}
					else if(questDone){
						nowTalking = "quest_finished1";
					}
					else{
						nowTalking = "quest_in_progress1";
					}
				}
				else if(nowTalking == "quest1"){
					nowTalking = "quest2";
				}
				else if(nowTalking == "quest2"){
					nowTalking = "quest3";
				}
				else if(nowTalking == "quest_in_progress1"){
					nowTalking = "quest_in_progress2";
				}
				else if(nowTalking == "quest_finished1"){
					nowTalking = "quest_finished2";
				}
				else if(nowTalking == "after_quest1"){
					nowTalking = "after_quest2";
				}
				else if(nowTalking == "quest3" or nowTalking == "quest_in_progress2" or nowTalking == "after_quest2"){
					nowTalking = "bye";
				}
				else if(nowTalking == "quest_finished2"){
					nowTalking = "bye";
					afterQuest = true;
				}
				else if(nowTalking == "bye"){
					nowTalking = "nothing";
				}
			}
		}
	}
	
}

void NPC::draw(){
	Entity::draw();
	talkDisplay.draw();
}

bool NPC::isQuestFinished(){
	return afterQuest;
}

NPC::NPC(sf::RenderWindow& window, b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, Alphabet& alphabet, std::string texturePath) : Entity(window, world, objectRef, properties, texturePath),
		talkDisplay(window, alphabet){
	objectType = ObjectType::NPC;
	talkDisplay.setScale(0.75, 0.75);
	talkDisplay.setCentre(getCentre().x, properties.rect.top - alphabet.getHeight() * lettersScaling * talkDisplay.getScale().y * 0.75);
}

bool NPC::isPlayerNearby() const{
	return playerNearby;
}

bool NPC::isPlayerMovedAway() const{
	return playerMovedAway;
}

bool NPC::isQuestStarted() const{
	return questStarted;
}

bool NPC::isQuestDone() const{
	return questDone;
}

bool NPC::isAfterQuest() const{
	return afterQuest;
}

bool NPC::isRewardGiven() const{
	return rewardGiven;
}

const std::string& NPC::getNowTalking() const{
	return nowTalking;
}

std::map<std::string, std::string>& NPC::getTalks(){
	return talks;
}

void NPC::setTalks(const std::map<std::string, std::string>& talks){
	this->talks = talks;
}

void NPC::setPlayerNearby(bool playerNearby){
	this->playerNearby = playerNearby;
}

void NPC::setPlayerMovedAway(bool playerMovedAway){
	this->playerMovedAway = playerMovedAway;
}

void NPC::setQuestStarted(bool questStarted){
	this->questStarted = questStarted;
}

void NPC::setQuestDone(bool questDone){
	this->questDone = questDone;
}

void NPC::setAfterQuest(bool afterQuest){
	this->afterQuest = afterQuest;
}

void NPC::setRewardGiven(bool rewardGiven){
	this->rewardGiven = rewardGiven;
}

void NPC::setNowTalking(const std::string& nowTalking){
	this->nowTalking = nowTalking;
}

const std::string& NPC::getQuestTarget() const{
	return questTarget;
}

void NPC::setQuestTarget(const std::string& questTarget){
	NPC::questTarget = questTarget;
}

int NPC::getAmmount() const{
	return ammount;
}

void NPC::setAmmount(int ammount){
	NPC::ammount = ammount;
}

const std::string& NPC::getReward() const{
	return reward;
}

void NPC::setReward(const std::string& reward){
	NPC::reward = reward;
}

int NPC::getRewardAmmount() const{
	return rewardAmmount;
}

void NPC::setRewardAmmount(int rewardAmmount){
	NPC::rewardAmmount = rewardAmmount;
}
