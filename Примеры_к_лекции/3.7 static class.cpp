#include <iostream> 
#include <strings.h>
#include <stdlib.h>

using namespace std;

// в классе Object ведетс€ подсчЄт кол-ва активных экземпл€ров
// а также присваиваютс€ уникальные номера
class Object
{
	static int nextId; // следующий присваиваемый номер
	static int curAlive; //текущее кол-во экземпл€ров данного класса
	
	int id;
public:
		
	Object() 
	{
		id = nextId++;
		++curAlive;
	}
	
	~Object() 
	{
		--curAlive;
	}
	
	void print()
	{
		cout << "ќбъект є" << id << endl;
	}
	
	//статический метод выводит информацию по кол-ву объектов класса
	static void printTotalInfo()
	{
		cout << "Ѕыло создано " << nextId - 1 << " объектов. —ейчас активно:" << curAlive << endl;
	}
};

//статические пол€ можно инициализировать только таким образом:
int Object::nextId = 1;
int Object::curAlive = 0;

int main(int argc, char** argv) 
{
	system("chcp 1251");

	//создаЄм 3 объекта в локальной области видимости функции main
	Object obj1, obj2, obj3;
	obj2.print();
	Object::printTotalInfo();
	
	{ // создаЄм ещЄ 3 объекта в своей локальной области
		Object obj4, obj5, obj6;
		obj5.print();
		Object::printTotalInfo();
	} // здесь объекты obj4, obj5, obj6 будут уничтожены
	
	Object::printTotalInfo();
	
	return 0;
}

