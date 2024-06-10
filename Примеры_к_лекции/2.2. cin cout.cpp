#include <iostream> // здесь наход€тс€ классы потока ввода\вывода

#define MAX_FIO 128

//*

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	char f[MAX_FIO], i[MAX_FIO], o[MAX_FIO];
	int age;
	std::cout << " ак вас зовут и сколько вам лет?" << std::endl;
	std::cin >> f >> i >> o >> age;
	
	std::cout << "¬ас зовут " << f << " " << i << " " << o << " и вам " << age << " лет." << std::endl;
	
	return 0;
}

//*/

/*

using namespace std; //using namespace позвол€ет использовать все имена в нем без указани€ пространства имен

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	char f[MAX_FIO], i[MAX_FIO], o[MAX_FIO];
	int age;
	cout << " ак вас зовут и сколько вам лет?" << endl;
	cin >> f >> i >> o >> age;
	
	cout << "¬ас зовут " << f << " " << i << " " << o << " и вам " << age << " лет." << endl;
	
	return 0;
}
//*/
