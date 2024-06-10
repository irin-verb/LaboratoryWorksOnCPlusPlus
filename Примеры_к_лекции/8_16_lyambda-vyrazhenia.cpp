#include <iostream> 
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void myFunc(void (*lambda)(const string&))
{
	lambda("������");
}

void sendAsFuncObject(const function<void(int,int)>& func)
{
	func(77,88);
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	// ������-��������� (��� ������ �������) ��������� ����������  
	// ������� ������ ������ �������.
	auto myLambda = [](const string& name)
					{
						cout << "������, " << name << "!" << endl;
					};
				
	// ����� �������� ��� ������� �������	
	myLambda("����");
	myLambda("��������");
	
	// ���������� ��� �������� � ������ �������, ����������� �� � ��������� �� �������
	myFunc(myLambda);
	
	/*
	�� ����� ����, ������ �� �������� ���������, � �������� ������ ����� ��������, 
	������� ���������� ���������. 
	�������� � ��� �������, ���������� ������������� operator(), ������� � ������ �� 
	����������� ������� ������� ��������.
	
	�.�. ���������� ������, ����������� ����, �����������:
	
	class 
	{
	public: 
		void operator ()(const string& name) const 
		{ 
			cout << "������, " << name << "!" << endl; 
		} 
	} myLambda;
	
	*/
	
	cout << endl;
	
	// ������ ����� ����������� �������� ��� ����������, �.�. 
	// ��������� � ���� ���������� �� ����� ������. ��� �����
	// �� ������� ��������� � []. ����� ��������� ������ �� ����������,
	// ������� ��� ���� �������� �� ���������� ������.
	
	int a = 3, b = 4, c = 7, d = 6;
	
	auto gotAvg = [a,b,c]()
				{
					cout << "����������� �������� ����� " << min(min(a,b),c) << endl;
					
					// d �� ��������, ������������� ����������� �����!
					// cout << d << endl; 
				};
	
	gotAvg();
	
	//����� ����������� �������� �� ������, �������� ����� ���� &
	auto modThem = [&a,&b,&c]()
				{
					a = 1;
					b = 2;
					c = 3;
				};
	modThem();
	
	cout << a << " " << b << " " << c << endl;
	
	cout << endl;
	
	/*
		[&] - ��������� ��� ���������� �� ������
		[=] - ��������� ��� �� ��������
	*/
	auto printThem = [=]()
				{
					cout << a << " " << b << " " << c << " " << d << endl;
					myLambda("���������"); // ���� ������ ������ ���� ���������!
				};
	printThem();
	
	/*
		������ ��� ������� [] ����� ���� ������������� � ��������� �� �������,
		�� � �������� - ���. ������� ������� ��������������� ������ � �����������
		�������������� ������ function �� ����������� ���������� <functional>
		��������� ����������:
		
		function<�����. ����.(�����1,�����2...)>
	*/
	
	function<void(int,int)> myFuncObject = 
		[a,b](int num1, int num2)
		{
			cout << a << " " << b << " " << num1 << " " << num2 << endl;
		};
				
	sendAsFuncObject(myFuncObject);
	
	cout << endl;
	
	
	// ������ � �������������� ������� function ����� ����� ������������ 
	// � ����������� ����������
	
	vector<string> months{
		"������",
		"�������",
		"����",
		"������",
		"���",
		"����",
		"����",
		"������",
		"��������",
		"�������",
		"������",
		"�������"
	};
	
  // ������������ ���������� ������� � ���������� � 4 �����
  auto fourLetterMonths = count_if(months.begin(), months.end(),
                                       [](const string& str) 
									   {
                                         return (str.length() == 4);
                                       });
 
  cout << "����� " << fourLetterMonths << " ������ �� 4 ����" << endl;
  
  return 0;
}

