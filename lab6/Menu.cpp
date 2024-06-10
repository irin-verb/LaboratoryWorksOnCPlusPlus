#include "Menu.h"

using namespace std;

void MainMenu(Storage* Store) {
	int Key; //����� �������� �������
	while (true ){
		system("cls");
		cout << "\n-----------  ����� ���������� � ��������� �������� �� ������! :)  -----------\n" << endl;
		cout << "������� ����� �������" << endl;
		cout << "1 - ���������� ���������� ������� (����� ������)" << endl;
		cout << "2 - �������� ��������� ������� (��������� ������)" << endl;
		cout << "3 - ���������� ������� (�������� ������)" << endl;
		cout << "4 - ������ ����� ������� (�������� ����� ������)" << endl;	
		cout << "5 - ������� ������� (������������ ������� �� ������ � ������ ������� �������)" << endl;
		cout << "6 - ��������� ������� ���� (���������� ������ ���������)\n" << endl;
		cin >> Key;
		switch (Key) {
		case 1: {
			OutputMenu(Store);
			break; 
		}
		case 2:	{
			GenerationMenu(Store);
			break;
		}
		case 3:	{
			DeletionMenu(Store);
			break;
		}
		case 4:{
			AdditionMenu(Store);
			break;
		}
		case 5:{
			MovementMenu(Store);
			break;
		}
		case 6:{
			try { 
				Store->DelAllContent(); 
				cout << "������ ��� ���������� ���� � ������������ ������, � �� �� ����� ���� :)" << endl;
			}
			catch (Error& E) { }
			catch(...) { cout << "��������� ����������� ������!" << endl; }	
			cout << "\n������� ������, ��� ��� ����������� ��� ����������" << endl;
			cout << "\n(���� � � �����-�� ������ ������� � ���� ����)" << endl;
			cout << "\n((���� ��� ��������� ���� �� ���-�� ��������� ��� �������)))" << endl;
			exit(0);
			break;
		}
		default:
			puts("����� ������� �� �������������!");
			system("pause");
			break;
		}
	};
}

void OutputMenu(Storage* const Store) {
	system("cls");
	int Key; 
	cout << "\n---------------------------------------  ����� ������  ---------------------------------------\n" << endl;
	cout << "��� �� ������ ����������?" << endl;
	cout << "1 - ������ ���������� ������ (����� ��� � ������� 2, �� ��� � � ��������)" << endl;	
	cout << "2 - ���������� ������ (����� ������� � �������� �������, ������� ��� �� ������������ � ������)" << endl;
	cout << "3 - ������ ����������� ������� (����� ������� � �������������)\n" << endl;
	cin >> Key;
	try {
		switch (Key) {
		case 1:	{ 
			Store->printAbout(); 
			break; 
		}	
		case 2:	{ 
			Store->printSimpleStorage(); 
			break; 
		}
		case 3: { 
			cout << "������� � ����� ������� �� ������ �������?" << endl;	
			cin >> Key;
			Store->printAboutContent(Key);
			break; 
		}
		default:
			puts("����� ������� �� �������������!");
			break;
		}
	}
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\n��������� ����������� ������!\n" << endl; }	
	cout << "" << endl;
	system("pause");
}

void DeletionMenu(Storage* Store) {
	system("cls");
	int Key; 
	cout << "\n---------------  �������� ������  ---------------\n" << endl;
	cout << "��� �� ������ ����������?" << endl;
	cout << "1 - ���������� �������" << endl;	
	cout << "2 - ����� ���� ����� (�������� ����� �����������)\n" << endl;
	cin >> Key;
	try {
		switch (Key) {
		case 1:	{
			cout << "������� � ����� ������� �� ������ ����������?" << endl;
			cin >> Key;
			Store->DelSomeContent(Key);
			break;
		}
		case 2: {
			Store->DelAllContent(); 
			break; 
		}
		default:
			puts("����� ������� �� �������������!");
			break;
		}
	}
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\n��������� ����������� ������!\n" << endl; }	
	cout << "" << endl;
	system("pause");
}

