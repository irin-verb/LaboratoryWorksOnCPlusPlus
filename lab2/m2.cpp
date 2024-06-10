#include "m2.h"
	//�����������, �������� �� ������� ���������
	bool Matrix3x3::Ident() {
		int i,j;
		//�������� ������� ���������
		for (i=0;i<N;i++) 
			if (fabs(arr[i][i]-1)>=eps) return 0;
		//�������� ��������� ���������	
		for (i=0;i<N;i++) 
		for (j=0;j<N;j++)
			if ((fabs(arr[i][j])>=eps)&&(i!=j)) return 0;
		return 1;
	}                                                                              
	//��������������� �������
	//������� ������������ ���������� �������
	float Matrix3x3::Determ (float A[N][N],int n) {
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
	//�����������
	Matrix3x3::Matrix3x3() {
		int i,j;
		for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			arr[i][j]=0;
		id=Ident();
	}
	//���������� �������
	void Matrix3x3::Create (float Matr[N][N]) {
		int i,j;
		for (i=0;i<N;i++)
		for (j=0;j<N;j++) {
			//printf("[%d][%d] = ",i+1,j+1);
			//scanf("%f",&A[i][j]);
			arr[i][j]=Matr[i][j];
		}
		id=Ident();
	}		
	//�������� ������
	void Matrix3x3::Summ (Matrix3x3 A, Matrix3x3 B) {
		int i,j;
		for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			this->arr[i][j]=A.arr[i][j]+B.arr[i][j];	
		this->id=this->Ident();
	}	
	//��������� ������
	void Matrix3x3::Mult (Matrix3x3 A, Matrix3x3 B) {
		int i,j,k;
		float S; //��� ���������� ������� ����� �������� �������� ������� C
		for (i=0;i<N;i++)
		for (j=0;j<N;j++) {
			S=0;
			for (k=0;k<N;k++)
				S+=A.arr[i][k]*B.arr[k][j];
			this->arr[i][j]=S;
		}		
		this->id=this->Ident();
	}
	//��������� �� ������
	void Matrix3x3::Scalar (int n) {
		int i,j;
		for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			arr[i][j]*=n;
		id = Ident();
	}
	//����������������
	void Matrix3x3::Transpos () {
		int i,j;
		float A[N][N]; //�������������� ������
		for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			A[i][j]=arr[i][j];
		for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			arr[i][j]=A[j][i];
		id=Ident();		
	}
	//���������� ������������
	float Matrix3x3::Det () {
		int i,j;
		float D;
		float A[N][N]; //��������������� �������
		//��������� �������� ��������� �� ��������������� �������
		for (i=0;i<N;i++) 
		for (j=0;j<N;j++)
			A[i][j]=arr[i][j];
		D=Determ(A,N); //������� � ������������ 
		return D;
	}
	//�������������� � ��������
	bool Matrix3x3::Reverse () {
		int i,j,k,q;
		float A[N][N]; //��������������� �������	 
		//��������� �������� ��������� �� ��������������� �������
		for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			A[i][j]=arr[i][j];		
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
			arr[i][j]=B[j][i];
		id=Ident();
		return 0;
		}		 	
	}
	//����� ����� �������
	void Matrix3x3::Out (int n) {
		int i,j;
		printf("\t������� %d\n",n);
		for (i=0;i<N;i++) {
			for (j=0;j<N;j++) printf("%*.3f  ", 7 , arr[i][j]);
			printf("\n");
		}
		if (id==0) printf("\t     �� ���������\n");
		else printf("\t        ���������\n");
	}	
	//��������� c ������ ��������
	bool Matrix3x3::Compare(float Matr[N][N]) {
		int i,j;
		for (i=0;i<N;i++) 
		for (j=0;j<N;j++)
			if (fabs(Matr[i][j]-arr[i][j])>=eps) return 0;
		return 1;
	}
