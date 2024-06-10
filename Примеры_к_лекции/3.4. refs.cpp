#include <iostream> 

using namespace std; 

int main(int argc, char** argv) 
{
	//int& iRefBad; //[Error] 'iRefBad' declared as reference but not initialized
	int i = 10, j = 20;
	
	int& iRef = i; 
	cout << i << " " << j << " "<< iRef << endl; //10 20 10
	
	iRef -= 5;
	cout << i << " " << j << " "<< iRef << endl; //5 20 5
	
	iRef = j; //�����! �� �� ���������� ������ (��� ���������� ����� �������������)
	          //� ��������� i ����� ������ iRef �������� j, �.�. ���������� i = j
	cout << i << " " << j << " "<< iRef << endl; //20 20 20
	
	return 0;
}
