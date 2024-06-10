#include <iostream> 
#include <strings.h>

using namespace std;


// �����-���������� ������ ����������
class Exception
{
	const char* info;
	
public:
	
	Exception(const char* info) : info(info)
	{
	}
	
	const char* getInfo() { return info; }	
};

//�����-���������� ��� ��������
class ArrayException: public Exception
{
	int data;
public:
	
	ArrayException(const char* info, int data = 0) : Exception(info), data(data)
	{	
	}
	
	int getData() { return data; }
};

// ����� ��������� �����������-������������������ ������
template <typename T>
class DynArray
{
	T* array;
	int length;
	
public:
	
	DynArray(int length) : length(length)
	{
		// ���������� �� ������������ ������ �������
		if(length<=0) 
			throw ArrayException("������������ ������ �������.", length);
		
		array = new T[length];
		
		if(0) // �������� �������� �� ������
		{
			delete[] array; //�� ������ �������� ������, �.�. ��� ������������ ����������
							//� ������������ ���������� ������ �� �����!
			throw Exception("�����-�� ������ � ������������");
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
		//���������� �� ������������ ������
		if(index<0 || index>=length) 
			throw ArrayException("������ ��� ���������.", index);
			
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
		cout << e.getInfo() << " ���. ����:" << e.getData() << endl;
	}
	catch(Exception& e)
	{
		cout << e.getInfo() << endl;
	}
	
	return 0;
}

