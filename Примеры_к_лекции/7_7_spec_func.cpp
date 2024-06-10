#include <iostream> 
#include <strings.h>

using namespace std;

//����� TheValue ������ ������������� �����-�� �������� � ����� ��� ������� � �������
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

    
/* ���� �� ����� ���������������� ������� ������ ��������
   ��� ������ ���� double � ���������������� �����, �� ������
   ���� ���������������� ������, �.�. ���� ������� ����������
   ������� print, ���� ��� � => double
   ����������� ����������� ��� ������.
*/ 
//template <> 
//void TheValue<double>::print()
//{
//    cout << scientific << value << endl;
//}


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	//�������������� ��������
	TheValue<int> theInt(42);
	TheValue<double> theDouble(5.5555);
	
	//�������
	theInt.print();
	theDouble.print(); // ��� ������������� ������� ����� ����� � ����. �����
	
	/*
		� ������ ������� �� ���������������� �������-����� ������, ������ ����������
		����� ���������������� ������� �������.
	*/

	
	return 0;
}

