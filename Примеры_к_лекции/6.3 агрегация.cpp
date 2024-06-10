#include <iostream> 
#include <strings.h>
#include <stdlib.h>

using namespace std;

/*
	������ ��� �� ������ � ������������� � ������������, �� �������
	��������� ����� �������� ��� "���������". ������ ����������� �� �����
	��������� ������ �������� - �����������, �� ������ ���������� ����� ����
	������� ������� ������������ (�� ����� �����������, �� �������� � ��� ���� ����������
	� �������������� �������������)
*/


class Department
{
	char name[128];
	
public:
	
	Department(const char* name = nullptr) 
	{ 
		setName(name);
		
	}
	
	const char* getName() 	{ return name; }
	
	// ������� ��������� ������ ��� ����� �������, ����� �����
	// ���� ������ ��������
	void setName(const char* name) 	
	{ 
		strcpy(this->name, name? name : "��� �����");  
	}
};
 


/* 
	����� University - ������������� ����� ��� ���� ������� - ������������� Department.
	�� ��������� �������� ������ Department
*/
class University
{
	// �������� ��������: ������ faculty - ��� ������ ���������� �� Department!
    Department** faculty;
    int facultyCount; //���������� ������������ ��������� � ������� Department
    int facultyCapacity; //������� ������������� �������, ������ ������ ��� ����� facultyCount
    
    void alloc(int capacity)
    {
    	if(capacity <= facultyCapacity) return;
    	
    	//�������� ������ ����������!
    	Department** facultyExtend = new Department*[capacity];
    	
    	for(int i = 0; i < facultyCount; ++i)
    		facultyExtend[i] = faculty[i];
    		
    	//�� �������� ������� ������ ������, �.�. �� ��� �� �����
    	if(facultyCapacity) 
			delete[] faculty;
			
		faculty = facultyExtend;	
    	
    	facultyCapacity = capacity;
	}
    
public:
	
	University()
	{
		facultyCount = 0;
		alloc(1); // ����� ������ ��� ����������� ������, � �������� ������ ����� ������� ����� ������� ��������
	}
	
	// ������� ����������� ����� � �������� ������������
	// �.�. ����� ��� ������� �� �������������� (���� �� ���������� ������������ ������)
	University(const University& other) = delete;
	University& operator=(const University& other) = delete;
	
	~University()
	{
		// ����� �� ������� ������ ������-����������, � �� ���� �������!
		if(facultyCapacity)
			delete[] faculty;
	}
	
    // ��������� ��������� �� ������, ������ ��� ������ �����!
    void addFaculty(Department* newFaculty)
    {
    	if(facultyCount == facultyCapacity) 
			alloc(facultyCapacity * 2); //������ ����������� ������ � 2 ����
    	
    	
    	faculty[facultyCount++] = newFaculty;
	}
	
	//������� ������ �� ���������. ��� ������ ��� ���� �� ���������!
    void removeFaculty(const Department* delFaculty)
    {
    	for(int i = 0; i < facultyCount; ++i)
    		if(faculty[i] == delFaculty) // ����� ���������� �� ������
    		{
    			// �������� ��� �������� �����, ������� ��������� �������
    			// ����� ����� ���������� �������� ������������ = ��-��������� ��� Department!
    			for(int j = i + 1; j < facultyCount; ++j)
    				faculty[j - 1] = faculty[j];
    			
    			--facultyCount;
    			return;
			}
	}
	
	// ������� � ������� ������ �����������
	void printAbout()
	{
		cout << "����������� ������� �� " << facultyCount << " �����������:" << endl;
		for(int i = 0; i < facultyCount; ++i)
			cout << "��������� \"" << faculty[i]->getName() << "\"" << endl;
		cout << endl;
	}	
};



int main(int argc, char** argv) 
{
	system("chcp 1251");


	University university1, university2;
	
	// �.�. ����� ���� ��������� �� ��������� �������� ������ ����� ������
	// ������ ������� �����
	Department* fac1 = new Department("���");
	Department* fac2 = new Department("���");
	Department* fac3 = new Department("��");
	Department* fac4 = new Department("�����");
	Department* fac5 = new Department("���");
	
	//��������� ���������� � ������ �����������
	university1.addFaculty(fac1);
	university1.addFaculty(fac2);
	university1.addFaculty(fac5); // ���� � ��� �� ���������
	
	//��������� ���������� �� ������ �����������
	university2.addFaculty(fac3);
	university2.addFaculty(fac4);
	university2.addFaculty(fac5); // ���� � ��� �� ���������
	
	university1.printAbout();
	university2.printAbout();
	
	//������� ��������� �������������
	fac5->setName("��� 2.0");
	
	//������ ��������� �� ������� ������������
	university2.removeFaculty(fac4);
	
	//����� ��� ��������� ��������� ����� �������������
	// �.�. ��� ������ ��������� �� ���� � ��� �� ������
	university1.printAbout();
	university2.printAbout();
	
	
	// �� �������� �������� ������!
	delete fac1;
	delete fac2;
	delete fac3;
	delete fac4;
	delete fac5;

	/*
		����� ������� ���������� University �� ��������� �������� ������ Department,
		��� ��������� � ������������ �����. ���� ����� �������� ���� � ��� �� Department
		� ��������� ������ �������� University 
	*/
	
	return 0;
}

