#include <iostream> 
#include <strings.h>
#include <ctime>
#include <stdlib.h>
using namespace std;


#define MAX_SUBJECTS 10
#define MAX_STR 256


// ������������ �����
class Human
{
	char fio[MAX_STR];
	int yearBirth;
	
public:
	
	Human(const char* fio, int yearBirth): yearBirth(yearBirth)
	{
		cout << "Human(...) " << fio << endl;
		strcpy(this->fio, fio);
	}
	
	~Human()
	{
		cout << "~Human(...) " << fio << endl;
	}
	
	const char* getFIO() { return fio; }
	
	int getAge()
	{
		time_t t = time(NULL);
		return (localtime(&t)->tm_year + 1900) - yearBirth;
	}
	
	void printAbout()
	{
		cout << getFIO() << " �������: " << getAge() << " ���." << endl;
	}
};

// ����� - �������
class Student: public Human
{
	int grades[MAX_SUBJECTS]; // ������ �� ���� ���������, ���� 0 - ��� ������
	
public:
	
	Student(const char* fio, int yearBirth) : Human(fio, yearBirth)
	{
		cout << "Student(...) " << fio << endl;
		memset(&grades, 0, MAX_SUBJECTS * sizeof(int));
	}

	~Student()
	{
		cout << "~Student(...) " << getFIO() << endl;
	}
	
	void setGrade(int subjectId, int grade)
	{
		if(subjectId < 0 || subjectId >= MAX_SUBJECTS || grade < 0 || grade > 5) return;
		
		grades[subjectId] = grade;
	}
	
	int getGrade(int subjectId)
	{
		if(subjectId < 0 || subjectId >= MAX_SUBJECTS) return 0;
	
		return grades[subjectId];
	}
	
	void printGrades()
	{
		for(int i = 0; i < MAX_SUBJECTS; ++i)
		{
			cout << "������� �" << i + 1 << ": ";
			
			if( grades[i] )
				cout << " ������ " << grades[i];	
			else
				cout << "��� ������";	
				
			cout << endl;
		}
	}
};

int main(int argc, char** argv) 
{
	system("chcp 1251");

	Human man("����", 1971);
	man.printAbout();
	cout << endl;

	Student student("����", 2001);
	//������������� ������ �� 3 ���������
	student.setGrade(3, 4);
	student.setGrade(5, 5);
	student.setGrade(9, 4);
	
	student.printAbout();
	student.printGrades();
	cout << endl;
	
	
	return 0;
}

