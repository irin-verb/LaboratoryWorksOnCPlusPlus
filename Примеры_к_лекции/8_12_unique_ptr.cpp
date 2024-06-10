#include <iostream> 
#include <memory>

using namespace std;

// Класс для проверки работы умного указателя
class MyClass
{
	string name;
public:
    MyClass(const string& name) : name(name) 
	{ 
		cout << name << " создан!" << endl; 
	}
	
    ~MyClass() 
	{ 
		cout << name << " уничтожен!" << endl; 
	}
	
	void sayMyName() const
	{
		cout << "Моё имя " << name << "!" << endl;
	}
};


unique_ptr<MyClass> createObject(const string& name)
{
	unique_ptr<MyClass> ptr(new MyClass(name)); // создан указатель локально
	
	// ...
	
	return ptr;
}

void getByValue(unique_ptr<MyClass> objPtr)
{
	//теперь getByValue владеет объектом, на который указывает obj
	if (objPtr) 
		objPtr->sayMyName();
	
} //здесь объект на который указывает objPtr уничтожается


void getByRef(const unique_ptr<MyClass>& objPtr)
{
	//при передаче по ссылке право владения не передаётся.
	
	if (objPtr) 
		objPtr->sayMyName();
	
}
void getByRawPointer(const MyClass* obj)
{
	//функция не знает как управляется память для объекта
	
	if (obj) 
		obj->sayMyName();
	
}

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	{
		//unique_ptr является заменой auto_ptr в C++11
		MyClass* obj1 = new MyClass(string("Объект 1"));
		unique_ptr<MyClass> obj1Ptr(obj1); // передаём право собственности obj1Ptr на obj1
		//obj1 = nullptr; // obj1 теперь управляется через obj1Ptr, прямая ссылка нам больше не нужна, лучше её занулить
		
		/* Нельзя:
		
		 1) позволять нескольким unique_ptr владеть одним и тем же ресурсом (хотя это синтаксически допустимо).
			MyClass* obj1 = new MyClass(string("Объект 1"));
			unique_ptr<MyClass> ptr1(obj1);
			unique_ptr<MyClass> ptr2(obj1);
			
		 2) не удалять выделеный вручную объект, переданый в unique_ptr.
			MyClass* obj1 = new MyClass(string("Объект 1"));
			unique_ptr<MyClass> obj1Ptr(obj1);
			delete obj1;
		*/
		
		
	} // obj1 будет уничтожен через obj1Ptr
	
	cout << endl;
	
	
	// unique_ptr корректно реализует семантику перемещения
	unique_ptr<MyClass> pA1(new MyClass(string("Объект A")));
	unique_ptr<MyClass> pA2;
	
	cout << (static_cast<bool>(pA1) ? "pA1 not null\n" : "pA1 null\n");
	cout << (static_cast<bool>(pA2) ? "pA2 not null\n" : "pA2 null\n");

	// pA2 = pA1; // не скомпилируется, т.к. семантика копирования запрещена!
	pA2 = move(pA1); // через std::move() передаём право владения из pA1 в pA2, теперь pA1 == nullptr
	
	cout << (static_cast<bool>(pA1) ? "pA1 not null\n" : "pA1 null\n");
	cout << (static_cast<bool>(pA2) ? "pA2 not null\n" : "pA2 null\n");
	
	cout << endl;
	
	//Доступ к самому объекту осуществляется через перегруженные * и -> как и в обычных указателях
	(*pA2).sayMyName();
	pA2->sayMyName();
	
	cout << endl;
	
	//unique_ptr можно использовать также и для динамических массивов, хотя предпочтительнее использовать vector
	{
		unique_ptr<int[]> arr(new int[10]);
		for(int t = 0; t < 10; ++t) arr[t] = t * t;
		for(int t = 0; t < 10; ++t) cout << arr[t] << " ";
		cout << endl;
	} // arr будет удалён корректно! unique_ptr понимает что нужно использовать delete[]
	
	cout << endl;
	
	// В C++14 добавили новую шаблонную функцию — std::make_unique(). 
	// Она создает объект типа шаблона и инициализирует его аргументами, переданными в функцию. 
	// Рекомендуется использовать всегда, вместо непосредственного создания объекта и передачи в unique_ptr
	
	// unique_ptr<MyClass> pB = make_unique<MyClass>(string("Объект B"));
	
	// auto позволяет ещё больше сократить запись
	// auto pC = make_unique<MyClass>(string("Объект C")); 
	
	
	// unique_ptr можно возвращать из функции по значению
	// если при этом значение не присваивается какому-либо объекту, то указатель
	// выходит из области видимости и удаляется, а если присваиввается - то с помощью
	// семантики перемещения перемещается в нужный объект. 
	// Нет смысла возвращать unique_ptr по адресу или ссылке без веских причин.
	/*auto ptr =*/ createObject("Объект, созданый в функции");
	
	cout << endl;
	
	// в функцию unique_ptr следует передавать по значению (через move), если вы хотите
	// передать владение указателем, иначе нужно передавать по ссылке.
	// однако во многих случаях можно просто получить raw указатель\ссылку на объект и передать
	// его в функцию, т.к. функции не зачем знать, каким образом и через какой указатель
	// управляется память объекта
	unique_ptr<MyClass> pObjParam(new MyClass(string("Объект, передаваемый как параметр")));
	getByRef(pObjParam);
	getByRawPointer(pObjParam.get()); // get() возвращает raw указатель
	getByValue(move(pObjParam)); //используем move т.к. прямое копирование запрещено!
	cout << (static_cast<bool>(pObjParam) ? "pObjParam not null\n" : "pObjParam null\n");
	
	cout << endl;

	// unique_ptr может использоваться и как член композиции класса 
	// (не нужно беспокоится об очистке его объекта в деструкторе). 
	
	
	cout << "конец программы" << endl;
	
	return 0;
}

