#include <iostream> 

using namespace std; 

void makeSquare(int& i)
{
	i *= i;
}

void printIt(const int& i)
{
	//i = 5; //[Error] assignment of read-only reference 'i'
	cout << i;
}

int main(int argc, char** argv) 
{
	int i = 5;
	
	makeSquare(i);
	printIt(i); //25
	return 0;
}
