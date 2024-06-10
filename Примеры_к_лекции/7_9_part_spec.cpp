#include <iostream> 
#include <strings.h>

using namespace std;

//����� ������������ ������� �� ������� 7.6 
template <class T, int size> 
class StaticArray
{
    T array[size]; 
 
public:
	
    T& operator[](int index)
    {
        return array[index];
    }
    
    // ������� ��� const � ��-const ������ ������� ������� � ������ ������� ����� ���������
    const T* getData() const { return array; }
    T* getData() { return array; }
};

//������� ������� ��� �������� StaticArray ����� ������
template <class T, int size>
void print(const StaticArray<T,size>& array)
{
    for (int i=0; i < size; ++i)
        cout << array.getData()[i] << " ";
    cout << endl;
}

/*
	� ��� ���� ��� ���� �������� ������? ���� �� ������������� ����������� ��-���������
	�� ��� ����� ������ ��������� ����� ������. ���� �� ����� ������ ������������� - 
	���������� ����� ��������� � ������ ������, ��� ����������� ����������� �� �����.
	�����: ������������ ��������� ������������� �������, ����� �������� T ������������ 
	��� char, � �������� size ������� ����������.	
*/
 
/*
template <int size> // �������� size ������� ����������
void print(const StaticArray<char,size>& array) // � �� ����� ��� T => char
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
	
    // ��������� ������������� ����������� ������ �� 10 ���������
    StaticArray<int, 10> intArray;
 
    // ��������� ������ ����������
    for (int i=0; i < 10; ++i)
        intArray[i] = i * i;
 
    // ������� �������� ������� 
    print(intArray);

    // ��������� ����������� ������ - ������
    StaticArray<char, 5> myString;
    
    //���������� � ���� ��������
    strcpy(myString.getData(),"HELLO");
   
    //�������
    print(myString); //��� ��������� ������������� ����� ����� ����� �������
    
    /*
    	� ���������, �������� ���������������� ����� ������ ������� ����� ������. 
		�������� ���������������� ��������� ������ ������� ��� ��������� ������� ������.
		
		��� ������ �������� ������ ������, ��� ������� print ��������� � �������� ���������
		��������� �����, � ������ ��� �� �������� ��������������.
    */
    
	return 0;
}

