#ifndef TAXI
#define TAXI
#include <iostream>
#include <string>
#include "engine.h"
#include "wheels.h"
#include "brain.h"
#include "sensors.h"
#include "location.h"


class Taxi{

public:
	Taxi(int id,string Estatus,int Epower,double Eversion,int Wheels[8],double Brain,string *Sensor);
	~Taxi(){ cout << "Dtor Taxi" << endl; };
	Taxi(const Taxi &source);			// copy Ctor
	void printMe(ostream &mystream=cout);
	void goAhead(int km=10);
	void goBack(int km=10);
	void turnRight(int radius=90);	
	void turnLeft(int radius=90);	
	void pickPassenger();
	void dropPassenger();
	int getlocationX(){ return this->mylocation.getX(); }
	int getlocationY(){ return this->mylocation.getY(); }
	int getlocationAngle(){return this->mylocation.getAngle(); }
	void setAngle(int angle){ mylocation.setAngle(angle); }
	void setLocation(int x, int y, int a=0){ mylocation.setX(x); mylocation.setY(y); this->mylocation.setAngle(a); }
	int getID(){ return id; };
	void reduceHealth(){ --health; }
	int getHealth(){ return health; }

private:

	int id;
	int km;
	Engine engine;
	Wheels wheels;
	Brain brain;
	Sensors sensors;
	int passenger;
	int health;
	Location mylocation;
};

#endif