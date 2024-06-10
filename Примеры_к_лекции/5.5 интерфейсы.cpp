#include <iostream> 
#include <strings.h>

using namespace std;

/*
Некоторые языки, такие как Java и C#, даже добавили в свой синтаксис 
ключевое слово interface, которое позволяет программистам напрямую 
определять интерфейсный класс, не указывая явно,  что все методы 
являются абстрактными.
*/

//единый интерфейс описывает реализуемые объектами операции
class IGreetinger
{
public:
	
	virtual ~IGreetinger() {}		
	virtual void greeting() const = 0;		
	virtual const char* getName() const = 0;		
};

//объект 1, реализует интерфейс, поэтому обязан описать все его абстрактные функции
class Hellower: public IGreetinger
{
public:	
	const char* getName() const { return "Hellower"; }
	void greeting() const override { cout << "Hello!" << endl; };		
};

//объект 2, реализует интерфейс, поэтому обязан описать все его абстрактные функции
class Heyer: public IGreetinger
{
public:	
	const char* getName() const { return "Heyer"; }
	void greeting() const override { cout << "Hey!" << endl; };		
};

//функция работает с интерфейсом, поэтому ей всё равно какая будет конечная реализация
void whatAboutThisObject(const IGreetinger& greetinger)
{
	cout << "Это " << greetinger.getName() << " и он говорит: ";
	greetinger.greeting();
	cout << endl;
}

// можем легко добавлять новые классы, а whatAboutThisObject не будет изменяться при этом
//class Hier: public IGreetinger
//{
//public:	
//	const char* getName() const { return "Hier"; }
//	void greeting() const override { cout << "Hi!" << endl; };		
//};

int main(int argc, char** argv) 
{
	system("chcp 1251");


	IGreetinger* greetinger1 = new Hellower();
	IGreetinger* greetinger2 = new Heyer();
//	IGreetinger* greetinger3 = new Hier();
	
	// для передачи указателя как параметр-ссылка его надо разыменовать
	whatAboutThisObject(*greetinger1); 
	whatAboutThisObject(*greetinger2);
//	whatAboutThisObject(*greetinger3);

	delete greetinger1;
	delete greetinger2;
	//delete greetinger3;
	
	return 0;
}

