#include <iostream> 

#include <vector> 
#include <stack> 
#include <list> 
#include <queue> 

using namespace std;

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	// СТЕК
	
	// по-умолчанию на базе deque
	stack<char> st; 
	
	//указываем что хотим использовать vector
	stack<char, vector<char>> vst (vector<char>({'X','Y','Z'})); 
	
	vst.push('#');
	
	while (!vst.empty()) 
	{
		cout << vst.top() << " : в стеке строк " << vst.size() << endl;
		vst.pop();
	}
	cout << "стек " << (vst.empty() ? "" : "не ") << "пуст" << endl;
	
	/*
		Легко понять что адаптер stack потерял присущие базовому контейнеру
		методы at(), [] и т.д. но приобрёл top(), push(), pop() и т.д.
	*/
	
	// ОЧЕРЕДЬ
	
	// по-умолчанию на базе deque
	queue<char> que; 
	
	// указываем что хотим использовать list
	queue<char, list<char>> lque(list<char>({ 'A', 'B', 'C' }));
	
	lque.push('#');
	
	while (!lque.empty()) 
	{
		cout << lque.front() << " : в очереди строк " << lque.size() << endl;
		lque.pop();
	}
	cout << "очередь " << (lque.empty() ? "" : "не ") << "пуста" << endl;
	
	/*
		Очередь не может быть построена на базовом контейнере vector, 
		т.к. у него нет метода pop_front()
		
		У queue нет метода top(), но есть аналогичный front()
	*/
	return 0;
}

