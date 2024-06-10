#include <iostream> 
#include <strings.h>

using namespace std;

/*
	Иерархия: A -> B -> c
*/


class A
{
public:
	virtual const char* getName1(int x) { return "A1"; }
	virtual const char* getName2(int x) { return "A2"; }
};
 
//final может запретить дальнейшее наследование класса
//class B final: public A
class B : public A
{
public:
	const char* getName1(short int x) { return "B1"; }  // тип параметра short int
	const char* getName2(int x) const { return "B2"; }  // метод является константным
	
	//override позволяет избежать ошибок в переопределениях
//	const char* getName1(int x) override { return "B1"; }  
//	const char* getName2(int x) override { return "B2"; }  

	//final не позволит переопределить данные функции в потомках
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
