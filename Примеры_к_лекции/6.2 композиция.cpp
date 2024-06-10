#include <iostream> 
#include <strings.h>

using namespace std;

/*
	В данном примере используется динамическое выделение памяти
	с помощью new\delete и композитный класс хранит уже не поля-значения,
	а поля-указатели. Но это всё ещё композиция, т.к. University полностью
	управляет жизненым циклом Department!
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
 


/* 
	Класс University - композитный класс для всех классов - подразделений Department.
	использует динамическую память для хранения объектов внутри себя.
*/
class University
{
    Department* faculty;
    int facultyCount; //количество используемых элементов в массиве Department
    int facultyCapacity; //ёмкость динамического массива, всегда больше или равна facultyCount
    
    void alloc(int capacity)
    {
    	if(capacity <= facultyCapacity) return;
    	
    	Department* facultyExtend = new Department[capacity];
    	
    	for(int i = 0; i < facultyCount; ++i)
    		facultyExtend[i] = faculty[i];
    	
    	//не забываем удалить старый массив, т.к. он уже не нужен
    	if(facultyCapacity) 
			delete[] faculty;
		
		//переписываем указатель, чтобы он указывал на новый увеличенный массив	
		faculty = facultyExtend;	
    	
    	facultyCapacity = capacity;
    	
    	// отладочная печать показывающая увеличение ёмкости
    	// динамического массива
    	cout<<"[Отладка] Ёмкость увеличена до " << capacity << endl;
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
		if(facultyCapacity)
			delete[] faculty;
	}
	
    // добавляем факультет по имени 
    void addFaculty(const char* name)
    {
    	if(facultyCount == facultyCapacity) 
			alloc(facultyCapacity * 2); //всегда увеличиваем массив в 2 раза
    	
    	
    	faculty[facultyCount++] = {name};
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
		
		cout<< "[Отладка] Ёмкость массива до " << facultyCapacity << endl;
		cout << endl;
	}	
};



int main(int argc, char** argv) 
{
	system("chcp 1251");

	/*
	 Извне ничего не изменилось, т.к. по сути интерфейс взаимодействия
	 с классом University отстался прежним. Только теперь он может расширятся
	 на гораздо большую длину чем MAX_FACULTY из предыдущего примера. Но и не
	 занимать много лишней памяти, если факультетов меньше 20.
	*/

	University university;
	university.addFaculty("ФВТ");
	university.addFaculty("ФРТ");
	university.addFaculty("ФЭ");
	university.addFaculty("ФАИТУ");
	university.printAbout();
	
	//удаляем один факультет
	university.removeFaculty("ФРТ");
	university.printAbout();

	/*
		Как видно из этого примера наличие лишь полей-указателей не
		делает отношение объектов агрегацией. Важно кто управляет временем
		их жизней.
	*/
	
	return 0;
}

