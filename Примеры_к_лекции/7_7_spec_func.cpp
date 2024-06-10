#include <iostream> 
#include <strings.h>

using namespace std;

//Класс TheValue просто инкапсулирует какое-то значение и может его вывести в консоль
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

    
/* если мы хотим специализировать функцию вывода значения
   для вывода типа double в экспоненциальной форме, мы должны
   явно специализировать шаблон, т.е. явно указать реализацию
   функции print, если тип Т => double
   Объявляется обязательно вне класса.
*/ 
//template <> 
//void TheValue<double>::print()
//{
//    cout << scientific << value << endl;
//}


int main(int argc, char** argv) 
{
	system("chcp 1251");
	
	//инициализируем значения
	TheValue<int> theInt(42);
	TheValue<double> theDouble(5.5555);
	
	//выводим
	theInt.print();
	theDouble.print(); // при специализации шаблона будет вывод в эксп. форме
	
	/*
		В данном примере мы специализировали функцию-метод класса, однако аналогично
		можно специализировать обычные функции.
	*/

	
	return 0;
}

