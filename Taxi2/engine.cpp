#include "engine.h"

void Engine::setPower(int power){ this->power = power;}

void Engine::printMe(ostream &mystream)
{
	mystream <<status<< ","<<power << "," << version << " ";
}

int Engine::getPower(){ return power; }