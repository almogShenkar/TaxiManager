#include "manager.h"
#include <exception>


int main(int argc,char *argv[]){
	try {
		Manager T(argc, argv);
		T.readRunCmnds("simulation.txt", "results.txt");			//this is why  T.readRunCmnds(simulation,output) can work
		cout << "OK, everything finish, please check results.txt and log.txt" << endl << endl;
		cout << "Notice that the Taxi 1 and Taxi 2 show same km and health," <<
			"just because we asked for the same ""size"" of path" << endl << endl;
	}
	catch (exception e) {
		system("pause");
	}

}

