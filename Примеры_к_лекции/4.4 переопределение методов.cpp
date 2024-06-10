#include <iostream> 
#include <strings.h>
#include <ctime>
#include <stdlib.h>

using namespace std;


#define MAX_SUBJECTS 10
#define MAX_STR 256


// Родительский класс
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
		cout << getFIO() << " возраст: " << getAge() << " лет." << endl;
	}
};

// Класс - потомок
class Student: public Human
{
	int grades[MAX_SUBJECTS];
	
	// passedOnly - выводить только предметы, где получена оценка
	void printGrades(bool passedOnly)
	{
		for(int i = 0; i < MAX_SUBJECTS; ++i)
		{
			if(!grades[i] && passedOnly) continue;
			
			cout << "Предмет №" << i + 1 << ": ";
			
			if(grades[i])
				cout << " оценка " << grades[i];	
			else
				cout << "нет оценки";	
				
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
	
	
	//можно переопределять методы, тогда метод родительского класса будет недоступен для объекта Student
	//printAbout в Student расширяет метод printAbout из Human. Параметры не обязательно должны совпадать.
	// passedOnly - выводить только предметы, где получена оценка
	void printAbout(bool passedOnly = false)
	{
		cout << "Student::printAbout(...)" << endl;
		
		// но получить доступ внутри можно через расширения видимости
		Human::printAbout(); 
		
		printGrades(passedOnly);
	}
};

int main(int argc, char** argv) 
{
	system("chcp 1251");

	Human man("Иван", 1971);
	man.printAbout();
	cout << endl;

	Student student("Петр", 2001);
	student.setGrade(3, 4);
	student.setGrade(5, 5);
	student.setGrade(9, 4);
	
	student.printAbout(true); 
	cout << endl;
	
	return 0;
}

