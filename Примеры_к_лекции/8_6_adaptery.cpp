#include <iostream> 

#include <vector> 
#include <stack> 
#include <list> 
#include <queue> 

using namespace std;

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	// ����
	
	// ��-��������� �� ���� deque
	stack<char> st; 
	
	//��������� ��� ����� ������������ vector
	stack<char, vector<char>> vst (vector<char>({'X','Y','Z'})); 
	
	vst.push('#');
	
	while (!vst.empty()) 
	{
		cout << vst.top() << " : � ����� ����� " << vst.size() << endl;
		vst.pop();
	}
	cout << "���� " << (vst.empty() ? "" : "�� ") << "����" << endl;
	
	/*
		����� ������ ��� ������� stack ������� �������� �������� ����������
		������ at(), [] � �.�. �� ������� top(), push(), pop() � �.�.
	*/
	
	// �������
	
	// ��-��������� �� ���� deque
	queue<char> que; 
	
	// ��������� ��� ����� ������������ list
	queue<char, list<char>> lque(list<char>({ 'A', 'B', 'C' }));
	
	lque.push('#');
	
	while (!lque.empty()) 
	{
		cout << lque.front() << " : � ������� ����� " << lque.size() << endl;
		lque.pop();
	}
	cout << "������� " << (lque.empty() ? "" : "�� ") << "�����" << endl;
	
	/*
		������� �� ����� ���� ��������� �� ������� ���������� vector, 
		�.�. � ���� ��� ������ pop_front()
		
		� queue ��� ������ top(), �� ���� ����������� front()
	*/
	return 0;
}

