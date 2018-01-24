//
//  InputController.h
//  PewPew
//
//  Created by Enric on 9/7/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef InputController_h
#define InputController_h

#include <SFML/Window/Keyboard.hpp>

namespace pew {
    struct InputController : public entityx::Component<InputController> {
        
        InputController()
        : left(sf::Keyboard::A)
        , altLeft(sf::Keyboard::Left)
        , right(sf::Keyboard::D)
        , altRight(sf::Keyboard::Right)
        , up(sf::Keyboard::W)
        , altUp(sf::Keyboard::Up)
        , down(sf::Keyboard::S)
        , altDown(sf::Keyboard::Down)
        , shoot(sf::Keyboard::Space)
        , pause(sf::Keyboard::Escape)
        {
        }
        
        sf::Keyboard::Key left, altLeft;
        
        sf::Keyboard::Key right, altRight;
        
        sf::Keyboard::Key up, altUp;
        
        sf::Keyboard::Key down, altDown;
        
        sf::Keyboard::Key shoot;
        
        sf::Keyboard::Key pause;
    };
}

#endif /* InputController_h */
