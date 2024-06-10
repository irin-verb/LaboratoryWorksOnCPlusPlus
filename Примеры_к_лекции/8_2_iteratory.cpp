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

	// �������� �� �������
    vector<int> vec;
    for (int i=0; i < 5; ++i) 
		vec.push_back(i + 1);
    
	vector<int>::const_iterator it; // ��������� ������ ���������
    it = vec.begin(); // ����������� ��� ��������� ������� � �������
    while (it != vec.end()) // ���������� ���� �������� �� ������ �� ����� �������
    {
        cout << *it << " "; // �������������� ��������, ����� �������� �������� ��������
        					// �� ������� �� ��������� � ������ ������
        ++it; // �������� �������� �� ��������� ������� �������
    }	
    cout << endl;
    
    //�������� �� ������� ����� for
    //������ ������������ auto ��� ���������� ���������
    for(auto it = vec.cbegin(); it != vec.cend(); ++it)
		cout << *it << " ";
    cout << endl << endl;
    
    
    //������� ��������� ����� �������� � ����� insert()
	std::vector<int> numbers = { 1, 2, 3, 4, 5 };
	auto iter = numbers.cbegin(); // �������� ��������� �� ������
	numbers.insert(iter + 2, 8); // insert(pos, value) ��������� ������� 8 �� ������� 2
								 // ���������� �������� �� ����������� �������
	printVals(numbers);
	
	// �����: ����� ��������� ������� ������� �������� ��������������!
	// ����� ������� insert, resize, push_back, pop_back, clear, swap...
	// ������� ����� ��� ������������ ���� ��������������� ���������� �������������
	iter = numbers.cbegin();
	numbers.insert(iter + 1, 3, 4); // insert(pos, n, value) ��������� ����� ������� �������� ��� ������� 
									// ���������� �������� �� ������ ����������� �������
	printVals(numbers);
	cout << endl;
	
	numbers = { 1, 2, 3, 4, 5 };
	std::vector<int> values = { 10, 20, 30, 40, 50 };
	iter = numbers.cbegin(); 
	// insert(pos, begin, end) ��������� ����� ������� �������� ��� �������� �� values
	numbers.insert(iter + 1, values.begin(), values.begin() + 3);
	printVals(numbers);
	iter = numbers.cbegin(); 
	//insert(pos, values) - ��������� ���������� ������ �������� ������� � ��������� ����������
	numbers.insert(iter + 5,{ 21, 22, 23 });
	printVals(numbers);
	cout << endl;
	
	//�������� ��������� ����� �������� � ����� erase()
	numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printVals(numbers);
	iter = numbers.cbegin();
	// erase(p) - ������� ������� �� ������� ��������� �������� 
	// ���������� �������� �� �������, ��������� ����� ����������, ��� ����� ���������� (���� ��� ����� ���������)
	numbers.erase(iter + 3); 
	printVals(numbers);
	//erase(begin, end) - ������� ��� �������� �� ��������� ����������� ���������
	numbers.erase(numbers.cbegin() + 2, numbers.cend()  - 2); //�������� ������ ������ � ��������� ��� ��������
	printVals(numbers);
	cout << endl;
	
	// ����������� ���� for (c C++11)
	// ������������ ��� ���������� ���������� �������� ����� for 
	// ����� ������������ ��� �������� ���� ��������� � ����������
	vector<int> v = {11, 22, 33, 44, 55};
    for (const int& i : v) // ������ �� �����. ������ (����� ������������ const auto&)
        cout << i << " ";
    cout << endl;
    for (int& i : v) // ������ �� ������ (����� ������������ auto&)
        i+=10;
    printVals(v);
    for (int i : v) // ������ �� �������� (����� ������������ auto)
        i+=10;
    printVals(v);
    cout << endl;
    int a[] = {9, 8, 9, 7, 9, 6};
    for (int n : a) // ������������� ����� ���� ������� ��������
        cout << n << " ";
    cout << endl << endl;
    
	return 0;
}