void AdditionMenu(Storage* Store) {
	int Key; 
	int N1;
	int N2;
	char S1[MAX_STR];
	char S2[MAX_STR];
	
	system("cls");
	cout << "\n-------------  ���������� ������  -------------\n" << endl;
	cout << "������� ������ ���� �� ������ �������� �� �����?" << endl;
	cout << "1 - ������" << endl;	
	cout << "2 - ������" << endl;
	cout << "3 - ��������" << endl;
	cout << "4 - ����" << endl;
	cout << "5 - ����������\n" << endl;
	cin >> Key;
	try {
		switch (Key) {
		case 1:	{
			cout << "�������� ������: ";
			cin >> S1;
			cout << "���: ";
			cin >> N1;
			cout << "���������: ";
			cin >> N2;
			Detail* D = new Detail(S1,N1,N2); 
			Store->AddContent(D);	
			break;
		}
		case 2: {
			cout << "�������� �������: ";
			cin >> S1;
			cout << "��� ���������� ��������������: ";
			cin >> S2;
			cout << "���������: ";
			cin >> N1;
			Sensor* S = new Sensor(S1,S2,N1);
			Store->AddContent(S);
			break; 
		}
		case 3: {
			cout << "�������� ���������: ";
			cin >> S1;
			cout << "����� ������: ";
			cin >> N1;
			Mechanism* M = new Mechanism(S1,N1);
			Store->AddContent(M);
			break; 
		}
		case 4: {
			cout << "�������� ����: ";
			cin >> S1;
			Group* G = new Group(S1);
			Store->AddContent(G);
			break; 
		}
		case 5: {
			cout << "�������� ����������: ";
			cin >> S1;
			Device* Dev = new Device(S1);
			Store->AddContent(Dev);
			break; 
		}	
		default:
			puts("����� ������� �� �������������!");
			break;
		}
		if (!(Key<0 || Key>5)) cout << "������� ������� ��������� � ��� ��� �� ������!" << endl;
	}
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\n��������� ����������� ������!\n" << endl; }	
	cout << "" << endl;
	system("pause");
}

void MovementMenu(Storage* Store) {
	system("cls");
	int Key1, Key2;
	cout << "\n---------------------  ������ �������  ---------------------\n" << endl;
	cout << "�� ������ ����� �������, ������� ���� ������ �� ������������." << endl;
	cout << "�� ������ ������������ ���� �� ��� � ������� �������, ������" << endl;
	cout << "����� ��������� ������� ��������:" << endl;
	cout << "| ������ � ������� �������������� � ����������" << endl;
	cout << "| ��������� ������������� � �����" << endl;
	cout << "| ���� �������������� � �����������" << endl;
	cout << "| ���������� ������ ������ ������������\n" << endl;
	cout << "\n������ �� ������ ����� ��������� �������, ��������� ��� ������:" << endl;
	Store->printSimpleContent();
	cout << "\n����� ������� �� ����������� ������������?" << endl;
	cin >> Key1;
	cout << "� ����� ������� �� ����������� ������������" << endl;
	cin >> Key2;
	try { Store->Joining(Key1,Key2); }
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\n��������� ����������� ������!\n" << endl; }	
	cout << "" << endl;
	system("pause");
}

void GenerationMenu(Storage* Store) {
	system("cls");
	int Key=0;
	cout << "\n---------------------  ��������� �������  ---------------------\n" << endl;
	while (Key<=0 || Key>20) {
		cout << "������� ������� ���������� �������������?" << endl;
		cin >> Key;	
		if (Key<=0) cout << "������� ������������� �����!" << endl;
		if (Key>20) cout << "����� �� ������������ ������ 20 ������� �� ���!" << endl;
	}
	Store->Gen(Key);
	cout << "����� ��������� ������� ���� ��� �� ������!" << endl;
	cout << "" << endl;
	system("pause");
}

