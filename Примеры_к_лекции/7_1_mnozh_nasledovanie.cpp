#include <iostream> 
#include <strings.h>

using namespace std;

/*
	Наследование: Flyer -> Eagle
					\
					 -> Duck
					/
				  Swimmer -> Shark
*/


class Flyer
{
public:
	
	virtual ~Flyer() {}
		
	virtual void about() = 0;
	void action() { cout << "Я могу летать!" << endl; }
};

class Swimmer
{
public:
	virtual ~Swimmer() {}
	
	virtual void about() = 0;
	void action() { cout << "Я могу плавать!" << endl; }
};


class Eagle: public Flyer
{
public:
	
	void about() override
	{
		cout << "Я орёл:" << endl;
		action();
		cout << endl;
	}	
};

class Shark:  public Swimmer
{
public:
	
	void about() override
	{
		cout << "Я акула:" << endl;
		action();
		cout << endl;
	}		
};

class Duck: public Flyer, public Swimmer
{
public:
	
	void about() override
	{
		cout << "Я утка:" << endl;
		
		//при множественном наследовании при совпадении методов
		//нужно указать явно из какого родительского класса вызывается метод
		Flyer::action(); 
		Swimmer::action();
		
		cout << endl;
	}
};

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	Eagle eagle;
	eagle.about();
	
	Shark shark;
	shark.about();
	
	Duck duck;
	duck.about();
	//duck.action(); // [Error] request for member 'action' is ambiguous
	
	return 0;
}

