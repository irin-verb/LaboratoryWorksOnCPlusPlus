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
		strcpy(this->fio, fio);
	}
	
	
	const char* getFIO() { return fio; }
	
	int getAge()
	{
		time_t t = time(NULL);
		return (localtime(&t)->tm_year + 1900) - yearBirth;
	}
	
	void printAbout()
	{
		cout << "Human::printAbout(...)" << endl;
		cout << getFIO() << " �������: " << getAge() << " ���." << endl;
	}
};

// ����� - �������
class Student: public Human
{
	int grades[MAX_SUBJECTS];
	
	// passedOnly - �������� ������ ��������, ��� �������� ������
	void printGrades(bool passedOnly)
	{
		for(int i = 0; i < MAX_SUBJECTS; ++i)
		{
			if(!grades[i] && passedOnly) continue;
			
			cout << "������� �" << i + 1 << ": ";
			
			if(grades[i])
				cout << " ������ " << grades[i];	
			else
				cout << "��� ������";	
				
			cout << endl;
		}
	}
	
public:
	
	Student(const char* fio, int yearBirth) : Human(fio, yearBirth)
	{
		memset(&grades, 0, MAX_SUBJECTS * sizeof(int));
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
	
	
	//����� �������������� ������, ����� ����� ������������� ������ ����� ���������� ��� ������� Student
	//printAbout � Student ��������� ����� printAbout �� Human. ��������� �� ����������� ������ ���������.
	// passedOnly - �������� ������ ��������, ��� �������� ������
	void printAbout(bool passedOnly = false)
	{
		cout << "Student::printAbout(...)" << endl;
		
		// �� �������� ������ ������ ����� ����� ���������� ���������
		Human::printAbout(); 
		
		printGrades(passedOnly);
	}
};

int main(int argc, char** argv) 
{
	system("chcp 1251");

	Human man("����", 1971);
	man.printAbout();
	cout << endl;

	Student student("����", 2001);
	student.setGrade(3, 4);
	student.setGrade(5, 5);
	student.setGrade(9, 4);
	
	student.printAbout(true); 
	cout << endl;
	
	return 0;
}

