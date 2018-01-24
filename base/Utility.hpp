#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include "stdlib.h"

#include <sstream>
namespace pew{
    #define RANDOM_BETWEEN(min, max) (((float) (rand() % ((unsigned)RAND_MAX + 1)) / RAND_MAX) * (max - min) + min)
    
    template <typename T>
    std::string    toString(const T& value){
        std::stringstream stream;
        stream << value;
        return stream.str();
    };
    
    struct ScreenSize{
        static float width;
        static float height;
    };
    
    static double DEG_TO_RAD = 3.1416f / 180.0f;
}


#endif // BOOK_UTILITY_HPP
