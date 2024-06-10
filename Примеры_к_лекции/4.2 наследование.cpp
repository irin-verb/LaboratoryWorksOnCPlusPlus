#include <iostream> 
#include <strings.h>
#include <ctime>

using namespace std;

#define MAX_STR 256

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
		
};

int main(int argc, char** argv) 
{
	system("chcp 1251");


	Human man("����", 1971);
	
	cout << man.getFIO() << " �������: " << man.getAge() << " ���." << endl;

	
	return 0;
}

