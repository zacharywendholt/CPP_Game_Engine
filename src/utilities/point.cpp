#include "../headers/point.h"
#include <stdio.h>

Point::Point(double x, double y) {
    x = x;
    y = y;
}

Point::Point() {
    x = 0;
    y = 0;
}

void Point::print(){
    printf("(");
    printf("%i", x, "test");
    printf(",");
    printf("%i", y);
    printf(")");
}