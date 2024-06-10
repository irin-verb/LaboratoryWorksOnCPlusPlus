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
	
	// модификация константной ссылки
	int i = 3;
    const int& ref_i = i; 
    const_cast<int&>(ref_i) = 4; // OK
    cout << i << endl; 
    
	// модификация константного указателя
	int k = 10;
	f(&k); // k передаётся как константный параметр
    cout << k << endl; 
 
 	// модификация константы
    const int j = 3; 
    int* pj = const_cast<int*>(&j);
    *pj = 5; // undefined behavior, не надо так делать
    cout << *pj << " " << j << endl; // j не поменялся из-за оптимизации (подставлено сразу значение 3)
 	
 	// --- reinterpret_cast ---
 	
 	// преобразуем const double в const-ссылку на long long
 	const double x = 1.112233;
 	const long long& y = reinterpret_cast<const long long&>( x );
 	cout << y << endl; // выводится мусор
 	
 	// преобразуем адрес структуры на int*
 	struct { int a; } s1 = {5};
 	cout << s1.a <<  endl; 
	int* val = reinterpret_cast<int*>(&s1);
	*val = 10;
	cout << *val << " " << s1.a <<  endl; 
 	
	return 0;
}

