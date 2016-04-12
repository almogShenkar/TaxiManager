#ifndef LOCATION
#define LOCATION

class Location{

public:
	Location(int X=0,int Y=0,int A=0) :x(X), y(Y), angle(A){};
	~Location(){};
	int getX(){ return x; }
	int getY(){ return y; }
	void setX(int x){ this->x = x;}
	void setY(int y){ this->y = y; }
	int getAngle(){ return angle; }
	void setAngle(int angle){ this->angle += angle; }
private:
	int x;
	int y;
	int angle;
};

#endif