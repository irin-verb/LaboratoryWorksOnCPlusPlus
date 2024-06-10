#include <iostream> 
#include <strings.h>

using namespace std;

/*
	Класс Department - описывает подразделение университета.
	Имеет поле - название.
*/
class Department
{
	char name[128];
	
public:
	
	// конструктор с параметром по умолчанию может заменить конструктор без параметоров!
	Department(const char* name = nullptr) 
	{ 
		strcpy(this->name, name? name : "нет имени"); 
	}
	
	// геттер для поля имени подразделения (нельзя изменить извне т.к. указатель константный)
	const char* getName() 	{ return name; }
};
 
#define MAX_FACULTY 20
/* 
	Класс University - композитный класс для всех классов - подразделений Department.
	явно внутри себя управляет временем их жизней, после уничтожения University уничтожаются
	все Department
*/
class University
{
    Department faculty[MAX_FACULTY];
    int facultyCount = 0; //количество реально используемых элементов в массиве Department
    
public:
    
    // добавляем факультет по имени 
    void addFaculty(const char* name)
    {
    	if(facultyCount == MAX_FACULTY) return;
    	
    	// ...
    	// вероятно здесь стоит добавить проверку на уникальность, но не будем усложнять пример
    	// ...
    	
    	/* 
		 здесь происходит копирование нового объекта Department созданного через
    	 униформную инициализацию ({name} фактически равносильно вызову конструктора 
    	 Department(name), компилятор сам может догататься какой класс используется 
		 по левой части выражения)
    	 И копируется в нужный элемент массива с помощью оператора = по-умолчанию для Department.
    	*/
    	
    	faculty[facultyCount++] = Department(name);
	}
	
	//удаляем факультет по имени
    void removeFaculty(const char* name)
    {
    	for(int i = 0; i < facultyCount; ++i)
    		if(strcmp(name, faculty[i].getName()) == 0) // нашли совпадение имени
    		{
    			//просто сдвигаем все элементы влево, затирая удаляемый элемент
    			//здесь опять вызывается оператор присваивания = по-умолчанию для Department!
    			for(int j = i + 1; j < facultyCount; ++j)
    				faculty[j - 1] = faculty[j];
    			
    			--facultyCount;
    			return;
			}
	}
	
	// выводим в консоль список факультетов
	void printAbout()
	{
		cout << "Университет состоит из " << facultyCount << " факультетов:" << endl;
		for(int i = 0; i < facultyCount; ++i)
			cout << "факультет \"" << faculty[i].getName() << "\"" << endl;
		cout << endl;
	}	
};



int main(int argc, char** argv) 
{
	system("chcp 1251");

	// создаём объект класса University. 
	// После создания в нем нет подразделений.
	University university;
	
	//добавляем подразделения
	university.addFaculty("ФВТ");
	university.addFaculty("ФРТ");
	university.addFaculty("ФЭ");
	university.addFaculty("ФАИТУ");
	
	//выводим массив в консоль
	university.printAbout();
	
	//удаляем один факультет
	university.removeFaculty("ФРТ");
	
	//проверяем что удалился
	university.printAbout();
	
	/*
		Таким образом композитный University полностью включает в себя объекты Department
		и управляет их временем жизни. Извне класса можно управлять их созданием
		только через методы University addFaculty() и removeFaculty()
	*/
	
	return 0;
}

