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
	bool Expect(float& Actual, const float& Expected);
	bool Expect(int& Actual, const int& Expected);
	//��� ������/��������
	bool ExpectM(Matrix3x3& Actual, int (&Expected)[N]);
	bool ExpectM(Matrix3x3& Actual, float(&Expected)[N][N]);
	//����� ��������� �� ������/�������
	void Success(bool n);
	//����� ����������� �����
	void Results();
	//����� ��������� �����
	void Head();

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

	//����� �����:
	bool CountOfAll();
	
	bool CountOfAct();
	void CountOfAct1(); //��������������� ������� � CountOfAct()
	void CountOfAct2(); //��������������� ������� � CountOfAct()
	
	bool TrueCopy();
	
	bool TrueOperations1();
	bool TrueOperations2();

public:
	//������ Unit-������������
	void Run();
};
