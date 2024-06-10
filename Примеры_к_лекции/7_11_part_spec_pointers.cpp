#include <iostream> 
#include <strings.h>

using namespace std;

/*
	� ������� 7.8 �� ���� ���������������� ������ ������ ��� ��������� char*
	�� ��� ���� ��� ���������� ����� �������� � � ������� ������ ����������
	����� int* � �.�.? � ���� ������ ����� ������� ��������� �������������
*/


template <class T>
class TheValue
{
private:
    T value;
public:
    TheValue(const T& value)
    {
         this->value = value;
    }

    void print()
    {
    	cout << "class TheValue<T>::print" << endl;
        cout << value << endl;
    }
};

//���� �������������� ������ ����� ������ ��� char*
template <>
class TheValue<char*> 
{
private:
    char* value = nullptr;
public:
    TheValue(const char* value)
    {
        if(value)
        {
        	int len = strlen(value);
	        this->value = new char[len];

	        strcpy(this->value, value);
	    }
    }
    
    ~TheValue()
    {
    	if(value)
    		delete[] value;
	}

    void print()
    {
    	cout << "class TheValue<char*>::print" << endl;
    	
    	if(value)
        	cout << value << endl;
        else
        	cout << "��� ��������" << endl;
    }
};

// ��������� ������������� ������� ������ TheValue ��� ������ � ������� ������ ����������
template <class T>
class TheValue<T*> 
{
private:
    T* value;
public:
    TheValue(T* value) // T - ��� ���������
    {
    	if(value)
    	{
	         this->value = new T(*value);  // ����� ���������� ����������� �����
     	}
    }
 
    ~TheValue()
    {
    	if(value)
        	delete value; 
    }
 
    void print()
    {
    	cout << "class TheValue<T*>::print" << endl;
    	
    	if(value)
        	cout << *value << endl;
        else
        	cout << "��� ��������" << endl;
    }
};

int main(int argc, char** argv) 
{
	system("chcp 1251");

	//�������� ����� ������ TheValue<T>
	TheValue<int> theInt(42);
	theInt.print();
	
	//�������� ������������������ ������ TheValue<char*>
	char* str = new char[128];
	strcpy(str, "������ ������");
	TheValue<char*> theString(str);
	
	delete[] str; // ������� ������!

	theString.print();
	
	//�������� �������� ������������������ ������ ��� ���������� TheValue<T*>
	int* val = new int;
	*val = 5;
	TheValue<int*> theIntPtr(val);
	
	delete val; // ������� ����������!

	theIntPtr.print(); // �������� �����������

	
	return 0;
}

