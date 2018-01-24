//
//  RenderSystem.cpp
//  PewPew
//
//  Created by Enric on 9/29/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "RenderSystem.hpp"
#include "Body.h"
#include "Ship.h"
#include "Bullet.h"
#include "Meteor.h"

using namespace entityx;

RenderSystem::RenderSystem(sf::RenderWindow& window)
: _window(&window)
{
}

void RenderSystem::update(EntityManager &entities,
                          EventManager &events,
                          double dt)
{
    _window->clear(sf::Color(200,200,200));
    
    entities.each<pew::Body, std::shared_ptr<sf::Shape>>(
                                                                    [&](entityx::Entity entity, pew::Body & body, std::shared_ptr<sf::Shape> & shape){
                                                                        if(body.isActive)
                                                                        {
                                                                            shape->setPosition(body.position.x, body.position.y);
                                                                            shape->setRotation(body.rotation);
                                                                            _window->draw(*shape);
                                                                        }
                                                                    });
}
