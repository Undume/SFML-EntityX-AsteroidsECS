//
//  MeteorSpawner.h
//  PewPew
//
//  Created by Enric on 9/7/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef MeteorSpawner_h
#define MeteorSpawner_h

namespace pew {
    struct MeteorSpawner : public entityx::Component<MeteorSpawner>{
        MeteorSpawner(float rateSpawning) : rateSpawning(rateSpawning), timerRateSpawning(0) {}
        float rateSpawning;
        float timerRateSpawning;
    };
}

#endif /* Header_h */
