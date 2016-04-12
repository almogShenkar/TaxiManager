#include "wheels.h"


Wheels::Wheels(int wheel[8]) :fl(wheel[0], wheel[1]), fr(wheel[2], wheel[3]), rr(wheel[4], wheel[5]), rl(wheel[6],wheel[7]){
	cout << "Ctor Wheels" << endl;
};

void  Wheels::setRadius(int radius){
	fr.setRadius(radius);
	fl.setRadius(radius);
};


void Wheels::printMe(ostream &mystream){
	mystream << "front left:";
	fl.printMe(mystream);
	mystream << "front right:";
	fr.printMe(mystream);
	mystream << "rear right:";
	rr.printMe(mystream);
	mystream << "rear left:";
	rl.printMe(mystream);
}

int Wheels::getRadius(){
	return fr.getRadius();
};
