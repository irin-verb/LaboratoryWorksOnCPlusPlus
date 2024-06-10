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
	static int All; //���-�� ��������� ��������
	static int Act; //���-�� �������� ��������
	int* Op; //��������� ��� ��������� ������ ��� ������
	int Ops; //������� ����� �������� � �������

public:
	//��������� ����������� ����� ������
	static void RestartObjInfo();

	Object();
	//����������� �����������
	Object(const Object& Obj);
	~Object();

	//����� All � Act
	static void PrintTotalInfo();
	//������� All � Act
	static int GetAll() { return All; };
	static int GetAct() { return Act; };

	//���������� �������� � ������ ��������
	void AddOp(int k);
	//����� ������� ��������
	void PrintOp();
	//�������� ������� ��������
	void ClearOp();

	//�������� ������������
	Object& operator= (Object& Matr);
	
	//��������� ������ ��������
	bool Comp(int (&Spis)[N]);
};
