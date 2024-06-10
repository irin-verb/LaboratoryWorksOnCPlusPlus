#include <iostream> 
#include <strings.h>

using namespace std;


// StaticArray - ����������� ������ �� size ��������� ���� T
template <class T, int size> // non-type �������� size - ��� �� ���, � ���������� ��������
class StaticArray
{
    T array[size];  //����� ������ ������������ ������� ����� non-type �������� size
 
public:
	
    T& operator[](int index)
    {
        return array[index];
    }
};

int main(int argc, char** argv) 
{
	system("chcp 1251");

    // ��������� ������������� ����������� ������ �� 10 ���������
    StaticArray<int, 10> intArray;
 
    // ��������� ������ ����������
    for (int i=0; i < 10; ++i)
        intArray[i] = i * i;
 
    // ������� �������� ������� 
    for (int i=0; i < 10; ++i)
        cout << intArray[i] << " ";
    cout << endl;
 
    // ��������� ����������� ������ ���� double �� 5 ���������
    StaticArray<double, 5> doubleArray;
 
    // ��������� ������ ����������
    for (int i=0; i < 5; ++i)
        doubleArray[i] = 1.1 + 0.1 * i;
 
    // ������� �������� ������� 
    for (int i=0; i < 5; ++i)
        cout << doubleArray[i] << ' ';
    cout << endl;

	return 0;
}

