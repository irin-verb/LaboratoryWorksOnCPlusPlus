#include <iostream> 
#include <strings.h>
#include <ctime>

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
	
	//����������� ���������� ������ ���� �����������!
	virtual ~Object() { cout << "dtor Object" << endl; }
		
	virtual void printAbout() const = 0; //������ ����� Object ��������� �����������, ��� ���������� ��������� ������	
};

/*
//����� ���������� ���������� �� ��������� � ���������� � ��� ��� ������ Object::printAbout()
//������ ����� Object ��������� �����������
void Object::printAbout() const
{
	cout << "Object::printAbout(...)" << endl;
	cout << "��� ������ ����� ������!" << endl;
}
//*/

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
	
	~Human() { cout << "dtor Human" << endl; }
	
	const char* getFIO() const { return fio; }
	
	int getAge() const
	{
		time_t t = time(NULL);
		return (localtime(&t)->tm_year + 1900) - yearBirth;
	}
	
	virtual void printAbout() const override
	{
		cout << "Human::printAbout(...)" << endl;
		//Object::printAbout(); // ����� ������� ���������� ��-��������� ���� ��� ����������
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
	
	virtual void printAbout() const override
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
	
	virtual ~Teacher() { cout << "dtor Teacher" << endl; }
	
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
	
	virtual void printAbout() const override
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

	//Object objAbstract; //[Error] cannot declare variable 'objAbstract' to be of abstract type 'Object'
	
	Object* obj = new Teacher("�������� ����������", 1963);
	printAboutObject(obj);
	delete obj;
	
	
	
	return 0;
}

