#include <iostream> 


//подключаем описание списка
#include <list>

using namespace std;

void printVals(const list<int>& lst)
{
	for(auto& item : lst)
		cout << item << " ";
	cout << endl;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	//инициализация списка
	list<int> list1;             	 // пустой список
	list<int> list2(5);          	 // list2 состоит из 5 чисел, каждый элемент имеет значение по умолчанию
	list<int> list3(5, 2);           // list3 состоит из 5 чисел, каждое число равно 2
	list<int> list4{ 1, 2, 4, 5 };   // list4 состоит из чисел 1, 2, 4, 5
	list<int> list5 = { 1, 2, 3, 5 };// list5 состоит из чисел 1, 2, 4, 5
	list<int> list6(list5);          // list6 - копия списка list5
	list<int> list7 = list6;         // list7 - копия списка list6
	
	/*
	у list нет прямого доступа к элементу по индексу at()
	можно обращаться только к первому или последнему элементу через front() и back().
	для доступа к элементам в середине нужно перебирать элементы
	с помощью циклов и итераторов
	*/
	std::list<int> numbers = { 11, 22, 33, 44, 55 };
    int first = numbers.front();  // 11
    int last = numbers.back();  // 55
    //перебор итератором
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
        cout << (*iter) << " ";
    cout << endl;
    //перебор циклом
    for (int n : numbers)
        cout << n << " ";
    cout << endl << endl;
    
    /* дейсвия методов для list аналогичны вектору:
    size() empty() resize() assign() swap() push_back() pop_back() 
	insert() clear() erase()
    */
    
    /* также в list появились методы по работе с первым элементом
    pop_front() - удалить первый элемент списка
    push_front(val) - добавить val в начало списка
    */
    printVals(numbers);
    numbers.pop_front();
    printVals(numbers);
    numbers.push_front(999);
    printVals(numbers);
	
	return 0;
}

