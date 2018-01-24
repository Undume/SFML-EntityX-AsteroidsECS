//
//  BulletPoolFactory.cpp
//  PewPew
//
//  Created by Enric on 8/11/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "ShipBuilder.hpp"
#include "Body.h"
#include "Motion.h"
#include "Ship.h"
#include "Hierarchy.h"
#include "Shooter.h"
#include "InputController.h"
#include "NetworkController.h"
#include "AIController.h"
#include "Utility.hpp"
#include <SFML/Graphics.hpp>

using namespace pew;



void ShipBuilder::buildShip(ShipControllerType type, const sf::Vector2<float> & size, sf::Color color, const sf::Vector2<float> & position, const float & rotation, entityx::EntityManager& ex) noexcept{
    
    entityx::Entity ship = ex.create();
    ship.assign<pew::Body>(pew::Shape::BOX, true, position,size, rotation);
    ship.assign<pew::Motion>(3.f);
    ship.assign<pew::Ship>("unnamed");
    std::shared_ptr<sf::Shape> shape(new sf::RectangleShape(size));
    shape->setFillColor(color);
    shape->setOrigin(size.x/2, size.y/2);
    ship.assign<std::shared_ptr<sf::Shape>>(shape);
    
    switch(type){
        case pew::ShipControllerType::PLAYER:
            ship.assign<InputController>();
            break;
        case pew::ShipControllerType::AI_OPPONENT:
            ship.assign<AIController>();
            break;
        case pew::ShipControllerType::NETWORK_OPPONENT:
            ship.assign<NetworkController>();
            break;
    }

    entityx::Entity weapon = ex.create();
    weapon.assign<pew::Body>(pew::Shape::BOX, true, position,size, rotation);
    weapon.assign<pew::Shooter>(1);
    pew::Hierarchy weaponHierarchy;
    weaponHierarchy.parent = &ship;
    weaponHierarchy.relativePositionOfParent = sf::Vector2f(std::cos(DEG_TO_RAD  * rotation) * 0,
                                                            std::sin(DEG_TO_RAD  * rotation) * 30);
    weapon.assign<pew::Hierarchy>(weaponHierarchy);
    std::shared_ptr<sf::Shape> shapeWeapon(new sf::RectangleShape(size));
    shapeWeapon->setFillColor(color);
    shapeWeapon->setOrigin(size.x/2, size.y/2);
    weapon.assign<std::shared_ptr<sf::Shape>>(shapeWeapon);
    
    pew::Hierarchy shipHierarchy;
    shipHierarchy.childs.push_back(&weapon);
    ship.assign<pew::Hierarchy>(shipHierarchy);
}
