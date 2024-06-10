#include <iostream> 
#include <strings.h>

using namespace std;

enum Fruits
{
    LEMON, KIWI
};
 
enum Colors
{
    PINK, GRAY
};
    

int main(int argc, char** argv) 
{
	system("chcp 1251");

    Fruits fruit = LEMON; // LEMON находятся в глобальной области видимости
    Colors color = PINK;  // PINK находятся в глобальной области видимости

    if (fruit == color) // Сравнение целых чисел! [Warning] comparison between 'enum Fruits' and 'enum Colors' [-Wenum-compare]
        cout << "одинаковое" << endl;
    else
        cout << "разное" << endl;

	return 0;
}

