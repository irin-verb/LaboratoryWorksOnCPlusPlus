#include <iostream> 
#include <strings.h>

using namespace std;

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	// в С-стиле
	int i1 = 11;
	int i2 = 3;
	float x = (float)i1 / i2;
	cout << x << endl;

	// в С++
	x = float(i1) / i2; // прямая инициализация через ()
	cout << x << endl;
	
	//static_cast
	x = static_cast<float>(i1) / i2; 
	cout << x << endl;
	
	// в отличии от С-стиля, static_cast более безопасен и
	// не позволяет приводить несовместимые типы (проверяется на этапе компиляции) 
	int* i1Ptr = &i1;
	char* p1 = (char*) i1Ptr; //можно сделать
	//char* p2 = static_cast<char*>(i1Ptr); //[Error] invalid static_cast from type 'int*' to type 'char*'
	
	const int u = 5;
	int* y1 = (int*)&u; //можно сделать
	//int* y2 = static_cast<int*>(&u); // [Error] invalid static_cast from type 'const int*' to type 'int*'
	
	return 0;
}

