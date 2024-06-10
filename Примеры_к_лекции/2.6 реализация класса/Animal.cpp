
#include "animal.h" //как и в случае с модулями, файл реализации всегда должен включать свой файл заголовка
#include <strings.h>
#include <iostream> 


using namespace std;

static const char* animalSizeNames[] = {"неизвестен", "маленький", "средний","большой"};

Animal::Animal(const char* name, float maxSpeed, float w, float h, float l, 
       			bool isPredator)
{
	strcpy(this->name,name);
	this->maxSpeed = this->curSpeed = maxSpeed; 
	this->isPredator = isPredator;
	calcSize(w,h,l);
	isHungry = false;
}
	
void Animal::calcSize(float w, float h, float l)
{
	if(w <= 0.0f || h<=0.0f || l<=0.0f) 
	{
		size = UNKNOWN;
		return;
	}
	
	float avg = (w + h + l) / 3.0f;
	size = avg > 100.0f ? BIG : (avg > 30.0f ? MEDIUM : SMALL);
}
	
Animal* Animal::roar()
{
	cout << "Р-р-р-р!" << endl;
	return this; // возвращаем this, чтобы составлять цепочки вызовов методов
}

Animal* Animal::howl()
{
	cout << "У-у-у-у!" << endl;
	return this; // возвращаем this, чтобы составлять цепочки вызовов методов
}
	
Animal* Animal::printAbout()
{
	cout <<"["<< name << "] скорость:" << curSpeed << " размер:" << animalSizeNames[size] << 
	(isPredator ? " хищник" : " травоядное") << (isHungry ? " (голоден)" : "") << endl;
	
	return this;
}
