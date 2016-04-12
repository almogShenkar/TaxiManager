#include "city.h"


void City::initCity(string **values,int size){
	for (int i = 0; i < size; i++)					// C++ array is [size-1]
	{												
		string type = values[i][0];					
		string point = values[i][1];
		int x =point[1] - '0'-1;
		int y = point[0] - 'A';
		matrix[x][y] = type;
	}
	matrix[0][0] = "T1,T2";
}

string** readmyfile(ifstream &mycity,int &size){
	string **values;
	values = new string*[10];
	for (int j = 0; j < 10; j++)
		values[j] = new string[2];
	char line[50];
	int i = 0;
	while (mycity.getline(line,50))
	{
		if (line[0] == '#') continue;
		values[i][0] = strtok(line, ",");
		values[i][1] =strtok(NULL, "endl");
		++i;
	}
	size = i;
	return values;
}
	
 
City::City(char *city){
	ifstream mycity(city);
	if (!city) cout << "Error file" << endl;
	int size = 0;
	string **values = readmyfile(mycity, size);
	initCity(values, size);
	mycity.close();
}

void City::printCity(ostream &mystream){
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{			
					
			if (matrix[i][j] == "P") mystream << "   P    ";
			else{
				if (matrix[i][j] == "C")mystream << "   C    ";
				else
					if (matrix[i][j] == "T1,T2")mystream << " T1,T2  ";
					else
						if (matrix[i][j] == "T1")mystream << "   T1   ";
						else
							if (matrix[i][j] == "T2")mystream << "   T2   ";
							else
								if (matrix[i][j] == "*T2")mystream << "   *T2  ";
									else
										if (matrix[i][j] == "*T1")mystream << "   *T1  ";
											else
											mystream << "   --   ";
				}
			}
			mystream << endl;
	
	}
}









bool City::calcRoute(int Tx, int Ty, int Dx, int Dy, char *route, int steps, int i){

	if (Tx >= 10 || Ty >= 10 || Tx < 0 || Ty < 0 || i>steps) return false;	
	if (matrix[Tx][Ty] == "P" || matrix[Tx][Ty] == "C" || matrix[Tx][Ty] == "*T1" || matrix[Tx][Ty] == "*T2")
		return false;
	if (Tx == Dx && Ty == Dy && matrix[Tx][Ty] != "+") return true;
	matrix[Tx][Ty] = "+";																		
	if (calcRoute(Tx + 1, Ty, Dx, Dy, route, steps, i + 1))	 { route[i] = 'E'; return true; }		
	if (calcRoute(Tx, Ty + 1, Dx, Dy, route, steps, i + 1))	 { route[i] = 'S'; return true; }	
	if (calcRoute(Tx - 1, Ty, Dx, Dy, route, steps, i + 1))	 { route[i] = 'W'; return true; }		
	if (calcRoute(Tx, Ty - 1, Dx, Dy, route, steps, i + 1))	 { route[i] = 'N'; return true; }		
	matrix[Tx][Ty] = "--";
	route[i]= '0';
	return false;																				
}



