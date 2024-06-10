#include <iostream>
#include "IntegerCalculator.Test.h"


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	//создаём объект юнит-теста и запускаем его
	(IntegerCalculator_Test()).run();
	
	return 0;
}
