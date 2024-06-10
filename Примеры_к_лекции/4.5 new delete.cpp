#include <iostream> 
#include <strings.h>

using namespace std;

class Dummy
{
	int justNum = 10;
public:
	
	Dummy() { cout << "Dummy()" << endl; }
	~Dummy() { cout << "~Dummy()" << endl; }	
	
	void printHello() { cout << "������!" << endl; }
	void printNum() { cout << justNum << endl; }
};

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	// ��������� ������ ��� ����������

	int* ptr = new int;
	*ptr = 5;
	cout << *ptr << endl << endl;
	
	delete ptr; 
	ptr = nullptr;
	
	// ��������� ������ ��� �������
	
	ptr = new int[10];
	
	for(int i = 0; i < 10; ++i)
		ptr[i] = rand() % 10;
		
	
	for(int i = 0; i < 10; ++i)
		cout << ptr[i] << " ";
	cout << endl << endl;
	
	delete[] ptr;
	ptr = nullptr;
	
	// ��������� ������ ��� ������
	
	//auto objPtr = new Dummy(); // � ������� auto ����� ������� ��� �� ��������� �������������
	Dummy* objPtr = new Dummy(); // ����� ����� �������� ��������� � �����������
	
	objPtr->printHello(); // ����� ��� � � ���������� �� ��������� ������������ -> ��� ������� � �����
	//���������� (*objPtr).sayHello();
	objPtr->printNum();
	
	delete objPtr; 
	objPtr = nullptr;
	
	cout << endl;
	
	// ��� ������������� malloc ��������� ������ ������, 
	// ����������� �� ����������! �� ����� ������������ ��� �������

	objPtr = (Dummy*) malloc(sizeof(Dummy));
	objPtr->printHello(); 
	objPtr->printNum();  // ������������� ���� �� ���������, ����� ������� �����
	free(objPtr); 
	objPtr = NULL;
	
	
	return 0;
}

