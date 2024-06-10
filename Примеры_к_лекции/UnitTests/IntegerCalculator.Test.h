#pragma once

class IntegerCalculator_Test
{
	const int testTotal = 7; // всего тестов
	int testPassed = 0; // сколько тестов пройдено
		
	// доступные тесты:	
		
	bool clear_8set_0Result();
	bool add_5add7_12Result();
	bool sub_10sub6_4Result();
	bool mul_5mul8_40Result();
	bool div_10div2_5Result();
	bool div_10div0_Error();
	bool exprCalc_5add7sub2mul9div2_45Result();
	
	
	//обнуляем счётчик пройденных тестов
	void startTest() { testPassed = 0; }
	//проверяет значение теста
	bool assertValue(int actual, int expected);
	// вывести успех\неудача теста и обновить testPassed
	void updateTestResult(bool passed);	
	 //вывести результаты тестов в консоль
	void printTestResults();
	
public:
	
	//запустить юнит-тестирование класса IntegerCalculator
	void run();		
};
