#ifndef PARTICLE
#define PARTICLE

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

class Particle {
    private:
        double mass = 0.2f;
        sf::Vector2f position; //define the postion of the partice
        sf::Vector2f acceleration; //define the acceleration of each particle
        sf::Vector2f past_positon; //define in order to keep track of the past positions
    public:
        Particle (double x, double y) : position(x, y), acceleration(x, y), past_positon(x, y) { }

        //apply the 2nd law of dynamics F = m * a => a = F / m;
        void Force_application (sf::Vector2f Force) {
            if (mass != 0.0) {
                acceleration.x += Force.x / static_cast<double>(mass);
                acceleration.y += Force.y / static_cast<double>(mass);
            } else {
                acceleration = sf::Vector2f(0.0f, 0.0f);
            }
        }


        //we update the position of the particle based on the equation r_now = r_old + velocity * time
        void update_position (double delta_time) {
            sf::Vector2f velocity = position - past_positon;
            past_positon = position;
            position += velocity + acceleration * static_cast<float>(pow(delta_time, 2));
            acceleration = sf::Vector2f(0.0f, 0.0f);
        }

        //we define the movement limits
        void limits (double width, double height) { 
            if (position.x < 0) position.x = 0;
            if (position.x > width) position.x = width;
            if (position.y < 0) position.y = 0;
            if (position.y = height) position.y = height;
        }
};
#endif
