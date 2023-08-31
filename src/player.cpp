#include "headers/point.h"
#include "headers/player.h"

int defaultSpeed = 0;

Player::Player(int speed, int width, int height, Point pos) 
{
    speed = speed;
    pos = pos;

    width = width;
    height = height;
}

Player::Player(int speed, int width, int height)
{
    speed = speed;
    pos = Point(0, 0);
    width = width;
    height = height;
}

Player::Player() 
{
    speed = 0;
    pos = Point(0, 0);
    width = 0;
    height = 0;
}

void Player::move(int x, int y)
{
    pos.x = pos.x + x;
    pos.y = pos.y + y;
}



