#include "headers/point.h"
#include "headers/player.h"
#include <stdio.h>

Player::Player(int speed, int width, int height, Point pos, SpriteTexture playerTexture) 
{
    printf("Start here with the parameters of the constructors. Should things like Point pos, and SpriteTexture playerTexture actually be pointers instead? feels like they should be");
    printf("also should probably rewrite sprite functions to use a renderer parameter.");
    this->speed = speed;
    this->pos = pos;
    this->width = width;
    this->height = height;
    this->playerTexture = playerTexture;
}


Player::Player() 
{    
    printf("Player Initialization (bad)\n");
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