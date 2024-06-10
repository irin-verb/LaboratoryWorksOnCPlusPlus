#include <iostream> 
#include <strings.h>

using namespace std;


void func2();
void func3();

void func1()
{
	cout << "func1()" << endl;
	
	func2();
}

void func2()
{
	cout << "func2()" << endl;
	
	//throw 1003;
	
	func3();
}

void func3()
{
	cout << "func3()" << endl;
	
	throw "описание ошибки в func3";
}

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	try
	{
		cout << "начало блока try" << endl;
		func1();
		cout << "конец блока try" << endl;
	}
	catch(int err)
	{
		cout << "Произошла ошибка с номером "<< err << endl; 
	}
	catch(const char* err)
	{
		cout << "Произошла ошибка: "<< err << endl;
	}
	catch(...) // ... обрабатывает все исключения, должен быть последним
	{
		cout << "Произошла неизвестная ошибка" << endl;
	}
	
	cout << "-- продолжение работы программы --" << endl;

	
	return 0;
}

