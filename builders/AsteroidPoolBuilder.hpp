//
//  AsteroidPoolFactory.hpp
//  PewPew
//
//  Created by Enric on 8/11/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef AsteroidPoolBuilder_hpp
#define AsteroidPoolBuilder_hpp

#include <stdio.h>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include "Config.h"

namespace pew{
    
    class AsteroidPoolBuilder{
    public:
        AsteroidPoolBuilder(const int nSmall,const int _nMedium,const int _nBig, entityx::EntityManager& ex);
        void activateMeteor(const MeteorSize & size,const sf::Vector2<float> & position,const float & rotation,const float & dRotation, const sf::Vector2<float> & speed) noexcept;
        
    private:
        std::unordered_map<int, std::vector<entityx::Entity>> _mapMeteors;
        
        std::vector<entityx::Entity>::iterator _itSmall;
        std::vector<entityx::Entity>::iterator _itMedium;
        std::vector<entityx::Entity>::iterator _itBig;
        
    };
}
#endif /* AsteroidPoolFactory_hpp */
