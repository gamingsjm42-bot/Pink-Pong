//include sfml with fix bug
#pragma once
#include "ponk.h"
#include <vector>
#include <iostream>
/// @brief that ball cls

class Ball
{
    private:
    //set Vars of class
    sf::Vector2f position;
    float radius;
    sf::Color color;
    sf::Vector2f speed;
    public:
    //set constractor like ponk
    Ball(sf::Vector2f position,float radius,sf::Color color,sf::Vector2f speed)
    {
        //set vars of class
        this->position = position;
        this->radius = radius;
        this->color = color;
        this->speed = speed;
    }
    //that function move this like position 
    void move(sf::Vector2f position,float dt){this->position+=dt*position;}
    //draw
    void draw(sf::RenderWindow &wnd)
    {
        //set Circle image
        sf::CircleShape s(radius);
        //set color
        s.setFillColor(color);
        //set
        s.setPosition(position);
        //draw on window
        wnd.draw(s);
    }
    /// @brief that function return is move 
    bool isToutch(ponk p)
    {
        return (((p.pos.x<=position.x) && ((position.x)<= (p.pos.x+ p.lengthAndWidth.x)) )&& ((position.y- p.lengthAndWidth.y<=p.pos.y) && (position.y<= p.pos.y)))||
        (((position.x<=p.pos.x) && ((p.pos.x)<= (position.x +radius)) )&& ((position.y-radius<=p.pos.y) && ((p.pos.y)<= (position.y )) ));
        
    }
    //
    sf::Vector2f getPosition(){return position;}
    //
    void ai(sf::RenderWindow &wnd,float dt,std::vector <ponk> ponks)
    {
        //move
        move(speed,dt);
        //set effect
        for (auto ponk = ponks.begin(); ponk != ponks.end(); ponk++) if(isToutch(*ponk)) {speed.x=-speed.x;}
        //set
        if(position.y>=wnd.getSize().y || position.y<=0) speed.y=-speed.y;
    }
};