#include <iostream> 
#include <strings.h>
#include <stdlib.h>

using namespace std;

// � ������ Object ������� ������� ���-�� �������� �����������
// � ����� ������������� ���������� ������
class Object
{
	static int nextId; // ��������� ������������� �����
	static int curAlive; //������� ���-�� ����������� ������� ������
	
	int id;
public:
		
	Object() 
	{
		id = nextId++;
		++curAlive;
	}
	
	~Object() 
	{
		--curAlive;
	}
	
	void print()
	{
		cout << "������ �" << id << endl;
	}
	
	//����������� ����� ������� ���������� �� ���-�� �������� ������
	static void printTotalInfo()
	{
		cout << "���� ������� " << nextId - 1 << " ��������. ������ �������:" << curAlive << endl;
	}
};

//����������� ���� ����� ���������������� ������ ����� �������:
int Object::nextId = 1;
int Object::curAlive = 0;

int main(int argc, char** argv) 
{
	system("chcp 1251");

	//������ 3 ������� � ��������� ������� ��������� ������� main
	Object obj1, obj2, obj3;
	obj2.print();
	Object::printTotalInfo();
	
	{ // ������ ��� 3 ������� � ����� ��������� �������
		Object obj4, obj5, obj6;
		obj5.print();
		Object::printTotalInfo();
	} // ����� ������� obj4, obj5, obj6 ����� ����������
	
	Object::printTotalInfo();
	
	return 0;
}

