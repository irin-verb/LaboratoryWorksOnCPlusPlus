#include <iostream> 
#include <strings.h>

//разрешить использовать cout, вместо std::cout
using std::cout;

//но при пересечении имен возникнут проблемы
//void cout()
//{
//}

//подключить всю область видимости
//using namespace std;

int main(int argc, char** argv) 
{
	system("chcp 1251");

	cout << "ѕривет!";
	
	//using нельз€ отменить, действует только в своей области видимости
//	{
//		using namespace myNameSpace;
//	}
	
	return 0;
}

