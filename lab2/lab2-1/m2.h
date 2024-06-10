#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>   
#include <stdbool.h>

#define N 3 //����������� ������
#define eps 1e-3 //����������� ��� ��������� ������������ �����

class Matrix3x3
{
private:
	//����
	float arr[N][N];
	bool id;
	//����������� ���� id
	bool Ident();
	//��������������� �������
	//������� ������������ ���������� �������
	float Determ (float A[N][N],int n); 
	
public:
	
	//�����������
	Matrix3x3 (float Matr[N][N]) ;
	//�������� ������
	Matrix3x3 Summ (Matrix3x3 A) ;
	//��������� ������
	Matrix3x3 Mult (Matrix3x3 A);
	//��������� �� ������
	void Scalar (int n) ;
	//����������������
	void Transpos () ;
	//���������� ������������
	float Det () ;
	//�������������� � ��������
	bool Reverse () ;
	//����� ����� �������
	void Out (int n) ;
	//��������� ���� ������
	bool Compare(float Matr[N][N]);
};
