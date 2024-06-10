#include <iostream> 
#include <math.h>
#include <cstring>
#include <time.h>
#include <stdlib.h>

using namespace std;

/*Класс RndData хранит случайную последовательность
чисел с плавающей точкой в заданном диапазоне*/
class RndData
{
	float* data = nullptr;
	int len = 0;
	
	
	void toZero()
	{
		if(!isEmpty())
			memset(data, 0, len * sizeof(float));
	}
	
	
	bool alloc(int num)
	{
		if(num <= 0) return false;
		
		//если массив пустой - выделяем память, иначе - изменяем размер
		if(isEmpty())
			data = (float*) malloc(num * sizeof(float));
		else
			if(num != len)
				data = (float*) realloc(data,num);
		
		if(!data) return false;
		
		len = num;
		
		toZero();
		
		return true;
	}
	
public:
	
	RndData()
	{
		
	}
	
	//конструктор копирования выделяет память и копирует данные в объект
	/*RndData(const RndData& otherData)
	{
		cout<<endl<<"copy ctor!"<<endl;
		
		alloc(otherData.len);
		
		memcpy(data,otherData.data, otherData.len * sizeof(float));
	}*/
	
	RndData(int num, float min, float max)
	{
		generate(num, min, max);
	}
	
	~RndData()
	{
		clear();
	}
	
	bool generate(int num, float min, float max)
	{
		if(!alloc(num))
			return false;
		
		for(int i=0; i<len; ++i)
			data[i] = (float) rand() / RAND_MAX * (max - min) + min;
			
		return true;
	}
	
	void clear()
	{	
		if(data)
		{
			//не нужно, но занулим буффер для примера порчи данных другого объекта
			toZero();
			
			free(data);
			data = nullptr;
		}
		len = 0;
	}
	
	int getLength() { return len; }
	
	int isEmpty() { return len == 0; }
	
	
	void print(const char* label)
	{		
		cout << endl << label << endl;
		
		if(isEmpty())
		{
			cout << "Нет данных!" << endl; 
			return;
		}

		for(int i=0; i<len; ++i)
			cout << "[" << i << "]=" << data[i] << endl;
	}
	
};

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	srand(time(0));
	
	RndData data1;
	data1.print("Data1:");
	
	data1.generate(10,-10.0f,10.0f);
	data1.print("Data1:");
	
	cout << endl << "RndData data2 = data1"<<endl;
	RndData data2 = data1;
	data1.print("Data1:");
	data2.print("Data2:");
	
	cout << endl << "очищаем data1..."<<endl;
	data1.clear();
	data1.print("Data1:");
	data2.print("Data2:");
	
	return 0;
}

