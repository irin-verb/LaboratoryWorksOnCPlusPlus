#include "m2.h"
float Nulls[N][N] = { 0,0,0,0,0,0,0,0,0 };

bool Matrix3x3::Ident() {
	int i, j;
	//проверка главной диагонали
	for (i = 0; i < N; i++)
		if (fabs(arr[i][i] - 1) >= eps) return 0;
	//проверка остальных элементов	
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if ((fabs(arr[i][j]) >= eps) && (i != j)) return 0;
	return 1;
}

float Matrix3x3::Determ(float(&A)[N][N], int n) const {
	int i, j, k;
	float a, b;
	float D;
	float B[N][N];//вспомогательная матрица, вычисляя определитель 
	//которой будем получать текущее алгебраическое дополнение
//если матрица 2x2 определитель находится элементарно			  
	if (n == 2)
		D = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	//если НЕ 2x2 матрица раскладывается по первой строке, разложение происходит 
	//до тех пор, пока все матрицы, определители которых ищем, не примут вид 2x2
	else {
		D = 0;
		//собственно разложение по первой строке
		for (k = 0; k < n; k++) {
			//заполнение текущей вспомогательной матрицы
			for (j = 0; j < n - 1; j++)
				for (i = 0; i < n - 1; i++) {
					if (j < k) B[i][j] = A[i + 1][j];
					else B[i][j] = A[i + 1][j + 1];
				}
			a = A[0][k]; //элемент первой строки, положение которого зависит от k
			b = Determ(B, n - 1); //определитель вспомогательной матрицы
			//определение знака алгебраического дополнения
			if ((2 + k) % 2 == 0) D = D + a * b;
			else D = D - a * b;
		}
	}
	return D;
}

Matrix3x3::Matrix3x3(const Matrix3x3& Matr) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = Matr.arr[i][j];
	id = Ident();
}

Matrix3x3::Matrix3x3(float(&Matr)[N][N]) : Object()  {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = Matr[i][j];
	id = Ident();
}

Matrix3x3::~Matrix3x3() {
}

Matrix3x3 Matrix3x3::St(int A, int B) {
	Matrix3x3 Res(Nulls);
	srand(time(NULL));
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			Res.arr[i][j] = A + rand() % (B - A + 1);
	return Res;
}

Matrix3x3 Matrix3x3::operator+ (Matrix3x3& A) {
	Matrix3x3 Res(Nulls);
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			Res.arr[i][j] = this->arr[i][j] + A.arr[i][j];
	Res.id = Res.Ident();
	AddOp(1);
	A.AddOp(1);
	return Res;
}

Matrix3x3 Matrix3x3::operator* (Matrix3x3& A) {
	int i, j, k;
	float S; //для накопления текущей суммы текущего элемента матрицы C
	Matrix3x3 Res(Nulls);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			S = 0;
			for (k = 0; k < N; k++)
				S += this->arr[i][k] * A.arr[k][j];
			Res.arr[i][j] = S;
		}
	Res.id = Res.Ident();
	AddOp(2);
	A.AddOp(2);
	return Res;
}

void Matrix3x3::operator* (const int& n) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			arr[i][j] *= n;
	id = Ident();
	AddOp(3);
}

void Matrix3x3::operator++ () {
	int i, j;
	float A[N][N]; //дополнительный массив
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			A[i][j] = arr[i][j];
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			arr[i][j] = A[j][i];
	id = Ident();
	AddOp(4);	
}

float Matrix3x3::Det() {
	int i, j;
	float D;
	float A[N][N]; //вспомогательная матрица
	//переносим элементы структуры во вспомогательную матрицу
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			A[i][j] = arr[i][j];
	D = Determ(A, N); //считаем её определитель 
	AddOp(5);
	return D;
}

void Matrix3x3::operator! () {
	int i, j, k, q;
	float A[N][N]; //вспомогательная матрица	 
	//переносим элементы структуры во вспомогательную матрицу
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			A[i][j] = arr[i][j];
	float B[N][N]; //присоединенная матрица из алгебраических дополнений
	float C[N][N]; //матрица для нахождения текущего минора 
	//проходимся по всем элементам исходной матрицы для каждого - свой минор, 
	//поэтому заполняем C в зависимости от положения текущего элемента
	for (k = 0; k < N; k++)
		for (q = 0; q < N; q++) {
			//собственно заполнение C	
			for (i = 0; i < N; i++)//
				for (j = 0; j < N; j++) {
					if (i < q) {
						if (j < k) C[i][j] = A[i][j];
						else if (j > k) C[i][j - 1] = A[i][j];
					}
					else if (i > q) {
						if (j < k) C[i - 1][j] = A[i][j];
						else if (j > k) C[i - 1][j - 1] = A[i][j];
					}
				}
			//считаем минор текущей матрицы, составленной для текущего элемента A[i][j]
			//тк присоединённая матрица должна быть транспонированной - [q][k], а не [k][q]
			B[q][k] = Determ(C, N - 1);
			//определяем знак, т.е. вносим алгебраическое дополнение в присоединённую матрицу B
			if ((k + q + 2) % 2 != 0) B[q][k] *= -1;
		}

	//в случае попытки найти обратную матрицу для матрицы с нулевым определителем
	//матрица преобразована не будет
	if (Determ(A, N) != 0) {
		//коэффициент, на который домножаем присоединенную матрицу для получения обратной
		float D = 1 / Determ(A, N);
		//собственно домножаем
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				B[i][j] *= D;
		//вносим полученную матрицу обратно в структуру
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				arr[i][j] = B[j][i];
		id = Ident();
		AddOp(6);
	}
}

void Matrix3x3::Out() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) printf("%*.3f  ", 7, arr[i][j]);
		printf("\n");
	}
	if (id == 0) printf("\t     НЕ единичная\n");
	else printf("\t        Единичная\n");
}

bool Matrix3x3::Compare(float(&Matr)[N][N]) const {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (fabs(Matr[i][j] - arr[i][j]) >= eps) return 0;
	return 1;
}

Matrix3x3& Matrix3x3::operator= (Matrix3x3 Matr) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			arr[i][j] = Matr.arr[i][j];
	id = Ident();
	return *this;
}
