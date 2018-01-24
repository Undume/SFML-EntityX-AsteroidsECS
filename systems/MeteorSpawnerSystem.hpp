//
//  MeteorSpawnerSystem.hpp
//  PewPew
//
//  Created by Enric on 10/4/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef MeteorSpawnerSystem_hpp
#define MeteorSpawnerSystem_hpp

#include "entityx/System.h"
#include <SFML/System/Vector2.hpp>
#include "AsteroidPoolBuilder.hpp"

class MeteorSpawnerSystem : public entityx::System<MeteorSpawnerSystem>
{
public:
    MeteorSpawnerSystem(pew::AsteroidPoolBuilder & asteroidPool);
    
    void update(entityx::EntityManager &entities,
                entityx::EventManager &events,
                double dt);
    
private:
    pew::AsteroidPoolBuilder & _asteroidPool;
};
#endif /* MovementSystem_hpp */

