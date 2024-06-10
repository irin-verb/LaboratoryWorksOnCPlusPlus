#include <iostream> 
#include <memory>

using namespace std;

/*
	shared_ptr ����� ������� ��������� ��� "�����������" �����������,
	����� ����� ���������, ��������, ���������� ������������ �����:
*/


class Human
{
	string name;
	shared_ptr<Human> partner; 
 
public:
		
	Human(const string& name): name(name)
	{ 
		cout << name << " ������!" << endl; 
	}
	~Human()
	{
		cout << name << " ���������!" << endl; 
	}
 
	friend bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2);
};
 
 
bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2)
{
	if (!h1 || !h2)
		return false;

	h1->partner = h2;
	h2->partner = h1;

	cout << h1->name << " �������� ��������� " << h2->name << endl;

	return true;
}


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	auto ivan = std::make_shared<Human>("����"); 
	auto vlad = std::make_shared<Human>("��������"); 
 
	partnerUp(vlad, ivan); // ������ ������������ �����
	
	// ...
	// ������� ������� �� ����� ��-�� ����������� �����������!
	// ...
	
	return 0;
}

