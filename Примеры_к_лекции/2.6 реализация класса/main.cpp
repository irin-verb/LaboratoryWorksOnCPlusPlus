#include "animal.h"
#include <iostream>

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
