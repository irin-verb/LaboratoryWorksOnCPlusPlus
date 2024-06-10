#include <iostream> 
#include <strings.h>

using namespace std;

/*
	DataPtrArray - ���������-������  ��� ������������� ������� ���������� ���� Data
	��� ����������� ����������-�������� �� ����������� �������. �� �� ����� ������������
	��������� �� float*, �� ��� �� ��� ���������, ������� ��������� ��������� ���������
	Data �� 3 float-��.
*/

//���������, ������� �� ����� ������� ����� ���������� � ����������
struct Data
{
	float a,b,c;	
};

class DataPtrArray
{
	Data** data; // ������ �� ������ ������ ����������!
	int length = 0;
	
	//����������� ��� ��������� ������ � ����������� ������
	void realloc(int newLength)
	{
		if(newLength == length) return;
		
		//������ � ������ ������ ���������� ������ �������
		Data** newData = new Data*[newLength];
		
		//������������ ������ � ����� ������
		int minLength = min(length, newLength);
		for(int i = 0; i < minLength; ++i)
			newData[i] = data[i];
			
		// ������� ������ ������
		if(length)
			delete[] data;
		
		//������������ ��������� � ���������� ����� ������
		data = newData;	
		length = newLength;
	}
	
public:
		
	DataPtrArray(int length = 0)
	{
		realloc(length);
	}
	
	~DataPtrArray()
	{
		clear(); //�� �������� �������� ������ � �����������
	}
	
	// ��������� ������� � ������ �� ����� pos.
	// ���� pos < 0, �� � ����� �������
	DataPtrArray& add(Data* elem, int pos = -1)
	{
		pos = pos < 0 ? length : pos;
		
		//������� ����������� ������
		realloc(length + 1);
		
		//����� �������� �������� ������ �� pos
		for(int i = length - 2; i >= pos; ++i)
			data[i+1] = data[i];
			
		//��������� ������� �� ������ �����
		data[pos] = elem;
		
		return *this; // ����� ������ ������� ������� �������
	}
	
	// ������� ������� �� ����� pos.
	// ���� pos < 0, �� ������� ��������� �������
	DataPtrArray& remove(int pos = -1)
	{
		pos = pos < 0 ? length - 1 : pos;

		//������� �������� ������� pos, ������� �������� �����
		for(int i = pos; i < length - 1; ++i)
			data[i] = data[i + 1];
			
		//��������� ������
		realloc(length - 1);
		
		return *this;  // ����� ������ ������� ������� �������
	}
	
	//������� �������
	DataPtrArray& clear()
	{
		if(length)
			delete[] data;
			
		length = 0;
		data = nullptr;
		
		return *this; // ����� ������ ������� ������� �������
	}
	
	int getLength() const { return length; }
	bool isEmpty() const { return length == 0; }
	
	//������ ���������� �������� � ������ 
	int getSizeInBytes() const 
	{ 
		return length * sizeof(Data*); 
	}
	

	
	//�.�. � ��� �������� �������� ����, ���������� �� �� ������
	const Data& operator[](int id) const
	{
		return *data[id];
	}
	Data& operator[](int id)
	{
		return *data[id];
	}
};

//����������� �������� ��� ������ � ������� ����� � ��� ��������� Data
ostream& operator<< (ostream &out, const Data& data)
{
	out << "Data[" << data.a << "," << data.b << "," << data.c << "] "; 
}

ostream& operator<< (ostream &out, const DataPtrArray& array)
{
    out << "DataPtrArray["<< array.getLength() << "]:" << endl;
    
    if(array.isEmpty())
    {
    	out << "������ ������!";
	}
	else
	{
	    for(int i=0; i < array.getLength(); ++i)
		 out << array[i] << " ";
	}
	
	out << "---> ����� " << array.getSizeInBytes() << " ����." << endl;
	
    return out;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	DataPtrArray arr;

	//��������� ��������� �� �������� (���� ������ �� ����� ������� � �����������, ����� new)
	//�.�. � ������� �� ������ ������ ���������, �� ��� �� ����� ��� ����������� ������ 
	//��� ��� ���������
	Data dataArr[] = {{1.11f,2.11f,3.11f},{1.22f,2.22f,3.22f},{1.33f,2.33f,3.33f}};
	arr.add(dataArr).add(dataArr + 1).add(dataArr + 2);
	cout << arr << endl;
	
	//������� ������� � �������� 1
	arr.remove(1);
	cout << arr << endl;
	
	//������� ������
	arr.clear();
	cout << arr << endl;

	
	return 0;
}

