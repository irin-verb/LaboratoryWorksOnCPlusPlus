#include <iostream> 
#include <strings.h>

using namespace std;


/*
	Наследование: 	  ->Flyer -> Eagle
					 /		 \
				Animal	      -> Duck
				    \	     /
					 -> Swimmer -> Shark
*/

class Animal
{
protected:
	int lifeAvg;		
public:
	
	virtual void about() = 0;
		
	virtual void eat()
	{
		cout << "Ам-ням! " << endl;
	}
};

class Flyer: public virtual Animal // добавление virtual предотвращает дублирование Animal
{
public:
	
	virtual ~Flyer() {}
		
	void action() { cout << "Я могу летать!" << endl; }
};

class Swimmer: public virtual Animal // добавление virtual предотвращает дублирование Animal
{
public:
	virtual ~Swimmer() {}

	void action() { cout << "Я могу плавать!" << endl; }
};


class Eagle: public Flyer
{
public:
	
	Eagle()
	{
		lifeAvg = 15;
	}
	
	virtual void about() override
	{
		cout << "Я орел:" << endl;
		action();
		eat();
		cout << endl;
	}	
};

class Shark:  public Swimmer
{
public:
	
	Shark()
	{
		lifeAvg = 30;
	}
	
	virtual void about() override
	{
		cout << "Я акула:" << endl;
		action();
		eat();
		cout << endl;
	}		
};

class Duck: public Flyer, public Swimmer
{
public:
	
	Duck()
	{
		lifeAvg = 10; // теперь ошибки нет
	}
	
	virtual void about() override
	{
		cout << "Я утка:" << endl;
		
		//при множественном наследовании при совпадении методов
		//нужно указать явно из какого родительского класса вызывается метод
		Flyer::action(); 
		Swimmer::action();
		
		eat(); // теперь ошибки нет
		
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

	
	return 0;
}

