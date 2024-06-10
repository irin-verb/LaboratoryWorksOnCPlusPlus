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
	
	throw "�������� ������ � func3";
}

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	try
	{
		cout << "������ ����� try" << endl;
		func1();
		cout << "����� ����� try" << endl;
	}
	catch(int err)
	{
		cout << "��������� ������ � ������� "<< err << endl; 
	}
	catch(const char* err)
	{
		cout << "��������� ������: "<< err << endl;
	}
	catch(...) // ... ������������ ��� ����������, ������ ���� ���������
	{
		cout << "��������� ����������� ������" << endl;
	}
	
	cout << "-- ����������� ������ ��������� --" << endl;

	
	return 0;
}

