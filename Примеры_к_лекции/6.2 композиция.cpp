#include <iostream> 
#include <strings.h>

using namespace std;

/*
	� ������ ������� ������������ ������������ ��������� ������
	� ������� new\delete � ����������� ����� ������ ��� �� ����-��������,
	� ����-���������. �� ��� �� ��� ����������, �.�. University ���������
	��������� �������� ������ Department!
*/


class Department
{
	char name[128];
	
public:
	
	// ����������� � ���������� �� ��������� ����� �������� ����������� ��� �����������!
	Department(const char* name = nullptr) 
	{ 
		strcpy(this->name, name? name : "��� �����"); 
	}
	
	// ������ ��� ���� ����� ������������� (������ �������� ����� �.�. ��������� �����������)
	const char* getName() 	{ return name; }
};
 


/* 
	����� University - ����������� ����� ��� ���� ������� - ������������� Department.
	���������� ������������ ������ ��� �������� �������� ������ ����.
*/
class University
{
    Department* faculty;
    int facultyCount; //���������� ������������ ��������� � ������� Department
    int facultyCapacity; //������� ������������� �������, ������ ������ ��� ����� facultyCount
    
    void alloc(int capacity)
    {
    	if(capacity <= facultyCapacity) return;
    	
    	Department* facultyExtend = new Department[capacity];
    	
    	for(int i = 0; i < facultyCount; ++i)
    		facultyExtend[i] = faculty[i];
    	
    	//�� �������� ������� ������ ������, �.�. �� ��� �� �����
    	if(facultyCapacity) 
			delete[] faculty;
		
		//������������ ���������, ����� �� �������� �� ����� ����������� ������	
		faculty = facultyExtend;	
    	
    	facultyCapacity = capacity;
    	
    	// ���������� ������ ������������ ���������� �������
    	// ������������� �������
    	cout<<"[�������] ������� ��������� �� " << capacity << endl;
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
		if(facultyCapacity)
			delete[] faculty;
	}
	
    // ��������� ��������� �� ����� 
    void addFaculty(const char* name)
    {
    	if(facultyCount == facultyCapacity) 
			alloc(facultyCapacity * 2); //������ ����������� ������ � 2 ����
    	
    	
    	faculty[facultyCount++] = {name};
	}
	
	//������� ��������� �� �����
    void removeFaculty(const char* name)
    {
    	for(int i = 0; i < facultyCount; ++i)
    		if(strcmp(name, faculty[i].getName()) == 0) // ����� ���������� �����
    		{
    			//������ �������� ��� �������� �����, ������� ��������� �������
    			//����� ����� ���������� �������� ������������ = ��-��������� ��� Department!
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
			cout << "��������� \"" << faculty[i].getName() << "\"" << endl;
		
		cout<< "[�������] ������� ������� �� " << facultyCapacity << endl;
		cout << endl;
	}	
};



int main(int argc, char** argv) 
{
	system("chcp 1251");

	/*
	 ����� ������ �� ����������, �.�. �� ���� ��������� ��������������
	 � ������� University �������� �������. ������ ������ �� ����� ����������
	 �� ������� ������� ����� ��� MAX_FACULTY �� ����������� �������. �� � ��
	 �������� ����� ������ ������, ���� ����������� ������ 20.
	*/

	University university;
	university.addFaculty("���");
	university.addFaculty("���");
	university.addFaculty("��");
	university.addFaculty("�����");
	university.printAbout();
	
	//������� ���� ���������
	university.removeFaculty("���");
	university.printAbout();

	/*
		��� ����� �� ����� ������� ������� ���� �����-���������� ��
		������ ��������� �������� ����������. ����� ��� ��������� ��������
		�� ������.
	*/
	
	return 0;
}

