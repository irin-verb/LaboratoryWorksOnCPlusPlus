#include <iostream> 
#include <strings.h>

using namespace std;

/*
	� ������ ������� �������� ������������� ��������������� ����� 
	����� �������� Doctor � Patient
*/

/*
 �.�. ���������� ������������� ������� ���������� �� ������� � ���
 ����� ���������� ������� ��� � ��������� �����. 
 � ������ ������ �������� ����� ������������ ��������� �����. �� �.�.
 �� ��� ��� �� �������, �� �� �������� �������� � ����� ������������
 ���������� �������� ������ � ������-�������.
*/

// ����� Object, ������� ��� �������� ��������� ���������
// � ����������� ������. ������ ������� � ���� ����������
// �������� ���� ����� �������.
class Object 
{ 
	char name[128];
public:
	
	Object(const char* name = nullptr)	
	{
		strcpy(this->name, name? name : "��� �����");  
	}
	
	const char* getName() 	{ return name; }
	virtual void printAbout() = 0;
};

void Object::printAbout() 
{
	cout << "���: " << name << endl;
}


// ����� ��� �������� ���������� �� ����� �������, ����������� �� Object
// �� ����� ���������� ����������� �������
class PtrArray
{
    Object** array;
    int count = 0; 
    int capacity;
    
    void alloc(int capacity)
    {
    	if(capacity <= this->capacity) return;
    	
    	Object** arrayExtend = new Object*[capacity];
    	
    	for(int i = 0; i < count; ++i)
    		arrayExtend[i] = array[i];
    	
    	if(this->capacity) 
			delete[] array;
			
		array = arrayExtend;	
    	this->capacity = capacity;
	}
	
public:
	
	PtrArray()
	{
		alloc(10);
	}
	
	~PtrArray()
	{
		if(capacity)
			delete[] array;
	}
	
	// ������� ����������� ����� � �������� ������������
	// �.�. ����� ��� ������� �� �������������� 
	PtrArray(const PtrArray& other) = delete;
	PtrArray& operator=(const PtrArray& other) = delete;
	
    void add(Object* object)
    {
    	if(count == capacity)  alloc(capacity * 2); 
    	array[count++] = object;
	}
	
    void remove(const Object* object)
    {
    	for(int i = 0; i < count; ++i)
    		if(array[i] == object) 
    		{
    			for(int j = i + 1; j < count; ++j)
    				array[j - 1] = array[j];
    			--count;
    			return;
			}
	}
	
	void clear() { count = 0; }
	int length() { return count; }
	
	// �������� ��������� �� ������� � ������������ �������
	Object* operator[](int i) 
	{
		return array[i];
	}
};


// ��������� ��������� ����� �������� Patient � Doctor ���������������, 
//�� ��� ������ Doctor ����� ����� ������������ ��������������� ����������
class Doctor;
 
class Patient: public Object
{
	PtrArray doctors; 
	int policyID; // ����� ������
	
	// ����� addDoctor() � removeDoctor()  ��������, ��� ��� 
	// ������ � ���� ����� �������������� ����� ����� Doctor
	// ��� �������, �.�. ������ ������������ ��������, � �� ��������
	void addDoctor(Doctor* doc);
	void removeDoctor(Doctor* doc);
	
public:
	
	Patient(const char* name, int policyID) : Object(name), policyID(policyID)
	{
	}
	
	int getPolicyID() { return policyID; }
	
	virtual void printAbout() override;
 
	// ������� ����� Doctor �������������, ����� ����� ������ 
	// � �������� ������� addDoctor() � removeDoctor()
	friend class Doctor;
};
 
class Doctor: public Object
{
	PtrArray patients;
 
public:
	
	Doctor(const char* name) : Object(name)
	{
	}
 
	void addPatient(Patient* pat)
	{
		// ���� ��������� ��������
		patients.add(pat);
		
		// ������� ��������� �����
		pat->addDoctor(this);
	}
	
	void removePatient(Patient* pat)
	{
		// ���� ������� ��������
		patients.remove(pat);
		
		// ������� ������� �����
		pat->removeDoctor(this);
	}
	
	virtual void printAbout() override
	{
		Object::printAbout();
		cout << "����� ";
		
		/*
			����� � ���� ������� �� ���������� � ������� getName() � getPolicyID()
			�.�. getName() - ��� ����� ������ Object, � ��������[] ���������� ���������
			�� Object - �� �������� ��� ������� �������.
			
			�� ����� getPolicyID() ��������� � ������ Patient, � ��������[] ���������� Object*
			������� �� ���� ����������� ��������� � Object* �  Patient*, ������ ��� �� �������
			� ������ ������, ��� ��� �������� �������������� ����� ���������.
		*/
		
		for(int i = 0; i < patients.length(); ++i)
			cout << patients[i]->getName() << "(����� " << ((Patient*)patients[i])->getPolicyID() << ") ";
		
		cout << endl;
	}
};

/*
	�������� ���� ������� ������� �������� ����� ������ �������, 
	�.�. � ��� ����� ������� ������	����� ������ ��������
*/

void Patient::addDoctor(Doctor* doc)
{
	doctors.add(doc);
}

void Patient::removeDoctor(Doctor* doc)
{
	doctors.remove(doc);
}

void Patient::printAbout()
{
	Object::printAbout();
	cout << "������� � ";
	for(int i = 0; i < doctors.length(); ++i)
		cout << doctors[i]->getName() << " ";
	cout << endl;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	// ������ ��������� � ��������
	Patient* p1 = new Patient("������",239546);
	Patient* p2 = new Patient("������",38478);
	Patient* p3 = new Patient("�������",856636);
	Doctor* d1 = new Doctor("�������");
	Doctor* d2 = new Doctor("��������");
	
	//��������� ����� - ����������
	d1->addPatient(p1);
	d1->addPatient(p2);
	
	d2->addPatient(p1);
	d2->addPatient(p3);
	
	//������� ����������
	p1->printAbout();
	p2->printAbout();
	p3->printAbout();
	
	d1->printAbout();
	d2->printAbout();
	
	//������� ������ �������� ������� � ������� ���������
	d1->removePatient(p1);
	
	cout << endl;
	
	//���������� ��������� � �������
	p1->printAbout();
	d1->printAbout();
	
	//�� �������� ������� ������
	delete p1;
	delete p2;
	delete p3;
	delete d1;
	delete d2;
	
	/*
		����� ������� ������ Patient � Doctor ��������� � ���������������
		������������� �����. ������ ������� ��� ������ �������� "������" �������
		��� ��������. ������ �� ��� ����� ��������� ����� � �������������
		����� � ������� ������������.
	*/
	
	return 0;
}

