#pragma once
#include <iostream>
#include "List.h"

#define MAXSTR 256
const int MAXSIZE = 16;

using namespace std;

//��������������
void MainMenu();
void CreateMenu(int Key);

template <class T, int MaxSize>
void ListMenu(List<T,MaxSize>& MyList);

template <class T, int MaxSize>
void InputElementMenu(List<T,MaxSize>& MyList, int Key);

//��������� ����
void MainMenu() {
	int Key; //����� �������� �������
	while (true ){
		system("cls");
		cout << "\n----- �������� ���������� ������ -----\n" << endl;
		cout << " ������ ������ ���� ����� �����������?" << endl;
		cout << "| 1 |             int                |" << endl;
		cout << "| 2 |             float              |" << endl;
		cout << "| 3 |             Vec2               |" << endl;
		cout << "| 4 |             char*              |" << endl;	
		cout << "| 5 |  ��������! (��������� ������)  |" << endl;	
		cout << "\n������� ����� �������: "; cin >> Key;
		
		if ((Key>=1)&&(Key<=4)) 
			CreateMenu(Key);
		else if (Key==5) 
			exit(0);
		else {
			puts("����� ������� �� �������������!");
			system("pause");
		}
	}
}

//�������� ������
void CreateMenu(int Key) {
	switch (Key) {
		case 1: { List<int,  MAXSIZE> L; ListMenu(L); break; }
		case 2: { List<float,MAXSIZE> L; ListMenu(L); break; }
		case 3: { List<Vec2, MAXSIZE> L; ListMenu(L); break; }
		case 4: { List<char*,MAXSIZE> L; ListMenu(L); break; }
	}
	
}

//������ � ��������� �������
template <class T, int MaxSize>
void ListMenu(List<T,MaxSize>& MyList) {
	int n;
	int Key;
	while (true) {
		system("cls");
		cout << "\n-------------------- ������ � ��������� ������� --------------------\n" << endl;
		cout << "����� ������� �� ������ ��������� �� �������?" << endl;
		cout << "| 1 | getLength()    | ������ ������� ���������� ���������         |" << endl;
		cout << "| 2 | isExist(elem)) | ������, ���� �� ������� � ������            |" << endl;
		cout << "| 3 | insert(elem,n) | �������� ������� elem �� ������� n          |" << endl;
		cout << "| 4 | remove(elem,n) | ������� ������� elem � ������� n            |" << endl;	
		cout << "| 5 |       +        | �������� �����-���� ������� � ������ ������ |" << endl;	
		cout << "| 6 |       -        | ������� ��� ��������� ������-�� ��������    |" << endl;	
		cout << "| 7 |      --        | ������� ������ ������� �� ������ ������     |" << endl;	
		cout << "| 8 |      []        | ������ ������� �������� �� ��� �������      |" << endl;	
		cout << "| 9 | ��������� � ���� �������� ������                             |" << endl;	
		MyList.print();	
		cout << "\n������� ����� �������: "; cin >> Key;
		switch (Key) {
			case 1: { printf("\n���-�� ��������� � ������: %d\n", MyList.getLength()); break;	}
			//case (2,3,4,5,6): case (2-6):
			case 2: case 3:	case 4:	case 5:	case 6:
				{ InputElementMenu(MyList,Key); break; }
			case 7: { --MyList; MyList.print(); break; }
			case 8: { 
				cout << "n = "; cin >> n;
				if (MyList.isIndex(n-1)) cout << "\n������� � "<< n << ": " << MyList[n-1] << endl;
				else cout << "\n������ ������� �� ������� ������!" << endl;
				break;
			}
			case 9: { MyList.Clear(); MainMenu(); break; }
			default:{ puts("����� ������� �� �������������!"); }
		}
		printf("\n"); system("pause");
	}
}

//������ � ��������� ������� + ���� �������� (������������� � ����������� �� ���� ��������)
// ����� ����������
template <class T, int MaxSize>
void InputElementMenu(List<T,MaxSize>& MyList, int Key) {
	//���� �������� � ��� ������� (��� �������������)
	T elem; 
	cout << "\nelem = "; cin >> elem;
	int n = 0;
	if ((Key == 3) || (Key == 4)) { cout << "n = "; cin >> n; }

	switch (Key) {
		case 2: { 
			if (MyList.isExist(elem)) puts("��, ����� ������� ���� � ������");
			else puts("���, ������ �������� � ������ ���");
			break; }
		case 3: { MyList.insert(elem,n-1); MyList.print(); break; }
		case 4: { MyList.remove(elem,n-1); MyList.print(); break;	}
		case 5: { MyList+elem; MyList.print(); break; }
		case 6: { MyList-elem; MyList.print(); break;}
	}
}

//���������� ��� ���� Vec2
template <int MaxSize>
void InputElementMenu(List<Vec2,MaxSize>& MyList, int Key) {
	//���� �������� � ��� ������� (��� �������������)
	int x; int y; Vec2 elem;
	cout << "\nelem:\n"; 
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	elem = {x,y};
	int n = 0;
	if ((Key == 3) || (Key == 4)) { cout << "n = "; cin >> n; }

	switch (Key) {
		case 2: { 
			if (MyList.isExist(elem)) puts("��, ����� ������� ���� � ������");
			else puts("���, ������ �������� � ������ ���");
			break; }
		case 3: { MyList.insert(elem,n-1); MyList.print(); break; }
		case 4: { MyList.remove(elem,n-1); MyList.print(); break;	}
		case 5: { MyList+elem; MyList.print(); break; }
		case 6: { MyList-elem; MyList.print(); break;}
	}
}

//���������� ��� ���� char*
template <int MaxSize>
void InputElementMenu(List<char*,MaxSize>& MyList, int Key) {
	//���� �������� � ��� ������� (��� �������������)
	char* s = new char[MAXSTR];
	cout << "\nelem = "; cin >> s; 
	int n = 0;
	if ((Key == 3) || (Key == 4)) { cout << "n = "; cin >> n; }

	switch (Key) {
		case 2: { 
			if (MyList.isExist(s)) puts("��, ����� ������� ���� � ������");
			else puts("���, ������ �������� � ������ ���");
			break; }
		case 3: { MyList.insert(s,n-1); MyList.print(); break; }
		case 4: { MyList.remove(s,n-1); MyList.print(); break;	}
		case 5: { MyList+s; MyList.print(); break; }
		case 6: { MyList-s; MyList.print(); break;}
		}
	delete s; s = nullptr;	
}



