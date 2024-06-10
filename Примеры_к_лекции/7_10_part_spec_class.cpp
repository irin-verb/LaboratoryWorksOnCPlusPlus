#include <iostream> 
#include <strings.h>

using namespace std;

// ���� �� ����� print ������� ������� ������ StaticArray � �������� ����������������
// ���, �� ��� ������� ��������� ����������� �����, ��� ������� � �������� ����������
// ������������ ����:

/*
// ����� � ����� ��������
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

//����� � ��������� ��������������
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
	������ �� ����� ���������� ��������� ������������, ���
	�������� ������������� ���
*/
//*

// � ������������ ����� ������� ��, ��� �������� ����� ����������
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

//�����-�������� ��� ���������� ��-��������� (�� ��� char)
template <class T, int size> 
class StaticArray: public StaticArrayBase<T,size>
{

};

//��������� ������������� ������ ��� T => char
template <int size> 
class StaticArray<char,size>: public StaticArrayBase<char,size>
{
public:
	
	// �������������� ����� print, ����� �� ��� ����� ������������
	// ���������� �� �������� �� ������ StaticArrayBase.
	void print() override
	{
	    for (int i=0; i < size; ++i)
	        cout << this->array[i];
	    cout << endl;
	}
};

/*
	�������� ��������, ��� � ���������������� print ��������� ��������� ����
	this->array ��� ������� � ���� ������������� ������.
	
	��� ������� � ���, ��� ������� ������� (� ������� �� ������� �������) 
	�� ��������� ����� ��� ����������� ������, � ������ �� ����� �������� ���������� ������� ������ 
	(�.�. � ������ ������� �� ������� StaticArray<char, 5> myString;)

	�� ����� ������� ���� ������ �� �������������, ��������� ������������, ��� ���� �� ����������. ������� �����
	���� ���������� ����������� ��� ��� ���� ������������� ����� ������ ������� ������, ����� ���������������.
*/

//*/

int main(int argc, char** argv) 
{
	//system("chcp 1251");
	
    // ��������� ������������� ����������� ������ �� 10 ���������
    StaticArray<int, 10> intArray;
 
    // ��������� ������ ����������
    for (int i=0; i < 10; ++i)
        intArray[i] = i * i;
 
    // ������� �������� ������� 
    intArray.print();


    // ��������� ����������� ������ - ������
    StaticArray<char, 5> myString;
    
    //���������� � ���� ��������
    strcpy(myString.getData(),"HELLO");
   
    //�������
    myString.print(); //��� ��������� ������������� ����� ����� ����� �������

    
	return 0;
}

