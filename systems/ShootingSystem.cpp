//
//  ShootingSystem.cpp
//  PewPew
//
//  Created by Enric on 10/4/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "ShootingSystem.hpp"
#include "Body.h"
#include "Shooter.h"

using namespace entityx;


double ShootingSystem::DEG_TO_RAD = 3.1416f / 180.0f;

ShootingSystem::ShootingSystem(pew::BulletPoolBuilder & bulletPool)
: _bulletPool(bulletPool)
{
}

void ShootingSystem::update(entityx::EntityManager &entities,
                            entityx::EventManager &events,
                            double dt)
{
    
    ComponentHandle<pew::Body> body;
    ComponentHandle<pew::Shooter> shooter;
    
    for (entityx::Entity entity : entities.entities_with_components(shooter, body))
    {
        shooter->timerRateShooting += dt;

        if(shooter->isShooting && shooter->timerRateShooting > shooter->rateShooting){
            shooter->timerRateShooting = 0;
            Entity * bullet = _bulletPool.activateBullet(body->position, body->rotation,5);
        }
    }
}
