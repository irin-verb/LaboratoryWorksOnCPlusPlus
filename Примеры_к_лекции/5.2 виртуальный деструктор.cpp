#include <iostream> 
#include <strings.h>

using namespace std;


/*
	Иерархия: A -> B -> c
*/

// базовый класс
class A
{
public:
	
	A() { cout << "ctor A();" << endl; }
	
	//В данном случае деструктор обязательно должен быть виртуальным!
	//~A() { cout << "dtor A();" << endl; }
	virtual ~A() { cout << "dtor A();" << endl; }
	
	virtual void greeting() { cout << "Hello!" << endl; }	
};

// потомок 1
class B : public A
{
public:
	
	B() { cout << "ctor B();" << endl; }
	~B() { cout << "dtor B();" << endl; }
	void greeting() { cout << "Hi!" << endl; }	
};

// потомок 2
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

	//с созданием и разрушением потомка всё хорошо
	C* c = new C();
	c->greeting();
	delete c;
	
	cout << endl;
	
	//но что будет если мы будем использовать класс родитель для разрушения потомка?
	//будет разрушен только класс родителя! Поэтому деструктор также должен быть виртуален для
	//полиморфных классов
	A* a = new C();
	a->greeting();
	delete a;
	
	return 0;
}

