#include <iostream> 
#include <strings.h>

using namespace std;

/*
	��������: A -> B -> c
*/


class A
{
public:
	virtual const char* getName1(int x) { return "A1"; }
	virtual const char* getName2(int x) { return "A2"; }
};
 
//final ����� ��������� ���������� ������������ ������
//class B final: public A
class B : public A
{
public:
	const char* getName1(short int x) { return "B1"; }  // ��� ��������� short int
	const char* getName2(int x) const { return "B2"; }  // ����� �������� �����������
	
	//override ��������� �������� ������ � ����������������
//	const char* getName1(int x) override { return "B1"; }  
//	const char* getName2(int x) override { return "B2"; }  

	//final �� �������� �������������� ������ ������� � ��������
//	const char* getName1(int x) override final { return "B1"; }  
//	const char* getName2(int x) override final { return "B2"; }  
};

class C : public B
{
public:
	const char* getName1(int x) override { return "C1"; }  
	const char* getName2(int x) override { return "C2"; }
};
 
int main()
{
	B b;
	A &a = b;
	cout << a.getName1(1) << endl;
	cout << a.getName2(2) << endl;
	
	
//	C c;
//	cout << c.getName1(1) << endl;
//	cout << c.getName2(2) << endl;
 
	return 0;
}
