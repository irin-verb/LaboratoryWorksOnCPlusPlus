#include <iostream> 
#include <memory>

using namespace std;

/*
	shared_ptr может служить проблемой при "циклической" зависимости,
	когда между объектами, например, существует двусторонн€€ св€зь:
*/


class Human
{
	string name;
	shared_ptr<Human> partner; 
 
public:
		
	Human(const string& name): name(name)
	{ 
		cout << name << " создан!" << endl; 
	}
	~Human()
	{
		cout << name << " уничтожен!" << endl; 
	}
 
	friend bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2);
};
 
 
bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2)
{
	if (!h1 || !h2)
		return false;

	h1->partner = h2;
	h2->partner = h1;

	cout << h1->name << " €вл€етс€ партнером " << h2->name << endl;

	return true;
}


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	auto ivan = std::make_shared<Human>("»ван"); 
	auto vlad = std::make_shared<Human>("¬ладимир"); 
 
	partnerUp(vlad, ivan); // создаЄм двустороннюю св€зь
	
	// ...
	// объекты удалены не будут из-за циклической зависимости!
	// ...
	
	return 0;
}

