//
//  MeteorSpawnerBuilder.cpp
//  PewPew
//
//  Created by Enric on 8/11/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "MeteorSpawnerBuilder.hpp"
#include "Body.h"
#include "MeteorSpawner.h"
#include "InputController.h"
#include "NetworkController.h"
#include "AIController.h"
#include <SFML/Graphics.hpp>

using namespace pew;



void MeteorSpawnerBuilder::spawnMeteorSpawner(const sf::Vector2<float> & position, const float & rotation, const float & spawnRate, entityx::EntityManager& ex) noexcept
{
    entityx::Entity spawner = ex.create();
    spawner.assign<pew::Body>(pew::Shape::BOX, true, position,sf::Vector2f(0,0), rotation);
    spawner.assign<pew::MeteorSpawner>(spawnRate);
    
}
