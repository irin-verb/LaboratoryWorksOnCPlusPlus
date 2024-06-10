#include <iostream>

namespace newNS1
{
	int func(int i)
	{
		return 2 + i; 
	}
}


namespace newNS2
{
	int func(int i)
	{
		return 2 * i; 
	}
}


int main(int argc, char** argv) 
{
	int rez1 = newNS1::func(10); //12
	int rez2 = newNS2::func(10); //20
	
	std::cout << rez1 << " " << rez2 << std::endl;
	
	return 0;
}
