//
//  MeteorSpawnerSystem.cpp
//  PewPew
//
//  Created by Enric on 10/12/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "MeteorSpawnerSystem.hpp"
#include "MeteorSpawner.h"
#include "Motion.h"
#include "Body.h"
#include "Utility.hpp"

using namespace entityx;


MeteorSpawnerSystem::MeteorSpawnerSystem(pew::AsteroidPoolBuilder & asteroidPool)
: _asteroidPool(asteroidPool)
{
}

void MeteorSpawnerSystem::update(entityx::EntityManager &entities,
                                 entityx::EventManager &events,
                                 double dt)
{
    ComponentHandle<pew::Body> body;
    ComponentHandle<pew::MeteorSpawner> spawner;
    
    for (entityx::Entity entity : entities.entities_with_components(spawner, body))
    {
        spawner->timerRateSpawning += dt;
        if(spawner->timerRateSpawning > spawner->rateSpawning){
            spawner->timerRateSpawning = 0;
            auto randomRotation = RANDOM_BETWEEN(-25.f, 25.f) + body->rotation;
            sf::Vector2f velocity(std::cos(pew::DEG_TO_RAD  * randomRotation) * RANDOM_BETWEEN(2.9f, 3.f),
                                  std::sin(pew::DEG_TO_RAD  * randomRotation) * RANDOM_BETWEEN(2.9f, 3.f));
            _asteroidPool.activateMeteor(pew::MeteorSize::BIG, body->position,  body->rotation, 5, velocity);
        }
    }
}


