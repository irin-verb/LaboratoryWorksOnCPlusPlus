#include <iostream> 
#include <strings.h>
#include <stdlib.h>

using namespace std;

float getRectArea(float w, float h)
{
	return w * h;
}

//��� �������� �������� ��-��������� ����� ���������� ����������������!
float getRectArea(float left, float top, float right = 100, float bottom = 100) 
{
	return (right - left) * (bottom - top);
}


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	cout<<"������� �������������� 1: " << getRectArea(50, 100) << endl;
	cout<<"������� �������������� 2: " << getRectArea(60, 150, 110, 250) << endl;
	
	return 0;
}

