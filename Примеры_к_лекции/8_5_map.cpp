#include <iostream> 

//���������� �������� �������������� �������
#include <map>

using namespace std;

int main(int argc, char** argv) 
{
	system("chcp 1251");

	// ��������� ���. ������ c ������� char, ���������� - int
	map<char,int> map1;
	
	// ��������� ���� �������, 
	map1.insert(pair<char,int>('Z',5));
	map1.insert(pair<char,int>('Y',7));
	map1.insert(pair<char,int>('X',9));
	/* ����������� ��������� ����� pair ��������� ���������������
		� ���� ���� �������� (� ����� ������ ����-��������)
		���������� � ��������� ���� ����� �����
		pair->first � pair->second
	*/
	
	//����� ��������� ��������� ����� ������ �������������
	map1.insert({{'R',1},{'T',2},{'B',4}});
	
	//��������� ��� �������� ����� ����� ��������
	for (auto it = map1.begin(); it != map1.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
		/*
			�������� ��������! ������� � ������������� �����������
			�� �����, ������� �������� �������� �� � ������� ��
			���������� (� ������ ������ � ������������� ���������� 
			��� ����������� �� �����������)
		*/
	}
	cout << endl;
	
	//�������� �������� ��������� ����� ����� �������� [<����>] = <��������>
	map1['R'] = 99;
	//��� ����� ����� at()
	map1.at('X') = -66;
		
	//������� ����� ����� erase
	map1.erase('Z');
	
	//���������� �������� ����� ����� ����� range for
	for (auto& elem : map1)
		cout << elem.first << " : " << elem.second << endl;
	
	auto it = map1.find('B');
	if(it != map1.end())
		cout << "������ �������: ['"<< it->first << "']=" << it->second<< endl;
	else
		cout << "�������� ���!" << endl;
	
	//������� ���. ������� � �������� �� ������ ������ 
	map1.clear();
	if(map1.empty()) 
		cout << "map1 ������!" << endl;
		
	cout << endl;
		
	// ������ multimap, ������� ����� ��������� ��������� �������� � ���������� ������
	multimap<char,int> map2 = {{'G',5},{'H',3},{'Z',5},{'H',7},{'Z',8},{'Z',2},{'A',5},{'G',6}};
	for (auto& elem : map2)
		cout << elem.first << " : " << elem.second << endl;
		
	// �������� [] ��� multimap ��������
	// map2['G'] = 5; // error!
	
	// find ��������� �������� �� ������ ������� � �������� ������
	it = map2.find('Z');
	if(it != map2.end())
	{
		while(it != map2.end() && it->first=='Z') // ���������� ��� �������� � �������� ������
		{
			cout << "������ �������: ['"<< it->first << "']=" << it->second<< endl;
			++it;
		}
	}
	else
		cout << "�������� ���!" << endl;
	
	return 0;
}

