#include <iostream> 
#include <strings.h>

using namespace std;

/*
	������������: Flyer -> Eagle
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
	void action() { cout << "� ���� ������!" << endl; }
};

class Swimmer
{
public:
	virtual ~Swimmer() {}
	
	virtual void about() = 0;
	void action() { cout << "� ���� �������!" << endl; }
};


class Eagle: public Flyer
{
public:
	
	void about() override
	{
		cout << "� ���:" << endl;
		action();
		cout << endl;
	}	
};

class Shark:  public Swimmer
{
public:
	
	void about() override
	{
		cout << "� �����:" << endl;
		action();
		cout << endl;
	}		
};

class Duck: public Flyer, public Swimmer
{
public:
	
	void about() override
	{
		cout << "� ����:" << endl;
		
		//��� ������������� ������������ ��� ���������� �������
		//����� ������� ���� �� ������ ������������� ������ ���������� �����
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

