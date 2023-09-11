#include "../headers/point.h"
#include <stdio.h>

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point() {
    this->x = 0;
    this->y = 0;
}

void Point::print(){
    printf("(");
    printf("%i", x);
    printf(",");
    printf("%i", y);
    printf(")");
}