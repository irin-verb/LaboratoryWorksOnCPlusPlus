#include <iostream> 
#include <strings.h>

using namespace std;

// если мы хотим print сделать методом класса StaticArray и частично специализировать
// его, то нам придётся полностью дублировать класс, что приведёт к большому количеству
// повторяемого кода:

/*
// класс с общим шаблоном
template <class T, int size> 
class StaticArray
{
    T array[size]; 
 
public:
	
    T& operator[](int index)
    {
        return array[index];
    }

    const T* getData() const { return array; }
    T* getData() { return array; }
    
	void print()
	{
	    for (int i=0; i < size; ++i)
	        cout << array[i] << " ";
	    cout << endl;
	}
};

//класс с частичной специализацией
template <int size> 
class StaticArray<char, size>
{
    char array[size]; 
 
public:
	
    char& operator[](int index)
    {
        return array[index];
    }

    const char* getData() const { return array; }
    char* getData() { return array; }
    
	void print()
	{
	    for (int i=0; i < size; ++i)
	        cout << array[i];
	    cout << endl;
	}
};
//*/

/*
	Однако мы можем попытаться применить наследование, что
	сократит повторяющийся код
*/
//*

// в родительский класс выносим всё, что касается общей реализации
template <class T, int size> 
class StaticArrayBase
{
protected:
	
    T array[size]; 
 
public:
	
    T& operator[](int index)
    {
        return array[index];
    }

    const T* getData() const { return array; }
    T* getData() { return array; }
    
	virtual void print()
	{
	    for (int i=0; i < size; ++i)
	        cout << array[i] << " ";
	    cout << endl;
	}
};

//класс-заглушка для реализации по-умолчанию (не для char)
template <class T, int size> 
class StaticArray: public StaticArrayBase<T,size>
{

};

//частичная специализация класса для T => char
template <int size> 
class StaticArray<char,size>: public StaticArrayBase<char,size>
{
public:
	
	// переопределяем метод print, чтобы он мог иметь отличающуюся
	// реализацию от базового из класса StaticArrayBase.
	void print() override
	{
	    for (int i=0; i < size; ++i)
	        cout << this->array[i];
	    cout << endl;
	}
};

/*
	Обратите внимание, что в переопределенном print требуется указывать явно
	this->array для доступа к полю родительского класса.
	
	Это связано с тем, что шаблоны классов (в отличии от обычных классов) 
	не создается сразу при определении класса, а только во время создания экземпляра шаблона класса 
	(т.е. в данном примере на строчке StaticArray<char, 5> myString;)

	До этого момента пока шаблон не инстанцирован, отношения наследования, для него не существует. Поэтому нужно
	явно подсказать компилятору что эти поля действительно будут полями данного класса, после инстанцирования.
*/

//*/

int main(int argc, char** argv) 
{
	//system("chcp 1251");
	
    // Объявляем целочисленный статический массив из 10 элементов
    StaticArray<int, 10> intArray;
 
    // Заполняем массив значениями
    for (int i=0; i < 10; ++i)
        intArray[i] = i * i;
 
    // Выводим элементы массива 
    intArray.print();


    // Объявляем статический массив - строку
    StaticArray<char, 5> myString;
    
    //записываем в него значения
    strcpy(myString.getData(),"HELLO");
   
    //выводим
    myString.print(); //без частичной специализации будет вывод через пробелы

    
	return 0;
}

