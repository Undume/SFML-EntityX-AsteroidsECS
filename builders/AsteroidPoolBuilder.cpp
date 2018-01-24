//
//  AsteroidPoolBuilder.cpp
//  PewPew
//
//  Created by Enric on 8/11/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "AsteroidPoolBuilder.hpp"
#include "Body.h"
#include "Meteor.h"
#include "Motion.h"
#include "DamageDealer.h"
#include <SFML/Graphics.hpp>

using namespace pew;

AsteroidPoolBuilder::AsteroidPoolBuilder(const int nSmall,const int nMedium,const int nBig, entityx::EntityManager& ex){
    _mapMeteors[MeteorSize::SMALL].reserve(nSmall);
    _mapMeteors[MeteorSize::MEDIUM].reserve(nMedium);
    _mapMeteors[MeteorSize::BIG].reserve(nBig);
    
    
    for(int i=0; i<nSmall; i++){
        entityx::Entity asteroid = ex.create();
        
        float radius(pew::MeteorSizeSmall);
        asteroid.assign<pew::Body>(pew::Shape::CIRCLE, false, sf::Vector2<float>(-1000,-1000),sf::Vector2<float>(radius,radius),0);
        
        asteroid.assign<pew::Meteor>(radius, MeteorSize::SMALL);
        asteroid.assign<pew::Motion>(pew::MeteorSpeedMotion);
        asteroid.assign<pew::DamageDealer>(pew::MeteorDamageSmall);
        std::shared_ptr<sf::Shape> shape(new sf::CircleShape(radius));
        shape->setFillColor(sf::Color(128,128,128, 255));
        shape->setOrigin(radius, radius);
        asteroid.assign<std::shared_ptr<sf::Shape>>(shape);
        
        _mapMeteors[MeteorSize::SMALL].emplace_back(asteroid);
    }
    for(int i=0; i<nMedium; i++){
        entityx::Entity asteroid = ex.create();
        
        float radius(pew::MeteorSizeMedium);
        asteroid.assign<pew::Body>(pew::Shape::CIRCLE, false, sf::Vector2<float>(-1000,-1000),sf::Vector2<float>(radius,radius),0);

        asteroid.assign<pew::Meteor>(radius, MeteorSize::MEDIUM);
        asteroid.assign<pew::Motion>(pew::MeteorSpeedMotion);
        asteroid.assign<pew::DamageDealer>(pew::MeteorDamageMedium);
        std::shared_ptr<sf::Shape> shape(new sf::CircleShape(radius));
        shape->setFillColor(sf::Color(128,128,128, 255));
        shape->setOrigin(radius, radius);
        asteroid.assign<std::shared_ptr<sf::Shape>>(shape);
        
        _mapMeteors[MeteorSize::MEDIUM].emplace_back(asteroid);
    }
    for(int i=0; i<nBig; i++){
        entityx::Entity asteroid = ex.create();
        
        float radius(pew::MeteorSizeBig);
        asteroid.assign<pew::Body>(pew::Shape::CIRCLE, false, sf::Vector2<float>(-1000,-1000),sf::Vector2<float>(radius,radius),0);
        
        asteroid.assign<pew::Meteor>(radius, MeteorSize::BIG);
        asteroid.assign<pew::Motion>(pew::MeteorSpeedMotion);
        asteroid.assign<pew::DamageDealer>(pew::MeteorDamageBig);
        std::shared_ptr<sf::Shape> shape(new sf::CircleShape(radius));
        shape->setFillColor(sf::Color(200,128,100, 255));
        shape->setOrigin(radius, radius);
        asteroid.assign<std::shared_ptr<sf::Shape>>(shape);
        
        _mapMeteors[MeteorSize::BIG].emplace_back(asteroid);
    }
    
    _itSmall = _mapMeteors[MeteorSize::SMALL].begin();
    _itMedium = _mapMeteors[MeteorSize::MEDIUM].begin();
    _itBig = _mapMeteors[MeteorSize::BIG].begin();
}


void AsteroidPoolBuilder::activateMeteor(const MeteorSize & size, const sf::Vector2<float> & position, const float & rotation, const float &  dRotation, const sf::Vector2<float> & speed) noexcept{
    
    std::vector<entityx::Entity>::iterator * it = nullptr;
    
    int counter = 0;
    if(size == MeteorSize::SMALL)
    {
        do{
            if(_itSmall == _mapMeteors[MeteorSize::SMALL].end()-1)
            {
                _itSmall = _mapMeteors[MeteorSize::SMALL].begin();
            }
            else
            {
                _itSmall++;
            }
            
            if(!_itSmall->component<Body>()->isActive)
            {
                it = &_itSmall;
            }
            counter++;
        }while(!it && counter<_mapMeteors[MeteorSize::SMALL].size());
    }
    else if(size == MeteorSize::MEDIUM)
    {
        do{
            if(_itMedium == _mapMeteors[MeteorSize::MEDIUM].end()-1)
            {
                _itMedium = _mapMeteors[MeteorSize::MEDIUM].begin();
            }
            else
            {
                _itMedium++;
            }
            
            if(!_itMedium->component<Body>()->isActive)
            {
                it = &_itMedium;
            }
            counter++;
        }while(!it && counter<_mapMeteors[MeteorSize::MEDIUM].size());
    }
    else if(size == MeteorSize::BIG)
    {
        do{
            if(_itBig == _mapMeteors[MeteorSize::BIG].end()-1)
            {
                _itBig = _mapMeteors[MeteorSize::BIG].begin();
            }
            else
            {
                _itBig++;
            }
            
            if(!_itBig->component<Body>()->isActive)
            {
                it = &_itBig;
            }
            counter++;
        }while(!it && counter<_mapMeteors[MeteorSize::BIG].size());
    }
    if(it){
        (*it)->component<Body>().get()->position=position;
        (*it)->component<Body>().get()->rotation=rotation;
        (*it)->component<Body>().get()->rotationd=dRotation;
        (*it)->component<Motion>().get()->velocity=speed;
        (*it)->component<Body>()->isActive = true;
    }
   
    
}
