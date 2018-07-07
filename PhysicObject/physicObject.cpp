//
// Created by capi1500 on 7/2/18.
//

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include "physicObject.hpp"
#include <config.h>
#include <Box2D/Collision/Shapes/b2CircleShape.h>

PhysicObjectProperties::PhysicObjectProperties(sf::FloatRect rect, bool dynamic, float density, float friction, PhysicObjectType type, bool isEntity){
	this->rect = rect;
	this->dynamic = dynamic;
	this->density = density;
	this->friction = friction;
	this->type = type;
	this->isEntity = isEntity;
}

ObjectPassResult PhysicObject::pass(sf::Time elapsedTime){
	Object::pass(elapsedTime);
	setPosition(meterToPixel(body->GetPosition().x), meterToPixel(body->GetPosition().y));
	setRotation(body->GetAngle() * 180 / b2_pi);
	return ObjectPassResult::OK;
}

void PhysicObject::addVelocity(sf::Vector2f velocity){
	body->ApplyLinearImpulseToCenter(b2Vec2(pixelToMeter(velocity.x), pixelToMeter(velocity.y)), true);
}

b2Body* PhysicObject::getBody(){
	return body;
}

PhysicObject::PhysicObject(b2World& world, std::vector<PhysicObject*>& objectRef, PhysicObjectProperties properties, std::string texturePath) : object(objectRef),
		Object(texturePath, properties.rect, properties.name),
		properties(properties){
	objectType = ObjectType::PhysicalObject;
	// Creating Box2D object to simulate physics
	b2BodyDef bodyDef;
	if(properties.dynamic){
		bodyDef.type = b2_dynamicBody;
	}
	if(properties.kinematic){
		bodyDef.type = b2_kinematicBody;
		bodyDef.active = false;
	}
	if(properties.isEntity){
		bodyDef.fixedRotation = true;
	}
	bodyDef.position.Set(pixelToMeter(properties.rect.left + properties.rect.width / 2), pixelToMeter(properties.rect.top + properties.rect.height / 2));
	body = world.CreateBody(&bodyDef);
	b2FixtureDef fixtureDef;
	b2CircleShape circleShape;
	b2PolygonShape polygonShape;
	if(properties.type == PhysicObjectType::Box){
		polygonShape.SetAsBox(pixelToMeter(properties.rect.width / 2), pixelToMeter(properties.rect.height / 2));
		fixtureDef.shape = &polygonShape;
	}
	else if(properties.type == PhysicObjectType::Circle){
		circleShape.m_radius = pixelToMeter(properties.rect.width / 2);
		fixtureDef.shape = &circleShape;
	}
	fixtureDef.density = properties.density;
	fixtureDef.restitution = 0;
	if(properties.dynamic){
		fixtureDef.friction = properties.friction;
	}
	body->CreateFixture(&fixtureDef);
	// SFML stuff
	setOrigin(sf::Vector2f(properties.rect.width / 2, properties.rect.height / 2));
}