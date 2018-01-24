//
//  Motion.h
//  PewPew
//
//  Created by Enric on 9/27/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef Motion_h
#define Motion_h

#include <SFML/System/Vector2.hpp>

namespace pew {
    struct Motion : public entityx::Component<Motion> {
        Motion(float maxSpeed) : maxSpeed(maxSpeed), velocity(sf::Vector2f(0,0)) {}
        float maxSpeed;
        float accelaration;
        sf::Vector2f velocity;
    };
}

#endif /* Motion_h */
