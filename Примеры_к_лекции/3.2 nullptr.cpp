#include <iostream> 
#include <strings.h>
using namespace std;

int doCalc(const int* i)
{
	if(!i) return 0;
	
	return *i * 2;
}

int doCalc(int i) 
{
	return i + 10;
}


int main(int argc, char** argv) 
{
	system("chcp 1251");

	
	//cout<< doCalc(NULL) << endl; // [Error] call of overloaded 'doCalc(NULL)' is ambiguous
	cout<< doCalc(nullptr) << endl; 
	cout<< doCalc(5) << endl; 
	
	return 0;
}

