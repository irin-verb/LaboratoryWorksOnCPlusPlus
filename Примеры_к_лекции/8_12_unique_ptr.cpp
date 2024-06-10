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


unique_ptr<MyClass> createObject(const string& name)
{
	unique_ptr<MyClass> ptr(new MyClass(name)); // ������ ��������� ��������
	
	// ...
	
	return ptr;
}

void getByValue(unique_ptr<MyClass> objPtr)
{
	//������ getByValue ������� ��������, �� ������� ��������� obj
	if (objPtr) 
		objPtr->sayMyName();
	
} //����� ������ �� ������� ��������� objPtr ������������


void getByRef(const unique_ptr<MyClass>& objPtr)
{
	//��� �������� �� ������ ����� �������� �� ���������.
	
	if (objPtr) 
		objPtr->sayMyName();
	
}
void getByRawPointer(const MyClass* obj)
{
	//������� �� ����� ��� ����������� ������ ��� �������
	
	if (obj) 
		obj->sayMyName();
	
}

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	{
		//unique_ptr �������� ������� auto_ptr � C++11
		MyClass* obj1 = new MyClass(string("������ 1"));
		unique_ptr<MyClass> obj1Ptr(obj1); // ������� ����� ������������� obj1Ptr �� obj1
		//obj1 = nullptr; // obj1 ������ ����������� ����� obj1Ptr, ������ ������ ��� ������ �� �����, ����� � ��������
		
		/* ������:
		
		 1) ��������� ���������� unique_ptr ������� ����� � ��� �� �������� (���� ��� ������������� ���������).
			MyClass* obj1 = new MyClass(string("������ 1"));
			unique_ptr<MyClass> ptr1(obj1);
			unique_ptr<MyClass> ptr2(obj1);
			
		 2) �� ������� ��������� ������� ������, ��������� � unique_ptr.
			MyClass* obj1 = new MyClass(string("������ 1"));
			unique_ptr<MyClass> obj1Ptr(obj1);
			delete obj1;
		*/
		
		
	} // obj1 ����� ��������� ����� obj1Ptr
	
	cout << endl;
	
	
	// unique_ptr ��������� ��������� ��������� �����������
	unique_ptr<MyClass> pA1(new MyClass(string("������ A")));
	unique_ptr<MyClass> pA2;
	
	cout << (static_cast<bool>(pA1) ? "pA1 not null\n" : "pA1 null\n");
	cout << (static_cast<bool>(pA2) ? "pA2 not null\n" : "pA2 null\n");

	// pA2 = pA1; // �� ��������������, �.�. ��������� ����������� ���������!
	pA2 = move(pA1); // ����� std::move() ������� ����� �������� �� pA1 � pA2, ������ pA1 == nullptr
	
	cout << (static_cast<bool>(pA1) ? "pA1 not null\n" : "pA1 null\n");
	cout << (static_cast<bool>(pA2) ? "pA2 not null\n" : "pA2 null\n");
	
	cout << endl;
	
	//������ � ������ ������� �������������� ����� ������������� * � -> ��� � � ������� ����������
	(*pA2).sayMyName();
	pA2->sayMyName();
	
	cout << endl;
	
	//unique_ptr ����� ������������ ����� � ��� ������������ ��������, ���� ���������������� ������������ vector
	{
		unique_ptr<int[]> arr(new int[10]);
		for(int t = 0; t < 10; ++t) arr[t] = t * t;
		for(int t = 0; t < 10; ++t) cout << arr[t] << " ";
		cout << endl;
	} // arr ����� ����� ���������! unique_ptr �������� ��� ����� ������������ delete[]
	
	cout << endl;
	
	// � C++14 �������� ����� ��������� ������� � std::make_unique(). 
	// ��� ������� ������ ���� ������� � �������������� ��� �����������, ����������� � �������. 
	// ������������� ������������ ������, ������ ����������������� �������� ������� � �������� � unique_ptr
	
	// unique_ptr<MyClass> pB = make_unique<MyClass>(string("������ B"));
	
	// auto ��������� ��� ������ ��������� ������
	// auto pC = make_unique<MyClass>(string("������ C")); 
	
	
	// unique_ptr ����� ���������� �� ������� �� ��������
	// ���� ��� ���� �������� �� ������������� ������-���� �������, �� ���������
	// ������� �� ������� ��������� � ���������, � ���� �������������� - �� � �������
	// ��������� ����������� ������������ � ������ ������. 
	// ��� ������ ���������� unique_ptr �� ������ ��� ������ ��� ������ ������.
	/*auto ptr =*/ createObject("������, �������� � �������");
	
	cout << endl;
	
	// � ������� unique_ptr ������� ���������� �� �������� (����� move), ���� �� ������
	// �������� �������� ����������, ����� ����� ���������� �� ������.
	// ������ �� ������ ������� ����� ������ �������� raw ���������\������ �� ������ � ��������
	// ��� � �������, �.�. ������� �� ����� �����, ����� ������� � ����� ����� ���������
	// ����������� ������ �������
	unique_ptr<MyClass> pObjParam(new MyClass(string("������, ������������ ��� ��������")));
	getByRef(pObjParam);
	getByRawPointer(pObjParam.get()); // get() ���������� raw ���������
	getByValue(move(pObjParam)); //���������� move �.�. ������ ����������� ���������!
	cout << (static_cast<bool>(pObjParam) ? "pObjParam not null\n" : "pObjParam null\n");
	
	cout << endl;

	// unique_ptr ����� �������������� � ��� ���� ���������� ������ 
	// (�� ����� ����������� �� ������� ��� ������� � �����������). 
	
	
	cout << "����� ���������" << endl;
	
	return 0;
}

