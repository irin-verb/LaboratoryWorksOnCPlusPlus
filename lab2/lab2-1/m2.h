#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>   
#include <stdbool.h>

#define N 3 //размерность матриц
#define eps 1e-3 //погрешность при сравнении вещественных чисел

class Matrix3x3
{
private:
	//поля
	float arr[N][N];
	bool id;
	//определение поля id
	bool Ident();
	//вспомогательная функция
	//находит определитель двумерного массива
	float Determ (float A[N][N],int n); 
	
public:
	
	//конструктор
	Matrix3x3 (float Matr[N][N]) ;
	//сложение матриц
	Matrix3x3 Summ (Matrix3x3 A) ;
	//умножение матриц
	Matrix3x3 Mult (Matrix3x3 A);
	//умножение на скаляр
	void Scalar (int n) ;
	//транспонирование
	void Transpos () ;
	//нахождение определителя
	float Det () ;
	//преобразование в обратную
	bool Reverse () ;
	//вывад одной матрицы
	void Out (int n) ;
	//сравнение двух матриц
	bool Compare(float Matr[N][N]);
};
