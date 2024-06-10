#include <iostream> 

//���������� �������� �������
#include <vector>


using namespace std;


void doubleVals(vector<int>& vec);
void printVals(const vector<int>& vec);

int main(int argc, char** argv) 
{
	system("chcp 1251");

	//������������� �������
	vector<int> array1;  //������ ������ (��� ���������� �� ������� �������� �����, �.�. ����������� �������� ������ �� �������)
	vector<int> array2 = { 6, 5, 4, 3, 2, 1 }; // ����� ������������ ������ ���������������
	vector<int> array3 { 6, 5, 4, 3, 2, 1 }; // uniform-������������� (�++11)
	vector<int> array4(4); //������ ������� �� 4 �����, ������ �� ��� ����� �������� �� ��������� (0)
	vector<int> array5(4,2); //������ ������� �� 4 �����, ������ �� ��� ����� �������� 2
	vector<int> array6(array5); //array6 - ����� ������� array5 (copy constructor)
	vector<int> array7 = array5; 
	
	
	// ������ � ��������� �������������� ��� ����� [] ���� at()
	cout << "array2[2] = " << array2[2] <<"    array3[4] = " << array3.at(4) << endl;
	//front() � back() ���������� ������������� ������ � ��������� ������� (��� ������!)
	cout << array2.front() << " " << array2.back() << endl;
	cout << endl;
	
	//vector ������ ���� ������� �����, ����� �������� ����� size()
	cout << "array2.size() = " << array2.size() << endl;
	cout << endl;
	
	//������� � �++11 ����� ����������� �������� ��� vector, ��������� ������ ���������������
	array2 = { 1, 2, 3, 4, 5 }; // ����� array2 ������ 5
	cout << "array2.size() = " << array2.size() <<  "    array2[0] = " << array2[0] << endl;
	array2 = { 6, 7, 8}; // ����� array2 ������ 3
	cout << "array2.size() = " << array2.size() << "    array2[0] = " << array2[0] << endl;
	cout << endl;
	
	// ����� vector ������� �� ������� ��������� �� ������������� ����������� 
	// ���������� ������������ ������
	{
		vector<int> array4 { 8, 9, 8, 9, 8}; 
		// ...
	}//����� ������ array4 ����� �������
	
	
	//����� ����� ������ ������ ������� ����� resize(n), resize(n, value) - ������������� ����� ��������� value
	for(int i = 0; i < array3.size(); ++i) cout << array3[i] << " ";
	cout << "array3.size() = " << array3.size() << endl;
	array3.resize(10);
	for(int i = 0; i < array3.size(); ++i) cout << array3[i] << " ";
	cout << "array3.size() = " << array3.size() << endl;
	cout << endl;
	/*
		��� ��������� ������� vector ������� �������� �����������, �
		����� (� ������ ����������) ���������������� ��������� �� ��������� (� ������ int - 0) 
		
		��������� ����� - ��������� ��������, ������� �������������� � �������������
	*/
	
	
	/*
		������� �������, ��� ������������ ������ ������� ������ ������, 
		��� ������������� (���������� � ������).
		�������� ������ ����� �������� ����� capacity()
		��������������� ������� ������ ������ ��� ������ ����� � ������� reserve(n)
	*/
	cout << "array2.capacity() = " << array2.capacity() << endl;
	cout << "array3.capacity() = " << array3.capacity() << endl;
	array3.reserve(100);
	cout << "array3.capacity() = " << array3.capacity() << endl;
	cout << endl;
	
	//������ ������ ����� ���������� � ������� ����� ������ 
	doubleVals(array2);
	//��� ����������� ������
	printVals(array2);
	cout << endl;
	
	//���������� �������� � ����� ����� push_back
	array2.push_back(9);
	printVals(array2);
	//������� ��������� ������� ����� pop_back
	array2.pop_back();
	printVals(array2);
	cout << endl;
	
	// *** ����� insert ��. � ������� "7.2 ���������" ***
	
	//assign() ��������� �������� �������� ������� ����������� �������
	printVals(array3);
	array3.assign(4,999);
	printVals(array3);
	array3.assign({111,222,333,444,555});
	printVals(array3);
	cout << endl;
	
	//swap() ���������� �������� ���� ��������
	vector<int> a1 { 1, 2, 3}, a2 { 4, 5, 6, 7, 8}; 
	printVals(a1);
	printVals(a2);
	a1.swap(a2);
	printVals(a1);
	printVals(a2);
	cout << endl;
	
	//������ ����� ��������� �������� ����� clear()
	//����� ���������� ������ �� ������ ����� empty()
	array2.clear();
	cout<< (array2.empty()? "array2 ������" : "array2 �� ������") << endl;
	cout << endl;
	
	/*
	������� ����� ����������. ������� �����, ���� ����� �� �������� 
	�� �������������� ��������.
	*/
	vector<int> b1 { 1, 2, 3}, b2 { 1, 2, 3}, b3 {5, 6, 7}, b4 {1, 2, 3, 9, 9, 9};
	cout << (b1 == b2 ? "�����" : "�� �����") << endl;
	cout << (b1 == b3 ? "�����" : "�� �����") << endl;
	cout << (b1 == b4 ? "�����" : "�� �����") << endl;
	cout << endl;
	
	// ����� �������� ������ ������ � ������ ����� ���������
	// ��������� ����� data()
	vector<int> arr { 0, 1, 2, 3, 4, 5};
	int* p = arr.data();
	cout << *p << endl;
	cout << *(p+2) << endl;
	
	return 0;
}

// vec ����� ������������� ����� ������
void doubleVals(vector<int>& vec)
{
	for(int i = 0; i < vec.size(); ++i)
		vec[i] *= 2;
}

// ������� ����� const �.�. ����� ������ ������ ������ �� �������
void printVals(const vector<int>& vec)
{
	for(int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}
