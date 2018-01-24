//
//  MovementSystem.hpp
//  PewPew
//
//  Created by Enric on 10/4/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef MovementSystem_hpp
#define MovementSystem_hpp

#include "entityx/System.h"
#include <SFML/System/Vector2.hpp>
#include "Motion.h"
#include "Body.h"
#include "Hierarchy.h"


class MovementSystem : public entityx::System<MovementSystem>
{
public:
    
    MovementSystem();
    
    void update(entityx::EntityManager &entities,
                entityx::EventManager &events,
                double dt);
    
private:
    
    bool isOnScreen(sf::Vector2f newPos, entityx::Entity &entity) const;
    
};
#endif /* MovementSystem_hpp */
