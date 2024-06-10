#include "m1.h"

//ОПРЕДЕЛЕНИЕ ПОЛЯ ID (ФЛАГА ЕДИНИЧНОСТИ МАТРИЦЫ)
bool Ident(Matrix3x3 Matr) {
	int i,j;
	//проверка главной диагонали
	for (i=0;i<N;i++) 
		if (fabs(Matr.arr[i][i]-1)>=eps) return 0;
	//проверка остальных элементов	
	for (i=0;i<N;i++) 
	for (j=0;j<N;j++)
		if ((fabs(Matr.arr[i][j])>=eps)&&(i!=j)) return 0;
	return 1;
}

//ЗАПОЛНЕНИЕ МАТРИЦЫ НУЛЯМИ
Matrix3x3 Nulls(Matrix3x3 Matr) {
	int i,j;
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		Matr.arr[i][j]=0;
	Matr.id=Ident(Matr);
	return Matr;
}

//СОЗДАНИЕ СТРУКТУРЫ МАТРИЦЫ ИЗ ВВЕДЕННОГО МАССИВА
Matrix3x3 Create (Matrix3x3 New) {
	float A[N][N]; //массив для заполнения
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

//СЛОЖЕНИЕ ДВУХ МАТРИЦ
Matrix3x3 Summ (Matrix3x3 A, Matrix3x3 B) {
	Matrix3x3 C; //матрица для результата сложения
	int i,j;
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		C.arr[i][j]=A.arr[i][j]+B.arr[i][j];	
	C.id=Ident(C);
	return C;
}

//УМНОЖЕНИЕ ДВУХ МАТРИЦ
Matrix3x3 Mult (Matrix3x3 A, Matrix3x3 B) {
	Matrix3x3 C; //матрица для результата умножения
	int i,j,k;
	float S; //для накопления текущей суммы текущего элемента матрицы C
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

//УМНОЖЕНИЕ МАТРИЦЫ НА СКАЛЯР
void Scalar (Matrix3x3* Matr, int n) {
	int i,j;
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		Matr->arr[i][j]*=n;
	Matr->id = Ident(*Matr);
}

//ТРАНСПОНИРОВАНИЕ МАТРИЦЫ
void Transpos (Matrix3x3* Matr) {
	int i,j;
	float A[N][N]; //дополнительный массив
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		A[i][j]=Matr->arr[i][j];
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		Matr->arr[i][j]=A[j][i];
	Matr->id=Ident(*Matr);		
}

//НАХОЖДЕНИЕ ОПРЕДЕЛИТЕЛЯ 
//(ТУТ РАБОТА НАПРЯМУЮ С МАССИВОМ, ЭТО ВСПОМОГАТЕЛЬНАЯ РЕКУРСИВНАЯ ФУНКЦИЯ)
float Determ (float A[N][N],int n) {
	int i,j,k;
	float a,b;
	float D;
	float B[N][N];//вспомогательная матрица, вычисляя определитель 
				  //которой будем получать текущее алгебраическое дополнение
	//если матрица 2x2 определитель находится элементарно			  
	if (n==2) 
		D=A[0][0]*A[1][1]-A[0][1]*A[1][0];
	//если НЕ 2x2 матрица раскладывается по первой строке, разложение происходит 
	//до тех пор, пока все матрицы, определители которых ищем, не примут вид 2x2
	else {	
		D=0;  
		//собственно разложение по первой строке
		for (k=0;k<n;k++) {  
			//заполнение текущей вспомогательной матрицы
			for (j=0;j<n-1;j++) 
			for (i=0;i<n-1;i++) {
				if (j<k) B[i][j]=A[i+1][j];
				else B[i][j]=A[i+1][j+1];
			}
			a=A[0][k]; //элемент первой строки, положение которого зависит от k
			b=Determ(B,n-1); //определитель вспомогательной матрицы
			 //определение знака алгебраического дополнения
			if ((2+k)%2==0) D=D+a*b;
			else D=D-a*b;
		}
	}
	return D;
}

//НАХОЖДЕНИЕ ОПРЕДЕЛИТЕЛЯ МАТРИЦЫ (РАБОТА СО СТРУКТУРОЙ)
float Det (Matrix3x3 Matr) {
	int i,j;
	float D;
	float A[N][N]; //вспомогательная матрица
	//переносим элементы структуры во вспомогательную матрицу
	for (i=0;i<N;i++) 
	for (j=0;j<N;j++)
		A[i][j]=Matr.arr[i][j];
	D=Determ(A,N); //считаем её определитель 
	return D;
}

//ПРЕОБРАЗОВАНИЕ МАТРИЦЫ В ОБРАТНУЮ
bool Reverse (Matrix3x3* Matr) {
	int i,j,k,q;
	float A[N][N]; //вспомогательная матрица	 
	//переносим элементы структуры во вспомогательную матрицу
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		A[i][j]=Matr->arr[i][j];		
	float B[N][N]; //присоединенная матрица из алгебраических дополнений
	float C[N][N]; //матрица для нахождения текущего минора 
	//проходимся по всем элементам исходной матрицы для каждого - свой минор, 
	//поэтому заполняем C в зависимости от положения текущего элемента
	for (k=0;k<N;k++)    	 
	for (q=0;q<N;q++) {	 
		//собственно заполнение C	
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
		//считаем минор текущей матрицы, составленной для текущего элемента A[i][j]
		//тк присоединённая матрица должна быть транспонированной - [q][k], а не [k][q]
		B[q][k]=Determ(C,N-1); 
		//определяем знак, т.е. вносим алгебраическое дополнение в присоединённую матрицу B
		if ((k+q+2)%2!=0) B[q][k]*=-1;				
	}		
	
	if (Determ(A,N)==0) return 1; //случай попытки найти обратную матрицу для матрицы с нулевым определителем
	else {
		//коэффициент, на который домножаем присоединенную матрицу для получения обратной
		float D=1/Determ(A,N);
		//собственно домножаем
	for (i=0;i<N;i++)
	for (j=0;j<N;j++)
		B[i][j]*=D;
	//вносим полученную матрицу обратно в структуру
	for (i=0;i<N;i++) 
	for (j=0;j<N;j++)
		Matr->arr[i][j]=B[j][i];
	Matr->id=Ident(*Matr);
	return 0;
	}		 	
}

//ВЫВОД ОДНОЙ МАТРИЦЫ
void Out (Matrix3x3 Matr, int n) {
	int i,j;
	printf("\n\tМАТРИЦА %d\n",n);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) printf("%*.3f  ", 7 , Matr.arr[i][j]);
		printf("\n");
	}
	if (Matr.id==0) printf("\t     НЕ единичная");
	else printf("\t        Единичная");
}

//ВЫВОД ВСЕХ ТРЕХ МАТРИЦ
void OutAll(Matrix3x3 A, Matrix3x3 B, Matrix3x3 C) {
	int i,j;
	printf("\n\tМАТРИЦА 1\t\t\tМАТРИЦА 2\t\t\tМАТРИЦА 3\n");
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
	if (A.id==0) printf("\t   НЕ единичная");
	else printf("\t      Единичная");
	if (B.id==0) printf("\t\t\t   НЕ единичная");
	else printf("\t\t\t      Единичная");
	if (C.id==0) printf("\t\t\t   НЕ единичная");
	else printf("\t\t\t      Единичная");
	//printf("\t  [%d]\t\t\t\t  [%d]\t\t\t\t  [%d]",A.id,B.id,C.id);
}
