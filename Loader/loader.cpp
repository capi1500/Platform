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
#include <NPC/NPC.hpp>

void Loader::loadProperties(){
	
	properties.rect = sf::FloatRect(0, 0, 0, 0);
	properties.friction = 0;
	properties.density = 0;
	properties.dynamic = false;
	properties.isEntity = false;
	properties.kinematic = false;
	properties.name = "default";
	properties.angle = 0;
	collected = false;
	sounds.erase(sounds.begin(), sounds.end());
	eq.erase(eq.begin(), eq.end());
	talks.erase(talks.begin(), talks.end());
	playerNearby = false;
	playerMovedAway = true;
	questStarted = false;
	questDone = false;
	afterQuest = false;
	rewardGiven = false;
	nowTalking = "nothing";
	ammount = 1;
	
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
		else if(text == "sound"){
			file >> text;
			try{
				sounds.push_back(text);
			} catch(std::string err){
				printf("%s", err.c_str());
			}
		}
		else if(text == "collected"){
			file >> text;
			if(text == "true"){
				collected = true;
			}
			else{
				collected = false;
			}
		}
		else if(text == "velocity"){
			file >> properties.velocity.x >> properties.velocity.y;
		}
		else if(text == "angle"){
			file >> properties.angle;
		}
		else if(text == "EQ{"){
			file >> text;
			while(text != "}"){
				file >> number;
				eq[text] = number;
				file >> text;
			}
		}
		else if(text == "talks{"){
			file >> text;
			while(text != "}"){
				char c;
				c = file.get();
				while(c != ';'){
					text2 += c;
					c = file.get();
				}
				talks[text] = text2.substr(1, text2.size() - 1);
				text2 = "";
				file >> text;
			}
		}
		else if(text == "playerNearby"){
			file >> text;
			if(text == "true"){
				playerNearby = true;
			}
			else{
				playerNearby = false;
			}
		}
		else if(text == "playerMovedAway"){
			file >> text;
			if(text == "true"){
				playerMovedAway = true;
			}
			else{
				playerMovedAway = false;
			}
		}
		else if(text == "questStarted"){
			file >> text;
			if(text == "true"){
				questStarted = true;
			}
			else{
				questStarted = false;
			}
		}
		else if(text == "questDone"){
			file >> text;
			if(text == "true"){
				questDone = true;
			}
			else{
				questDone = false;
			}
		}
		else if(text == "afterQuest"){
			file >> text;
			if(text == "true"){
				afterQuest = true;
			}
			else{
				afterQuest = false;
			}
		}
		else if(text == "rewardGiven"){
			file >> text;
			if(text == "true"){
				rewardGiven = true;
			}
			else{
				rewardGiven = false;
			}
		}
		else if(text == "nowTalking"){
			file >> nowTalking;
		}
		else if(text == "ammount"){
			file >> ammount;
		}
		else if(text == "target"){
			file >> questTarget;
		}
		else if(text == "rewardAmmount"){
			file >> rewardAmmount;
		}
		else if(text == "reward"){
			file >> reward;
		}
		file >> text;
	}
}

void Loader::loadSounds(){
	object[object.size() - 1]->addSound(sounds);
}

void Loader::saveObject(PhysicObject* obj){
	switch(obj->getObjectType()){
		case ObjectType::PhysicalObject:
			file << "Object{\n";
			break;
		case ObjectType::Player:
			file << "Player{\n";
			break;
		case ObjectType::Ground:
			file << "Ground{\n";
			break;
		case ObjectType::Entity:
			file << "Entity{\n";
			break;
		case ObjectType::Collectible:
			file << "Collectible{\n";
			break;
		case ObjectType::NPC:
			file << "NPC{\n";
			break;
		default:
			file << "Object{\n";
			break;
	}
	if(obj->getProperties().dynamic){
		file << "\ttype dynamic\n";
		file << "\tdensity " << obj->getProperties().density << "\n";
		file << "\tfriction " << obj->getProperties().friction << "\n";
	}
	else if(obj->getProperties().kinematic){
		file << "\ttype kinematic\n";
	}
	else{
		file << "\ttype static\n";
	}
	if(obj->getProperties().type == PhysicObjectType::Box){
		file << "\tshape box\n";
	}
	else if(obj->getProperties().type == PhysicObjectType::Circle){
		file << "\tshape circle\n";
	}
	file << "\tname " << obj->getName() << "\n";
	file << "\tposition " << obj->getProperties().rect.left << " " << obj->getProperties().rect.top << "\n";
	file << "\tsize " << obj->getProperties().rect.width << " " << obj->getProperties().rect.height << "\n";
	file << "\tvelocity " << obj->getProperties().velocity.x << " " << obj->getProperties().velocity.y << "\n";
	file << "\tangle " << obj->getProperties().angle << "\n";
	for(auto i : obj->getSoundList()){
		file << "\tsound " << i << "\n";
	}
	file << "\ttexture " << obj->getTexturePath() << "\n";
	if(obj->getObjectType() == ObjectType::Collectible){
		file << "\tcollected " << (dynamic_cast<Collectible*>(obj)->isCollected() ? "true\n" : "false\n");
		file << "\tammount " << dynamic_cast<Collectible*>(obj)->getAmmount() << "\n";
	}
	if(obj->getObjectType() == ObjectType::Player){
		file << "\tEQ{\n";
		for(auto i : dynamic_cast<Player*>(obj)->getCollected()){
			file << "\t\t" << i.first << " " << i.second << "\n";
		}
		file << "\t}\n";
	}
	if(obj->getObjectType() == ObjectType::NPC){
		file << "\ttalks{\n";
		for(auto i : dynamic_cast<NPC*>(obj)->getTalks()){
			file << "\t\t" << i.first << " " << i.second << ";\n";
		}
		file << "\t}\n";
		file << "\tplayerNearby " << (dynamic_cast<NPC*>(obj)->isPlayerNearby() ? "true\n" : "false\n");
		file << "\tplayerMovedAway " << (dynamic_cast<NPC*>(obj)->isPlayerMovedAway() ? "true\n" : "false\n");
		file << "\tquestStarted " << (dynamic_cast<NPC*>(obj)->isQuestStarted() ? "true\n" : "false\n");
		file << "\tquestDone " << (dynamic_cast<NPC*>(obj)->isQuestDone() ? "true\n" : "false\n");
		file << "\tafterQuest " << (dynamic_cast<NPC*>(obj)->isAfterQuest() ? "true\n" : "false\n");
		file << "\trewardGiven " << (dynamic_cast<NPC*>(obj)->isRewardGiven() ? "true\n" : "false\n");
		file << "\tnowTalking " << dynamic_cast<NPC*>(obj)->getNowTalking() << "\n";
		file << "\tammount " << dynamic_cast<NPC*>(obj)->getAmmount() << "\n";
		file << "\ttarget " << dynamic_cast<NPC*>(obj)->getQuestTarget() << "\n";
		file << "\trewardAmmount " << dynamic_cast<NPC*>(obj)->getRewardAmmount() << "\n";
		file << "\treward " << dynamic_cast<NPC*>(obj)->getReward() << "\n";
	}
	file << "}\n";
}

