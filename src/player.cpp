#include "headers/point.h"
#include "headers/player.h"
#include <stdio.h>

Player::Player(int speed, int width, int height, Point pos) 
{
    
    this->speed = speed;
    this->pos = pos;
    this->width = width;
    this->height = height;
    this->playerSurface = IMG_Load("res/player.bmp");
}

Player::Player(int speed, int width, int height)
{   
    this->speed = speed;
    this->pos = Point(0, 0);
    this->width = width;
    this->height = height;
    this->playerSurface = IMG_Load("res/player.bmp");
}

Player::Player() 
{
    this->speed = 5;
    this->pos = Point(50, 50);
    this->width = 10;
    this->height = 10;
    this->playerSurface = IMG_Load("res/player.bmp");
}

void Player::move(int x, int y) 
{
    pos.x += x;
    pos.y += y;
}

void Player::close() {
    //this->speed = NULL;
    //this->width = NULL;
    //this->height = NULL;
    //this->playerSurface = NULL;
}