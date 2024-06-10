#include <iostream> 
#include <strings.h>

using namespace std;


/*
	��������: A -> B -> c
*/

// ������� �����
class A
{
public:
	
	A() { cout << "ctor A();" << endl; }
	
	//� ������ ������ ���������� ����������� ������ ���� �����������!
	//~A() { cout << "dtor A();" << endl; }
	virtual ~A() { cout << "dtor A();" << endl; }
	
	virtual void greeting() { cout << "Hello!" << endl; }	
};

// ������� 1
class B : public A
{
public:
	
	B() { cout << "ctor B();" << endl; }
	~B() { cout << "dtor B();" << endl; }
	void greeting() { cout << "Hi!" << endl; }	
};

// ������� 2
class C : public B
{
public:
	
	C() { cout << "ctor C();" << endl; }
	~C() { cout << "dtor C();" << endl; }
	void greeting() { cout << "Heya!" << endl; }	
};

int main(int argc, char** argv) 
{
	system("chcp 1251");

	//� ��������� � ����������� ������� �� ������
	C* c = new C();
	c->greeting();
	delete c;
	
	cout << endl;
	
	//�� ��� ����� ���� �� ����� ������������ ����� �������� ��� ���������� �������?
	//����� �������� ������ ����� ��������! ������� ���������� ����� ������ ���� ��������� ���
	//����������� �������
	A* a = new C();
	a->greeting();
	delete a;
	
	return 0;
}

