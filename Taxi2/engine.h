#ifndef ENGINE
#define ENGINE
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Engine{

public:
	Engine(string status, int power, double version) :status(status), power(power), version(version){
		cout << "Ctor Engine" << endl;
	};
	~Engine(){ cout << "Dtor Engine" << endl; };
	void setPower(int power);
	int getPower();
	void printMe(ostream &mystream=cout);
	
private:
	string status;
	int power;
	double version;
};

#endif