#include <iostream> // ����� ��������� ������ ������ �����\������

#define MAX_FIO 128

//*

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	char f[MAX_FIO], i[MAX_FIO], o[MAX_FIO];
	int age;
	std::cout << "��� ��� ����� � ������� ��� ���?" << std::endl;
	std::cin >> f >> i >> o >> age;
	
	std::cout << "��� ����� " << f << " " << i << " " << o << " � ��� " << age << " ���." << std::endl;
	
	return 0;
}

//*/

/*

using namespace std; //using namespace ��������� ������������ ��� ����� � ��� ��� �������� ������������ ����

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	char f[MAX_FIO], i[MAX_FIO], o[MAX_FIO];
	int age;
	cout << "��� ��� ����� � ������� ��� ���?" << endl;
	cin >> f >> i >> o >> age;
	
	cout << "��� ����� " << f << " " << i << " " << o << " � ��� " << age << " ���." << endl;
	
	return 0;
}
//*/
