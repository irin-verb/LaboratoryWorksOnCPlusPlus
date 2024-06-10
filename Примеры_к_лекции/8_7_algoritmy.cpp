#include <iostream> 

#include <vector> 
#include <list>
#include <algorithm>  


using namespace std;

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	vector<int> vec {5,-3,3,7,9};
	list<char> lst {'A','Z','F','X','B'};
	
	// нахождение минимального и максимального элемента
	// с помощью алгоритмов min_element и max_element
	
	vector<int>::const_iterator it; 
    it = min_element(vec.begin(), vec.end());
	cout << "Минимальный элемент в векторе: " << *it << endl;
    it = max_element(vec.begin(), vec.end());
	cout << "Максимальный элемент в векторе: " << *it << endl;
	
	list<char>::const_iterator it2; 
    it2 = min_element(lst.begin(), lst.end());
	cout << "Минимальный элемент в списке: " << *it2 << endl;
    it2 = max_element(lst.begin(), lst.end());
	cout << "Максимальный элемент в списке: " << *it2 << endl;
	cout << endl;
	
	// поиск элемента и вставка с помощью find и insert
	auto it3 = find(vec.begin(), vec.end(), -3); // ищем в векторе -3
	vec.insert(it3,0); //вставляем перед ним элемент 0
	
	for(auto& elem : vec) cout << elem << ' ';
	cout << endl << endl;
	
	// алгоритмы сортировки и реверса
	sort(vec.begin(), vec.end());
	reverse(lst.begin(), lst.end());
	
	for(auto& elem : vec) cout << elem << ' ';
	cout << endl;
	
	for(auto& elem : lst) cout << elem << ' ';
	cout << endl;
	
	return 0;
}

