//
//  BoundariesCheckingSystem.hpp
//  PewPew
//
//  Created by Enric on 10/6/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef CollisionSystem_hpp
#define CollisionSystem_hpp

#pragma once

#include "entityx/System.h"
#include "Body.h"
#include "Meteor.h"
#include "Bullet.h"
#include "Ship.h"
#include <SFML/System/Vector2.hpp>

class CollisionSystem : public entityx::System<CollisionSystem>
{
public:
    CollisionSystem(entityx::EntityManager &entities, sf::Vector2u & screenSize);
    
    void update(entityx::EntityManager &entities,
                entityx::EventManager &events,
                double dt);
    
    bool checkCollision(pew::Body & bodyA, pew::Body & bodyB);
    void hit(pew::Bullet & bullet, pew::Ship & ship);
    void hit(pew::Bullet & bullet, pew::Meteor & meteor);

private:
	unsigned int _halfHeightScreen;
    entityx::ComponentHandle<pew::Body> _northShip;
    entityx::ComponentHandle<pew::Body> _southShip;
};

#endif /* BoundariesCheckingSystem_hpp */
