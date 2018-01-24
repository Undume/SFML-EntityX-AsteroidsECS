//
//  AsteroidPoolFactory.hpp
//  PewPew
//
//  Created by Enric on 8/11/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef ShipBuilder_hpp
#define ShipBuilder_hpp

#include <stdio.h>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

namespace pew{
    
    enum ShipControllerType{PLAYER=0, AI_OPPONENT, NETWORK_OPPONENT};
    
    class ShipBuilder{
    public:
        void buildShip(ShipControllerType type, const sf::Vector2<float> &size, sf::Color color,  const sf::Vector2<float> & position, const float & rotation, entityx::EntityManager& ex) noexcept;
    };
}
#endif
