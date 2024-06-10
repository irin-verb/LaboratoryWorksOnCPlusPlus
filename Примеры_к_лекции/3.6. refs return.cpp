#include <iostream> 

using namespace std; 

struct Data
{
	int id;
	float value;
};

const Data& getData(int i)
{
	static Data bigData[] = {{5,36.56773f}, {34,46.67574f}, {10,68.345345f}};
	static int bigDataLen = sizeof(bigData) / sizeof(bigData[0]);
	
	return bigData[i < 0? 0 : ( i >= bigDataLen ? bigDataLen - 1 : i )];
}


int main(int argc, char** argv) 
{
	cout << getData(0).id << " " << getData(6).value;
	
	//getData(0).id++; //	[Error] increment of member 'Data::id' in read-only object
	
	return 0;
}
