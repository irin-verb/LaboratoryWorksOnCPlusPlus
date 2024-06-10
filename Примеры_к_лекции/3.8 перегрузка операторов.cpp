#include <iostream> 
#include <strings.h>

using namespace std;


/*

����� ����������� ��������� ���������:

+	-	*	/	%	?	&	|	~
!	=	<	>	+=	-=	*=	/=	%=
?=	&=	|=	<<	>>	<<=	>>=	==	!=
<=	>=	&&	||	++	--	,	->*	->
()	[]	new	delete	new[]	delete[]

����� ����������� ��� �������, ��� � �������� ����� ��������� ����������:
+	-	*	&

������� ��������� ������ ���� ��� ����� ������ ��� ����������:
[], =, ->, ()
	
������ ����������� ���������:
.	::	?: sizeof

*/


/*
� C++11 ����� ���������� ��������� ��� typedef, ������� ��������� ������ 
���������� ����������. ���� ��������� ���������� type alias. 
*/
using byte = unsigned char;

/*����� Color ��������� ���� � ������� RGB */
class Color
{
	byte r, g, b;
	
public:
	
	Color(byte r, byte g, byte b) : r(r), g(g), b(b) {}
	
	// ������� ��������� ��� ����� ������ ����������� ��� []
	int operator[] (int i) const // const ����������� ������������ ������ ������� ��� ������ ������
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
		cout << "������� �����: "  << (*this)[0] 
		     << " ������� �����: " << (*this)[1] 
		     << " ����� �����: "   << (*this)[2]
		     << endl;
	}
};

// ���������� ���������� ����� ��������� ��� ������, ����� � ���
// �� ���������� ��������� this, ������� � ���������� ������ ����
// ��� ��������
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
	
	//�������� + ��� ���������� ��� Color, ���������� ����� ������ Color
	Color myColor3 = myColor + myColor2;
	
	myColor3.print();
	
	return 0;
}

