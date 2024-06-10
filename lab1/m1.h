#ifndef M1_H
#define M1_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>   
#include <stdbool.h>

#define N 3 //ПЮГЛЕПМНЯРЭ ЛЮРПХЖ
#define eps 1e-6 //ОНЦПЕЬМНЯРЭ ОПХ ЯПЮБМЕМХХ БЕЫЕЯРБЕММШУ ВХЯЕК

//ярпсйрспю люрпхжш
typedef struct {
	float arr[N][N];
	bool id;
} Matrix3x3; 

//нопедекемхе онкъ ID (ткюцю едхмхвмнярх люрпхжш)
bool Ident(Matrix3x3 Matr);

//гюонкмемхе люрпхжш мскълх
Matrix3x3 Nulls(Matrix3x3 Matr);

//янгдюмхе ярпсйрспш люрпхжш хг ббедеммнцн люяяхбю
Matrix3x3 Create (Matrix3x3 New);

//якнфемхе дбсу люрпхж
Matrix3x3 Summ (Matrix3x3 A, Matrix3x3 B);

//слмнфемхе дбсу люрпхж
Matrix3x3 Mult (Matrix3x3 A, Matrix3x3 B);

//слмнфемхе люрпхжш мю яйюкъп
void Scalar (Matrix3x3* Matr, int n);

//рпюмяонмхпнбюмхе люрпхжш
void Transpos (Matrix3x3* Matr);

//мюунфдемхе нопедекхрекъ 
//(пюанрю мюопълсч я люяяхбнл, щрн бяонлнцюрекэмюъ пейспяхбмюъ тсмйжхъ)
float Determ (float A[N][N],int n);

//мюунфдемхе нопедекхрекъ люрпхжш (пюанрю ян ярпсйрспни)
float Det (Matrix3x3 Matr);

//опенапюгнбюмхе люрпхжш б напюрмсч
bool Reverse (Matrix3x3* Matr);

//бшбнд ндмни люрпхжш
void Out (Matrix3x3 Matr, int n);

//бшбнд бяеу рпеу люрпхж
void OutAll(Matrix3x3 A, Matrix3x3 B, Matrix3x3 C);

#endif
