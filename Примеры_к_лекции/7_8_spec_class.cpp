#include <iostream> 
#include <strings.h>
#include <stdlib.h>
using namespace std;

/*
	ћожно специализировать шаблоны не только отдельных функций, 
	но и шаблоны классов в целом.
*/

// класс TheValue из предыдущего примера
template <class T>
class TheValue
{
private:
    T value;
public:
    TheValue(const T& value)
    {
         this->value = value;
    }

    void print()
    {
        cout << value << endl;
    }
};

// специализаци€ дл€ double
template <> 
void TheValue<double>::print()
{
    cout << scientific << value << endl;
}


/*
	ј что, если мы захотим инкапсулировать не значение,
	а указатель на строку (char*)? ¬ реализации по умолчанию
	шаблон просто скопирует указатель, а нам нужно создать копию строки.
*/


template <> //аналогично шаблону функции специализируем шаблон всего класса
class TheValue<char*> //указываем дл€ какого шаблона специализаци€
{
private:
    char* value = nullptr;
public:
    TheValue(const char* value)
    {
        if(value)
        {
    		//определ€ем длину переданой строки и выдел€ем под нее пам€ть
        	int len = strlen(value);
	        this->value = new char[len];
	        //создаЄм копию переданой строки
	        strcpy(this->value, value);
	    }
    }
    
    ~TheValue()
    {
    	if(value)
    		delete[] value;
	}

    void print()
    {
    	if(value)
        	cout << value << endl;
        else
        	cout << "нет значени€" << endl;
    }
};
//*/

int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	//инициализируем значени€
	TheValue<int> theInt(42);
	TheValue<double> theDouble(5.5555);
	
	//выводим
	theInt.print();
	theDouble.print(); // при специализации шаблона будет вывод в эксп. форме
	
	
	// ј что если нам надо инкапсулировать значение строки?
	
	//выдел€ем пам€ть и заполн€ем строку
	char* str = new char[128];
	strcpy(str, "ѕример строки");
	
	//инкапсулируем значение строки
	TheValue<char*> theString(str);
	
	// ”дал€ем строку!
	delete[] str;
	
	// без специализации класса получим мусор в выводе
	theString.print();


	/*
		 онечно мы могли бы сделать отдельный класс TheStringValue дл€ инкапсул€ции
		строк. ќднако тогда программисту нужно было бы всегда помнить, что дл€ строк нужно
		использовать отдельный класс TheStringValue, а шаблон TheValue<T> использовать
		нельз€. Ёто может приводить к ошибкам. 
	*/
	
	return 0;
}

