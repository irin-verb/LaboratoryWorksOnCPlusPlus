#include "t1.h"
using namespace std;

//������� ������� ��� ����������
float MNull[N][N] = { 0,0,0,0,0,0,0,0,0 };

//���������� � �������� ������ ������:

float Test1M1[N][N] = { 3,9,10,-11,23,0,4,7,9 };
float Test1M2[N][N] = { -9,3,11,5,7,8,4,0,55 };
//����� 1 � 2
float Test1R[N][N] = { -6,12,21,-6,30,8,8,7,64 };

float Test2M1[N][N] = { 3,9,10,-11,23,0,4,7,9 };
float Test2M2[N][N] = { -9,3,11,5,7,8,4,0,55 };
//������������ 1 � 2
float Test2R[N][N] = { 58,72,655,214,128,63,35,61,595 };

float Test3M[N][N] = { -9,3,11,5,7,8,4,0,55 };
const int Test3Sclr = 2;
//��������� �� Sclr
float Test3R[N][N] = { -18,6,22,10,14,16,8,0,110 };

float Test4M[N][N] = { 3,9,10,-11,23,0,4,7,9 };
//����������������
float Test4R[N][N] = { 3,-11,4,9,23,7,10,0,9 };

float Test5M[N][N] = { 3,-11,4,9,23,7,10,0,9 };
//������������
float Test5R = -178;

float Test6M[N][N] = { 58,72,655,214,128,63,35,61,595 };
//�������������� � ��������
float Test6R[N][N] = { 0.0902,-0.0036,-0.0989,-0.1561,0.0145,0.1704,0.0107,-0.0013,-0.0099 };

//��������� �������
float Test7R[N][N] = { 1,0,0,0,1,0,0,0,1 };

//���������������� �������
float Test8M[N][N] = { 1,2,3,4,5,6,7,8,9 };

//����� T1M1 � T1M2 + ���������������� ���������� +��������� �� Sclr
float Test9R[N][N] = { 18,18,-24,-36,-90,-21,-63,-24,-192 };
int Test9Sclr = -3;

void Test::Start() {
	Pass = 0;
	Numb = 0;
}

bool Test::Expect(float& Actual, const float& Expected) {
	cout << "\n��������� ���������: " << Expected << endl;
	cout << "����������� ���������: " << Actual << endl;
	return fabs(Actual - Expected) < eps;
}

bool Test::Expect(int& Actual, const int& Expected) {
	cout << "\n��������� ���������: " << Expected << endl;
	cout << "����������� ���������: " << Actual << endl;
	return (Actual==Expected);
}

bool Test::ExpectM(Matrix3x3& Actual, int (&Expected)[N]) {
	int i;
	cout << "\n��������� ���������: " << endl;
	for (i = 0; i < N; i++)
		switch (Expected[i]) {
		case 1: {cout << i + 1 << ") ��������" << endl; break; }
		case 2: {cout << i + 1 << ") ���������" << endl; break; }
		case 3: {cout << i + 1 << ") ��������� �� ������" << endl; break; }
		case 4: {cout << i + 1 << ") ����������������" << endl; break; }
		case 5: {cout << i + 1 << ") ���������� ������������" << endl; break; }
		case 6: {cout << i + 1 << ") �������������� � ��������" << endl; break; }
		}
	cout << "����������� ���������: " << endl;
	Actual.PrintOp();
	return Actual.Comp(Expected);
}

bool Test::ExpectM(Matrix3x3& Actual, float(&Expected)[N][N]) {
	cout << "\n\t��������:" << endl;
	int i, j;
	bool I; //�������� �� ����������� ���������� �������
	I = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%*.3f  ", 7, Expected[i][j]);
			if ((fabs(Expected[i][i] - 1) >= eps || ((fabs(Expected[i][j]) >= eps) && (i != j))))
				I = 0;
		}
		printf("\n");
	}
	if (!I) printf("\t     �� ���������");
	else printf("\t        ���������");
	cout << "\n\t���������:" << endl;
	Actual.Out();
	return Actual.Compare(Expected);
}

void Test::Success(bool n) {
	++Numb;
	if (n) ++Pass, cout << "\n�����!" << endl;
	else cout << "\n�������!" << endl;
}

