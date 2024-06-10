#include <iostream> 
#include <strings.h>
#include <ctime>
#include <stdlib.h>

using namespace std;


#define MAX_SUBJECTS 10
#define MAX_STR 256

#define VALID_SUBJ(subjectID) (subjectID >= 0 && subjectID <= MAX_SUBJECTS - 1)
#define VALID_GRADE(grade) (grade >= 0 && grade <= 5)


/*

	��������: Object -> Human -> Student
	                        \
	                         -> Teacher

*/

//������� �����
class Object
{
public:
		
	//�������� ����� virtual ��������� �������
	//printAbout - ����������� ��������
	virtual void printAbout() const
	//void printAbout() const
	{
		cout << "Object::printAbout(...)" << endl;
		cout << "��� ������ ����� ������!" << endl;
	}	
};


// ������������ �����
class Human: public Object
{
	char fio[MAX_STR];
	int yearBirth;
	
public:
	
	Human(const char* fio, int yearBirth): yearBirth(yearBirth)
	{
		strcpy(this->fio, fio);
	}
	
	
	const char* getFIO() const { return fio; }
	
	int getAge() const
	{
		time_t t = time(NULL);
		return (localtime(&t)->tm_year + 1900) - yearBirth;
	}
	
	void printAbout() const
	{
		cout << "Human::printAbout(...)" << endl;
		Object::printAbout();
		cout << getFIO() << " �������: " << getAge() << " ���." << endl;
	}
};

// ����� - ������� 1
class Student: public Human
{
	int grades[MAX_SUBJECTS];
	
	
	void printGrades() const
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
	
public:
	
	Student(const char* fio, int yearBirth) : Human(fio, yearBirth)
	{
		memset(&grades, 0, MAX_SUBJECTS * sizeof(int));
	}
	
	void setGrade(int subjectId, int grade)
	{
		if(!VALID_SUBJ(subjectId) || !VALID_GRADE(grade)) return;
		grades[subjectId] = grade;
	}
	
	int getGrade(int subjectId) const
	{
		if(!VALID_SUBJ(subjectId)) return 0;
		return grades[subjectId];
	}
	
	//����� ����������� ������� �� ����� ����� �������� passedOnly, �.�. ��������� ������ ���������
	void printAbout() const override
	{
		cout << "Student::printAbout(...)" << endl;
		
		Human::printAbout(); 
		printGrades();
	}
};


// ����� - ������� 2
class Teacher: public Human
{
	bool subjects[MAX_SUBJECTS];

	void printSubjects() const
	{
		cout << "����� ��������:" << endl;
		for(int i = 0; i < MAX_SUBJECTS; ++i)
			if(subjects[i]) 
				cout << i + 1 << " ";	
		cout << endl;
	}
	
public:
	
	Teacher(const char* fio, unsigned short yearBirth) : Human(fio, yearBirth)
	{
		memset(&subjects, 0, MAX_SUBJECTS * sizeof(bool));
	}
	
	void setSubject(int subjectId)
	{
		if(!VALID_SUBJ(subjectId)) return;
		subjects[subjectId] = true;
	}
	
	bool getSubject(int subjectId) const
	{
		if(!VALID_SUBJ(subjectId)) return false;
		return subjects[subjectId];
	}
	
	void printAbout() const
	{
		cout << "Teacher::printAbout(...)" << endl;
		
		Human::printAbout(); 
		printSubjects();
	}
};


void printAboutObject(const Object* object)
{
	object->printAbout();
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	Student student("����", 2001);
	student.setGrade(3, 4);
	student.setGrade(5, 5);
	student.setGrade(9, 4);
	student.printAbout();
	cout << endl;
	
	Teacher teacher("�������� ����������", 1963);
	teacher.setSubject(3);
	teacher.setSubject(6);
	teacher.setSubject(8);
	teacher.printAbout();
	cout << endl << "------------------------------" << endl << endl;
	
	//� ��� ����� ���� �� ������� ������ � �������� ����?
	Object* object = &student;
	object->printAbout();

	cout << endl;
	object = &teacher;
	object->printAbout();
	cout << endl;
	
	printAboutObject(object);
	
	// �������� ����� virtual ��������� ������� printAbout - ����������� ��������
	// ������������� ��� ���������� ������� Student � Teacher � �������� Object
	// � ����������� ����� printAbout ����� �� ����� �������� ���������� 
	// �� Student � Teacher. ��� virtual ����� ������ printAbout �� Object
	
	
	return 0;
}

