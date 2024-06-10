#pragma once
#include "m3.h"
#define N 3 //размерность матриц
#define eps 1e-3 //погрешность при сравнении вещественных чисел

class Matrix3x3 : public Object
{
private:
	//поля
	float arr[N][N];
	bool id;
	//определение поля id
	bool Ident();
	//определитель двумерного массива
	float Determ(float(&A)[N][N], int n) const;

public:

	//конструктор копирования
	Matrix3x3(const Matrix3x3& Matr);
	Matrix3x3(float(&Matr)[N][N]);
	~Matrix3x3();
	//статический метод, возвращающий новый объект
	static Matrix3x3 St(int A, int B);

	//сложение матриц
	Matrix3x3 operator+ (Matrix3x3& A);
	//умножение матриц
	Matrix3x3 operator* (Matrix3x3& A);
	//умножение на скаляр
	void operator* (const int& n);
	//транспонирование
	//void operator& ();
	void operator++ ();
	//нахождение определителя
	float Det ();
	//преобразование в обратную
	void operator! ();
	//вывод одной матрицы
	void Out();
	//сравнение двух матриц
	bool Compare(float(&Matr)[N][N]) const;
	//оператор присваивания
	Matrix3x3& operator= (Matrix3x3 Matr);
};
