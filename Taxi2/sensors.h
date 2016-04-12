#ifndef SENSORS
#define SENSORS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sensors{

public:
	Sensors(string *sensors);
	~Sensors();
    void printMe(ostream &mystream=cout);
	//set's not needed for now
	//get's not needed for now

private:
	string *sensorsArray;
	int size;
};

#endif