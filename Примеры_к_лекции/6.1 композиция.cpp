#include <iostream> 
#include <strings.h>

using namespace std;

/*
	����� Department - ��������� ������������� ������������.
	����� ���� - ��������.
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
 
#define MAX_FACULTY 20
/* 
	����� University - ����������� ����� ��� ���� ������� - ������������� Department.
	���� ������ ���� ��������� �������� �� ������, ����� ����������� University ������������
	��� Department
*/
class University
{
    Department faculty[MAX_FACULTY];
    int facultyCount = 0; //���������� ������� ������������ ��������� � ������� Department
    
public:
    
    // ��������� ��������� �� ����� 
    void addFaculty(const char* name)
    {
    	if(facultyCount == MAX_FACULTY) return;
    	
    	// ...
    	// �������� ����� ����� �������� �������� �� ������������, �� �� ����� ��������� ������
    	// ...
    	
    	/* 
		 ����� ���������� ����������� ������ ������� Department ���������� �����
    	 ���������� ������������� ({name} ���������� ����������� ������ ������������ 
    	 Department(name), ���������� ��� ����� ���������� ����� ����� ������������ 
		 �� ����� ����� ���������)
    	 � ���������� � ������ ������� ������� � ������� ��������� = ��-��������� ��� Department.
    	*/
    	
    	faculty[facultyCount++] = Department(name);
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
		cout << endl;
	}	
};



int main(int argc, char** argv) 
{
	system("chcp 1251");

	// ������ ������ ������ University. 
	// ����� �������� � ��� ��� �������������.
	University university;
	
	//��������� �������������
	university.addFaculty("���");
	university.addFaculty("���");
	university.addFaculty("��");
	university.addFaculty("�����");
	
	//������� ������ � �������
	university.printAbout();
	
	//������� ���� ���������
	university.removeFaculty("���");
	
	//��������� ��� ��������
	university.printAbout();
	
	/*
		����� ������� ����������� University ��������� �������� � ���� ������� Department
		� ��������� �� �������� �����. ����� ������ ����� ��������� �� ���������
		������ ����� ������ University addFaculty() � removeFaculty()
	*/
	
	return 0;
}

