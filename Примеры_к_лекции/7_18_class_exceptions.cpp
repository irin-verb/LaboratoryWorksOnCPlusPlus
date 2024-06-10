#include <iostream> 
#include <strings.h>

using namespace std;


// класс-исключений общего назначения
class Exception
{
	const char* info;
	
public:
	
	Exception(const char* info) : info(info)
	{
	}
	
	const char* getInfo() { return info; }	
};

//класс-исключений для массивов
class ArrayException: public Exception
{
	int data;
public:
	
	ArrayException(const char* info, int data = 0) : Exception(info), data(data)
	{	
	}
	
	int getData() { return data; }
};

// класс реализует динамически-инициализированный массив
template <typename T>
class DynArray
{
	T* array;
	int length;
	
public:
	
	DynArray(int length) : length(length)
	{
		// исключение на неправильный размер массива
		if(length<=0) 
			throw ArrayException("Недопустимый размер массива.", length);
		
		array = new T[length];
		
		if(0) // эмуляция проверки на ошибку
		{
			delete[] array; //не забыть очистить данные, т.к. при выбрасывании исключения
							//в конструкторе деструктор вызван не будет!
			throw Exception("Какая-то ошибка в конструкторе");
		}
		
		for(int i = 0; i < length; ++i) 
			array[i] = rand() % 10;
	}
	
	~DynArray()
	{
		delete[] array;
	}
	
	T& operator[](int index) 
	{ 
		//исключение на неправильный индекс
		if(index<0 || index>=length) 
			throw ArrayException("Индекс вне диапазона.", index);
			
	    return array[index];
	}
	
	void print()
	{
		for(int i = 0; i < length; ++i) 
			cout << array[i] << " ";
		cout << endl;
	}
	
};


int main(int argc, char** argv) 
{
	system("chcp 1251");

	try
	{
		DynArray<int> array(100);
		array[400] = 5;
	}
	catch(ArrayException& e)
	{
		cout << e.getInfo() << " Доп. инфо:" << e.getData() << endl;
	}
	catch(Exception& e)
	{
		cout << e.getInfo() << endl;
	}
	
	return 0;
}

