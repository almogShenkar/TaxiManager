#ifndef WHEEL
#define WHEEL
#include <iostream>
#include <fstream>
using namespace std;

class Wheel{

public:
	Wheel(int radius, int thick):radius(radius),thick(thick){
		cout << "Ctor Wheel" << endl;
	};
	~Wheel(){ cout << "Dtor Wheel" << endl; };
	void setRadius(int radius);
	int getRadius();
	void printMe(ostream &mystream=cout);

private:
	int radius;
	int thick;
};

#endif