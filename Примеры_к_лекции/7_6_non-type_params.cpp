#include <iostream> 
#include <strings.h>

using namespace std;


// StaticArray - статический массив из size элементов типа T
template <class T, int size> // non-type параметр size - это не тип, а конкретное значение
class StaticArray
{
    T array[size];  //задаём размер статического массива через non-type параметр size
 
public:
	
    T& operator[](int index)
    {
        return array[index];
    }
};

int main(int argc, char** argv) 
{
	system("chcp 1251");

    // Объявляем целочисленный статический массив из 10 элементов
    StaticArray<int, 10> intArray;
 
    // Заполняем массив значениями
    for (int i=0; i < 10; ++i)
        intArray[i] = i * i;
 
    // Выводим элементы массива 
    for (int i=0; i < 10; ++i)
        cout << intArray[i] << " ";
    cout << endl;
 
    // Объявляем статический массив типа double из 5 элементов
    StaticArray<double, 5> doubleArray;
 
    // Заполняем массив значениями
    for (int i=0; i < 5; ++i)
        doubleArray[i] = 1.1 + 0.1 * i;
 
    // Выводим элементы массива 
    for (int i=0; i < 5; ++i)
        cout << doubleArray[i] << ' ';
    cout << endl;

	return 0;
}

