#ifndef M1_H
#define M1_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>   
#include <stdbool.h>

#define N 3 //����������� ������
#define eps 1e-6 //����������� ��� ��������� ������������ �����

//��������� �������
typedef struct {
	float arr[N][N];
	bool id;
} Matrix3x3; 

//����������� ���� ID (����� ����������� �������)
bool Ident(Matrix3x3 Matr);

//���������� ������� ������
Matrix3x3 Nulls(Matrix3x3 Matr);

//�������� ��������� ������� �� ���������� �������
Matrix3x3 Create (Matrix3x3 New);

//�������� ���� ������
Matrix3x3 Summ (Matrix3x3 A, Matrix3x3 B);

//��������� ���� ������
Matrix3x3 Mult (Matrix3x3 A, Matrix3x3 B);

//��������� ������� �� ������
void Scalar (Matrix3x3* Matr, int n);

//���������������� �������
void Transpos (Matrix3x3* Matr);

//���������� ������������ 
//(������ �������� � ��������, ��� ��������������� ����������� �������)
float Determ (float A[N][N],int n);

//���������� ������������ ������� (������ �� ����������)
float Det (Matrix3x3 Matr);

//�������������� ������� � ��������
bool Reverse (Matrix3x3* Matr);

//����� ����� �������
void Out (Matrix3x3 Matr, int n);

//����� ���� ���� ������
void OutAll(Matrix3x3 A, Matrix3x3 B, Matrix3x3 C);

#endif
