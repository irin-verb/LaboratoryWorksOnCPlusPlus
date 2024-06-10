#pragma once
#include "m3.h"
#define N 3 //����������� ������
#define eps 1e-3 //����������� ��� ��������� ������������ �����

class Matrix3x3 : public Object
{
private:
	//����
	float arr[N][N];
	bool id;
	//����������� ���� id
	bool Ident();
	//������������ ���������� �������
	float Determ(float(&A)[N][N], int n) const;

public:

	//����������� �����������
	Matrix3x3(const Matrix3x3& Matr);
	Matrix3x3(float(&Matr)[N][N]);
	~Matrix3x3();
	//����������� �����, ������������ ����� ������
	static Matrix3x3 St(int A, int B);

	//�������� ������
	Matrix3x3 operator+ (Matrix3x3& A);
	//��������� ������
	Matrix3x3 operator* (Matrix3x3& A);
	//��������� �� ������
	void operator* (const int& n);
	//����������������
	//void operator& ();
	void operator++ ();
	//���������� ������������
	float Det ();
	//�������������� � ��������
	void operator! ();
	//����� ����� �������
	void Out();
	//��������� ���� ������
	bool Compare(float(&Matr)[N][N]) const;
	//�������� ������������
	Matrix3x3& operator= (Matrix3x3 Matr);
};
