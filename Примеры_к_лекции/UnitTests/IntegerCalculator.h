#pragma once


/*
	Класс IntegerCalculator - простая реализация целочисленного калькулятора.
	Позволяет складывать, вычитать, умножать и делить целые числа (с сохранением результата вычислений). 
*/

class IntegerCalculator
{
	int value = 0; //текущее значение калькулятора
	bool hasErrors = false; //флаг, показывающий были ли ошибки после предыдущей операции
public:
	
	IntegerCalculator(int value = 0) // value - можно задать начальное значение калькулятора
	{
		this->value = value;
	}
	
	//очистить значение калькулятора (перед каждой новой операцией флаг ошибки сбрасывается)
	void clear() { resetError(); setValue(0); }

	//Установить текущее значение калькулятора
	void setValue(int value) { this->value = value; }
	//получить текущее значение калькулятора
	int getValue() { return value; }
	
	//получить флаг ошибки последней операции
	bool getLastError() { return hasErrors;	}
	//сбросить флаг ошибки
	void resetError() { hasErrors = false;	}
	
	//реализация операции сложение. Возвращается сам объект калькулятора для
	//использования цепочки методов
	IntegerCalculator* add(int num);
	
	//реализация операции вычитание
	IntegerCalculator* sub(int num);
	
	//реализация операции умножение
	IntegerCalculator* mul(int num);
	
	//реализация операции деление (может изменить флаг ошибки!)
	IntegerCalculator* div(int num);

};
