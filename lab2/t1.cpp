#include "t1.h"
using namespace std;

//���������� � �������� ������ ������:

float Test1M1[N][N]={3,9,10,-11,23,0,4,7,9}; 
float Test1M2[N][N]={-9,3,11,5,7,8,4,0,55}; 
//����� 1 � 2
float Test1R[N][N]={-6,12,21,-6,30,8,8,7,64};

float Test2M1[N][N]={3,9,10,-11,23,0,4,7,9}; 
float Test2M2[N][N]={-9,3,11,5,7,8,4,0,55}; 
//������������ 1 � 2
float Test2R[N][N]={58,72,655,214,128,63,35,61,595};

float Test3M[N][N]={-9,3,11,5,7,8,4,0,55};  
int Test3Sclr=2; 
//��������� �� Sclr
float Test3R[N][N]={-18,6,22,10,14,16,8,0,110};

float Test4M[N][N]={3,9,10,-11,23,0,4,7,9};   
//����������������
float Test4R[N][N]={3,-11,4,9,23,7,10,0,9};

float Test5M[N][N]={3,-11,4,9,23,7,10,0,9};
//������������
float Test5R=-178;

float Test6M[N][N]={58,72,655,214,128,63,35,61,595};
//�������������� � ��������
float Test6R[N][N]={0.0902,-0.0036,-0.0989,-0.1561,0.0145,0.1704,0.0107,-0.0013,-0.0099};

//��������� �������
float Test7R[N][N]={1,0,0,0,1,0,0,0,1};

//���������������� �������
float Test8M[N][N]={1,2,3,4,5,6,7,8,9};

//����� T1M1 � T1M2 + ���������������� ���������� +��������� �� Sclr
float Test9R[N][N]={18,18,-24,-36,-90,-21,-63,-24,-192};
int Test9Sclr=-3;


//��������� ���������
void Test::Start() {
	Pass=0; 
Numb=0;
}
//��������� �����������
//��� �������
bool Test::Expect(int Actual, int Expected) {
	cout << "��������� ���������: " << Expected << endl;
	cout << "����������� ���������: " << Actual << endl;
	return Actual == Expected;
}
//��� ������
bool Test::ExpectM(Matrix3x3 Actual, float Expected[N][N], int n) {
	cout << "��������� ������� � "<< n << ":" << endl;
	int i,j;
	bool I; //�������� �� ����������� ���������� �������
	I=1;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			printf("%*.3f  ", 7 , Expected[i][j]);
			if ((fabs(Expected[i][i]-1)>=eps||((fabs(Expected[i][j])>=eps)&&(i!=j)))) 
				I=0;
		}
		printf("\n");
	}
	if (!I) printf("\t     �� ���������");
	else printf("\t        ���������");
	cout << "\n\n����������� ���������: " << endl;
	Actual.Out(n);
	return Actual.Compare(Expected);
}
//����� ��������� �� ������/�������
void Test::Success(bool n) {
	++Numb;
	if (n) ++Pass, cout << "\n�����!" << endl; 
	else cout << "\n�������!" << endl;
}	
//����� ����������� �����
void Test::Results()
{
	cout << "\n\n���������� ������������ ������ MATRI3X3" << endl;
	cout << "������ ��������: " << Pass << " �� " << Numb << endl;
}	

//���� �����
bool Test::TSumm() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A,B,C;
	A.Create(Test1M1); A.Out(1);
	B.Create(Test1M2); B.Out(2);
	cout << "\n�������� ������ 1 � 2\n" << endl;
	//act
	C.Summ(A,B);	
	//assert
	return ExpectM(C,Test1R,3);
}
bool Test::TMult() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A,B,C;
	A.Create(Test2M1); A.Out(1);
	B.Create(Test2M2); B.Out(2);
	cout << "\n��������� ������ 1 � 2\n" << endl;
	//act
	C.Mult(A,B);	
	//assert
	return ExpectM(C,Test2R,3);
}
bool Test::TSclr() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A;
	A.Create(Test3M);
	A.Out(1);
	cout << "\n��������� ������� 1 �� ����� " << Test3Sclr << "\n" << endl;
	//act
	A.Scalar(Test3Sclr);	
	//assert
	return ExpectM(A,Test3R,1);			
}
bool Test::TTransp() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A;
	A.Create(Test4M);
	A.Out(1);
	cout << "\n���������������� ������� 1\n" << endl;
	//act
	A.Transpos();	
	//assert
	return ExpectM(A,Test4R,1);
}
bool Test::TDet() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A;
	A.Create(Test5M);
	A.Out(1);
	cout << "\n���������� ������������ ������� 1\n" << endl;
	//act
	float D;
	D=A.Det();	
	//assert
	return Expect(D,Test5R);
}
bool Test::TRev() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A;
	A.Create(Test6M);
	A.Out(1);
	cout << "\n�������������� ������� 1 � ��������\n" << endl;
	//act
	A.Reverse();
	//assert
	return ExpectM(A,Test6R,1);
}
bool Test::TMath() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A,B,C;
	A.Create(Test6M); B.Create(Test6M);
	A.Out(1); B.Out(2);
	cout << "\n�������������� ������� 1 � ��������, � ����� ������������ ������ 1 � 2" << endl;
	cout << "(�������� ������� �� �������� ������� �*�^(-1)=�)\n" << endl;
	//act
	A.Reverse(); 
	C.Mult(A,B);
	//assert
	return ExpectM(C,Test7R,3);
}
bool Test::TDetNull() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A;
	A.Create(Test8M);
	A.Out(1);
	cout << "\n���������� ������������ ���������������� ������� 1\n" << endl;
	//act
	float D;
	D=A.Det();	
	//assert
	return Expect(D,0);
}
bool Test::TSummTranspSclr() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A,B,C;
	A.Create(Test1M1); A.Out(1);
	B.Create(Test1M2); B.Out(2);
	cout << "\n�������� ������ 1 � 2, � ����� ���������������� ���������� � ��������� �� ����� " << Test9Sclr << "\n"<< endl;
	//act
	C.Summ(A,B);
	C.Transpos();	
	C.Scalar(Test9Sclr);
	//assert
	return ExpectM(C,Test9R,3);		
}
bool Test::TRevNever() {
	//arrange
	cout << "\n���� �" << Pass+1 << "\n" << endl;
	Matrix3x3 A;
	A.Create(Test8M);
	A.Out(1);
	cout << "\n�������������� ������� 1 � ��������" << endl;
	cout << "(������� �������������� ������� � ������� ������������� � ��������)\n" << endl;
	//act
	A.Reverse();
	//assert
	return ExpectM(A,Test8M,1);
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

	Results();	
}	
