//
//  InputPlayerSystem.cpp
//  PewPew
//
//  Created by Enric on 10/6/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "BoundariesCheckingSystem.hpp"
#include <iostream>
#include "Body.h"
#include "Meteor.h"
#include "Ship.h"
#include "Bullet.h"
#include "Motion.h"
#include <SFML/System/Vector2.hpp>
#include "Utility.hpp"

using namespace entityx;
BoundariesCheckingSystem::BoundariesCheckingSystem()
{
}


void BoundariesCheckingSystem::update(EntityManager &entities, EventManager &events, double dt)
{
	ComponentHandle<pew::Meteor> meteor;
	ComponentHandle<pew::Bullet> bullet;
	ComponentHandle<pew::Body> body;
    ComponentHandle<pew::Ship> ship;

	for (Entity entity : entities.entities_with_components(bullet, body))
	{
		if (body->isActive)
			body->isActive = !(body->position.x + body->size.x < -pew::ScreenSize::width * 0.2f || body->position.x - body->size.x > pew::ScreenSize::width*1.2f ||
				body->position.y + body->size.y < -pew::ScreenSize::height * 0.2f || body->position.y - body->size.y > pew::ScreenSize::height * 1.2f);
	}

	for (Entity entity : entities.entities_with_components(meteor, body))
	{
        if(!body->isActive) continue;
        
		if (!meteor->inBattleground)
		{
			meteor->inBattleground = body->position.x > body->size.x * 1.1f && body->position.x < pew::ScreenSize::width - body->size.x*1.1f &&
				body->position.y > body->size.y * 1.1f && body->position.y < pew::ScreenSize::height - body->size.y*1.1f;
		}
		else
		{
			if (!(body->position.x - body->size.x > 0  && body->position.x + body->size.x < pew::ScreenSize::width))
			{
				entity.component<pew::Motion>()->velocity = sf::Vector2f(-entity.component<pew::Motion>()->velocity.x, entity.component<pew::Motion>()->velocity.y);
			}
            
            float aa = body->position.y + body->size.y;
            float bb = body->position.y - body->size.y;
            float cc = pew::ScreenSize::height;
            
            if(!(body->position.y + body->size.y > 0  && body->position.y - body->size.y < pew::ScreenSize::height))
            {
                body->isActive=false;
                meteor->inBattleground=false;
            }
        }
    }
    
    for (Entity entity : entities.entities_with_components(ship, body))
    {
        if(body->position.x - body->size.x/2 < 0)
        {
            body->position.x = body->size.x/2;
        }
        else if(body->position.x + body->size.x/2 > pew::ScreenSize::width)
        {
            body->position.x = pew::ScreenSize::width-body->size.x/2;
        }
    }
    
}
