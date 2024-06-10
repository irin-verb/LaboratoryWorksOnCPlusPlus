#include <iostream> 

#include <string> 

using namespace std;


int main(int argc, char** argv) 
{
	system("chcp 1251");
	

	

	
	//����� ���������������� ��� ����������
	string str("Hello!");
	cout << str << endl;
	//����� ����������� ����� ��������
	str = "Hi";
	cout << str << endl;
	//��������� ������� � �����:
	str.push_back('!');
	cout << str << endl;
	//��� � ����� ����� ����� insert
	str.insert(0,"You say: ");
	cout << str << endl;
	//����� ��������������� ������ ����� �������� +
	str += " Have a nice day!";
	cout << str << endl;
	//����� ������� ����� ������ ����� erase
	str.erase(3,4);
	cout << str << endl;
	//�������� ����� ������ ����� replace
	str.replace(16,4,"good",4);
	cout << str << endl;
	//���������� � �������� ����� []
	cout << str[5] << " - ��� 6-� ������ ������ str" << endl;
	//����� ������ ����� �������� ����� length()
	cout << "������� ����� ������ str " << str.length() << " ��������." << endl;
	//�������� ������
	str.clear();
	if(str.empty())
		cout << "str ������!" << endl;
	
	
	//���������
	// string to int, string  to float
	string strI = "43";
	string strF = "13.3333";
	int i = stoi(strI);
	float f = stof(strF);
	cout << "i=" << i << " f=" << f << endl;
	// string to char*
	string myString = "������ ������";
	const char *cstr = myString.c_str(); 
	//c_str() ���������� ����������� ��������� ��
	//�������� � string ������ ��������
	cout << cstr << endl;
	// int, float to string
	int a = 40;
	float b = 40.123f;
	string strA = to_string(a), strB = to_string(b);
	cout << "a=" << strA << " b=" << strB << endl;

	
	// --------------------
	
	// ���� ����� ����� ����������� ����� ����� cin:
	string name;
	cout << "���� ���? ";
	cin >> name; //�����! ������� �� ������ ������ �� ������� �������!
	//���� ����� ������� ��� ������ - ���� ������������ getline
	//getline(cin,name);
	cout << name << endl;
	
	
	//����� � getline ����� ���������� �������� �� ����������� ������ 
	//����� ����� ������ ������
	int t;
	cout << "������� �����:";
	cin >> t;
	cout << t << endl;
	
	/*
		���� ������ ������ ����� ��������. ��� ���������� ��-�� ����, ���
		�� ���� �� � ����� ����� ����� "42\n", 42 - ����� ������� � t, �
		'\n' ��������� � ������ �����. � ������ ��� ������ ������� ���������
		getline � ��������� ��� ���� ��� ��������. ����� ������ �� �����������
		������� �������� ����� ����� �� ����� ������� ����� ����� ignore()
	*/
	//cin.ignore(32767,'\n');
	cout << "������� ������:";
	getline(cin,name);
	cout << name << endl;
	
	
	
	return 0;
}

