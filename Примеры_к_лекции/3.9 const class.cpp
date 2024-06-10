#include <iostream> 
#include <strings.h>

using namespace std;

#define clamp(n, min, max) (n < min? min : (n > max? max : n))

/*����� Date ������ � ���� ���� � �������� ���� � � ��������� �������������*/
class Date
{
private:
    int day;
    int month;
    int year;
    
    char strVal[11];
    
    void updateString() 
	{
    	sprintf(strVal,"%d.%d.%d",day,month,year);
	}
 
public:
	
    Date(int day, int month, int year)
    {
        setDate(day, month, year);
    }
 
 	//������� ������������� �����, �������� ��������� �������
    void setDate(int day, int month, int year)
    {
        this->day = clamp(day,1, 31);
        this->month = clamp(month,1,12);
        this->year = clamp(year,1900,3000);
        
        updateString(); // ��������� ��������� �������������
    }
 
 	//����������� ������ ����������� �� ���������� ������� ��� �� ������
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    
    // toString() ��� ����������� ��������
    const char* toString() const { return strVal;  } 
	
	// toString() ��� ������������� ��������
    const char* toString() { return strVal;  } 
};

/*
���� �� ������� ������ getDay, getMonth, getYear ������������, ����� ������, �.�. ��������
�������� ��� const
[Error] passing 'const Date' as 'this' argument of 'int Date::getDay()' discards qualifiers [-fpermissive]
*/
void printDate(const Date &date)
{
    cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << endl;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

    Date date(12, 11, 2018);
    printDate(date);
    
    
	//���������� ������������ �������, ����� �������������
	//�������� ��� ����� ������
    const Date date2(15,7,2020); 
    
    date.setDate(5,5,2006); //setDate � �������������� ������� ������� �����
    //date2.setDate(5,5,2006); //� � ������������ - ���
	
	// �.�. � ��� ���� ��� ������ toString ��� ����������� � �������������
	// ��������, �� ��� ������� ������� ����� ������� ������ ������ �������
	// ����������� const ������ � ���������, ������� ������� � const � ��� 
	// ��� ������ ������� � �.�. �����������
	cout << date.toString() << endl;
	cout << date2.toString() << endl;
	
	return 0;
}

