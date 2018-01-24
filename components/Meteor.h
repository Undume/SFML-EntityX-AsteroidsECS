//
//  Meteor.hpp
//  PewPew
//
//  Created by Enric on 9/4/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef Meteor_h
#define Meteor_h

#include "Config.h"

namespace pew {
    struct Meteor : public entityx::Component<Meteor>{
        Meteor(float radius, MeteorSize type) : radius(radius), type(type), inBattleground(false) {}
        float radius;
        bool inBattleground;
        MeteorSize type;
    };
}

#endif /* Meteor_hpp */
