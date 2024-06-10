#include <iostream> 
#include <strings.h>
using namespace std;


enum AnimalSize { UNKNOWN, SMALL, MEDIUM, BIG };
const char* animalSizeNames[] = {"����������", "���������", "�������","�������"};

class Animal
{
private:
	
	//���� ����� ������ �� ������������ ������, ����� � ��� ������ ����� ������-������ ������
	char name[256];
	float maxSpeed;
	float curSpeed;
	AnimalSize size;
	bool isPredator;
	bool isHungry;
	
	//����� ������������ ������ ������ ������, ������� ��� ����� ������� private
	void calcSize(float w, float h, float l)
	{
		if(w <= 0.0f || h<=0.0f || l<=0.0f) 
		{
			size = UNKNOWN;
			return;
		}
		
		float avg = (w + h + l) / 3.0f;
		size = avg > 100.0f ? BIG : (avg > 30.0f ? MEDIUM : SMALL);
	}
		
public:

	//����������� ����� ����� ���������, ������� ����� ����� ������� ��� �������� ����������.
	//���� �������� ���� ���� ����������� - ����������� ��-��������� �� �����������!
	Animal(const char* name, float maxSpeed, float w, float h, float l, 
	       bool isPredator = true) // �������� ��-���������
	       //:maxSpeed(maxSpeed),curSpeed(maxSpeed),isPredator(isPredator) ...
	{
		strcpy(this->name,name); // ���������� this ����� ���������� � ���� ������
		this->maxSpeed = this->curSpeed = maxSpeed; 
		this->isPredator = isPredator;
		calcSize(w,h,l);
		isHungry = false;
	}
	
	// ������ (setter) � �����, ������������ ��� ���������� ������-���� �������� ������������������ ����. 
	// ��������� ���������� �������������� �������� ���� ��������� ������ ����������� ��������.
	void setHungry(bool isHungry)
	{
		curSpeed = isHungry? maxSpeed * 0.7f : maxSpeed;
		this->isHungry = isHungry; // ���������� this ����� ���������� � ���� ������
	}
	
	// ������ (getter) � ����������� �����, ����������� �������� ������, 
	// ������ � ������� �������� ���������.
	bool getHungry()
	{
		return isHungry;
	}
	
	float getCurSpeed()
	{
		return curSpeed;
	}
	
	Animal* roar()
	{
		cout << "�-�-�-�!" << endl;
		return this; // ���������� this, ����� ���������� ������� ������� �������
	}
	
	Animal* howl()
	{
		cout << "�-�-�-�!" << endl;
		return this; // ���������� this, ����� ���������� ������� ������� �������
	}
	
	Animal* printAbout()
	{
		cout <<"["<< name << "] ��������:" << curSpeed << " ������:" << animalSizeNames[size] << 
		(isPredator ? " ������" : " ����������") << (isHungry ? " (�������)" : "") << endl;
		
		return this;
	}	
};


int main(int argc, char** argv)  
{
	system("chcp 1251");
	
	// ������ �������������:
	//Animal myAnimal = Animal("����",2.7f,35.0f,70.0f,120.0f); // ������ �����
	Animal myAnimal("����",2.7f,35.0f,70.0f,120.0f); // ����������� �����
	
	//������������� ����� �����������
	//Animal myAnimal = {"����",2.7f,35.0f,70.0f,120.0f};
	
	//uniform - ������������� (C++11):
	//Animal myAnimal {"����",2.7f,35.0f,70.0f,120.0f}; 
	
	myAnimal.printAbout();
	myAnimal.setHungry(true);
	myAnimal.printAbout()->roar()->howl();
	
	return 0;
}

