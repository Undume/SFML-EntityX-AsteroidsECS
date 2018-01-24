//
//  InputPlayerSystem.hpp
//  PewPew
//
//  Created by Enric on 10/6/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef InputPlayerSystem_hpp
#define InputPlayerSystem_hpp

#pragma once

#include "entityx/System.h"
#include "InputController.h"
#include "Motion.h"
#include "Body.h"
#include "Shooter.h"
#include <SFML/System/Vector2.hpp>

class KeyHandler;

class InputPlayerSystem : public entityx::System<InputPlayerSystem>
{
public:
    
    InputPlayerSystem(const KeyHandler& keyHandler);
    
    void update(entityx::EntityManager &entities,
                entityx::EventManager &events,
                double dt);
    
private:
    
     const KeyHandler & _keyHandler;
};

#endif /* InputPlayerSystem_hpp */
