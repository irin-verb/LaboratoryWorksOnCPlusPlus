#include <iostream> 
#include <memory>

using namespace std;

/*
   ����� ��������� weak_ptr ��� ���������� ��� ������� �������� ������������ �����������, 
   weak_ptr �������� ������������ � �� ����� ��������� � �������� ������ � ���� �� �������, 
   �� ������� ��������� shared_ptr (��� ������ weak_ptr), �� �� ��������� ���������� ����� �������. 
   ����� shared_ptr ������� �� ������� ���������, �� ���������, ���� �� ������ ��������� shared_ptr. 
   weak_ptr ���������� �� ���������!
*/

class Human
{
	string name;
	
	// ��� ������������ weak_ptr, � ��� ��������� �� ����������� ��� �������� ������
	weak_ptr<Human> partner; 
 
public:
		
	Human(const string& name): name(name)
	{ 
		cout << name << " ������!" << endl; 
	}
	~Human()
	{
		cout << name << " ���������!" << endl; 
	}
	
	/*
		����������� weak_ptr �������� ��, ��� ��� ������ ������������ �������� (��� ��������� ->). 
		����� ������������ weak_ptr, ������� ����� �������������� ��� � shared_ptr � ������� lock(), 
		� ����� ��� ������������ ��� shared_ptr. 
	*/
	const shared_ptr<Human> getPartner() const 
	{ 
		return partner.lock(); 
	} 
	
	const string& getName() const { return name; }
 
	friend bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2);
};
 
 
bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2)
{
	if (!h1 || !h2)
		return false;

	h1->partner = h2;
	h2->partner = h1;
	
	return true;
}


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	auto ivan = std::make_shared<Human>("����"); 
	auto vlad = std::make_shared<Human>("��������"); 
 
	partnerUp(vlad, ivan); // ������ ������������� �����
	
	auto partner = ivan->getPartner(); // �������� partner-� ���������� ������ ���������, ������� ������� ivan
	cout << ivan->getName() << " ��������� � ����������� � " << partner->getName() << endl;

	// ������ ������� ����� �������!

	
	return 0;
}

