#pragma once
#include "MovingObject.h"
#include <math.h>


MovingObject::MovingObject(double x, double y, double speed, double damage) : x(x), y(y), speed(speed), damage(damage) {};
double MovingObject::distance(double x1, double y1) {
	return sqrt(pow(x - x1, 2) + pow(y - y1, 2));
}
double MovingObject::directionX(double x1) {
	double dirX = x - x1;
	return dirX;
}
double MovingObject::directionY(double y1) {
	double dirY = y - y1;
	return dirY;
}