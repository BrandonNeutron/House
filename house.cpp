#include <iostream>
#include "house.h"
#include <cmath>
#include <iomanip>
using namespace std;

House::House(int size, char border, char fill)
{
	if (size < 3)
		sz = 3;
	else if (size > 37)
		sz = 37;
	else
		sz = size;

	borderChar = border;
	fillChar = fill;
};

int House::GetSize()
{
	return sz;
};

int House::Perimeter()
{
	return (sz+2)*2 + (sz * 3) + 2;
};

double House::Area()
{
	cout << fixed << showpoint << setprecision(2);
	return ((sqrt(3)/4)*((sz+2)*(sz+2)))+(sz*sz);
};

void House::Grow()
{
	if (sz < 37)
		sz = sz + 1;
}

void House::Shrink()
{
	if (sz > 3)
		sz = sz - 1;
}

void House::SetBorder(char newBord)
{
	if (int(newBord) < 127 && int(newBord) > 32)
		borderChar = newBord;
	else
		borderChar = 'X';
}

void House::SetFill(char newFill)
{
	if (int(newFill) < 127 && int(newFill) > 32)
		fillChar = newFill;
	else
		fillChar = '*';
}

void House::Draw()
{
	for (int i = 0; i < sz + 1; i++)
	{
		cout << string((sz + 2)-(i + 1), ' ');
		cout << borderChar;
		if (i == 1)
			cout << ' ' << borderChar;
		if (i > 1)
		{
			for (int j = 0; j < i-1; j++)
			{
				cout << ' ' << fillChar;
			}
			cout << ' ';
			cout << borderChar;
		}
		cout << endl;
	}
	cout << borderChar << ' ' << borderChar;
	for (int m = 0; m < sz-2; m++)
		cout << ' ' << fillChar;
	cout << ' ' << borderChar << ' ' << borderChar << endl;
	for (int k = 0; k < sz-2; k++)
	{
		cout << "  " << borderChar;
		for (int l = 0; l < sz-2; l++)
			cout << ' ' << fillChar;
		cout << ' ';
		cout << borderChar;
		cout << endl;
	}
	cout << ' ';
	for (int n = 0; n < sz; n++)
		cout << ' ' << borderChar;
	cout << endl;
}

void House::Summary()
{
	cout << "House width and height base to roof = " << GetSize() << " units." << endl;
	cout << "Perimeter of house = " << Perimeter() << " units." << endl;
	cout << "Area of house = " << Area() << " units." << endl;
	cout << "House looks like: " << endl;
	Draw();
}
