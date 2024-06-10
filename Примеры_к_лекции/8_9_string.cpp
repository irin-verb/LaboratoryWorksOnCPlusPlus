#include <iostream> 

#include <string> 

using namespace std;


int main(int argc, char** argv) 
{
	system("chcp 1251");
	

	

	
	//можно инициализировать при объявлении
	string str("Hello!");
	cout << str << endl;
	//можно присваивать новое значение
	str = "Hi";
	cout << str << endl;
	//вставлять символы в конец:
	str.push_back('!');
	cout << str << endl;
	//или в любое место через insert
	str.insert(0,"You say: ");
	cout << str << endl;
	//можно конкатенировать строки через оператор +
	str += " Have a nice day!";
	cout << str << endl;
	//можно удалить часть строки через erase
	str.erase(3,4);
	cout << str << endl;
	//заменить часть строки через replace
	str.replace(16,4,"good",4);
	cout << str << endl;
	//обращаться к символам через []
	cout << str[5] << " - это 6-й символ строки str" << endl;
	//длину строки можно получить через length()
	cout << "Текущая длина строки str " << str.length() << " символов." << endl;
	//очистить строку
	str.clear();
	if(str.empty())
		cout << "str пустая!" << endl;
	
	
	//Конверсии
	// string to int, string  to float
	string strI = "43";
	string strF = "13.3333";
	int i = stoi(strI);
	float f = stof(strF);
	cout << "i=" << i << " f=" << f << endl;
	// string to char*
	string myString = "Просто строка";
	const char *cstr = myString.c_str(); 
	//c_str() возвращает константный указатель на
	//хранимый в string массив символов
	cout << cstr << endl;
	// int, float to string
	int a = 40;
	float b = 40.123f;
	string strA = to_string(a), strB = to_string(b);
	cout << "a=" << strA << " b=" << strB << endl;

	
	// --------------------
	
	// ввод строк через стандартный поток ввода cin:
	string name;
	cout << "Ваше имя? ";
	cin >> name; //Важно! Считает из потока только до первого пробела!
	//если нужно считать всю строку - надо использовать getline
	//getline(cin,name);
	cout << name << endl;
	
	
	//также с getline может возникнуть проблема со считыванием строки 
	//после ввода других данных
	int t;
	cout << "Введите число:";
	cin >> t;
	cout << t << endl;
	
	/*
		ввод строки просто будет пропущен. Это происходит из-за того, что
		по сути мы в поток ввода ввели "42\n", 42 - будет занесен в t, а
		'\n' останется в потоке ввода. И именно его первым считает следующий
		getline и посчитает что ввод был завершён. Чтобы такого не происходило
		следует очистить буфер ввода от этого символа через метод ignore()
	*/
	//cin.ignore(32767,'\n');
	cout << "Введите строку:";
	getline(cin,name);
	cout << name << endl;
	
	
	
	return 0;
}

