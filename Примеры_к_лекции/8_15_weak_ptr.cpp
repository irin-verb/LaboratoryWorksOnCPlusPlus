#include <iostream> 
#include <memory>

using namespace std;

/*
   Умный указатель weak_ptr был разработан для решения проблемы «циклической зависимости», 
   weak_ptr является наблюдателем — он может наблюдать и получать доступ к тому же объекту, 
   на который указывает shared_ptr (или другой weak_ptr), но не считаться владельцем этого объекта. 
   Когда shared_ptr выходит из области видимости, он проверяет, есть ли другие владельцы shared_ptr. 
   weak_ptr владельцем не считается!
*/

class Human
{
	string name;
	
	// тут используется weak_ptr, и эти указатели не учитываются при подсчёте ссылок
	weak_ptr<Human> partner; 
 
public:
		
	Human(const string& name): name(name)
	{ 
		cout << name << " создан!" << endl; 
	}
	~Human()
	{
		cout << name << " уничтожен!" << endl; 
	}
	
	/*
		Недостатком weak_ptr является то, что его нельзя использовать напрямую (нет оператора ->). 
		Чтобы использовать weak_ptr, сначала нужно конвертировать его в shared_ptr с помощью lock(), 
		а затем уже использовать как shared_ptr. 
	*/
	const shared_ptr<Human> getPartner() const 
	{ 
		return partner.lock(); 
	} 
	
	const string& getName() const { return name; }
 
	friend bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2);
};
 
 
bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2)
{
	if (!h1 || !h2)
		return false;

	h1->partner = h2;
	h2->partner = h1;
	
	return true;
}


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	auto ivan = std::make_shared<Human>("Иван"); 
	auto vlad = std::make_shared<Human>("Владимир"); 
 
	partnerUp(vlad, ivan); // создаём ассоциативную связь
	
	auto partner = ivan->getPartner(); // передаем partner-у содержимое умного указателя, которым владеет ivan
	cout << ivan->getName() << " находится в партнерстве с " << partner->getName() << endl;

	// теперь объекты будут удалены!

	
	return 0;
}

