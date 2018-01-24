//
//  AsteroidPoolFactory.hpp
//  PewPew
//
//  Created by Enric on 8/11/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef MeteorSpawnerBuilder_hpp
#define MeteorSpawnerBuilder_hpp

#include <stdio.h>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

namespace pew{
    
    class MeteorSpawnerBuilder{
    public:
        void spawnMeteorSpawner(const sf::Vector2<float> & position, const float & rotation, const float & spawnRate, entityx::EntityManager& ex) noexcept;
    };
}
#endif
