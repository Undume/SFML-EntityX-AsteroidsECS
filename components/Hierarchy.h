//
//  Parent.h
//  PewPew
//
//  Created by Enric on 10/4/17.
//  Copyright © 2017 Enric Cantalejos. All rights reserved.
//

#ifndef Hierarchy_h
#define Hierarchy_h

#include "entityx/Entity.h"
#include <SFML/System/Vector2.hpp>

namespace pew {
struct Hierarchy : public entityx::Component<Hierarchy>
{
    Hierarchy() : parent(0)
    {
    }
    std::vector<uint64_t> childIds;
    uint64_t parent;
    sf::Vector2f relativePositionOfParent;
    
    template<typename T>
    entityx::Entity * findFirstChildWithComponent()
    {
        for(uint64_t * child : childIds)
        {
            entityx::ComponentHandle<T> shooter = entityManager;
            if(child->has_component<T>())
                return child;
        }
        return nullptr;
    };
    
    template<typename T>
    std::vector<entityx::Entity *> findAllChildWithComponent()
    {
        std::vector<entityx::Entity *> childsTemp;
        for(auto child : childs)
        {
            if(child->entityx::Entity::has_component<T>())
                childsTemp.push_back(child);
        }
        return childsTemp;
    };
};
}

#endif /* Parent_h */
