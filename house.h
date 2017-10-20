#include <iostream>

using namespace std;

class House
{
public:
	House(int size, char border = 'X', char fill = '*');
	
	int GetSize();
	
	void Grow();
	void Shrink();
	
	void SetBorder(char newBord);
	void SetFill(char newFill);

	void Draw();
	void Summary();

private:
	int sz;
	char borderChar;
	char fillChar;
};
