#include "IntegerCalculator.Test.h"
#include "IntegerCalculator.h"
#include <iostream>
		
using namespace std;		
		
bool IntegerCalculator_Test::assertValue(int actual, int expected)
{
	cout << "Ожидаемый результат: " << expected << endl;
	cout << "Фактический результат: " << actual << endl;
	return actual == expected;
}		
		
		
bool IntegerCalculator_Test::clear_8set_0Result()
{
	cout << "Тестируем clear(): должен сбросить значение 8 на 0" << endl;
	
	//arrange
	IntegerCalculator calc(8);
	
	//act
	calc.clear();
	
	//assert
	return assertValue(calc.getValue(),0);
}
	
bool IntegerCalculator_Test::add_5add7_12Result()
{
	cout << "Тестируем add(): 5 + 7" << endl;
	
	//arrange
	IntegerCalculator calc(5);
	
	//act
	calc.add(7);
	
	//assert
	return assertValue(calc.getValue(),12);
}

bool IntegerCalculator_Test::sub_10sub6_4Result()
{
	cout << "Тестируем sub(): 10 - 6" << endl;
	
	//arrange
	IntegerCalculator calc(10);
	
	//act
	calc.sub(6);
	
	//assert
	return assertValue(calc.getValue(),4);
}

bool IntegerCalculator_Test::mul_5mul8_40Result()
{
	cout << "Тестируем mul(): 5 * 8" << endl;
	
	//arrange
	IntegerCalculator calc(5);
	
	//act
	calc.mul(8);
	
	//assert
	return assertValue(calc.getValue(),40);
}

bool IntegerCalculator_Test::div_10div2_5Result()
{
	cout << "Тестируем div(): 10 / 2" << endl;
	
	//arrange
	IntegerCalculator calc(10);
	
	//act
	calc.div(2);
	
	//assert
	return assertValue(calc.getValue(),5);
}

bool IntegerCalculator_Test::div_10div0_Error()
{
	cout << "Тестируем div(): 10 / 0 => Error (1)" << endl;
	
	//arrange
	IntegerCalculator calc(10);
	
	//act
	calc.div(0);
	
	//assert
	return assertValue(calc.getLastError(),true);
}

bool IntegerCalculator_Test::exprCalc_5add7sub2mul9div2_45Result()
{
	cout << "Тестируем расчёт выражения: (5 + 7 - 2) * 9 / 2" << endl;
	
	//arrange
	IntegerCalculator calc;
	
	//act
	calc.setValue(5);
	calc.add(7)->sub(2)->mul(9)->div(2);
	
	//assert
	return assertValue(calc.getValue(),45);
}

void IntegerCalculator_Test::updateTestResult(bool passed)
{
	if(passed) 
		++testPassed, cout << "Успех!" << endl; 
	else 
		cout << "Неудача!" << endl;
}

void IntegerCalculator_Test::printTestResults()
{
	cout << "[Результаты тестирования IntegerCalculator] Тестов пройдено: " << testPassed << " из " << testTotal << endl;
}


void IntegerCalculator_Test::run()
{
	startTest();
	
	updateTestResult(clear_8set_0Result());
	updateTestResult(add_5add7_12Result());
	updateTestResult(sub_10sub6_4Result());
	updateTestResult(mul_5mul8_40Result());
	updateTestResult(div_10div2_5Result());
	updateTestResult(div_10div0_Error());
	updateTestResult(exprCalc_5add7sub2mul9div2_45Result());
	
	printTestResults();
}		

