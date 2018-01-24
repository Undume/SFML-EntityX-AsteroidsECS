//
//  Velocity.h
//  PewPew
//
//  Created by Enric on 8/10/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef Velocity_h
#define Velocity_h

#include <SFML/System/Vector2.hpp>

namespace pew {
    enum Shape{BOX, CIRCLE};
    
    struct Body : public entityx::Component<Body> {
        Body(Shape shape, bool isActive, const sf::Vector2f position, sf::Vector2f size, float rotation, float rotationd = 0.0)
        : isActive(isActive),position(position), size(size), rotation(rotation), rotationd(rotationd), alpha(0.0),shape(shape) {}
        
        Shape shape;
        sf::Vector2f size;
        sf::Vector2f position;
        float rotation = 0.0, rotationd, alpha;
        bool isActive;
    };
}

#endif /* Velocity_h */
