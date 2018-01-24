//
//  InputPlayerSystem.cpp
//  PewPew
//
//  Created by Enric on 10/6/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "InputPlayerSystem.hpp"
#include <iostream>
#include "KeyHandler.hpp"
#include "Hierarchy.h"

using namespace entityx;
InputPlayerSystem::InputPlayerSystem(const KeyHandler& keyHandler)

: _keyHandler(keyHandler)
{
}


void InputPlayerSystem::update(EntityManager &entities,
                                 EventManager &events,
                                 double dt)
{
    ComponentHandle<pew::InputController> inputController;
    ComponentHandle<pew::Motion> motion;
    
    for (Entity entity : entities.entities_with_components(inputController, motion))
    {
        if (_keyHandler.isPressed(inputController->right)
            || _keyHandler.isPressed(inputController->altRight))
        {
            motion->velocity.x = motion->maxSpeed;
        }
        else if (_keyHandler.isPressed(inputController->left)
                 || _keyHandler.isPressed(inputController->altLeft))
        {
            motion->velocity.x = -motion->maxSpeed;
        }else{
            motion->velocity.x = 0;
        }
        
        if (_keyHandler.isPressed(inputController->up)
            || _keyHandler.isPressed(inputController->altUp))
        {
            
        }
        else if (_keyHandler.isPressed(inputController->down)
                 || _keyHandler.isPressed(inputController->altDown))
        {
            
        }
        Entity * weapon;
        if (entity.has_component<pew::Hierarchy>())
        {
            weapon = entity.component<pew::Hierarchy>()->findFirstChildWithComponent<pew::Shooter>();
            if (weapon)
            {
                ComponentHandle<pew::Shooter> shooter = weapon->component<pew::Shooter>();
                shooter->isShooting  = _keyHandler.isPressed(inputController->shoot);
            }
        }
    }
}
