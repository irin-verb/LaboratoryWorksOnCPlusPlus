#include <iostream> 
#include <strings.h>
#include <stdlib.h>
using namespace std;

/*
	����� ���������������� ������� �� ������ ��������� �������, 
	�� � ������� ������� � �����.
*/

// ����� TheValue �� ����������� �������
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
        cout << value << endl;
    }
};

// ������������� ��� double
template <> 
void TheValue<double>::print()
{
    cout << scientific << value << endl;
}


/*
	� ���, ���� �� ������� ��������������� �� ��������,
	� ��������� �� ������ (char*)? � ���������� �� ���������
	������ ������ ��������� ���������, � ��� ����� ������� ����� ������.
*/


template <> //���������� ������� ������� �������������� ������ ����� ������
class TheValue<char*> //��������� ��� ������ ������� �������������
{
private:
    char* value = nullptr;
public:
    TheValue(const char* value)
    {
        if(value)
        {
    		//���������� ����� ��������� ������ � �������� ��� ��� ������
        	int len = strlen(value);
	        this->value = new char[len];
	        //������ ����� ��������� ������
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
    	if(value)
        	cout << value << endl;
        else
        	cout << "��� ��������" << endl;
    }
};
//*/

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	//�������������� ��������
	TheValue<int> theInt(42);
	TheValue<double> theDouble(5.5555);
	
	//�������
	theInt.print();
	theDouble.print(); // ��� ������������� ������� ����� ����� � ����. �����
	
	
	// � ��� ���� ��� ���� ��������������� �������� ������?
	
	//�������� ������ � ��������� ������
	char* str = new char[128];
	strcpy(str, "������ ������");
	
	//������������� �������� ������
	TheValue<char*> theString(str);
	
	// ������� ������!
	delete[] str;
	
	// ��� ������������� ������ ������� ����� � ������
	theString.print();


	/*
		������� �� ����� �� ������� ��������� ����� TheStringValue ��� ������������
		�����. ������ ����� ������������ ����� ���� �� ������ �������, ��� ��� ����� �����
		������������ ��������� ����� TheStringValue, � ������ TheValue<T> ������������
		������. ��� ����� ��������� � �������. 
	*/
	
	return 0;
}

