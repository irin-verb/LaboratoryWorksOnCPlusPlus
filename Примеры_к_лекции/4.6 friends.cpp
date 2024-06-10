#include <iostream> 
#include <strings.h>

using namespace std;

class Data
{
private:
	
	//какие-то приватные поля с данными:
	float data1;
	int data2;
	const char* data3;
	
public:
	
	Data() : data1(4.5f), data2(5), data3("Просто строка")  { }
	
	//позволяет функции print получить доступ к приватным полям класса Data
	friend void print(const Data&);
	//позволяет классу Printer получить доступ к приватным полям класса Data
	friend class Printer;
};

//друг класса Data
void print(const Data& data)
{
	cout<<"Приватные поля Data: " 
		<< " data1=" << data.data1 
		<< " data2=" << data.data2 
		<< " data3=" << data.data3
		<< endl;
}

//друг класса Data
class Printer
{
private:
	// приватный конструктор предотвращает возможность создания экземпляров класса
	// используется например для статических классов, синглетонов и т.д.
	Printer() { } 
	
public:
	
	static print(const Data& data)	
	{
		cout<<"Приватные поля Data: " 
			<< " data1=" << data.data1 
			<< " data2=" << data.data2 
			<< " data3=" << data.data3
			<< endl;	
	}
		
};





int main(int argc, char** argv) 
{
	system("chcp 1251");

	Data data;
	
	print(data);
	
	Printer::print(data);
	
	//приватный конструктор не даст создать экземпляр Printer
	//Printer printer;
	
	return 0;
}

