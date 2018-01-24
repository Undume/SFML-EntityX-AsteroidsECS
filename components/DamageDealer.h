//
//  DamageDealer.h
//  PewPew
//
//  Created by Enric on 1/3/18.
//  Copyright © 2018 Enric Cantalejos. All rights reserved.
//

#ifndef DamageDealer_h
#define DamageDealer_h

#include "entityx/Entity.h"

namespace pew {
    struct DamageDealer : public entityx::Component<DamageDealer>
    {
        // Note: Passing the Entity here by reference will break the MovementSystem (where the parent is retrieved).
        
        DamageDealer(unsigned damage):damage(damage){}
        unsigned damage;
    };
}

#endif /* DamageDealer_h */
