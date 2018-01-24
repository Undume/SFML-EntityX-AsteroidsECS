#include "CollisionSystem.hpp"
#include <iostream>
#include "Utility.hpp"
#include "MeteorSpawner.h"

using namespace entityx;

CollisionSystem::CollisionSystem(EntityManager &entities, sf::Vector2u &screenSize)
{
    _halfHeightScreen = screenSize.y/2;
	for (auto ship : entities.entities_with_components<pew::Body, pew::Ship>())
	{
		if (ship.component <pew::Body>()->position.y > _halfHeightScreen)
		{
            _southShip = ship.component<pew::Body>();
		}
		else
		{
            _northShip = ship.component<pew::Body>();
		}
	}
}


void CollisionSystem::update(EntityManager &entities, EventManager &events, double dt)
{
    auto meteors  = entities.entities_with_components<pew::Body, pew::Meteor>();
    auto bullets = entities.entities_with_components<pew::Body, pew::Bullet>();

	int i(0);
    for (Entity entityMeteor : meteors)
    {
        if(entityMeteor.component<pew::Body>()->isActive && entityMeteor.component<pew::Meteor>()->inBattleground)
        {
			for (auto entityBullet : bullets)
			{
				if (entityBullet.component<pew::Body>()->isActive)
				{
                    if(checkCollision(*entityBullet.component<pew::Body>(), *entityMeteor.component<pew::Body>()))
                    {
                        
                    }
				}
			}
            
            if(entityMeteor.component<pew::Body>()->position.y>_halfHeightScreen)
            {
                if(checkCollision(*_southShip, *entityMeteor.component<pew::Body>()))
                {
                    
                }
            }
            else
            {
                if(checkCollision(*_northShip, *entityMeteor.component<pew::Body>()))
                {
                    
                }
            }
        }
    }

	for (auto entityBullet : bullets)
	{
		if (entityBullet.component<pew::Body>()->isActive)
		{
            if(entityBullet.component<pew::Body>()->position.y>_halfHeightScreen)
            {
                if(checkCollision(*_southShip, *entityBullet.component<pew::Body>()))
                {
                    printf("shipS");
                }
            }
            else
            {
                if(checkCollision(*_northShip, *entityBullet.component<pew::Body>()))
                {
                    printf("shipN");
                }
            }
		}
	}
}


bool CollisionSystem::checkCollision(pew::Body & bodyA, pew::Body & bodyB)
{
    if(bodyA.shape == pew::Shape::BOX && bodyB.shape == pew::Shape::BOX) //Bullet && ship
    {
        return (abs(bodyA.position.x - bodyB.position.x) * 2 < (bodyA.size.x + bodyB.size.x)) && (abs(bodyA.position.y - bodyB.position.y) * 2 < (bodyA.size.y + bodyB.size.y));
    }
    else if(bodyB.shape == pew::Shape::CIRCLE) //Bullet && Meteor
    {
        sf::Vector2f circleDistance;
        
        circleDistance.x = abs(bodyB.position.x - bodyA.position.x);
        circleDistance.y = abs(bodyB.position.y - bodyA.position.y);
        
        if (circleDistance.x > (bodyA.size.x/2 + bodyB.size.x)) { return false; }
        if (circleDistance.y > (bodyA.size.y/2 + bodyB.size.x)) { return false; }
        
        if (circleDistance.x <= (bodyA.size.x/2)) { return true; }
        if (circleDistance.y <= (bodyA.size.y/2)) { return true; }
        
        float cornerDistance_sq = pow(circleDistance.x - bodyA.size.x/2, 2) + pow(circleDistance.y - bodyA.size.y/2,2);
        
        return (cornerDistance_sq <= (bodyB.size.x*bodyB.size.x));
    }
    return false;
}

void CollisionSystem::hit(pew::Bullet & bullet, pew::Ship & ship)
{
    
}

void CollisionSystem::hit(pew::Bullet & bullet, pew::Meteor & meteor)
{
    
}
