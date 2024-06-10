#include <iostream> 
#include <strings.h>

using namespace std;


/*

Можно перегружать следующие операторы:

+	-	*	/	%	?	&	|	~
!	=	<	>	+=	-=	*=	/=	%=
?=	&=	|=	<<	>>	<<=	>>=	==	!=
<=	>=	&&	||	++	--	,	->*	->
()	[]	new	delete	new[]	delete[]

Можно перегрузить как унарную, так и бинарную формы следующих операторов:
+	-	*	&

Функция оператора должна быть как метод класса для операторов:
[], =, ->, ()
	
Нельзя перегружать операторы:
.	::	?: sizeof

*/


/*
в C++11 ввели улучшенный синтаксис для typedef, который имитирует способ 
объявления переменных. Этот синтаксис называется type alias. 
*/
using byte = unsigned char;

/*Класс Color описывает цвет в формате RGB */
class Color
{
	byte r, g, b;
	
public:
	
	Color(byte r, byte g, byte b) : r(r), g(g), b(b) {}
	
	// функция оператора как метод класса обязательно для []
	int operator[] (int i) const // const гарантирует неизменность самого объекта при вызове метода
	{ 
		i = i > 2 ? 2 : (i < 0 ? 0 : i);
		
		switch(i)
		{
			case 0: return r;
			case 1: return g;
			case 2: return b;
		}
		
		return 0;
	}
	
	void print()
	{
		cout << "красный канал: "  << (*this)[0] 
		     << " зеленый канал: " << (*this)[1] 
		     << " синий канал: "   << (*this)[2]
		     << endl;
	}
};

// перегрузку операторов можно объявлять вне класса, тогда в них
// не передаются указатели this, поэтому в параметрах должны быть
// оба операнда
Color operator+ (const Color& color1, const Color& color2) 
{ 
	return { byte((color1[0] + color2[0]) / 2),
			 byte((color1[1] + color2[1]) / 2),
			 byte((color1[2] + color2[2]) / 2) };
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	Color myColor(255, 50, 25), myColor2(120, 95, 88);
	
	myColor.print();
	myColor2.print();
	
	//оператор + был перегружен для Color, возвращает новый объект Color
	Color myColor3 = myColor + myColor2;
	
	myColor3.print();
	
	return 0;
}

