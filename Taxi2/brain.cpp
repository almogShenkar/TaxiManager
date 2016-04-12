#include "brain.h"

double Brain::getVersion(){ return version; }

void Brain::setVersion(double nVersion){ version = nVersion; }




void Brain::printMe(ostream &mystream){
	mystream << "Brain: " << version<<endl;
}
