#pragma once
#include "m2.h"

//����� �����:
class Test
{
	int Pass; //���������� ���������� ������
	int Numb; //����� ���������� ������
	
	//��������� ���������
	void Start();
	//��������� �����������
	//��� �������
	bool Expect(int Actual, int Expected);
	//��� ������
	bool ExpectM(Matrix3x3 Actual, float Expected[N][N], int n);
	//����� ��������� �� ������/�������
	void Success(bool n);
	//����� ����������� �����
	void Results();
	
	//��������� �����:
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
	//������ Unit-������������
	void Run();
};
