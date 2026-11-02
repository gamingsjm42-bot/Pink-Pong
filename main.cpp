//includes
#include <SFML/Graphics.hpp>
#include "object/ball.h"
//
//set ponks ball
std::vector<ponk> ponks ={ponk({0,200},constances::lengthAndWidth,sf::Color::Red,constances::speed),ponk({1900,800},constances::lengthAndWidth,sf::Color::Red,constances::speed)};
Ball ball({700,100},30,sf::Color::Blue,sf::Vector2f(constances::speed,constances::speed));
//main
int main()
{
    //I Will to set t on my programe
    sf::Clock clock;
    sf::Time t;
    //set begin ;of clock
    clock.start();
    float dt;
    //set Window variable
    ponk s({34,56},{12,64},sf::Color::Red,3);
    sf::RenderWindow window(sf::VideoMode({1920,1080}),"Pink Ponk",sf::State::Fullscreen);
    //loop 
    while (window.isOpen())
    {
        //set dt
        dt = clock.getElapsedTime().asSeconds()-t.asSeconds();
        //set time value
        t = clock.getElapsedTime();
        //set all event window
        while (std::optional<sf::Event> event = window.pollEvent())
        {
            //set Even Close
            if(event->is<sf::Event::Closed>()) window.close();
        }
        //set background color
        window.clear(sf::Color::Green);
        //set draw ponks
        for (auto ponk = ponks.begin(); ponk !=ponks.end(); ponk++) ponk->draw(window);
        //draw ball
        ball.draw(window);
        ///move script
        ponks[0].ponkAi(window,(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)? ponk::Up:((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))? ponk::Down:ponk::Stand)),dt);
        ponks[1].ponkAi(window ,(ponks[1].getPosition().y>ball.getPosition().y)? ponk::Up:ponk::Down,dt);
        ball.ai(window,dt,ponks);
        //set frame limite
        window.setFramerateLimit(60);
        //set display
        window.display();
        //draw background
    }
    
}