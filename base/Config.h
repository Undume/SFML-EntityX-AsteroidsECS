//
//  ConfigConstants.h
//  PewPew
//
//  Created by Enric on 11/8/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef ConfigConstants_h
#define ConfigConstants_h

#include <SFML/System/Vector2.hpp>

namespace pew{
    const float MeteorSizeSmall = 10;
    const float MeteorSizeMedium = 20;
    const float MeteorSizeBig = 40;
    const float MeteorSpeedMotion = 5.f;
    const unsigned MeteorDamageSmall = 1;
    const unsigned MeteorDamageMedium  = 2;
    const unsigned MeteorDamageBig  = 3;
    enum MeteorSize { SMALL=0, MEDIUM=1, BIG=2};
}

#endif /* ConfigConstants_h */
