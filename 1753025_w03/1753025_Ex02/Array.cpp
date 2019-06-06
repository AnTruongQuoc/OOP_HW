#include "Array.h"



Array::Array()
{
	array = NULL;
	length = 0;
}

Array::Array(const Array& src) {
	if (this == &src)
		return;
	delete[]array;
	length = src.length;
	array = new Point[length];
	for (int i = 0; i < length; i++) {
		array[i] = src.array[i];
	}
}

void Array::input(const char *nameFile)
{
	FILE *in = fopen(nameFile, "r");

	if (in == NULL)
	{
		cout << "Error." << endl;
		return;
	}

	fscanf(in, "%d", &length);
	if (length == 0)
	{
		cout << "Error." << endl;
		fclose(in);
		return;
	}

	array = new Point[length];

	for (int i = 0; i < length; i++)
	{
		fscanf(in, "%lf %lf", &array[i].getX(), &array[i].getY());
	}

	fclose(in);
}

void Array::output()
{
	for (int i = 0; i < length; i++)
	{
		array[i].display();
	}
	cout << endl;
}

Point Array::FLD(Point p)
{
	Point max = array[0];
	for (int i = 1; i < length; i++)
	{
		if (p.distance(max) < p.distance(array[i]))
		{
			max = array[i];
		}
	}
	return max;
}

Array::~Array()
{
	delete[]array;
}
