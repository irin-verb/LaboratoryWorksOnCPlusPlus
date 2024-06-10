#include <iostream> 

using namespace std;


 
template<class T>
class SmartPtr
{
	T* ptr;
public:
	// ѕолучаем указатель дл€ "владени€" через конструктор
	// SmartPtr теперь имеет композиционную св€зь с ptr и
	// полностью управл€ет жизненым циклом данного указател€
	SmartPtr(T* ptr=nullptr)
		:ptr(ptr)
	{
	}
	
	// ƒеструктор позаботитс€ об удалении указател€
	~SmartPtr()
	{
		delete ptr;
	}
 
	// ¬ыполн€ем перегрузку оператора разыменовани€ и оператора ->, 
	// чтобы иметь возможность использовать SmartPtr как обычный указатель 
	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
};
 
//  ласс дл€ проверки работы умного указател€
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
};
 
 
int main(int argc, char** argv)
{
	system("chcp 1251");
	
	// MyClass в угловых скобках не требуетс€ символ *, 
	// поскольку это предоставл€етс€ шаблоном класса
	
	// динамическое выделение пам€ти
	SmartPtr<MyClass> obj1(new MyClass({"ќбъект 1"})); 

	{
		// динамическое выделение пам€ти
		SmartPtr<MyClass> obj2(new MyClass(string("ќбъект 2"))); 
		
	 	// ...
	    // никакого €вного delete здесь не нужно!
	    // ...
		
		
	} // obj2 выходит из области видимости и уничтожает выделенный MyClass автоматически
 
 
	return 0;
} // obj1 выходит из области видимости и уничтожает выделенный MyClass автоматически

