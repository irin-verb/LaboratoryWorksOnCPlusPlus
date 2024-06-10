#include <iostream> 
#include <strings.h>

using namespace std;

//класс статического массива из примера 7.6 
template <class T, int size> 
class StaticArray
{
    T array[size]; 
 
public:
	
    T& operator[](int index)
    {
        return array[index];
    }
    
    // геттеры для const и не-const случая прямого доступа к данным массива через указатель
    const T* getData() const { return array; }
    T* getData() { return array; }
};

//функция выводит все элементы StaticArray через пробел
template <class T, int size>
void print(const StaticArray<T,size>& array)
{
    for (int i=0; i < size; ++i)
        cout << array.getData()[i] << " ";
    cout << endl;
}

/*
	А что если нам надо выводить строки? Если мы воспользуемся реализацией по-умолчанию
	то все буквы строки выведутся через пробел. Если мы введём полную специализацию - 
	необходимо будет указывать и размер строки, что накладывает ограничение на класс.
	Выход: использовать частичную специализацию шаблона, когда параметр T определяется 
	как char, а параметр size остаётся изменяемым.	
*/
 
/*
template <int size> // параметр size остаётся изменяемым
void print(const StaticArray<char,size>& array) // в то время как T => char
{
    for (int i=0; i < size; ++i)
        cout << array.getData()[i];
    cout << endl;
}
//
*/
int main(int argc, char** argv) 
{
	system("chcp 1251");
	
    // Объявляем целочисленный статический массив из 10 элементов
    StaticArray<int, 10> intArray;
 
    // Заполняем массив значениями
    for (int i=0; i < 10; ++i)
        intArray[i] = i * i;
 
    // Выводим элементы массива 
    print(intArray);

    // Объявляем статический массив - строку
    StaticArray<char, 5> myString;
    
    //записываем в него значения
    strcpy(myString.getData(),"HELLO");
   
    //выводим
    print(myString); //без частичной специализации будет вывод через пробелы
    
    /*
    	К сожалению, частично специализировать можно только шаблоны всего класса. 
		Частично специализировать отдельные методы классов или отдельные функции нельзя.
		
		Наш пример работает только потому, что функция print принимает в качестве параметра
		шаблонный класс, и именно его мы частично специализируем.
    */
    
	return 0;
}

