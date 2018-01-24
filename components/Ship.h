//
//  Ship.h
//  PewPew
//
//  Created by Enric on 9/7/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef Ship_h
#define Ship_h

#include <SFML/System/Vector2.hpp>
#include <entityx.h>

namespace pew {
    struct Ship : public entityx::Component<Ship> {
        Ship(std::string name) : name(name), lifes(lifes) {}
        std::string name;
        float accelaration;
        float maxSpeed;
        int lifes;
    };
}

#endif /* Header_h */
