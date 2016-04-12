#ifndef BRAIN
#define BRAIN
#include <fstream>
#include <iostream>
using namespace std;

class Brain{

public:
	
	~Brain(){cout << "Dtor Brain" << endl;	};
	Brain(double nVersion) :version(nVersion){ cout << "Ctor Brain" << endl; };
	void setVersion(double nVersion);
	double getVersion();
	void printMe(ostream &mystream);
	//set's not needed for now
	//get's not needed for now
private:
	double version;
};


#endif