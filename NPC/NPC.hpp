//
// Created by capi1500 on 09/07/18.
//

#ifndef PLATFORM_NPC_HPP
#define PLATFORM_NPC_HPP

#include <Entity/entity.hpp>
#include <GraphicString/graphicString.hpp>

class NPC : public Entity{
	private:
		GraphicString talkDisplay;
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
	public:
		const std::string& getReward() const;
		
		void setReward(const std::string& reward);
		
		int getRewardAmmount() const;
		
		void setRewardAmmount(int rewardAmmount);
	
	public:
		const std::string& getQuestTarget() const;
		
		void setQuestTarget(const std::string& questTarget);
		
		int getAmmount() const;
		
		void setAmmount(int ammount);
	
	private:
		int ammount;
	public:
		void setTalks(const std::map<std::string, std::string>& talks);
		void setPlayerNearby(bool playerNearby);
		void setPlayerMovedAway(bool playerMovedAway);
		void setQuestStarted(bool questStarted);
		void setQuestDone(bool questDone);
		void setAfterQuest(bool afterQuest);
		void setRewardGiven(bool rewardGiven);
		void setNowTalking(const std::string& nowTalking);
		bool isPlayerNearby() const;
		bool isPlayerMovedAway() const;
		bool isQuestStarted() const;
		bool isQuestDone() const;
		bool isAfterQuest() const;
		bool isRewardGiven() const;
		const std::string& getNowTalking() const;
		
		ObjectPassResult pass(sf::Time elapsedTime);
		void draw();
		void handleEvent(sf::Event event);
		std::map<std::string, std::string>& getTalks();
		
		bool isQuestFinished();
		
		NPC(sf::RenderWindow& window, b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, Alphabet& alphabet, std::string texturePath = "");
};

#endif //PLATFORM_NPC_HPP
