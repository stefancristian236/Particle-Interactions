#ifndef PARTICLE
#define PARTICLE

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

class Particle {
    private:
        sf::Vector2f position; //define the postion of the partice
        sf::Vector2f acceleration; //define the acceleration of each particle
        sf::Vector2f past_positon; //define in order to keep track of the past positions
    public:
        

};


#endif
