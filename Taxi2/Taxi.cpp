#include "Taxi.h"


Taxi::Taxi(const Taxi &source) :id(source.id), km(source.km), engine(source.engine),
wheels(source.wheels), brain(source.brain), sensors(source.sensors), passenger(source.passenger), health(100),
mylocation(source.mylocation) {
	cout << "Taxi Copy Ctor" << endl;
}

Taxi::Taxi(int id, string Estatus, int Epower, double Eversion, int Wheels[8], double Brain, string *Sensors) :
id(id), km(0), engine(Estatus, Epower, Eversion), wheels(Wheels), brain(Brain), sensors(Sensors), passenger(0), health(100), mylocation()
{
	cout << "Ctor Taxi" << endl;
};




void Taxi::printMe(ostream &mystream){
	mystream <<endl<< "id:" << id << ",km:" << km << ",health: " << health<< ",Engine: ";
	engine.printMe(mystream);
	mystream << endl;
	wheels.printMe(mystream);
	brain.printMe(mystream);
	sensors.printMe(mystream);
};

void Taxi::goAhead(int km){ this->km += km; setAngle(0); }
void Taxi::goBack(int km){ this->km += km; setAngle(180); }
void Taxi::turnRight(int radius){ mylocation.setAngle(radius); }
void Taxi::turnLeft(int radius){ mylocation.setAngle(-radius); }
void Taxi::pickPassenger(){
	++passenger; 
	cout << "================================================================================" << endl;
	cout << passenger << "  is in the taxi right now" << endl<< endl;
	cout << "================================================================================" << endl << endl;
};
void Taxi::dropPassenger(){
	if (passenger)
	--passenger;
	cout << "================================================================================" << endl;
	cout << passenger << "  is in the taxi right now" << endl<< endl;
	cout << "================================================================================" << endl << endl;
};

