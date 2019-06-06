#include "Array.h"
#include <iostream>
using namespace std;

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
	array = new Student[length];
	for (int i = 0; i < length; i++) {
		array[i] = src.array[i];
	}
}
void Array::input(const char* nameFile)
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
	array = new Student[length];
	char temp[223];
	for (int i = 0; i < length; i++)
	{
		fscanf(in, "%*c");

		fgets(temp, 223, in);
		array[i].getID() = _strdup(temp);
		array[i].getID()[strlen(array[i].getID()) - 1] = '\0';

		fgets(temp, 223, in);
		array[i].getFullName() = _strdup(temp);
		array[i].getFullName()[strlen(array[i].getFullName()) - 1] = '\0';

		fgets(temp, 223, in);
		array[i].getAddress() = _strdup(temp);
		array[i].getAddress()[strlen(array[i].getAddress()) - 1] = '\0';

		fscanf(in, "%d %d %d", &array[i].dateOfB(), &array[i].monthOfB(), &array[i].yearOfB());

		fscanf(in, "%lf", &array[i].getMark());
	}
	fclose(in);
}
void Array::sortName()
{
	for (int i = 0; i < length - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j < length; j++)
		{
			if (strcmp(array[index].getLastName(), array[j].getLastName()) == 1)
			{
				index = j;
			}
		}
		if (index != i)
		{
			swapStudent(array[index], array[i]);
		}
	}
}

void Array::swapStudent(Student &b, Student &y)
{
	char *temp = _strdup(b.getAddress());
	b.getAddress() = _strdup(y.getAddress());
	y.getAddress() = _strdup(temp);

	temp = _strdup(b.getFullName());
	b.getFullName() = _strdup(y.getFullName());
	y.getFullName() = _strdup(temp);

	temp = _strdup(b.getID());
	b.getID() = _strdup(y.getID());
	y.getID() = _strdup(temp);

	int DOB = b.dateOfB();
	b.dateOfB() = y.dateOfB();
	y.dateOfB() = DOB;

	DOB = b.monthOfB();
	b.monthOfB() = y.monthOfB();
	y.monthOfB() = DOB;

	DOB = b.yearOfB();
	b.yearOfB() = y.yearOfB();
	y.yearOfB() = DOB;

	double mark = b.getMark();
	b.getMark() = y.getMark();
	y.getMark() = mark;

	delete[]temp;
}
void Array::output()
{
	for (int i = 0; i < length; i++)
	{
		array[i].output();
	}
}
void Array::output(const char* nameFile)
{
	FILE *out = fopen(nameFile, "w");
	if (out == NULL)
	{
		cout << "Error." << endl;
		return;
	}
	fprintf(out, "<List of Students>\n");
	for (int i = 0; i < length; i++)
	{
		fprintf(out, "<Student>\n");
		fprintf(out, "<Name>");
		fprintf(out, "%s", array[i].getFullName());
		fprintf(out, "</Name>\n");
		fprintf(out, "<ID>");
		fprintf(out, "%s", array[i].getID());
		fprintf(out, "</ID>\n");
		fprintf(out, "<Address>");
		fprintf(out, "%s", array[i].getAddress());
		fprintf(out, "</Address>\n");
		fprintf(out, "<DOB>");
		fprintf(out, "%d %d %d", array[i].dateOfB(), array[i].monthOfB(), array[i].yearOfB());
		fprintf(out, "</DOB>\n");
		fprintf(out, "<Mark>");
		fprintf(out, "%lf", array[i].getMark());
		fprintf(out, "</Mark>\n");
		fprintf(out, "</Student>\n");
	}
	fprintf(out, "</List of Students>");
	fclose(out);
}
Array::~Array()
{
	delete[]array;
}