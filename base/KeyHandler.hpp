//
//  KeyHandler.hpp
//  PewPew
//
//  Created by Enric on 10/6/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef KeyHandler_hpp
#define KeyHandler_hpp

#pragma once

#include <map>
#include <SFML/Window/Keyboard.hpp>

class KeyHandler
{
public:
    
    KeyHandler();
    
    void updateKey(sf::Keyboard::Key key, bool isPressed);
    
    bool isPressed(sf::Keyboard::Key key) const;
    
private:
    
    typedef std::map<sf::Keyboard::Key, bool> KeyMap;
    KeyMap m_keyMap;
};

#endif /* KeyHandler_hpp */
