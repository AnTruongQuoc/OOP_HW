#pragma once
class Fraction
{
public:
	Fraction();
	void input();
	int& getNum();
	int& getDenom();
	void display();
	bool compare(Fraction p);
	Fraction add(Fraction p);

private:
	int num;
	int denom;
};

