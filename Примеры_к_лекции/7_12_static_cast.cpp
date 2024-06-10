#include <iostream> 
#include <strings.h>

using namespace std;

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	// � �-�����
	int i1 = 11;
	int i2 = 3;
	float x = (float)i1 / i2;
	cout << x << endl;

	// � �++
	x = float(i1) / i2; // ������ ������������� ����� ()
	cout << x << endl;
	
	//static_cast
	x = static_cast<float>(i1) / i2; 
	cout << x << endl;
	
	// � ������� �� �-�����, static_cast ����� ��������� �
	// �� ��������� ��������� ������������� ���� (����������� �� ����� ����������) 
	int* i1Ptr = &i1;
	char* p1 = (char*) i1Ptr; //����� �������
	//char* p2 = static_cast<char*>(i1Ptr); //[Error] invalid static_cast from type 'int*' to type 'char*'
	
	const int u = 5;
	int* y1 = (int*)&u; //����� �������
	//int* y2 = static_cast<int*>(&u); // [Error] invalid static_cast from type 'const int*' to type 'int*'
	
	return 0;
}