void Test::Results()
{
	cout << "\n_______________________________________" << endl;
	cout << "\n���������� ������������ ������ MATRI3X3" << endl;
	cout << "������ ��������: " << Pass << " �� " << Numb << endl;
}

void Test::Head() {
	cout << "\n________���� �" << Pass + 1 << "__________\n" << endl;
}

bool Test::TSumm() {
	//arrange
	this->Head();
	cout << "�������� ������ 1 � 2\n" << endl;
	Matrix3x3 A(Test1M1);
	Matrix3x3 B(Test1M2);
	Matrix3x3 C(MNull);
	printf("\t������� 1\n");
	A.Out();
	printf("\t������� 2\n");
	B.Out();
	//act
//	C=A.Summ(B);
	C = (A + B);
	//assert
	return ExpectM(C, Test1R);
}

bool Test::TMult() {
	//arrange
	this->Head();
	cout << "��������� ������ 1 � 2\n" << endl;
	Matrix3x3 A(Test2M1);
	Matrix3x3 B(Test2M2);
	Matrix3x3 C(MNull);
	printf("\t������� 1\n");
	A.Out();
	printf("\t������� 2\n");
	B.Out();
	//act
	C = A * B;
	//assert
	return ExpectM(C, Test2R);
}

bool Test::TSclr() {
	//arrange
	this->Head();
	cout << "��������� ������� 1 �� ����� " << Test3Sclr << "\n" << endl;
	Matrix3x3 A(Test3M);
	printf("\t������� 1\n");
	A.Out();
	//act
	//A.Scalar(Test3Sclr);	
	A* Test3Sclr;
	//assert
	return ExpectM(A, Test3R);
}

bool Test::TTransp() {
	//arrange
	this->Head();
	cout << "���������������� ������� 1\n" << endl;
	Matrix3x3 A(Test4M);
	printf("\t������� 1\n");
	A.Out();
	//act
	//A.Transpos();	
	++A;
	//assert
	return ExpectM(A, Test4R);
}

bool Test::TDet() {
	//arrange
	this->Head();
	cout << "���������� ������������ ������� 1\n" << endl;
	Matrix3x3 A(Test5M);
	printf("\t������� 1\n");
	A.Out();
	//act
	float D;
	//D=A.Det();
	D = A.Det();
	//assert
	return Expect(D, Test5R);
}

bool Test::TRev() {
	//arrange
	this->Head();
	cout << "�������������� ������� 1 � ��������\n" << endl;
	Matrix3x3 A(Test6M);
	printf("\t������� 1\n");
	A.Out();
	//act
	//A.Reverse();
	!A;
	//assert
	return ExpectM(A, Test6R);
}

bool Test::TMath() {
	//arrange
	this->Head();
	cout << "�������������� ������� 1 � ��������, � ����� ������������ ������ 1 � 2" << endl;
	cout << "(�������� ������� �� �������� ������� �*�^(-1)=�)\n" << endl;
	Matrix3x3 A(Test6M);
	Matrix3x3 B(Test6M);
	Matrix3x3 C(MNull);
	printf("\t������� 1\n");
	A.Out();
	printf("\t������� 2\n");
	B.Out();
	//act
	//A.Reverse(); 
	!A;
	C = A * B;
	//assert
	return ExpectM(C, Test7R);
}

bool Test::TDetNull() {
	//arrange
	this->Head();
	cout << "���������� ������������ ���������������� ������� 1\n" << endl;
	Matrix3x3 A(Test8M);
	printf("\t������� 1\n");
	A.Out();
	//act
	float D;
	//D=A.Det();
	D = A.Det();
	//assert
	return Expect(D, 0);
}

bool Test::TSummTranspSclr() {
	//arrange
	this->Head();
	cout << "�������� ������ 1 � 2, � ����� ���������������� ���������� � ��������� �� ����� " << Test9Sclr << "\n" << endl;
	Matrix3x3 A(Test1M1);
	Matrix3x3 B(Test1M2);
	Matrix3x3 C(MNull);
	printf("\t������� 1\n");
	A.Out();
	printf("\t������� 2\n");
	B.Out();
	//act
	C = (A + B);
	//C.Transpos();	
	//C.Scalar(Test9Sclr);
	++C;
	C* Test9Sclr;
	//assert
	return ExpectM(C, Test9R);
}