void Loader::loadObject(){
	loadProperties();
	object.push_back(new PhysicObject(window, world, object, properties, texturePath));
	loadSounds();
}

void Loader::loadGround(){
	loadProperties();
	properties.dynamic = false;
	object.push_back(new GroundObject(window, world, object, properties, texturePath));
	loadSounds();
}

void Loader::loadEntity(){
	loadProperties();
	properties.isEntity = true;
	properties.dynamic = true;
	object.push_back(new Entity(window, world, object, properties, texturePath));
	loadSounds();
}

void Loader::loadPlayer(){
	loadProperties();
	properties.isEntity = true;
	properties.dynamic = true;
	object.push_back(new Player(window, world, object, properties, texturePath));
	loadSounds();
	dynamic_cast<Player*>(object[object.size() - 1])->setCollected(eq);
	
}

void Loader::loadCollectible(){
	loadProperties();
	object.push_back(new Collectible(window, world, object, properties, texturePath));
	loadSounds();
	if(collected){
		dynamic_cast<Collectible*>(object[object.size() - 1])->collect(true);
	}
	dynamic_cast<Collectible*>(object[object.size() - 1])->setAmmount(ammount);
}

void Loader::loadNPC(){
	loadProperties();
	object.push_back(new NPC(window, world, object, properties, alphabet, texturePath));
	loadSounds();
	dynamic_cast<NPC*>(object[object.size() - 1])->setTalks(talks);
	dynamic_cast<NPC*>(object[object.size() - 1])->setPlayerNearby(playerNearby);
	dynamic_cast<NPC*>(object[object.size() - 1])->setPlayerMovedAway(playerMovedAway);
	dynamic_cast<NPC*>(object[object.size() - 1])->setQuestStarted(questStarted);
	dynamic_cast<NPC*>(object[object.size() - 1])->setQuestDone(questDone);
	dynamic_cast<NPC*>(object[object.size() - 1])->setAfterQuest(afterQuest);
	dynamic_cast<NPC*>(object[object.size() - 1])->setRewardGiven(rewardGiven);
	dynamic_cast<NPC*>(object[object.size() - 1])->setNowTalking(nowTalking);
	dynamic_cast<NPC*>(object[object.size() - 1])->setAmmount(ammount);
	dynamic_cast<NPC*>(object[object.size() - 1])->setQuestTarget(questTarget);
	dynamic_cast<NPC*>(object[object.size() - 1])->setRewardAmmount(rewardAmmount);
	dynamic_cast<NPC*>(object[object.size() - 1])->setReward(reward);
}

bool Loader::load(std::string path){
	// clean everything
	for(auto* i : object){
		i->getBody()->DestroyFixture(i->getBody()->GetFixtureList());
		world.DestroyBody(i->getBody());
	}
	object.erase(object.begin(), object.end());
	time = sf::milliseconds(0);
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
		else if(text == "NPC{"){
			loadNPC();
		}
		else if(text == "time"){
			file >> number;
			time = sf::milliseconds(number);
		}
	}
	file.close();
	clear();
	log.error = "";
	return true;
}

bool Loader::save(std::string path){
	file.open(path, std::fstream::out | std::fstream::trunc);
	if(not file.is_open()){
		log.error = "Error while opening file";
		return false;
	}
	file << "time " << time.asMilliseconds() << "\n";
	for(auto i : object){
		saveObject(i);
	}
	file.close();
	log.error = "";
	return true;
}

void Loader::clear(){
	sounds.erase(sounds.begin(), sounds.end());
	eq.erase(eq.begin(), eq.end());
}

Loader::Loader(sf::RenderWindow& window, b2World& worldRef, std::vector<PhysicObject*>& objectRef, sf::Time& time, Alphabet& alphabet) : window(window),
		world(worldRef),
		object(objectRef),
		properties(sf::FloatRect(0, 0, 0, 0)),
		time(time),
		alphabet(alphabet){
}