#ifndef CITY
#define CITY
#include<iostream>
#include <fstream>
#include<string>
using namespace std;

class City{

public:

	void printCity(ostream &mystream=cout);
	City(char*city);
	~City(){};
	void initCity(string **values, int size);
	bool calcRoute(int Tx, int Ty, int Dx, int Dy, char *route, int steps, int i=0);
	void markTaxiLocation(int id, int x, int y){ matrix[x][y] = id == 1 ? "*T1" : "*T2"; }

private:
	string matrix[10][10];
};

#endif