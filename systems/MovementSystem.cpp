//
//  MovementSystem.cpp
//  PewPew
//
//  Created by Enric on 10/4/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "MovementSystem.hpp"
#include "Body.h"
#include "Motion.h"

using namespace entityx;

MovementSystem::MovementSystem(){}

void MovementSystem::update(entityx::EntityManager &entities,
                            entityx::EventManager &events,
                            double dt)
{
    
    ComponentHandle<pew::Body> body;
    ComponentHandle<pew::Motion> motion;
    
    for (entityx::Entity entity : entities.entities_with_components(motion, body))
    {
        if(body->isActive){
            body->position.x += motion->velocity.x;
            body->position.y += motion->velocity.y;
        }
    }
    
    
    ComponentHandle<pew::Hierarchy> parent;
    for (entityx::Entity entity : entities.entities_with_components(body, parent))
    {
        if(parent->parent)
        {
            ComponentHandle<pew::Body> parentPosition = parent->parent->component<pew::Body>();
            body->position.x = parent->relativePositionOfParent.x + parentPosition->position.x;
            body->position.y = parent->relativePositionOfParent.y + parentPosition->position.y;
        }
    }
}

