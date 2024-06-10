#include <iostream> 
#include <strings.h>
#include <stdlib.h>

using namespace std;

/*
	Возьмём тот же пример с университетом и факультетами, но сделаем
	отношения между классами как "агрегация". Теперь университет не может
	управлять жизнью объектов - факультетов, но теперь факультеты могут быть
	частями другого университета (не очень реалистично, но допустим у них есть соглашение
	о сотрудничестве подразделений)
*/


class Department
{
	char name[128];
	
public:
	
	Department(const char* name = nullptr) 
	{ 
		setName(name);
		
	}
	
	const char* getName() 	{ return name; }
	
	// добавим публичный сеттер для этого примера, чтобы можно
	// было менять название
	void setName(const char* name) 	
	{ 
		strcpy(this->name, name? name : "нет имени");  
	}
};
 


/* 
	Класс University - агрегационный класс для всех классов - подразделений Department.
	не управляет жизненым циклом Department
*/
class University
{
	// обратите внимание: теперь faculty - это массив указателей на Department!
    Department** faculty;
    int facultyCount; //количество используемых элементов в массиве Department
    int facultyCapacity; //ёмкость динамического массива, всегда больше или равна facultyCount
    
    void alloc(int capacity)
    {
    	if(capacity <= facultyCapacity) return;
    	
    	//выделяем массив указателей!
    	Department** facultyExtend = new Department*[capacity];
    	
    	for(int i = 0; i < facultyCount; ++i)
    		facultyExtend[i] = faculty[i];
    		
    	//не забываем удалить старый массив, т.к. он уже не нужен
    	if(facultyCapacity) 
			delete[] faculty;
			
		faculty = facultyExtend;	
    	
    	facultyCapacity = capacity;
	}
    
public:
	
	University()
	{
		facultyCount = 0;
		alloc(1); // хотим увидет как расширяется массив, в реальном случае стоит конечно брать большее значение
	}
	
	// удаляем конструктор копии и оператор присваивания
	// т.к. иначе нам придётся их переопределять (ведь мы используем динамическую память)
	University(const University& other) = delete;
	University& operator=(const University& other) = delete;
	
	~University()
	{
		// Здесь мы удаляем только массив-указателей, а не сами объекты!
		if(facultyCapacity)
			delete[] faculty;
	}
	
    // добавляем факультет по ссылке, объект был создан извне!
    void addFaculty(Department* newFaculty)
    {
    	if(facultyCount == facultyCapacity) 
			alloc(facultyCapacity * 2); //всегда увеличиваем массив в 2 раза
    	
    	
    	faculty[facultyCount++] = newFaculty;
	}
	
	//удаляем ссылку на факультет. Сам объект при этом не удаляется!
    void removeFaculty(const Department* delFaculty)
    {
    	for(int i = 0; i < facultyCount; ++i)
    		if(faculty[i] == delFaculty) // нашли совпадение по адресу
    		{
    			// сдвигаем все элементы влево, затирая удаляемый элемент
    			// здесь опять вызывается оператор присваивания = по-умолчанию для Department!
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
			cout << "факультет \"" << faculty[i]->getName() << "\"" << endl;
		cout << endl;
	}	
};



int main(int argc, char** argv) 
{
	system("chcp 1251");


	University university1, university2;
	
	// т.к. связь типа агрегация не управляет жизненым циклом своих членов
	// создаём объекты извне
	Department* fac1 = new Department("ФВТ");
	Department* fac2 = new Department("ФРТ");
	Department* fac3 = new Department("ФЭ");
	Department* fac4 = new Department("ФАИТУ");
	Department* fac5 = new Department("ФТП");
	
	//добавляем факультеты в первый университет
	university1.addFaculty(fac1);
	university1.addFaculty(fac2);
	university1.addFaculty(fac5); // один и тот же факультет
	
	//добавляем факультеты во второй университет
	university2.addFaculty(fac3);
	university2.addFaculty(fac4);
	university2.addFaculty(fac5); // один и тот же факультет
	
	university1.printAbout();
	university2.printAbout();
	
	//изменим назваение подразделения
	fac5->setName("ФТП 2.0");
	
	//удалим факультет из второго университета
	university2.removeFaculty(fac4);
	
	//видим что изменения коснулись обоих университетов
	// т.к. они хранят указатель на один и тот же объект
	university1.printAbout();
	university2.printAbout();
	
	
	// не забываем очистить память!
	delete fac1;
	delete fac2;
	delete fac3;
	delete fac4;
	delete fac5;

	/*
		Таким образом агрегатный University не управляет жизненым циклом Department,
		они создаются и уничтожаются извне. Зато можно добавить один и тот же Department
		в несколько разных объектов University 
	*/
	
	return 0;
}

