//
//  ShootingSystem.hpp
//  PewPew
//
//  Created by Enric on 10/4/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef ShootingSystem_hpp
#define ShootingSystem_hpp

#include "entityx/System.h"
#include <SFML/System/Vector2.hpp>
#include "BulletPoolBuilder.hpp"

class ShootingSystem : public entityx::System<ShootingSystem>
{
public:
    ShootingSystem(pew::BulletPoolBuilder & bulletPool);
    
    void update(entityx::EntityManager &entities,
                entityx::EventManager &events,
                double dt);
    
private:
    
    static double DEG_TO_RAD;
    pew::BulletPoolBuilder & _bulletPool;
};
#endif /* MovementSystem_hpp */
