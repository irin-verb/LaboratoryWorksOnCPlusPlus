#include <iostream> 
#include <strings.h>

using namespace std;

class Dummy
{
	int justNum = 10;
public:
	
	Dummy() { cout << "Dummy()" << endl; }
	~Dummy() { cout << "~Dummy()" << endl; }	
	
	void printHello() { cout << "ѕривет!" << endl; }
	void printNum() { cout << justNum << endl; }
};

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	// выделение пам€ти дл€ переменной

	int* ptr = new int;
	*ptr = 5;
	cout << *ptr << endl << endl;
	
	delete ptr; 
	ptr = nullptr;
	
	// выделение пам€ти дл€ массива
	
	ptr = new int[10];
	
	for(int i = 0; i < 10; ++i)
		ptr[i] = rand() % 10;
		
	
	for(int i = 0; i < 10; ++i)
		cout << ptr[i] << " ";
	cout << endl << endl;
	
	delete[] ptr;
	ptr = nullptr;
	
	// выделение пам€ти дл€ класса
	
	//auto objPtr = new Dummy(); // с помощью auto можно вывести тип из выражени€ инициализации
	Dummy* objPtr = new Dummy(); // здесь можно передать параметры в конструктор
	
	objPtr->printHello(); // также как и в указател€х на структуры используетс€ -> дл€ доступа к пол€м
	//аналогично (*objPtr).sayHello();
	objPtr->printNum();
	
	delete objPtr; 
	objPtr = nullptr;
	
	cout << endl;
	
	// при использовании malloc выделитс€ только пам€ть, 
	// конструктор не вызываетс€! Ќ≈ нужно использовать дл€ классов

	objPtr = (Dummy*) malloc(sizeof(Dummy));
	objPtr->printHello(); 
	objPtr->printNum();  // инициализаци€ пол€ не произошла, будет выведен мусор
	free(objPtr); 
	objPtr = NULL;
	
	
	return 0;
}

