#include "m1.h"

//����������� ���� ID (����� ����������� �������)
bool Ident(Matrix3x3 Matr) {
	int i,j;
	//�������� ������� ���������
	for (i=0;i<N;i++) 
		if (fabs(Matr.arr[i][i]-1)>=eps) return 0;
	//�������� ��������� ���������	
	for (i=0;i<N;i++) 
	for (j=0;j<N;j++)
		if ((fabs(Matr.arr[i][j])>=eps)&&(i!=j)) return 0;
	return 1;
}

//���������� ������� ������
Matrix3x3 Nulls(Matrix3x3 Matr) {
	int i,j;
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		Matr.arr[i][j]=0;
	Matr.id=Ident(Matr);
	return Matr;
}

//�������� ��������� ������� �� ���������� �������
Matrix3x3 Create (Matrix3x3 New) {
	float A[N][N]; //������ ��� ����������
	int i,j;
	for (i=0;i<N;i++)
	for (j=0;j<N;j++) {
		printf("[%d][%d] = ",i+1,j+1);
		scanf("%f",&A[i][j]);
		New.arr[i][j]=A[i][j];
	}
	New.id=Ident(New);
	return New;
}

//�������� ���� ������
Matrix3x3 Summ (Matrix3x3 A, Matrix3x3 B) {
	Matrix3x3 C; //������� ��� ���������� ��������
	int i,j;
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		C.arr[i][j]=A.arr[i][j]+B.arr[i][j];	
	C.id=Ident(C);
	return C;
}

//��������� ���� ������
Matrix3x3 Mult (Matrix3x3 A, Matrix3x3 B) {
	Matrix3x3 C; //������� ��� ���������� ���������
	int i,j,k;
	float S; //��� ���������� ������� ����� �������� �������� ������� C
	for (i=0;i<N;i++)
	for (j=0;j<N;j++) {
		S=0;
		for (k=0;k<N;k++)
			S+=A.arr[i][k]*B.arr[k][j];
		C.arr[i][j]=S;
	}		
	C.id=Ident(C);
	return C;
}

//��������� ������� �� ������
void Scalar (Matrix3x3* Matr, int n) {
	int i,j;
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		Matr->arr[i][j]*=n;
	Matr->id = Ident(*Matr);
}

//���������������� �������
void Transpos (Matrix3x3* Matr) {
	int i,j;
	float A[N][N]; //�������������� ������
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		A[i][j]=Matr->arr[i][j];
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		Matr->arr[i][j]=A[j][i];
	Matr->id=Ident(*Matr);		
}

//���������� ������������ 
//(��� ������ �������� � ��������, ��� ��������������� ����������� �������)
float Determ (float A[N][N],int n) {
	int i,j,k;
	float a,b;
	float D;
	float B[N][N];//��������������� �������, �������� ������������ 
				  //������� ����� �������� ������� �������������� ����������
	//���� ������� 2x2 ������������ ��������� �����������			  
	if (n==2) 
		D=A[0][0]*A[1][1]-A[0][1]*A[1][0];
	//���� �� 2x2 ������� �������������� �� ������ ������, ���������� ���������� 
	//�� ��� ���, ���� ��� �������, ������������ ������� ����, �� ������ ��� 2x2
	else {	
		D=0;  
		//���������� ���������� �� ������ ������
		for (k=0;k<n;k++) {  
			//���������� ������� ��������������� �������
			for (j=0;j<n-1;j++) 
			for (i=0;i<n-1;i++) {
				if (j<k) B[i][j]=A[i+1][j];
				else B[i][j]=A[i+1][j+1];
			}
			a=A[0][k]; //������� ������ ������, ��������� �������� ������� �� k
			b=Determ(B,n-1); //������������ ��������������� �������
			 //����������� ����� ��������������� ����������
			if ((2+k)%2==0) D=D+a*b;
			else D=D-a*b;
		}
	}
	return D;
}

//���������� ������������ ������� (������ �� ����������)
float Det (Matrix3x3 Matr) {
	int i,j;
	float D;
	float A[N][N]; //��������������� �������
	//��������� �������� ��������� �� ��������������� �������
	for (i=0;i<N;i++) 
	for (j=0;j<N;j++)
		A[i][j]=Matr.arr[i][j];
	D=Determ(A,N); //������� � ������������ 
	return D;
}

//�������������� ������� � ��������
bool Reverse (Matrix3x3* Matr) {
	int i,j,k,q;
	float A[N][N]; //��������������� �������	 
	//��������� �������� ��������� �� ��������������� �������
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		A[i][j]=Matr->arr[i][j];		
	float B[N][N]; //�������������� ������� �� �������������� ����������
	float C[N][N]; //������� ��� ���������� �������� ������ 
	//���������� �� ���� ��������� �������� ������� ��� ������� - ���� �����, 
	//������� ��������� C � ����������� �� ��������� �������� ��������
	for (k=0;k<N;k++)    	 
	for (q=0;q<N;q++) {	 
		//���������� ���������� C	
		for (i=0;i<N;i++)//
		for (j=0;j<N;j++) {
			if (i<q) {
				if (j<k) C[i][j]=A[i][j];
				else if (j>k) C[i][j-1]=A[i][j];
			}
			else if (i>q) {
				if (j<k) C[i-1][j]=A[i][j];
				else if (j>k) C[i-1][j-1]=A[i][j];
			}				
		}
		//������� ����� ������� �������, ������������ ��� �������� �������� A[i][j]
		//�� ������������� ������� ������ ���� ����������������� - [q][k], � �� [k][q]
		B[q][k]=Determ(C,N-1); 
		//���������� ����, �.�. ������ �������������� ���������� � ������������� ������� B
		if ((k+q+2)%2!=0) B[q][k]*=-1;				
	}		
	
	if (Determ(A,N)==0) return 1; //������ ������� ����� �������� ������� ��� ������� � ������� �������������
	else {
		//�����������, �� ������� ��������� �������������� ������� ��� ��������� ��������
		float D=1/Determ(A,N);
		//���������� ���������
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		B[i][j]*=D;
	//������ ���������� ������� ������� � ���������
	for (i=0;i<N;i++) 
	for (j=0;j<N;j++)
		Matr->arr[i][j]=B[j][i];
	Matr->id=Ident(*Matr);
	return 0;
	}		 	
}

//����� ����� �������
void Out (Matrix3x3 Matr, int n) {
	int i,j;
	printf("\n\t������� %d\n",n);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) printf("%*.3f  ", 7 , Matr.arr[i][j]);
		printf("\n");
	}
	if (Matr.id==0) printf("\t     �� ���������");
	else printf("\t        ���������");
}

//����� ���� ���� ������
void OutAll(Matrix3x3 A, Matrix3x3 B, Matrix3x3 C) {
	int i,j;
	printf("\n\t������� 1\t\t\t������� 2\t\t\t������� 3\n");
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++)
			printf("%*.3f	",7,A.arr[i][j]);
		printf("\t");
		for (j=0;j<N;j++)
			printf("%*.3f	",7,B.arr[i][j]);
		printf("\t");
		for (j=0;j<N;j++)
			printf("%*.3f	",7,C.arr[i][j]);
		printf("\n");
	}
	if (A.id==0) printf("\t   �� ���������");
	else printf("\t      ���������");
	if (B.id==0) printf("\t\t\t   �� ���������");
	else printf("\t\t\t      ���������");
	if (C.id==0) printf("\t\t\t   �� ���������");
	else printf("\t\t\t      ���������");
	//printf("\t  [%d]\t\t\t\t  [%d]\t\t\t\t  [%d]",A.id,B.id,C.id);
}
