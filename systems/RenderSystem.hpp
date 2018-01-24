//
//  RenderSystem.hpp
//  PewPew
//
//  Created by Enric on 9/29/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef RenderSystem_hpp
#define RenderSystem_hpp

#include <SFML/Graphics.hpp>
#include "entityx/System.h"

class RenderSystem : public entityx::System<RenderSystem>
{
public:
    /// <summary>
    /// Loads the background image, creates the sprites for the background and main sprite sheet.
    /// </summary>
    /// <param name="window">The SFML render window.</param>
    /// <param name="spSSTexture">The sprite sheet texture.</param>
    explicit RenderSystem(sf::RenderWindow& window);
    
    void update(entityx::EntityManager& entities,
                entityx::EventManager& events,
                double dt);
    
    
private:
    
    sf::RenderWindow *_window;
};

#endif /* RenderSystem_hpp */
