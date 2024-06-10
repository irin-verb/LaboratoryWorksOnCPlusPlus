#include <iostream> 
#include <memory>

using namespace std;


// ����� ��� �������� ������ ������ ���������
class MyClass
{
	string name;
public:
    MyClass(const string& name) : name(name) 
	{ 
		cout << name << " ������!" << endl; 
	}
	
    ~MyClass() 
	{ 
		cout << name << " ���������!" << endl; 
	}
	
	void sayMyName() const
	{
		cout << "�� ��� " << name << "!" << endl;
	}
};

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	//shared_ptr ������������ ��� �������, ����� ��������� ����� ���������� ��������� 
	//������� ����� ����������� ���������� ��������.
	MyClass* obj1 = new MyClass(string("������ 1"));
	shared_ptr<MyClass> obj1Ptr1(obj1);
	obj1Ptr1->sayMyName();
	
	{
		// ����� ������������ ���������� �������������
		shared_ptr<MyClass> obj1Ptr2(obj1Ptr1);
		obj1Ptr2->sayMyName();
		
		// �� ������ ��������� ����� shared_ptr �� ��� ������������ ���������
		// �.�. ��� ����� ��������� ��� ������ ���������!
		// ������ ����� ��������� ����������� ��� ������������� shared_ptr
		
		//shared_ptr<MyClass> obj1Ptr3(obj1); //error!
	}
	obj1Ptr1->sayMyName();
	
	// ���������� make_unique() ���� ������� make_shared(), ������� ��������� � �++11
	auto obj2Ptr1 = make_shared<MyClass>(string("������ 2"));
	{
		auto obj2Ptr2 = obj2Ptr1; // ������� obj2Ptr2 �� obj2Ptr1, ��������� ��������� �����������
	} 

	/*
		unique_ptr ����� ���� ������������� � shared_ptr ����� ����������� �����������, 
		����������� unique_ptr. 

		������ shared_ptr ������ ��������� �������������� � unique_ptr. �������, ���� 
		���������� ������� �������, ������� ����� ���������� ����� ���������, ����� ���������� 
		unique_ptr � ����� ����������� ��� shared_ptr, ����� ��� ����� �������.
	*/
	
	return 0;
}

