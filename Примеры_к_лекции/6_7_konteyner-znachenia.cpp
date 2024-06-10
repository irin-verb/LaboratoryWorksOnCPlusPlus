#include <iostream> 
#include <strings.h>

using namespace std;

/*
	FloatArray - контейнер-значения  для динамического массива типа float
	в отличии от предыдущих примеров не использует резервирование памяти
	под будущие аллокации и может уменьшаться (не эффективно по производительности
	но эффективно по занимаемой памяти). 
*/

class FloatArray
{
	float* data;
	int length = 0;
	
	//увеличиваем или уменьшаем массив с сохранением данных
	void realloc(int newLength)
	{
		if(newLength == length) return;
		
		//создаём в памяти массив нового размера
		float* newData = new float[newLength];
		
		//переписываем данные в новый массив
		int minLength = min(length, newLength);
		for(int i = 0; i < minLength; ++i)
			newData[i] = data[i];
			
		// очищаем старый массив
		if(length)
			delete[] data;
		
		//переписываем указатель и запоминаем новый размер
		data = newData;	
		length = newLength;
	}
	
public:
		
	FloatArray(int length = 0)
	{
		realloc(length);
	}
	
	~FloatArray()
	{
		clear(); //не забываем очистить память в деструкторе
	}
	
	// добавляем элемент в массив на место pos.
	// если pos < 0, то в конец массива
	FloatArray& add(float elem, int pos = -1)
	{
		pos = pos < 0 ? length : pos;
		
		//сначала увеличиваем массив
		realloc(length + 1);
		
		//затем сдвигаем элементы вправо от pos
		for(int i = length - 2; i >= pos; ++i)
			data[i+1] = data[i];
			
		//вставляем элемент на нужное место
		data[pos] = elem;
		
		return *this; // хотим делать цепочки вызовов методов
	}
	
	// удаляем элемент на месте pos.
	// если pos < 0, то удаляем последний элемент
	FloatArray& remove(int pos = -1)
	{
		pos = pos < 0 ? length - 1 : pos;

		//сначала затираем элемент pos, сдвигая элементы влево
		for(int i = pos; i < length - 1; ++i)
			data[i] = data[i + 1];
			
		//уменьшаем массив
		realloc(length - 1);
		
		return *this;  // хотим делать цепочки вызовов методов
	}
	
	//очистка массива
	FloatArray& clear()
	{
		if(length)
			delete[] data;
			
		length = 0;
		data = nullptr;
		
		return *this; // хотим делать цепочки вызовов методов
	}
	
	int getLength() const { return length; }
	bool isEmpty() const { return length == 0; }
	
	//размер занимаемый массивом в байтах 
	int getSizeInBytes() const 
	{ 
		return length * sizeof(float); 
	}
	

	
	//т.к. у нас элементы простого типа, можно возвращать их по значению
	float operator[](int id) const
	{
		return data[id];
	}
};

//friend не нужен, т.к. действуем через public интерфейс
ostream& operator<< (ostream &out, const FloatArray& array)
{
    out << "FloatArray["<< array.getLength() << "]:" << endl;
    
    if(array.isEmpty())
    {
    	out << "массив пустой!";
	}
	else
	{
	    for(int i=0; i < array.getLength(); ++i)
		 out << array[i] << " ";
	}
	
	out << "---> Всего " << array.getSizeInBytes() << " байт." << endl;
	
    return out;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	FloatArray arr;

	//добавляем элементы
	arr.add(5.0f).add(1.4f).add(5.8f).add(8.3f).add(9.9f).add(3.4f);
	cout << arr << endl;
	
	//удаляем сначала последний элемент, затем с индексом 2
	arr.remove().remove(2);
	cout << arr << endl;
	
	//очищаем массив
	arr.clear();
	cout << arr << endl;
	
	return 0;
}

