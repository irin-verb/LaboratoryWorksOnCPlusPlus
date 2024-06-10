#include <iostream> 
#include <strings.h>

using namespace std;

struct Vec3;

// класс реализует динамически-инициализированный массив
template <typename T>
class DynArray
{
	T* array;
	int length;
	
public:
	
	DynArray(int length) : length(length)
	{
		array = new T[length];
		
		//занулим элементы
		for(int i = 0; i < length; ++i) 
			array[i] = 0;
	}
	
	~DynArray()
	{
		delete[] array;
	}
	
	T& operator[](int index) 
	{ 
	    return array[index];
	}
	
	void print();
	
};

// объявление метода вне описания класса-шаблона
template <typename T>
void DynArray<T>::print()
{
	for(int i = 0; i < length; ++i) 
		cout << array[i] << " ";
	cout << endl;
}

struct Vec3
{
	float x = 0, y = 0, z = 0;

	// перегрузка для =
	Vec3& operator=(float value) 
	{ 
		x = y = z = value;
	    return *this;
	}
};

// перегрузка оператора << класса ostream для того чтобы 
// Vec3 можно было выводить в стандартном потоке вывода cout
ostream& operator<<(ostream& os, const Vec3& vec) 
{ 
    return os << " vec: " << vec.x << " " << vec.y << " " << vec.z;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	//работаем с шаблонным DynArray для типа int
	cout << "Шаблон DynArray<int>:" << endl;
	DynArray<int> intArray(10);
	intArray[3] = 999;
	intArray[4] = -100;
	intArray.print();
	
	//работаем с шаблонным DynArray для типа float
	cout << "Шаблон DynArray<float>:" << endl;
	DynArray<float> floatArray(10);
	floatArray[6] = 5.555f;
	floatArray[8] = 0.111f;
	floatArray.print();
	
	//работаем с шаблонным DynArray для типа Vec3
	cout << "Шаблон DynArray<Vec3>:" << endl;
	DynArray<Vec3> vecArray(10);
	vecArray[2] = 0.123f;
	vecArray[5] = 0.456f;
	vecArray.print();
	
	return 0;
}

