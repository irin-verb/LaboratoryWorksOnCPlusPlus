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
 
 
int main(int argc, char** argv)
{
	system("chcp 1251");
	
	// MyClass � ������� ������� �� ��������� ������ *, 
	// ��������� ��� ��������������� �������� ������
	
	// ������������ ��������� ������
	SmartPtr<MyClass> obj1(new MyClass({"������ 1"})); 

	{
		// ������������ ��������� ������
		SmartPtr<MyClass> obj2(new MyClass(string("������ 2"))); 
		
	 	// ...
	    // �������� ������ delete ����� �� �����!
	    // ...
		
		
	} // obj2 ������� �� ������� ��������� � ���������� ���������� MyClass �������������
 
 
	return 0;
} // obj1 ������� �� ������� ��������� � ���������� ���������� MyClass �������������

