#include <iostream> 
#include <strings.h>
using namespace std;


enum AnimalSize { UNKNOWN, SMALL, MEDIUM, BIG };
const char* animalSizeNames[] = {"неизвестен", "маленький", "средний","большой"};

class Animal
{
private:
	
	//поля лучше скрыть от пользователя класса, давая к ним доступ через геттер-сеттер методы
	char name[256];
	float maxSpeed;
	float curSpeed;
	AnimalSize size;
	bool isPredator;
	bool isHungry;
	
	//метод используется только внутри класса, поэтому его можно сделать private
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

	//конструктор может иметь параметры, которые нужно будет указать при создании экземпляра.
	//если объявлен хоть один конструктор - конструктор по-умолчанию не добавляется!
	Animal(const char* name, float maxSpeed, float w, float h, float l, 
	       bool isPredator = true) // значение по-умолчанию
	       //:maxSpeed(maxSpeed),curSpeed(maxSpeed),isPredator(isPredator) ...
	{
		strcpy(this->name,name); // используем this чтобы обратиться к полю класса
		this->maxSpeed = this->curSpeed = maxSpeed; 
		this->isPredator = isPredator;
		calcSize(w,h,l);
		isHungry = false;
	}
	
	// Сеттер (setter) — метод, используемый для присвоения какого-либо значения инкапсулированному полю. 
	// Позволяет произвести дополнительные проверки либо выполнить другие необходимые операции.
	void setHungry(bool isHungry)
	{
		curSpeed = isHungry? maxSpeed * 0.7f : maxSpeed;
		this->isHungry = isHungry; // используем this чтобы обратиться к полю класса
	}
	
	// Геттер (getter) — специальный метод, позволяющий получить данные, 
	// доступ к которым напрямую ограничен.
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
		cout << "Р-р-р-р!" << endl;
		return this; // возвращаем this, чтобы составлять цепочки вызовов методов
	}
	
	Animal* howl()
	{
		cout << "У-у-у-у!" << endl;
		return this; // возвращаем this, чтобы составлять цепочки вызовов методов
	}
	
	Animal* printAbout()
	{
		cout <<"["<< name << "] скорость:" << curSpeed << " размер:" << animalSizeNames[size] << 
		(isPredator ? " хищник" : " травоядное") << (isHungry ? " (голоден)" : "") << endl;
		
		return this;
	}	
};


int main(int argc, char** argv)  
{
	system("chcp 1251");
	
	// прямая инициализация:
	//Animal myAnimal = Animal("волк",2.7f,35.0f,70.0f,120.0f); // полная форма
	Animal myAnimal("волк",2.7f,35.0f,70.0f,120.0f); // сокращённая форма
	
	//инициализация через копирование
	//Animal myAnimal = {"волк",2.7f,35.0f,70.0f,120.0f};
	
	//uniform - инициализация (C++11):
	//Animal myAnimal {"волк",2.7f,35.0f,70.0f,120.0f}; 
	
	myAnimal.printAbout();
	myAnimal.setHungry(true);
	myAnimal.printAbout()->roar()->howl();
	
	return 0;
}

