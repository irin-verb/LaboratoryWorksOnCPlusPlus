#include <iostream> 
#include <strings.h>
#include <stdlib.h>

using namespace std;


enum AnimalSize { SMALL, MEDIUM, BIG };
const char* animalSizeNames[] = {"���������", "�������","�������"};

class Animal
{
public:
	
	char name[256];
	float speed;
	AnimalSize size;
	bool isPredator;
	
	//����������� ������
	Animal() 
	: isPredator(true), speed(1.0f), size(MEDIUM) // ����� ����� ������ �������������
	{
		cout<<"ctor Animal"<<endl;
		strcpy(name,"�����������");
		isPredator = true;
		speed = 1.0f;
		size = MEDIUM;
	}
	
	//���������� ������
	~Animal()
	{
		cout<<"dtor Animal"<<endl;
	}
	
	//����� ����������� ������������� ������ ���������
	bool calcSize(float w, float h, float l)
	{
		if(w <= 0.0f || h<=0.0f || l<=0.0f) return false;
		
		float avg = (w + h + l) / 3.0f;
		size = avg > 100.0f ? BIG : (avg > 30.0f ? MEDIUM : SMALL);
		
		return true;
	}
	
	void printAbout()
	{
		cout <<"["<< name << "] ��������:" << speed << " ������:" << animalSizeNames[size] << 
		(isPredator ? " ������" : " ����������") << endl;
	}	
};


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	Animal myAnimal; //�������� ���������� ������
	//strcpy(myAnimal.name, "����");
	//myAnimal.speed = 2.7f;
	//myAnimal.calcSize(35.0f,70.0f,120.0f);
	
	myAnimal.printAbout();
	
	//����� ���������� ������� ��������� myAnimal ����� ���������
	
	return 0;
}

