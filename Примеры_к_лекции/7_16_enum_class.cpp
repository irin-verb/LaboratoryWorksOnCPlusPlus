#include <iostream> 
#include <strings.h>

using namespace std;

enum class Fruits
{
    LEMON, KIWI
};
 
enum class Colors
{
    PINK, GRAY
};
    
// перегрузка оператора << класса ostream для Colors
// для вывода в стандартном потоке вывода
ostream& operator<<(ostream& os, const Colors& t) { 
	switch (t) {
		case Colors::PINK: {
			return os << "PINK";
			break;
		}
		case Colors::GRAY: {
			return os << "GRAY";
			break;
		}
	}
}

int main(int argc, char** argv) 
{
	system("chcp 1251");
	Colors t1 = Colors::PINK;
	cout << t1 << " rghhth" << endl;
	// напрямую LEMON не доступен (локальная область видимости), должен использоваться Fruits::LEMON
    Fruits fruit = Fruits::LEMON; 
    Fruits fruit2 = Fruits::KIWI; 
    Colors color = Colors::PINK; 

//    if (fruit == color) // Ошибка, компилятор не будет сравнивать два несовместимых enum class-а
//        cout << "одинаковое" << endl;
//    else
//        cout << "разное" << endl;
        
    if (fruit == fruit2) // так сравнение произойдёт, т.к. тип совпадает
        cout << "одинаковое" << endl;
    else
        cout << "разное" << endl;
        
	return 0;
}

