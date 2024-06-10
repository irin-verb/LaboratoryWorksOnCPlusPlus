#include <iostream> 
#include <strings.h>

using namespace std;

enum class Fruits
{
    LEMON, KIWI
};
 
enum class Colors
{
    PINK, GRAY
};
    
// ���������� ��������� << ������ ostream ��� Colors
// ��� ������ � ����������� ������ ������
ostream& operator<<(ostream& os, const Colors& t) { 
	switch (t) {
		case Colors::PINK: {
			return os << "PINK";
			break;
		}
		case Colors::GRAY: {
			return os << "GRAY";
			break;
		}
	}
}

int main(int argc, char** argv) 
{
	system("chcp 1251");
	Colors t1 = Colors::PINK;
	cout << t1 << " rghhth" << endl;
	// �������� LEMON �� �������� (��������� ������� ���������), ������ �������������� Fruits::LEMON
    Fruits fruit = Fruits::LEMON; 
    Fruits fruit2 = Fruits::KIWI; 
    Colors color = Colors::PINK; 

//    if (fruit == color) // ������, ���������� �� ����� ���������� ��� ������������� enum class-�
//        cout << "����������" << endl;
//    else
//        cout << "������" << endl;
        
    if (fruit == fruit2) // ��� ��������� ���������, �.�. ��� ���������
        cout << "����������" << endl;
    else
        cout << "������" << endl;
        
	return 0;
}

