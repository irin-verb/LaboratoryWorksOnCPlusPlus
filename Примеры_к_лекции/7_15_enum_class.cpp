#include <iostream> 
#include <strings.h>

using namespace std;

enum Fruits
{
    LEMON, KIWI
};
 
enum Colors
{
    PINK, GRAY
};
    

int main(int argc, char** argv) 
{
	system("chcp 1251");

    Fruits fruit = LEMON; // LEMON ��������� � ���������� ������� ���������
    Colors color = PINK;  // PINK ��������� � ���������� ������� ���������

    if (fruit == color) // ��������� ����� �����! [Warning] comparison between 'enum Fruits' and 'enum Colors' [-Wenum-compare]
        cout << "����������" << endl;
    else
        cout << "������" << endl;

	return 0;
}

