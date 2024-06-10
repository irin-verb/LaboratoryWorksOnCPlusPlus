#include <iostream> 
#include <strings.h>

using namespace std;

/*
	FloatArray - ���������-��������  ��� ������������� ������� ���� float
	� ������� �� ���������� �������� �� ���������� �������������� ������
	��� ������� ��������� � ����� ����������� (�� ���������� �� ������������������
	�� ���������� �� ���������� ������). 
*/

class FloatArray
{
	float* data;
	int length = 0;
	
	//����������� ��� ��������� ������ � ����������� ������
	void realloc(int newLength)
	{
		if(newLength == length) return;
		
		//������ � ������ ������ ������ �������
		float* newData = new float[newLength];
		
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
		
	FloatArray(int length = 0)
	{
		realloc(length);
	}
	
	~FloatArray()
	{
		clear(); //�� �������� �������� ������ � �����������
	}
	
	// ��������� ������� � ������ �� ����� pos.
	// ���� pos < 0, �� � ����� �������
	FloatArray& add(float elem, int pos = -1)
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
	FloatArray& remove(int pos = -1)
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
	FloatArray& clear()
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
		return length * sizeof(float); 
	}
	

	
	//�.�. � ��� �������� �������� ����, ����� ���������� �� �� ��������
	float operator[](int id) const
	{
		return data[id];
	}
};

//friend �� �����, �.�. ��������� ����� public ���������
ostream& operator<< (ostream &out, const FloatArray& array)
{
    out << "FloatArray["<< array.getLength() << "]:" << endl;
    
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

	FloatArray arr;

	//��������� ��������
	arr.add(5.0f).add(1.4f).add(5.8f).add(8.3f).add(9.9f).add(3.4f);
	cout << arr << endl;
	
	//������� ������� ��������� �������, ����� � �������� 2
	arr.remove().remove(2);
	cout << arr << endl;
	
	//������� ������
	arr.clear();
	cout << arr << endl;
	
	return 0;
}

