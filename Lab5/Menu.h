#pragma once
#include <iostream>
#include "List.h"

#define MAXSTR 256
const int MAXSIZE = 16;

using namespace std;

//Предобъявления
void MainMenu();
void CreateMenu(int Key);

template <class T, int MaxSize>
void ListMenu(List<T,MaxSize>& MyList);

template <class T, int MaxSize>
void InputElementMenu(List<T,MaxSize>& MyList, int Key);

//Стартовое меню
void MainMenu() {
	int Key; //номер вводимой команды
	while (true ){
		system("cls");
		cout << "\n----- СОЗДАНИЕ ШАБЛОННОГО СПИСКА -----\n" << endl;
		cout << " Список какого типа будем тестировать?" << endl;
		cout << "| 1 |             int                |" << endl;
		cout << "| 2 |             float              |" << endl;
		cout << "| 3 |             Vec2               |" << endl;
		cout << "| 4 |             char*              |" << endl;	
		cout << "| 5 |  Никакого! (Завершить работу)  |" << endl;	
		cout << "\nВведите номер команды: "; cin >> Key;
		
		if ((Key>=1)&&(Key<=4)) 
			CreateMenu(Key);
		else if (Key==5) 
			exit(0);
		else {
			puts("Такой команды не предусмотрено!");
			system("pause");
		}
	}
}

//Создание списка
void CreateMenu(int Key) {
	switch (Key) {
		case 1: { List<int,  MAXSIZE> L; ListMenu(L); break; }
		case 2: { List<float,MAXSIZE> L; ListMenu(L); break; }
		case 3: { List<Vec2, MAXSIZE> L; ListMenu(L); break; }
		case 4: { List<char*,MAXSIZE> L; ListMenu(L); break; }
	}
	
}

//Работа с шаблонным списком
template <class T, int MaxSize>
void ListMenu(List<T,MaxSize>& MyList) {
	int n;
	int Key;
	while (true) {
		system("cls");
		cout << "\n-------------------- РАБОТА С ШАБЛОННЫМ СПИСКОМ --------------------\n" << endl;
		cout << "Какую команду вы хотите выполнить со списком?" << endl;
		cout << "| 1 | getLength()    | узнать текущее количество элементов         |" << endl;
		cout << "| 2 | isExist(elem)) | узнать, есть ли элемент в списке            |" << endl;
		cout << "| 3 | insert(elem,n) | добавить элемент elem на позицию n          |" << endl;
		cout << "| 4 | remove(elem,n) | удалить элемент elem с позиции n            |" << endl;	
		cout << "| 5 |       +        | добавить какой-либо элемент в начало списка |" << endl;	
		cout << "| 6 |       -        | удалить все вхождения какого-то элемента    |" << endl;	
		cout << "| 7 |      --        | удалить первый элемент из начала списка     |" << endl;	
		cout << "| 8 |      []        | узнать значени элемента по его индексу      |" << endl;	
		cout << "| 9 | Вернуться к меню создания списка                             |" << endl;	
		MyList.print();	
		cout << "\nВведите номер команды: "; cin >> Key;
		switch (Key) {
			case 1: { printf("\nКол-во элементов в списке: %d\n", MyList.getLength()); break;	}
			//case (2,3,4,5,6): case (2-6):
			case 2: case 3:	case 4:	case 5:	case 6:
				{ InputElementMenu(MyList,Key); break; }
			case 7: { --MyList; MyList.print(); break; }
			case 8: { 
				cout << "n = "; cin >> n;
				if (MyList.isIndex(n-1)) cout << "\nЭлемент № "<< n << ": " << MyList[n-1] << endl;
				else cout << "\nИндекс выходит за пределы списка!" << endl;
				break;
			}
			case 9: { MyList.Clear(); MainMenu(); break; }
			default:{ puts("Такой команды не предусмотрено!"); }
		}
		printf("\n"); system("pause");
	}
}

//Работа с шаблонным списком + ввод элемента (специализации в зависимости от типа элемента)
// общая реализация
template <class T, int MaxSize>
void InputElementMenu(List<T,MaxSize>& MyList, int Key) {
	//ввод элемента и его индекса (при необходимости)
	T elem; 
	cout << "\nelem = "; cin >> elem;
	int n = 0;
	if ((Key == 3) || (Key == 4)) { cout << "n = "; cin >> n; }

	switch (Key) {
		case 2: { 
			if (MyList.isExist(elem)) puts("Да, такой элемент есть в списке");
			else puts("Нет, такого элемента в списке нет");
			break; }
		case 3: { MyList.insert(elem,n-1); MyList.print(); break; }
		case 4: { MyList.remove(elem,n-1); MyList.print(); break;	}
		case 5: { MyList+elem; MyList.print(); break; }
		case 6: { MyList-elem; MyList.print(); break;}
	}
}

//Реализация под ввод Vec2
template <int MaxSize>
void InputElementMenu(List<Vec2,MaxSize>& MyList, int Key) {
	//ввод элемента и его индекса (при необходимости)
	int x; int y; Vec2 elem;
	cout << "\nelem:\n"; 
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	elem = {x,y};
	int n = 0;
	if ((Key == 3) || (Key == 4)) { cout << "n = "; cin >> n; }

	switch (Key) {
		case 2: { 
			if (MyList.isExist(elem)) puts("Да, такой элемент есть в списке");
			else puts("Нет, такого элемента в списке нет");
			break; }
		case 3: { MyList.insert(elem,n-1); MyList.print(); break; }
		case 4: { MyList.remove(elem,n-1); MyList.print(); break;	}
		case 5: { MyList+elem; MyList.print(); break; }
		case 6: { MyList-elem; MyList.print(); break;}
	}
}

//Реализация под ввод char*
template <int MaxSize>
void InputElementMenu(List<char*,MaxSize>& MyList, int Key) {
	//ввод элемента и его индекса (при необходимости)
	char* s = new char[MAXSTR];
	cout << "\nelem = "; cin >> s; 
	int n = 0;
	if ((Key == 3) || (Key == 4)) { cout << "n = "; cin >> n; }

	switch (Key) {
		case 2: { 
			if (MyList.isExist(s)) puts("Да, такой элемент есть в списке");
			else puts("Нет, такого элемента в списке нет");
			break; }
		case 3: { MyList.insert(s,n-1); MyList.print(); break; }
		case 4: { MyList.remove(s,n-1); MyList.print(); break;	}
		case 5: { MyList+s; MyList.print(); break; }
		case 6: { MyList-s; MyList.print(); break;}
		}
	delete s; s = nullptr;	
}



