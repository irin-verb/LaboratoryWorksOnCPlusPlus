#include <iostream> 
#include <strings.h>

using namespace std;

class Data
{
private:
	
	//�����-�� ��������� ���� � �������:
	float data1;
	int data2;
	const char* data3;
	
public:
	
	Data() : data1(4.5f), data2(5), data3("������ ������")  { }
	
	//��������� ������� print �������� ������ � ��������� ����� ������ Data
	friend void print(const Data&);
	//��������� ������ Printer �������� ������ � ��������� ����� ������ Data
	friend class Printer;
};

//���� ������ Data
void print(const Data& data)
{
	cout<<"��������� ���� Data: " 
		<< " data1=" << data.data1 
		<< " data2=" << data.data2 
		<< " data3=" << data.data3
		<< endl;
}

//���� ������ Data
class Printer
{
private:
	// ��������� ����������� ������������� ����������� �������� ����������� ������
	// ������������ �������� ��� ����������� �������, ����������� � �.�.
	Printer() { } 
	
public:
	
	static print(const Data& data)	
	{
		cout<<"��������� ���� Data: " 
			<< " data1=" << data.data1 
			<< " data2=" << data.data2 
			<< " data3=" << data.data3
			<< endl;	
	}
		
};





int main(int argc, char** argv) 
{
	system("chcp 1251");

	Data data;
	
	print(data);
	
	Printer::print(data);
	
	//��������� ����������� �� ���� ������� ��������� Printer
	//Printer printer;
	
	return 0;
}

