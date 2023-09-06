#include "headers/point.h"
#include "headers/player.h"
#include <stdio.h>

Player::Player(int speed, int width, int height, Point pos) 
{
    
    this->speed = speed;
    this->pos = pos;
    this->width = width;
    this->height = height;
}

Player::Player(int speed, int width, int height)
{   
    this->speed = speed;
    this->pos = Point(0, 0);
    this->width = width;
    this->height = height;
}

Player::Player() 
{
    this->speed = 5;
    this->pos = Point(50, 50);
    this->width = 10;
    this->height = 10;
}

void Player::move(int x, int y) 
{
    pos.x += x;
    pos.y += y;
}