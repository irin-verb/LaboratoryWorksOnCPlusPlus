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
	bool Expect(int Actual, int Expected);
	//для матриц
	bool ExpectM(Matrix3x3 Actual, float Expected[N][N], int n);
	//вывод сообщения об успехе/неудаче
	void Success(bool n);
	//вывод результатов теста
	void Results();
	
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

public:	
	//запуск Unit-тестирования
	void Run();
};
