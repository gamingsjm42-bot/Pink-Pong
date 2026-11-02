//includes SFML WITH Fix
#pragma once
#include <SFML/Graphics.hpp>
/// @brief that class of ponk + effect
class ponk
{
private: 
//variables
    sf::Vector2f pos,lengthAndWidth;
    float Speed;
    sf::Color color;
public:
    //set enum
    using direction = enum {Stand,Up,Down};
     ponk(sf::Vector2f defaultPosition ,sf::Vector2f lengthAndWidth,sf::Color color,float speed)
     {
        //set vars of length
        pos = defaultPosition;
        //set length and Width Variable
        this->lengthAndWidth = lengthAndWidth;
        //color
        this->color = color;
        //
        Speed = speed;
     }
     /// @brief that function on loop that draw ponk
     void draw( sf::RenderWindow  &wnd  )
     {
        //set shape color for all
        sf::RectangleShape _rec (lengthAndWidth);
        //set color for rectangle
        _rec.setFillColor(color);
        //set color based
        auto newPos = pos;
        newPos.y-=lengthAndWidth.y;
        _rec.setPosition(newPos);
        //
        wnd.draw(_rec);
     }
     ///i have to create function move
     void move(sf::Vector2f speed,float dt){pos+=speed*dt;}
     //set ai for ponk
     ///@param _direction that do it with condition like (boolean_1)? Up:(boolean_2)? Down: Stand
     void ponkAi(sf::RenderWindow &wnd,direction _direction,float dt)
     {
        //set fix pos
        if(pos.y>lengthAndWidth.y&& _direction == Up) move({0,-Speed},dt); 
        else if(pos.y<wnd.getSize().y  && _direction == Down) move({0,Speed},dt);
     }
     //
     sf::Vector2f getPosition(){return pos;}
     //set Ball friendd
     friend class Ball;
};
//constances
namespace constances
{
    sf::Vector2f lengthAndWidth = {30,200};
    float speed = 1000.0f;
} // namespace constances
