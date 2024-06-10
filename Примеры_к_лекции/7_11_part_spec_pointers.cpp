#include <iostream> 
#include <strings.h>

using namespace std;

/*
	В примере 7.8 мы явно специализировали шаблон класса для указателя char*
	но что если нам необходимо также работать и с другими типами указателей
	вроде int* и т.д.? В этом случае опять поможет частичная специализация
*/


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
    	cout << "class TheValue<T>::print" << endl;
        cout << value << endl;
    }
};

//явно специализируем шаблон всего класса для char*
template <>
class TheValue<char*> 
{
private:
    char* value = nullptr;
public:
    TheValue(const char* value)
    {
        if(value)
        {
        	int len = strlen(value);
	        this->value = new char[len];

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
    	cout << "class TheValue<char*>::print" << endl;
    	
    	if(value)
        	cout << value << endl;
        else
        	cout << "нет значения" << endl;
    }
};

// частичная специализация шаблона класса TheValue для работы с другими типами указателей
template <class T>
class TheValue<T*> 
{
private:
    T* value;
public:
    TheValue(T* value) // T - тип указателя
    {
    	if(value)
    	{
	         this->value = new T(*value);  // здесь вызывается конструктор копии
     	}
    }
 
    ~TheValue()
    {
    	if(value)
        	delete value; 
    }
 
    void print()
    {
    	cout << "class TheValue<T*>::print" << endl;
    	
    	if(value)
        	cout << *value << endl;
        else
        	cout << "нет значения" << endl;
    }
};

int main(int argc, char** argv) 
{
	system("chcp 1251");

	//Работает обший шаблон TheValue<T>
	TheValue<int> theInt(42);
	theInt.print();
	
	//работает специализированный шаблон TheValue<char*>
	char* str = new char[128];
	strcpy(str, "Пример строки");
	TheValue<char*> theString(str);
	
	delete[] str; // Удаляем строку!

	theString.print();
	
	//работает частично специализированный шаблон для указателей TheValue<T*>
	int* val = new int;
	*val = 5;
	TheValue<int*> theIntPtr(val);
	
	delete val; // Удаляем переменную!

	theIntPtr.print(); // значение сохранилось

	
	return 0;
}

