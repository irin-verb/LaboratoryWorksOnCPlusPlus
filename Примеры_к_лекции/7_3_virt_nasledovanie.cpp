#include <iostream> 
#include <strings.h>

using namespace std;


/*
	������������: 	  ->Flyer -> Eagle
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
		cout << "��-���! " << endl;
	}
};

class Flyer: public virtual Animal // ���������� virtual ������������� ������������ Animal
{
public:
	
	virtual ~Flyer() {}
		
	void action() { cout << "� ���� ������!" << endl; }
};

class Swimmer: public virtual Animal // ���������� virtual ������������� ������������ Animal
{
public:
	virtual ~Swimmer() {}

	void action() { cout << "� ���� �������!" << endl; }
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
		cout << "� ����:" << endl;
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
		cout << "� �����:" << endl;
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
		lifeAvg = 10; // ������ ������ ���
	}
	
	virtual void about() override
	{
		cout << "� ����:" << endl;
		
		//��� ������������� ������������ ��� ���������� �������
		//����� ������� ���� �� ������ ������������� ������ ���������� �����
		Flyer::action(); 
		Swimmer::action();
		
		eat(); // ������ ������ ���
		
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

