#include <iostream> 
#include <strings.h>

using namespace std;

void f(const int* param)
{
	*const_cast<int*>(param) = 20;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	// --- const_cast ---
	
	// ����������� ����������� ������
	int i = 3;
    const int& ref_i = i; 
    const_cast<int&>(ref_i) = 4; // OK
    cout << i << endl; 
    
	// ����������� ������������ ���������
	int k = 10;
	f(&k); // k ��������� ��� ����������� ��������
    cout << k << endl; 
 
 	// ����������� ���������
    const int j = 3; 
    int* pj = const_cast<int*>(&j);
    *pj = 5; // undefined behavior, �� ���� ��� ������
    cout << *pj << " " << j << endl; // j �� ��������� ��-�� ����������� (����������� ����� �������� 3)
 	
 	// --- reinterpret_cast ---
 	
 	// ����������� const double � const-������ �� long long
 	const double x = 1.112233;
 	const long long& y = reinterpret_cast<const long long&>( x );
 	cout << y << endl; // ��������� �����
 	
 	// ����������� ����� ��������� �� int*
 	struct { int a; } s1 = {5};
 	cout << s1.a <<  endl; 
	int* val = reinterpret_cast<int*>(&s1);
	*val = 10;
	cout << *val << " " << s1.a <<  endl; 
 	
	return 0;
}

