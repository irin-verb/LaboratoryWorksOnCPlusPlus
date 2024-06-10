#include <iostream> 

#include <initializer_list> 

using namespace std;

class ArrayInt
{
private:
	int length;
	int *data;
 
public:
	ArrayInt() : length(0), data(nullptr) { }
 
	ArrayInt(int length) : length(length)
	{
		data = new int[length];
	}
 
 	// ��������� �������������� ������ ����� ������ �������������
	ArrayInt(const std::initializer_list<int> &list): 
		ArrayInt(list.size()) // ���������� ����� ������������ ��� ��������� ������
	{
		// ���������� ��� �������� �� ������ ������������� 
		// � ���������� �������� � ������
		int count = 0;
		for (auto &elem : list)
		{
			data[count] = elem;
			++count;
		}
		
		// std::initializer_list �� ������������ �������� ���������� [] 
	}
 
	~ArrayInt()
	{
		delete[] data;
	}
 
	int operator[](int index)
	{
		if(index >= 0 && index < length)
			return data[index];
		return 0;
	}
 
	int getLength() { return length; }
};

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	//������ ����� ���������������� ��� ������ ����� ������ �������������
	ArrayInt array { 7, 6, 5, 4, 3, 2, 1 }; 
	
	for (int i = 0; i < array.getLength(); ++i)
		cout << array[i] << ' ';
	
	return 0;
}

