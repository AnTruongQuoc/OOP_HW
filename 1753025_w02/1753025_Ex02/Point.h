#pragma once
class Point
{
public:
	Point();
	void input();
	void display();
	double& getX();
	double& getY();
	double distance(Point p);
private:
	double x;
	double y;
};

