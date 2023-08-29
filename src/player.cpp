#include "headers/point.h"
#include "headers/player.h"

int defaultSpeed = 0;

Player::Player(int speed, Point pos) 
{
    speed = speed;
    pos = pos;
}

Player::Player(int speed)
{
    speed = speed;
    pos = Point(0, 0);
}

Player::Player() 
{
    speed = 0;
    pos = Point(0, 0);
}



