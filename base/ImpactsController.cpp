//
//  ImpactsController.cpp
//  PewPew
//
//  Created by Enric on 1/3/18.
//  Copyright © 2018 Enric Cantalejos. All rights reserved.
//

#include "ImpactsController.hpp"
#include "AsteroidPoolBuilder.hpp"
#include "DamageDealer.h"
#include "Config.h"
#include <SFML/System/Vector2.hpp>

pew::ImpactsController::ImpactsController(AsteroidPoolBuilder & asteroidPoolBuilder) : asteroidPoolBuilder(asteroidPoolBuilder)
{
    
}

void pew::ImpactsController::impactShip(entityx::Entity * damageEntity, pew::Ship * ship)
{
    entityx::ComponentHandle<DamageDealer> damageDealer = damageEntity->component<DamageDealer>();
    if(damageDealer)
    {
        ship->lifes -=damageDealer;
    }
}

void pew::ImpactsController::impactAsteroid(entityx::Entity * meteorEntity, entityx::Entity * bulletEntity)
{
    entityx::ComponentHandle<Meteor> meteorComponent = meteorEntity->component<Meteor>();
    entityx::ComponentHandle<Body> bodyComponent = meteorEntity->component<Body>();
    entityx::ComponentHandle<Motion> motionComponent = meteorEntity->component<Motion>();

    auto newYSpeed  = fabs(motionComponent->velocity.y) * ((bulletEntity->component<Motion>()->velocity.y<0) * (-1) + (bulletEntity->component<Motion>()->velocity.y>0));
    bodyComponent->isActive = false;


    switch(meteorComponent->type)
    {
        case BIG:
            asteroidPoolBuilder.activateMeteor(MeteorSize::MEDIUM, bodyComponent->position, bodyComponent->rotation, bodyComponent->rotationd,
                                               sf::Vector2f(motionComponent->velocity.x*0.5, newYSpeed));
			asteroidPoolBuilder.activateMeteor(MeteorSize::MEDIUM, bodyComponent->position, bodyComponent->rotation, bodyComponent->rotationd,
												   sf::Vector2f(motionComponent->velocity.x*0.5, newYSpeed));
            break;
        case MEDIUM:
            asteroidPoolBuilder.activateMeteor(MeteorSize::SMALL, bodyComponent->position, bodyComponent->rotation, bodyComponent->rotationd,
                                               sf::Vector2f(motionComponent->velocity.x*0.5,newYSpeed));
            asteroidPoolBuilder.activateMeteor(MeteorSize::SMALL, bodyComponent->position, bodyComponent->rotation, bodyComponent->rotationd,
                                               sf::Vector2f(motionComponent->velocity.x*1.5,newYSpeed));
            break;
        case SMALL:
            break;
    }
}
