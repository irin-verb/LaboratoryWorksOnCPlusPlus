#include <iostream> 

using namespace std;


 
template<class T>
class SmartPtr
{
	T* ptr;
public:
	// �������� ��������� ��� "��������" ����� �����������
	// SmartPtr ������ ����� �������������� ����� � ptr �
	// ��������� ��������� �������� ������ ������� ���������
	SmartPtr(T* ptr=nullptr)
		:ptr(ptr)
	{
	}
	
	// ���������� ����������� �� �������� ���������
	~SmartPtr()
	{
		delete ptr;
	}
 
	// ��������� ���������� ��������� ������������� � ��������� ->, 
	// ����� ����� ����������� ������������ SmartPtr ��� ������� ��������� 
	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
	
	/*
	// ����������� �����������, ������� ��������� ��������� �����������
	SmartPtr(SmartPtr& a) // ������ �� �������� �����������!
	{
		ptr = a.ptr; // ���������� ��������� �� ��������� � ��������
		a.ptr = nullptr; // �������� ������ �� ������� ����������
	}
	
	// �������� ������������, ������� ������������� ��������� �����������
	SmartPtr& operator=(SmartPtr& a) // ����������: ������ �� �������� �����������
	{
		if (&a == this)
			return *this;
 
		delete ptr; // ������� ����� ���������, ������� ��� ������ ���� �� �����
		ptr = a.ptr; // ���������� ��������� �� ��������� � ��������
		a.ptr = nullptr; // �������� ������ �� ������� ����������
		return *this;
	}
	//*/
};
 
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
};
 

/* 
�� ��������� ����������� ����� ��������� ������������� �����������
������ ����� �������� ��������� �� �������� ��������� ����������� ������� obj1 � param
� ������������� ��� ����� ��������� �� ���� � �� �� ����� � ������.
����� ������ param �� ������� ��������� �� ������� ���������, �� ����� ����������
��� obj1 � ���� ������� ����� ������� ��� ��������� param ������, � ���������
������!
*/
void smartPtrByValue(SmartPtr<MyClass> param)
{
} // ����� param ����� �����!
 
int main(int argc, char** argv)
{
	system("chcp 1251");

	SmartPtr<MyClass> obj1(new MyClass(string("������ 1")));
	smartPtrByValue(obj1);
	
	
	/*
	�� �� �������� ��������� ��� ����������� �� �������� �� �������.
	�� �� ����� ������� SmartPtr �� ������, �.�. ��������� ������
	����� ��������� � ����� ������� � ����������� ������ ��� ����� ���������
	�� ������� ������.
	������� �� ������ ����� �� �� ��������.
	������� �� �������� �������� � �������������� �����������
	� �������� ������� SmartPtr � ��� ��������� ����������.
	
	??? generateItem()
	{
	     Item *item = new Item;
	     return Auto_ptr1(item);
	}
	
	����� �� �����? ����� ����������� "��������� �����������", �.�.
	�������������� ����������� ����� � �������� ������������ ��� SmartPtr
	� ���������� �������� ���������� �� ��������� � ������ ����������.
	
	*/
	
	cout << "����� ���������" << endl;
	

	return 0;
} 

