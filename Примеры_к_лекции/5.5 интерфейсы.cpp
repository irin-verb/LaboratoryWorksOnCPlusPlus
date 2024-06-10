#include <iostream> 
#include <strings.h>

using namespace std;

/*
��������� �����, ����� ��� Java � C#, ���� �������� � ���� ��������� 
�������� ����� interface, ������� ��������� ������������� �������� 
���������� ������������ �����, �� �������� ����,  ��� ��� ������ 
�������� ������������.
*/

//������ ��������� ��������� ����������� ��������� ��������
class IGreetinger
{
public:
	
	virtual ~IGreetinger() {}		
	virtual void greeting() const = 0;		
	virtual const char* getName() const = 0;		
};

//������ 1, ��������� ���������, ������� ������ ������� ��� ��� ����������� �������
class Hellower: public IGreetinger
{
public:	
	const char* getName() const { return "Hellower"; }
	void greeting() const override { cout << "Hello!" << endl; };		
};

//������ 2, ��������� ���������, ������� ������ ������� ��� ��� ����������� �������
class Heyer: public IGreetinger
{
public:	
	const char* getName() const { return "Heyer"; }
	void greeting() const override { cout << "Hey!" << endl; };		
};

//������� �������� � �����������, ������� �� �� ����� ����� ����� �������� ����������
void whatAboutThisObject(const IGreetinger& greetinger)
{
	cout << "��� " << greetinger.getName() << " � �� �������: ";
	greetinger.greeting();
	cout << endl;
}

// ����� ����� ��������� ����� ������, � whatAboutThisObject �� ����� ���������� ��� ����
//class Hier: public IGreetinger
//{
//public:	
//	const char* getName() const { return "Hier"; }
//	void greeting() const override { cout << "Hi!" << endl; };		
//};

int main(int argc, char** argv) 
{
	system("chcp 1251");


	IGreetinger* greetinger1 = new Hellower();
	IGreetinger* greetinger2 = new Heyer();
//	IGreetinger* greetinger3 = new Hier();
	
	// ��� �������� ��������� ��� ��������-������ ��� ���� ������������
	whatAboutThisObject(*greetinger1); 
	whatAboutThisObject(*greetinger2);
//	whatAboutThisObject(*greetinger3);

	delete greetinger1;
	delete greetinger2;
	//delete greetinger3;
	
	return 0;
}

