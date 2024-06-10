#include <iostream> 

//подключаем описание вектора
#include <vector>


using namespace std;


void doubleVals(vector<int>& vec);
void printVals(const vector<int>& vec);

int main(int argc, char** argv) 
{
	system("chcp 1251");

	//инициализация вектора
	vector<int> array1;  //пустой вектор (при объявлении не требует указания длины, т.к. динамически выделяет память по запросу)
	vector<int> array2 = { 6, 5, 4, 3, 2, 1 }; // можно использовать списко инициализаторов
	vector<int> array3 { 6, 5, 4, 3, 2, 1 }; // uniform-инициализация (С++11)
	vector<int> array4(4); //вектор состоит из 4 чисел, каждое из них имеет значение по умолчанию (0)
	vector<int> array5(4,2); //вектор состоит из 4 чисел, каждое из них имеет значение 2
	vector<int> array6(array5); //array6 - копия вектора array5 (copy constructor)
	vector<int> array7 = array5; 
	
	
	// доступ к элементам осуществляется или через [] либо at()
	cout << "array2[2] = " << array2[2] <<"    array3[4] = " << array3.at(4) << endl;
	//front() и back() возвращают соотвественно первый и последний элемент (как ссылку!)
	cout << array2.front() << " " << array2.back() << endl;
	cout << endl;
	
	//vector помнит свою текущую длину, можно получить через size()
	cout << "array2.size() = " << array2.size() << endl;
	cout << endl;
	
	//начиная с С++11 можно присваивать значения для vector, используя список инициализаторов
	array2 = { 1, 2, 3, 4, 5 }; // длина array2 теперь 5
	cout << "array2.size() = " << array2.size() <<  "    array2[0] = " << array2[0] << endl;
	array2 = { 6, 7, 8}; // длина array2 теперь 3
	cout << "array2.size() = " << array2.size() << "    array2[0] = " << array2[0] << endl;
	cout << endl;
	
	// когда vector выходит из области видимости он автоматически освобождает 
	// занимаемую динамическую память
	{
		vector<int> array4 { 8, 9, 8, 9, 8}; 
		// ...
	}//здесь память array4 будет очищена
	
	
	//можно легко менять размер вектора через resize(n), resize(n, value) - инициализация новых значением value
	for(int i = 0; i < array3.size(); ++i) cout << array3[i] << " ";
	cout << "array3.size() = " << array3.size() << endl;
	array3.resize(10);
	for(int i = 0; i < array3.size(); ++i) cout << array3[i] << " ";
	cout << "array3.size() = " << array3.size() << endl;
	cout << endl;
	/*
		при изменении размера vector текущие элементы сохраняются, а
		новые (в случае расширения) инициазилируются значением по умолчанию (в случае int - 0) 
		
		изменение длины - затратная операция, следует минимизировать её использование
	*/
	
	
	/*
		следует помнить, что используемый размер вектора обычно меньше, 
		чем аллоцированый (занимаемый в памяти).
		Реальный размер можно получить через capacity()
		Зарезервировать заранее больше памяти под вектор можно с помощью reserve(n)
	*/
	cout << "array2.capacity() = " << array2.capacity() << endl;
	cout << "array3.capacity() = " << array3.capacity() << endl;
	array3.reserve(100);
	cout << "array3.capacity() = " << array3.capacity() << endl;
	cout << endl;
	
	//вектор всегда стоит передавать в функцию через ссылку 
	doubleVals(array2);
	//или константную ссылку
	printVals(array2);
	cout << endl;
	
	//добавление элемента в конец через push_back
	array2.push_back(9);
	printVals(array2);
	//удалить последний элемент через pop_back
	array2.pop_back();
	printVals(array2);
	cout << endl;
	
	// *** метод insert см. в примере "7.2 итераторы" ***
	
	//assign() позволяет заменить элементы вектора определнным набором
	printVals(array3);
	array3.assign(4,999);
	printVals(array3);
	array3.assign({111,222,333,444,555});
	printVals(array3);
	cout << endl;
	
	//swap() обменивает значения двух векторов
	vector<int> a1 { 1, 2, 3}, a2 { 4, 5, 6, 7, 8}; 
	printVals(a1);
	printVals(a2);
	a1.swap(a2);
	printVals(a1);
	printVals(a2);
	cout << endl;
	
	//вектор можно полностью очистить через clear()
	//можно определить пустой ли вектор через empty()
	array2.clear();
	cout<< (array2.empty()? "array2 пустой" : "array2 не пустой") << endl;
	cout << endl;
	
	/*
	вектора можно сравнивать. Вектора равны, если равны их элементы 
	на соотвествующих позициях.
	*/
	vector<int> b1 { 1, 2, 3}, b2 { 1, 2, 3}, b3 {5, 6, 7}, b4 {1, 2, 3, 9, 9, 9};
	cout << (b1 == b2 ? "равны" : "не равны") << endl;
	cout << (b1 == b3 ? "равны" : "не равны") << endl;
	cout << (b1 == b4 ? "равны" : "не равны") << endl;
	cout << endl;
	
	// можно получить прямой доступ к памяти через указатель
	// используя метод data()
	vector<int> arr { 0, 1, 2, 3, 4, 5};
	int* p = arr.data();
	cout << *p << endl;
	cout << *(p+2) << endl;
	
	return 0;
}

// vec будет модифицирован через ссылку
void doubleVals(vector<int>& vec)
{
	for(int i = 0; i < vec.size(); ++i)
		vec[i] *= 2;
}

// передаём через const т.к. хотим только читать данные из вектора
void printVals(const vector<int>& vec)
{
	for(int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}
