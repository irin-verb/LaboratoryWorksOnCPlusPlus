#include <iostream> 
#include <strings.h>

using namespace std;

#define clamp(n, min, max) (n < min? min : (n > max? max : n))

/*класс Date хранит в себе дату в числовом виде и её текстовое представление*/
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
 
 	//обычный неконстантный метод, изменяет состояние объекта
    void setDate(int day, int month, int year)
    {
        this->day = clamp(day,1, 31);
        this->month = clamp(month,1,12);
        this->year = clamp(year,1900,3000);
        
        updateString(); // обновляем строковое представление
    }
 
 	//константные методы гарантируют не изменность объекта при их вызове
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    
    // toString() для константных объектов
    const char* toString() const { return strVal;  } 
	
	// toString() для неконстантных объектов
    const char* toString() { return strVal;  } 
};

/*
Если не сделать методы getDay, getMonth, getYear константными, будет ошибка, т.к. параметр
объявлен как const
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
    
    
	//объявление константного объекта, после инициализации
	//изменять его будет нельзя
    const Date date2(15,7,2020); 
    
    date.setDate(5,5,2006); //setDate у неконстантного объекта вызвать можно
    //date2.setDate(5,5,2006); //а у константного - нет
	
	// т.к. у нас есть две версии toString для константных и неконстантных
	// объектов, то для каждого объекта будет вызвана нужная версия функции
	// модификатор const входит в сигнатуру, поэтому функции с const и без 
	// это разные функции с т.з. компилятора
	cout << date.toString() << endl;
	cout << date2.toString() << endl;
	
	return 0;
}

