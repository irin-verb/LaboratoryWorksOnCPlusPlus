#include <iostream> 
#include <strings.h>

using namespace std;

/*
	В данном примере создадим ассоциативную двунаправленную связь 
	между классами Doctor и Patient
*/

/*
 т.к. функционал динамического массива указателей на объекты у нас
 будет повторятся вынесем его в отдельный класс. 
 В данном случае идеально будет использовать шаблонный класс. Но т.к.
 мы его ещё не изучали, то мы применим хитрость и будем использовать
 приведение базового класса к классу-потомка.
*/

// класс Object, который нам позволит приводить указатели
// к конкретному классу. Заодно вынесем в него функционал
// хранения поля имени объекта.
class Object 
{ 
	char name[128];
public:
	
	Object(const char* name = nullptr)	
	{
		strcpy(this->name, name? name : "нет имени");  
	}
	
	const char* getName() 	{ return name; }
	virtual void printAbout() = 0;
};

void Object::printAbout() 
{
	cout << "Имя: " << name << endl;
}


// класс для хранения указателей на любые объекты, наследуемые от Object
// он почти аналогичен предыдущему примеру
class PtrArray
{
    Object** array;
    int count = 0; 
    int capacity;
    
    void alloc(int capacity)
    {
    	if(capacity <= this->capacity) return;
    	
    	Object** arrayExtend = new Object*[capacity];
    	
    	for(int i = 0; i < count; ++i)
    		arrayExtend[i] = array[i];
    	
    	if(this->capacity) 
			delete[] array;
			
		array = arrayExtend;	
    	this->capacity = capacity;
	}
	
public:
	
	PtrArray()
	{
		alloc(10);
	}
	
	~PtrArray()
	{
		if(capacity)
			delete[] array;
	}
	
	// удаляем конструктор копии и оператор присваивания
	// т.к. иначе нам придётся их переопределять 
	PtrArray(const PtrArray& other) = delete;
	PtrArray& operator=(const PtrArray& other) = delete;
	
    void add(Object* object)
    {
    	if(count == capacity)  alloc(capacity * 2); 
    	array[count++] = object;
	}
	
    void remove(const Object* object)
    {
    	for(int i = 0; i < count; ++i)
    		if(array[i] == object) 
    		{
    			for(int j = i + 1; j < count; ++j)
    				array[j - 1] = array[j];
    			--count;
    			return;
			}
	}
	
	void clear() { count = 0; }
	int length() { return count; }
	
	// получаем указатель по индексу в динамическом массиве
	Object* operator[](int i) 
	{
		return array[i];
	}
};


// Поскольку отношения между классами Patient и Doctor двунаправленные, 
//то для класса Doctor здесь нужно использовать предварительное объявление
class Doctor;
 
class Patient: public Object
{
	PtrArray doctors; 
	int policyID; // номер полиса
	
	// метод addDoctor() и removeDoctor()  закрытый, так как 
	// доступ к нему будет осуществляться через класс Doctor
	// это логично, т.к. доктор регистрирует пациента, а не наоборот
	void addDoctor(Doctor* doc);
	void removeDoctor(Doctor* doc);
	
public:
	
	Patient(const char* name, int policyID) : Object(name), policyID(policyID)
	{
	}
	
	int getPolicyID() { return policyID; }
	
	virtual void printAbout() override;
 
	// Сделаем класс Doctor дружественным, чтобы иметь доступ 
	// к закрытым методам addDoctor() и removeDoctor()
	friend class Doctor;
};
 
class Doctor: public Object
{
	PtrArray patients;
 
public:
	
	Doctor(const char* name) : Object(name)
	{
	}
 
	void addPatient(Patient* pat)
	{
		// Врач добавляет Пациента
		patients.add(pat);
		
		// Пациент добавляет Врача
		pat->addDoctor(this);
	}
	
	void removePatient(Patient* pat)
	{
		// Врач удаляет Пациента
		patients.remove(pat);
		
		// Пациент удаляет Врача
		pat->removeDoctor(this);
	}
	
	virtual void printAbout() override
	{
		Object::printAbout();
		cout << "лечит ";
		
		/*
			далее в этом примере мы обращаемся к методам getName() и getPolicyID()
			т.к. getName() - это метод класса Object, и оператор[] возвращает указатель
			на Object - мы вызываем его обычным образом.
			
			но метод getPolicyID() находится в классе Patient, а оператор[] возвращает Object*
			Поэтому мы явно преобразуем указатель с Object* в  Patient*, потому что мы уверены
			в данном случае, что эта операция преобразования будет допустима.
		*/
		
		for(int i = 0; i < patients.length(); ++i)
			cout << patients[i]->getName() << "(полис " << ((Patient*)patients[i])->getPolicyID() << ") ";
		
		cout << endl;
	}
};

/*
	пришлось тела методов вынести отдельно после класса доктора, 
	т.к. у нас класс доктора описан	после класса пациента
*/

void Patient::addDoctor(Doctor* doc)
{
	doctors.add(doc);
}

void Patient::removeDoctor(Doctor* doc)
{
	doctors.remove(doc);
}

void Patient::printAbout()
{
	Object::printAbout();
	cout << "лечится у ";
	for(int i = 0; i < doctors.length(); ++i)
		cout << doctors[i]->getName() << " ";
	cout << endl;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	// Создаём пациентов и докторов
	Patient* p1 = new Patient("Иванов",239546);
	Patient* p2 = new Patient("Петров",38478);
	Patient* p3 = new Patient("Сидоров",856636);
	Doctor* d1 = new Doctor("Смирнов");
	Doctor* d2 = new Doctor("Дорофеев");
	
	//назначаем связи - ассоциации
	d1->addPatient(p1);
	d1->addPatient(p2);
	
	d2->addPatient(p1);
	d2->addPatient(p3);
	
	//выводим информацию
	p1->printAbout();
	p2->printAbout();
	p3->printAbout();
	
	d1->printAbout();
	d2->printAbout();
	
	//пациент Иванов перестал лечится у доктора Дорофеева
	d1->removePatient(p1);
	
	cout << endl;
	
	//отображаем изменения в консоль
	p1->printAbout();
	d1->printAbout();
	
	//не забываем очищать память
	delete p1;
	delete p2;
	delete p3;
	delete d1;
	delete d2;
	
	/*
		Таким образом классы Patient и Doctor находятся в двунаправленной
		ассоциативной связи. Нельзя сказать что первый является "частью" второго
		или наоборот. Каждый из них может находится также в ассоциативной
		связи с другими экземплярами.
	*/
	
	return 0;
}

