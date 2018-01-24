//
//  Ship.h
//  PewPew
//
//  Created by Enric on 9/7/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef Shooter_h
#define Shooter_h

namespace pew {
    struct Shooter : public entityx::Component<Shooter> {
        Shooter(float rateShooting) : rateShooting(rateShooting), isShooting(false),timerRateShooting(0) {}
        bool isShooting;
        float rateShooting;
        float timerRateShooting;
    };
}

#endif /* Header_h */
