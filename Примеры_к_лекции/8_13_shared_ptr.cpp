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

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	//shared_ptr предназначен для случаев, когда несколько умных указателей совместно 
	//владеют одним динамически выделенным ресурсом.
	MyClass* obj1 = new MyClass(string("Объект 1"));
	shared_ptr<MyClass> obj1Ptr1(obj1);
	obj1Ptr1->sayMyName();
	
	{
		// можно использовать копирующую инициализацию
		shared_ptr<MyClass> obj1Ptr2(obj1Ptr1);
		obj1Ptr2->sayMyName();
		
		// но нельзя создавать новый shared_ptr из уже управляемого указателя
		// т.к. это будут считаться два разных указателя!
		// всегда нужно выполнять копирование уже существующего shared_ptr
		
		//shared_ptr<MyClass> obj1Ptr3(obj1); //error!
	}
	obj1Ptr1->sayMyName();
	
	// аналогично make_unique() есть функция make_shared(), которая появилась с С++11
	auto obj2Ptr1 = make_shared<MyClass>(string("Объект 2"));
	{
		auto obj2Ptr2 = obj2Ptr1; // создаем obj2Ptr2 из obj2Ptr1, используя семантику копирования
	} 

	/*
		unique_ptr может быть конвертирован в shared_ptr через специальный конструктор, 
		принимающий unique_ptr. 

		Однако shared_ptr нельзя безопасно конвертировать в unique_ptr. Поэтому, если 
		необходимо создать функцию, которая будет возвращать умный указатель, лучше возвращать 
		unique_ptr и затем присваивать его shared_ptr, когда это будет уместно.
	*/
	
	return 0;
}

