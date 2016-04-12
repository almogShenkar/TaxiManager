#include "wheel.h"

void  Wheel::setRadius(int radius){
	this->radius = radius;
};

int Wheel::getRadius(){
	return radius;
};

void Wheel::printMe(ostream &mystream){
	mystream << '(' << radius << "," << thick << ')' << endl;
}

