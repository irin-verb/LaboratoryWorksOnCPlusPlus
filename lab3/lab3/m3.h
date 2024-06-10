#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>   
#include <stdbool.h>
#include <time.h>
#define N 3 

class Object {

private:
	static int All; //кол-во созданных объектов
	static int Act; //кол-во активных объектов
	int* Op; //указатель для выделения памяти под массив
	int Ops; //счетчик числа операций в массиве

public:
	//обнуление статических полей класса
	static void RestartObjInfo();

	Object();
	//конструктор копирования
	Object(const Object& Obj);
	~Object();

	//вывод All и Act
	static void PrintTotalInfo();
	//геттеры All и Act
	static int GetAll() { return All; };
	static int GetAct() { return Act; };

	//добавление операции в массив операций
	void AddOp(int k);
	//вывод истории операций
	void PrintOp();
	//очищение истории операций
	void ClearOp();

	//оператор присваивания
	Object& operator= (Object& Matr);
	
	//сравнение списка операций
	bool Comp(int (&Spis)[N]);
};
