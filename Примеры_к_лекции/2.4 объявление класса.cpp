#include <iostream> 
#include <strings.h>
#include <stdlib.h>

using namespace std;


enum AnimalSize { SMALL, MEDIUM, BIG };
const char* animalSizeNames[] = {"маленький", "средний","большой"};

class Animal
{
public:
	
	char name[256];
	float speed;
	AnimalSize size;
	bool isPredator;
	
	//конструктор класса
	Animal() 
	: isPredator(true), speed(1.0f), size(MEDIUM) // можно через список инициализации
	{
		cout<<"ctor Animal"<<endl;
		strcpy(name,"неопределен");
		isPredator = true;
		speed = 1.0f;
		size = MEDIUM;
	}
	
	//деструктор класса
	~Animal()
	{
		cout<<"dtor Animal"<<endl;
	}
	
	//метод расчитывает относительный размер животного
	bool calcSize(float w, float h, float l)
	{
		if(w <= 0.0f || h<=0.0f || l<=0.0f) return false;
		
		float avg = (w + h + l) / 3.0f;
		size = avg > 100.0f ? BIG : (avg > 30.0f ? MEDIUM : SMALL);
		
		return true;
	}
	
	void printAbout()
	{
		cout <<"["<< name << "] скорость:" << speed << " размер:" << animalSizeNames[size] << 
		(isPredator ? " хищник" : " траво€дное") << endl;
	}	
};


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	Animal myAnimal; //создание экземпл€ра класса
	//strcpy(myAnimal.name, "волк");
	//myAnimal.speed = 2.7f;
	//myAnimal.calcSize(35.0f,70.0f,120.0f);
	
	myAnimal.printAbout();
	
	//после завершени€ функции экземпл€р myAnimal будет уничтожен
	
	return 0;
}

