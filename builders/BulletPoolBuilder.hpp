//
//  AsteroidPoolFactory.hpp
//  PewPew
//
//  Created by Enric on 8/11/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef BulletPoolBuilder_hpp
#define BulletPoolBuilder_hpp

#include <stdio.h>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

namespace pew{
    
    class BulletPoolBuilder{
    public:
        BulletPoolBuilder(int numberOfBullets, entityx::EntityManager & ex);
        entityx::Entity * activateBullet(sf::Vector2f position, float rotation, float speed) noexcept;
        
    private:
        std::vector<entityx::Entity> _bulletsPool;
        std::vector<entityx::Entity>::iterator _itBullet;
    };
}
#endif /* BulletPoolBuilder */
