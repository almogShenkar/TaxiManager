#include "sensors.h"


Sensors::Sensors(string *sensors){
	cout << "Ctor Sensors" << endl;
	sensorsArray = new string[sizeof(sensors)-1];
	int i = sizeof(sensors) - 1;
	int k = 0;
	size = i;
	while (k<i)
	{
		sensorsArray[k]=sensors[k];
		++k;
	}
}


void Sensors::printMe(ostream &mystream){
	int i = 0;
	while (i < (sizeof(sensorsArray)-1))
	{
		mystream << sensorsArray[i] << ',';
		++i;
	}
	mystream << endl;
}


Sensors::~Sensors()
{	
	cout << "Dtor sensors" << endl;
}

