#include <iostream> 

//подключаем описание ассоциативного массива
#include <map>

using namespace std;

int main(int argc, char** argv) 
{
	system("chcp 1251");

	// объявляем асс. массив c ключами char, значениями - int
	map<char,int> map1;
	
	// добавляем один элемент, 
	map1.insert(pair<char,int>('Z',5));
	map1.insert(pair<char,int>('Y',7));
	map1.insert(pair<char,int>('X',9));
	/* Специальный шаблонный класс pair позволяет инкапсулировать
		в себе пару значений (в нашем случае ключ-значение)
		обращаться к элементам пары можно через
		pair->first и pair->second
	*/
	
	//можно добавлять несколько через список инициализации
	map1.insert({{'R',1},{'T',2},{'B',4}});
	
	//Перебрать все элементы можно через итератор
	for (auto it = map1.begin(); it != map1.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
		/*
			Обратите внимание! Порядок в ассоциативных контейнерах
			не важен, поэтому получаем элементы НЕ в порядке их
			добавления (в данном случае в ассоциативном контейнере 
			они сортируются по возрастанию)
		*/
	}
	cout << endl;
	
	//изменять значения элементов можно через оператор [<ключ>] = <значение>
	map1['R'] = 99;
	//или через метод at()
	map1.at('X') = -66;
		
	//удалять можно через erase
	map1.erase('Z');
	
	//перебирать элементы можно также через range for
	for (auto& elem : map1)
		cout << elem.first << " : " << elem.second << endl;
	
	auto it = map1.find('B');
	if(it != map1.end())
		cout << "Найден элемент: ['"<< it->first << "']=" << it->second<< endl;
	else
		cout << "Элемента нет!" << endl;
	
	//очистка асс. массива и проверка на пустой массив 
	map1.clear();
	if(map1.empty()) 
		cout << "map1 пустой!" << endl;
		
	cout << endl;
		
	// создаём multimap, который может содержать несколько значений с одинаковым ключем
	multimap<char,int> map2 = {{'G',5},{'H',3},{'Z',5},{'H',7},{'Z',8},{'Z',2},{'A',5},{'G',6}};
	for (auto& elem : map2)
		cout << elem.first << " : " << elem.second << endl;
		
	// оператор [] для multimap отключен
	// map2['G'] = 5; // error!
	
	// find возвратит итератор на первый элемент с указаным ключём
	it = map2.find('Z');
	if(it != map2.end())
	{
		while(it != map2.end() && it->first=='Z') // перебираем все элементы с заданным ключем
		{
			cout << "Найден элемент: ['"<< it->first << "']=" << it->second<< endl;
			++it;
		}
	}
	else
		cout << "Элемента нет!" << endl;
	
	return 0;
}

