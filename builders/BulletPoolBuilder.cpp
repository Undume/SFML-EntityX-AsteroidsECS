//
//  BulletPoolBuilder.cpp
//  PewPew
//
//  Created by Enric on 8/11/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "BulletPoolBuilder.hpp"
#include "Body.h"
#include "Bullet.h"
#include "Motion.h"
#include "DamageDealer.h"
#include "Utility.hpp"
#include <SFML/Graphics.hpp>

using namespace pew;

BulletPoolBuilder::BulletPoolBuilder(int numberOfBullets, entityx::EntityManager& ex){
    _bulletsPool.reserve(numberOfBullets);
    
    for(int i=0; i<numberOfBullets; i++){
        entityx::Entity bullet = ex.create();
        sf::Vector2f size(10,20);
        bullet.assign<pew::Body>(pew::Shape::BOX, false, size,sf::Vector2<float>(0,0),0);
        bullet.assign<pew::Bullet>();
        bullet.assign<pew::DamageDealer>(1);
        bullet.assign<pew::Motion>(10);
        std::shared_ptr<sf::Shape> shape(new sf::RectangleShape(size));
        shape->setFillColor(sf::Color(128,128,128, 0));
        shape->setOrigin(size.x/2, size.y/2);
        bullet.assign<std::shared_ptr<sf::Shape>>(shape);
        
        _bulletsPool.emplace_back(bullet);
    }
    
}


entityx::Entity * BulletPoolBuilder::activateBullet(sf::Vector2f position, float rotation, float speed) noexcept{
    
    while(_itBullet->component<Body>()->isActive){
        _itBullet++;
        if(_itBullet == _bulletsPool.end())
        {
            _itBullet = _bulletsPool.begin();
        }
    }
    
    _itBullet->component<Body>()->position=std::move(position);
    _itBullet->component<Body>()->rotation=std::move(rotation);
    _itBullet->component<Body>()->isActive = true;
    _itBullet->component<Motion>()->velocity = sf::Vector2f(std::cos(pew::DEG_TO_RAD  * rotation) * speed,
    std::sin(pew::DEG_TO_RAD  * rotation) * speed);

    return &(*_itBullet);
}