bool Test::TRevNever() {
	//arrange
	this->Head();
	cout << "�������������� ������� 1 � ��������" << endl;
	cout << "(������� �������������� ������� � ������� ������������� � ��������)\n" << endl;
	Matrix3x3 A(Test8M);
	printf("\t������� 1\n");
	A.Out();
	//act
	//A.Reverse();
	!A;
	//assert
	return ExpectM(A, Test8M);
}

bool Test::CountOfAll() {
	//arrange
	Object::RestartObjInfo();
	this->Head();
	cout << "�������� ���� ������ ����������� ������� ���������" << endl;
	cout << "� ����ר� ��� ��� ���������� ��������� ��������" << endl;
	//act
	Matrix3x3 A = Matrix3x3::St(-100,100);
	Matrix3x3 B = Matrix3x3::St(-100,100);	
	printf("\t������� 1\n");
	A.Out();
	printf("\t������� 2\n");
	B.Out();
	//assert
	int T=2;
	int R=Object::GetAll();
	return Expect(R,T);
}

void Test::CountOfAct1() {
	Matrix3x3 A = Matrix3x3::St(-100,100);
	printf("\t������� 1\n");
	A.Out();
}
void Test::CountOfAct2() {
	Matrix3x3 B(Test4M);
	printf("\t������� 2\n");
	B.Out();
}
bool Test::CountOfAct() {
	//arrange
	Object::RestartObjInfo();
	this->Head();
	cout << "�������� ���� ������ � ���� ��������� �������� � ����� - ��������������� � ������� �����" << endl;
	cout << "����ר� ���������� �������� �������� ����� �� ��������" << endl;
	//act
	CountOfAct1();
	CountOfAct2();
	Matrix3x3 C(Test7R);
	printf("\t������� 3\n");
	C.Out();
	//assert
	int T=1;
	int R=Object::GetAct();
	return Expect(R,T);
}

bool Test::TrueCopy() {
	//arrange
	this->Head();
	cout << "������������� � ����� ������� - ��� ������������������" << endl;
	cout << "��������� �������� � ����������� ������� � ��������, �� ���������� �� ��������" << endl;
	float T[N][N] = { 18,18,-24,-36,-90,-21,-63,-24,-192 };
	Matrix3x3 A(T);
	printf("\t����������� �������\n");
	A.Out();
	//act
	Matrix3x3 B = A;
	++A; !A; A*3; 
	printf("\t����ͨ���� �����������\n");
	A.Out();
	//assert
	return ExpectM(B,T);
}

bool Test::TrueOperations1() {
	//arrange
	this->Head();
	cout << "���������������� �������, ���������, ��������� �� ������" << endl;
	cout << "�������� ������ ������� �������� ���� �������." << endl;
	float R[N][N] = { 3,9,10,-11,23,0,4,7,9 };
	Matrix3x3 A(R);
	printf("\t�������\n");
	A.Out();
	//act
	++A;
	!A;
	A*2;
	printf("  ��������������� �������\n");
	A.Out();
	//assert
	int T[N]={4,6,3}; 
	return ExpectM(A,T);
}
bool Test::TrueOperations2() {
	//arrange
	this->Head();
	cout << "�������� ������� � � Ũ ����������������. ������������� ������� � ����� �" << endl;
	cout << "��������� ������� � �� ��������� ������� � � �������� � �������� D." << endl;
	cout << "�������� ������ �������� ������� �." << endl;
	//act
	Matrix3x3 A = Matrix3x3::St(-10,10);
	++A;
	Matrix3x3 B = A;
	Matrix3x3 C(Test3R);
	Matrix3x3 D(Test9R);
	B*C;
	B+D;
	//assert
	int T[N]={2,1};
	return ExpectM(B,T);
}

//������ Unit-������������
void Test::Run() {
	Start();
	
	Success(TSumm());
	Success(TMult());
	Success(TSclr());
	Success(TTransp());
	Success(TDet());
	Success(TRev());
	Success(TMath());
	Success(TDetNull());
	Success(TSummTranspSclr());
	Success(TRevNever());
	
	Success(CountOfAll());
	Success(CountOfAct());
	Success(TrueCopy());
	Success(TrueOperations1());
	Success(TrueOperations2());
	
	
	Results();
}
