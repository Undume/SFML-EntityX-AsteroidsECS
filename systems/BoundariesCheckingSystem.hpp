//
//  BoundariesCheckingSystem.hpp
//  PewPew
//
//  Created by Enric on 10/6/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef BoundariesCheckingSystem_hpp
#define BoundariesCheckingSystem_hpp

#pragma once

#include "entityx/System.h"

class BoundariesCheckingSystem : public entityx::System<BoundariesCheckingSystem>
{
public:
    
    BoundariesCheckingSystem();
    
    void update(entityx::EntityManager &entities,
                entityx::EventManager &events,
                double dt);
};

#endif /* BoundariesCheckingSystem_hpp */
