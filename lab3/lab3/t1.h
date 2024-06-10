#pragma once
#include "m2.h"

//класс теста:
class Test
{
	int Pass; //количество пройденных тестов
	int Numb; //общее количество тестов

	//обнуление счетчиков
	void Start();
	//сравнение результатов
	//для величин
	bool Expect(float& Actual, const float& Expected);
	bool Expect(int& Actual, const int& Expected);
	//для матриц/массивов
	bool ExpectM(Matrix3x3& Actual, int (&Expected)[N]);
	bool ExpectM(Matrix3x3& Actual, float(&Expected)[N][N]);
	//вывод сообщения об успехе/неудаче
	void Success(bool n);
	//вывод результатов теста
	void Results();
	//вывод заголовка теста
	void Head();

	//возможные тесты:
	bool TSumm();
	bool TMult();
	bool TSclr();
	bool TTransp();
	bool TDet();
	bool TRev();
	bool TMath();
	bool TDetNull();
	bool TSummTranspSclr();
	bool TRevNever();

	//НОВЫЕ ТЕСТЫ:
	bool CountOfAll();
	
	bool CountOfAct();
	void CountOfAct1(); //вспомогательная функция к CountOfAct()
	void CountOfAct2(); //вспомогательная функция к CountOfAct()
	
	bool TrueCopy();
	
	bool TrueOperations1();
	bool TrueOperations2();

public:
	//запуск Unit-тестирования
	void Run();
};
