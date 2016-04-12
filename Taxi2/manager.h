#ifndef MANAGER
#define MANAGER
#include <fstream>
#include <string>
#include "Taxi.h"
#include "city.h"
												//mangaer is the comminication between city and Taxi
using namespace std;
												//runing the comnds shows every change in the map
												//T1 before moving then *T1/*T2 after change
class Manager{

public:
	Manager(int num, char*births[]);		//initials N taxis 
	~Manager();
	void readRunCmnds(char *mystream,char *out);//read and run the commands from simulation
	void printMe(ostream &mystream=cout);					  //print to the required output
	Taxi* getTaxi(int id);									//return Taxi* which match id
	void movePassenger(int x,int y,int id,ostream &out);	//activate a navigation of city ,recursive 
															//search for solution every step East South West Notrh
							//because of the large matrix [10][10], and almost all free it can find solution according
							//to required steps. so to get diffrent Routes we asked for longer/shorter path.
							//this is why you'll see same health in result function of Taxi 1 and Taxi2
							//if you asked 4 more steps youll get diffrent solution. 
							//as required
	private:
		Taxi** taxis;		//hold our Taxis..could be more then 2
		City mycity;		//our Map
		int size;			//Taxi counter
		Taxi* CreateTaxi(istream &input);//allocate Taxi object with the given data 	
		ofstream log;			//log file
};

#endif