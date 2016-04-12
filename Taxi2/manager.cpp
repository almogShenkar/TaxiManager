#include "manager.h"

Manager::Manager(int num, char*births[]) :mycity(births[num - 1]), size(0), log("log.txt") {
	taxis = new Taxi*[num-2];
	for (int i = 1; i < num-1; i++)
	{
		ifstream birth(births[i]);
			if (!birth)
			{
				log << "Error files";
				exit(1);
			}
		taxis[i - 1] = CreateTaxi(birth);
		size++;
		birth.close();
	}
}



string* readBirth(istream &Fbirth,int &size){
	int id, km, power, radius1, radius2, radius3, radius4, thick1, thick2, thick3, thick4;
	double Eversion, Bversion;
	string *Values;
	string *ValuesTemp;
	Values = new string[14];
	char*c;
	int j = 0;
	char line[200];
	while (Fbirth.getline(line, 200))
	{
		if (line[0] == '#') continue;
		c = strtok(line, ",");		
		while (c)
		{
			if (j >= 13)					//if there are some sensors dynamiclly allocate each 1 at time
			{
				ValuesTemp = new string[j + 1];
				for (int k = 0; k < j + 1; k++)
				{
					ValuesTemp[k] = new char[sizeof(line)];
					if (k < j)
						ValuesTemp[k]=(Values[k]);
				}
				delete[]Values;
				Values = ValuesTemp;
			}
			Values[j]=c;
			c = strtok(NULL, ",");
			j++;
		}
	}
	size = j;
	return Values;
}

//create taxi will call read and then return the new taxi ptr
Taxi* Manager::CreateTaxi(istream &input){
	int size;
	string *Values = readBirth(input,size);
	int id = stoi(Values[0]);
	int km = 0;
	string Estatus = Values[1];
	int power = stoi(Values[2]);
	double Eversion = stof(Values[3]);
	int wheels[8];
	for (int k = 0; k < 8; k++)
		wheels[k] = stoi(Values[4 + k]);
	double Bversion = stof(Values[12]);
	int i = 0;
	int x = size - 13;
	string *sensors = new string[size - 13];
	while (i <size - 13)
	{
		sensors[i] = Values[i + 13];
		++i;
	}
	Taxi *t= new Taxi(id, Estatus, power, Eversion, wheels, Bversion, sensors);
	return t;

};



Taxi* Manager::getTaxi(int id){
	int i = 0;
	while (taxis[i]->getID() != id)
		++i;
	return taxis[i];
}


void Manager::readRunCmnds(char *simulation,char *results){
	ofstream out(results);
	ifstream mystream(simulation);
	int size;
	string Spoint,Dpoint;
	int cmnd,Dx,Dy,Sx,Sy,id;
	char line[200];
	while (mystream.getline(line, 200))
	{
		if (line[0] == '#') continue;
		cmnd = stoi(strtok(line, ","));
		id = stoi(strtok(NULL, ","));
		Spoint = strtok(NULL, ",");
		Dpoint = strtok(NULL, ",");
		int Dy = Dpoint[1] - '0' - 1;
		int Dx = Dpoint[0] - 'A';
		int Sy = Spoint[1] - '0' - 1;
		int Sx = Spoint[0] - 'A';
		if (!cmnd || !id)
			log << "Error simulation file" << endl;
		out << endl << "N=NORTH W=WEST S=SOUTH E=EAST " << endl;
		out <<endl<< "This is the way to Customer at " << Spoint << endl;
		cout << "================================================================================" << endl << endl;
		mycity.printCity();
		cout << "================================================================================" << endl << endl;
		movePassenger(Sx, Sy,id,out);
		mycity.markTaxiLocation(id,Sy,Sx);
		mycity.printCity();
		cout << "================================================================================" << endl << endl;
		out <<endl<< "This is the way to Customer Destiny " << Dpoint << endl;
		movePassenger(Dx, Dy, id,out);
		mycity.markTaxiLocation(id, Dy, Dx);
		mycity.printCity();
		cout << "================================================================================" << endl << endl;
		getTaxi(id)->printMe(out);
	}
	out.close();
	mystream.close();
}

void Manager::movePassenger(int x, int y, int id, ostream &out){
	cout << endl << "Please Wait! Calculating path" << endl;
	int steps = 10;
	Taxi *Revive;
	Taxi *CurentRide = getTaxi(id);
	char* route = new char[10];
	for (int i = 0; i < 10; i++)
	route[i] = '0';	out << "option1: ";
	if (mycity.calcRoute(CurentRide->getlocationX(), CurentRide->getlocationY() , x, y , route,steps))	{		//make the drive to the customer -update graphic city
		int i = 0;
		while (route[i] != '0'){
			switch (route[i])
			{
			case'N':{CurentRide->goBack(); break; }
			case'S':{CurentRide->goAhead(); break; }
			case'E':{CurentRide->turnRight(); CurentRide->goAhead(); break; }
			case'W':{CurentRide->turnLeft();  CurentRide->goAhead(); break; }
			}
			CurentRide->reduceHealth();
			if (CurentRide->getHealth() <= 0)		//if we should activte copy Ctor
			{
				Revive = new Taxi(*CurentRide);
				CurentRide->~Taxi();
				CurentRide = Revive;
				log << "Taxi id" << id << "is done, copy created" << endl;
				
			}
			out<< route[i];
			++i;
		}
		out << endl;
		for (int i = 0; i < 20; i++)
			route[i] = '0';
		steps = 14;
		i = 0;
		mycity.calcRoute(CurentRide->getlocationX(), CurentRide->getlocationY(), x, y, route, steps);
		out << "option2: ";
		while (route[i] != '0')
			out << route[i++];
		out << endl;
		for (int i = 0; i < 20; i++)
			route[i] = '0';
		steps = 10;
		i = 0;
		mycity.calcRoute(CurentRide->getlocationX(), CurentRide->getlocationY(), x, y, route, steps);
		out << "option3: ";
		while (route[i] != '0')
			out << route[i++];
		out << endl;
		CurentRide->setLocation(x,y);				//if all good move the taxi;

	}
	
	else
		log << "can't find route" << endl;

}


void Manager::printMe(ostream &mystream){
	mycity.printCity(mystream);
};

Manager::~Manager(){
	cout << "Dtor Autotaxi" << endl;
	int i = 0;
	while (i<size)
	{
		taxis[i]->~Taxi();
		++i;
	}
}