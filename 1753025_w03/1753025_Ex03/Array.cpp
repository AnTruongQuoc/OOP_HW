#include "Array.h"


Array::Array() {
	this->data = NULL;
	size = NULL;
}
Array::Array(const Array& src) {
	if (this == &src)
		return;
	delete[]data;
	size = src.size;
	data = new Triangle[size];
	for (int i = 0; i < size; i++) {
		data[i] = src.data[i];
	}
}

Array::~Array() {
	delete[]data;
}

void Array::input()
{
	ifstream fin;
	fin.open("input.txt", ios_base::in);
	
	Triangle temp;

	double a,b,c;

	if (fin.fail()) {
		cout << "Failed to open this file!" << endl;
		return;
	}


	
	size = fin.tellg();
	data = new Triangle[size];
	while (!fin.eof()) {
		for (int i = 0; i < size; i++) {
			getline(fin, a, ',');
			data[i].setA(a);
			getline(fin, b, ',');
			data[i].setB(b);
			getline(fin, c, '\n');
			data[i].setC(c);
		}
		
	}
	fin.close();
}

void Array::output()
{
	ofstream fout("output.txt");
	fout << size;
	fout << " ";

	for (int i = 0; i < size; i++)
	{
		if (data[i].classify() == 1)
		{
			fout << data[i].getA();
			fout << ";";
			fout << data[i].getB();
			fout << ";";
			fout << data[i].getC();
			fout << "(Right triangles)  ";
		}

		else if (data[i].classify() == 2)
		{
			fout << data[i].getA();
			fout << ";";
			fout << data[i].getB();
			fout << ";";
			fout << data[i].getC();
			fout << "(Equilateral triangles)  ";
		}

		else if (data[i].classify() == 3)
		{
			fout << data[i].getA();
			fout << ";";
			fout << data[i].getB();
			fout << ";";
			fout << data[i].getC();
			fout << "(Right equilateral triangles)  ";
		}

		else if (data[i].classify() == 4)
		{
			fout << data[i].getA();
			fout << ";";
			fout << data[i].getB();
			fout << ";";
			fout << data[i].getC();
			fout << "(Acute triangles)  ";
		}

		else if (data[i].classify() == 5)
		{
			fout << data[i].getA();
			fout << ";";
			fout << data[i].getB();
			fout << ";";
			fout << data[i].getC();
			fout << "(Obtuse triangles)  ";
		}
		else
			fout << "" << endl;
	}
}

