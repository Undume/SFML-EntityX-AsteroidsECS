//
//  KeyHandler.cpp
//  PewPew
//
//  Created by Enric on 10/6/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#include "KeyHandler.hpp"

KeyHandler::KeyHandler()
: m_keyMap()
{
}

void KeyHandler::updateKey(sf::Keyboard::Key key, bool isPressed)
{
    m_keyMap[key] = isPressed;
}

bool KeyHandler::isPressed(sf::Keyboard::Key key) const
{
    KeyMap::const_iterator it = m_keyMap.find(key);
    
    if (it != m_keyMap.end())
    {
        return it->second;
    }
    
    return false;
}
