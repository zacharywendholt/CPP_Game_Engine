#include "headers/point.h"
#include "headers/player.h"
#include <stdio.h>

Player::Player(int speed, int width, int height, Point pos, SpriteTexture playerTexture) 
{
    this->speed = speed;
    this->pos = pos;
    this->width = width;
    this->height = height;
    this->playerTexture = playerTexture;
}


Player::Player() 
{    
    // make sure that the player width and height match up with the other stuff
    
    this->speed = 5;
    this->pos = Point(50, 50);
    this->width = 10;
    this->height = 10;
}

void Player::animationUpdate() 
{
    this->playerTexture.render(this->pos.x, this->pos.y);
}

void Player::move(int x, int y) 
{
    pos.x += x;
    pos.y += y;
}

void Player::close() {
    this->playerSurface = NULL;
}