#include <iostream> 
#include <strings.h>

using namespace std;

/*
	DataPtrArray - контейнер-ссылки  для динамического массива указателей типа Data
	это модификация контейнера-значений из предыдущего примера. Мы бы могли использовать
	указатели на float*, но это не так интересно, поэтому придумаем некоторую структуру
	Data из 3 float-ов.
*/

//структура, которую мы будем хранить ввиде указателей в контейнере
struct Data
{
	float a,b,c;	
};

class DataPtrArray
{
	Data** data; // теперь мы храним массив указателей!
	int length = 0;
	
	//увеличиваем или уменьшаем массив с сохранением данных
	void realloc(int newLength)
	{
		if(newLength == length) return;
		
		//создаём в памяти массив указателей нового размера
		Data** newData = new Data*[newLength];
		
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
		
	DataPtrArray(int length = 0)
	{
		realloc(length);
	}
	
	~DataPtrArray()
	{
		clear(); //не забываем очистить память в деструкторе
	}
	
	// добавляем элемент в массив на место pos.
	// если pos < 0, то в конец массива
	DataPtrArray& add(Data* elem, int pos = -1)
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
	DataPtrArray& remove(int pos = -1)
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
	DataPtrArray& clear()
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
		return length * sizeof(Data*); 
	}
	

	
	//т.к. у нас элементы сложного типа, возвращаем их по ссылке
	const Data& operator[](int id) const
	{
		return *data[id];
	}
	Data& operator[](int id)
	{
		return *data[id];
	}
};

//перегружаем оператор для вывода в консоль также и для структуры Data
ostream& operator<< (ostream &out, const Data& data)
{
	out << "Data[" << data.a << "," << data.b << "," << data.c << "] "; 
}

ostream& operator<< (ostream &out, const DataPtrArray& array)
{
    out << "DataPtrArray["<< array.getLength() << "]:" << endl;
    
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

	DataPtrArray arr;

	//добавляем указатели на элементы (сами данные мы можем создать и динамически, через new)
	//т.к. в массиве мы храним только указатели, то ему всё равно как управляется память 
	//для его элементов
	Data dataArr[] = {{1.11f,2.11f,3.11f},{1.22f,2.22f,3.22f},{1.33f,2.33f,3.33f}};
	arr.add(dataArr).add(dataArr + 1).add(dataArr + 2);
	cout << arr << endl;
	
	//удаляем элемент с индексом 1
	arr.remove(1);
	cout << arr << endl;
	
	//очищаем массив
	arr.clear();
	cout << arr << endl;

	
	return 0;
}

