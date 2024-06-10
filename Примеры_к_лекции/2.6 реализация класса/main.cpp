#include "animal.h"
#include <iostream>

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
