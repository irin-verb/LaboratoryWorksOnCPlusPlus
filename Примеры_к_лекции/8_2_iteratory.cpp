#include <iostream> 
#include <strings.h>
#include <vector>

using namespace std;

void printVals(const vector<int>& vec)
{
	for(int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	// Итерация по вектору
    vector<int> vec;
    for (int i=0; i < 5; ++i) 
		vec.push_back(i + 1);
    
	vector<int>::const_iterator it; // объявляем объект итератора
    it = vec.begin(); // присваеваем ему начальную позицию в векторе
    while (it != vec.end()) // продолжаем пока итератор не укажет на конец вектора
    {
        cout << *it << " "; // разыменовываем итератор, чтобы получить значение элемента
        					// на который он указывает в данный момент
        ++it; // сдвигаем итератор на следующий элемент вектора
    }	
    cout << endl;
    
    //Итерация по вектору через for
    //удобно использовать auto при объявлении итератора
    for(auto it = vec.cbegin(); it != vec.cend(); ++it)
		cout << *it << " ";
    cout << endl << endl;
    
    
    //вставка элементов через итератор и метод insert()
	std::vector<int> numbers = { 1, 2, 3, 4, 5 };
	auto iter = numbers.cbegin(); // итератор указывает на начало
	numbers.insert(iter + 2, 8); // insert(pos, value) вставляем элемент 8 на позицию 2
								 // возвращает итератор на вставленный элемент
	printVals(numbers);
	
	// ВАЖНО: после изменения размера массива итератор инвалидируется!
	// после методов insert, resize, push_back, pop_back, clear, swap...
	// поэтому важно его перезаписать если подразумевается дальнейшее использование
	iter = numbers.cbegin();
	numbers.insert(iter + 1, 3, 4); // insert(pos, n, value) добавляем после первого элемента три четвёрки 
									// возвращает итератор на первый вставленный элемент
	printVals(numbers);
	cout << endl;
	
	numbers = { 1, 2, 3, 4, 5 };
	std::vector<int> values = { 10, 20, 30, 40, 50 };
	iter = numbers.cbegin(); 
	// insert(pos, begin, end) добавляем после первого элемента три элемента из values
	numbers.insert(iter + 1, values.begin(), values.begin() + 3);
	printVals(numbers);
	iter = numbers.cbegin(); 
	//insert(pos, values) - вставляем конкретный список значений начиная с указанной итератором
	numbers.insert(iter + 5,{ 21, 22, 23 });
	printVals(numbers);
	cout << endl;
	
	//удаление элементов через итератор и метод erase()
	numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printVals(numbers);
	iter = numbers.cbegin();
	// erase(p) - удаляет элемент на который указывает итератор 
	// Возвращает итератор на элемент, следующий после удаленного, или конец контейнера (если был удалён последний)
	numbers.erase(iter + 3); 
	printVals(numbers);
	//erase(begin, end) - удаляет все элементы из заданного итераторами диапазона
	numbers.erase(numbers.cbegin() + 2, numbers.cend()  - 2); //оставить только первые и последние два элемента
	printVals(numbers);
	cout << endl;
	
	// Диапазонный цикл for (c C++11)
	// используется как упрощённый эквивалент обычного цикла for 
	// можно использовать для перебора всех элементов в контейнере
	vector<int> v = {11, 22, 33, 44, 55};
    for (const int& i : v) // доступ по конст. ссылке (можно использовать const auto&)
        cout << i << " ";
    cout << endl;
    for (int& i : v) // доступ по ссылке (можно использовать auto&)
        i+=10;
    printVals(v);
    for (int i : v) // доступ по значению (можно использовать auto)
        i+=10;
    printVals(v);
    cout << endl;
    int a[] = {9, 8, 9, 7, 9, 6};
    for (int n : a) // инициализатор может быть обычным массивом
        cout << n << " ";
    cout << endl << endl;
    
	return 0;
}

