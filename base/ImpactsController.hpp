//
//  ImpactsController.hpp
//  PewPew
//
//  Created by Enric on 1/3/18.
//  Copyright © 2018 Enric Cantalejos. All rights reserved.
//

#ifndef ImpactsController_hpp
#define ImpactsController_hpp

#include "Ship.h"
#include "Meteor.h"
#include "Body.h"
#include "Motion.h"
#include "entityx.h"
#include "AsteroidPoolBuilder.hpp"

namespace pew
{
    class ImpactsController
    {
    public:
        ImpactsController(AsteroidPoolBuilder & asteroidPoolBuilder);
        void impactShip(entityx::Entity * damageDealer, pew::Ship * ship);
        void impactAsteroid(entityx::Entity * meteorEntity, entityx::Entity * bulletEntity);
        
    private:
        AsteroidPoolBuilder asteroidPoolBuilder;
    };
}
#endif /* ImpactsController_hpp */
