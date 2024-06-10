#include "Menu.h"

using namespace std;

void MainMenu(Storage* Store) {
	int Key; //номер вводимой команды
	while (true ){
		system("cls");
		cout << "\n-----------  ДОБРО ПОЖАЛОВАТЬ В СИМУЛЯТОР СБОРЩИКА НА ЗАВОДЕ! :)  -----------\n" << endl;
		cout << "Введите номер команды" << endl;
		cout << "1 - Посмотреть содержимое скалада (вывод данных)" << endl;
		cout << "2 - Закупить случайные изделия (генерация данных)" << endl;
		cout << "3 - Уничтожить изделие (удаление данных)" << endl;
		cout << "4 - Купить новое изделие (внесение новых данных)" << endl;	
		cout << "5 - Собрать изделие (присоединить изделие со склада в состав другого изделия)" << endl;
		cout << "6 - Закончить рабочий день (завершение работы программы)\n" << endl;
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
				cout << "Потому что существует лишь в динамической памяти, а не на самом деле :)" << endl;
			}
			catch (Error& E) { }
			catch(...) { cout << "Произошла неизвестная ошибка!" << endl; }	
			cout << "\nХочется верить, что Вам понравилось это приложение" << endl;
			cout << "\n(Ведь я в каком-то смысле вложила в него душу)" << endl;
			cout << "\n((Хотя это сообщение вряд ли кто-то прочитает или заметит)))" << endl;
			exit(0);
			break;
		}
		default:
			puts("Такой команды не предусмотрено!");
			system("pause");
			break;
		}
	};
}

void OutputMenu(Storage* const Store) {
	system("cls");
	int Key; 
	cout << "\n---------------------------------------  ВЫВОД ДАННЫХ  ---------------------------------------\n" << endl;
	cout << "Что вы хотите посмотреть?" << endl;
	cout << "1 - Полное содержимое склада (вывод как в команде 2, но еще и с составом)" << endl;	
	cout << "2 - Содержимое склада (вывод номеров и названий изделий, которые еще не присоединены к другим)" << endl;
	cout << "3 - Сборку конкретного изделия (вывод состава и характеристик)\n" << endl;
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
			cout << "Изделие с каким номером вы хотите вывести?" << endl;	
			cin >> Key;
			Store->printAboutContent(Key);
			break; 
		}
		default:
			puts("Такой команды не предусмотрено!");
			break;
		}
	}
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\nПроизошла неизвестная ошибка!\n" << endl; }	
	cout << "" << endl;
	system("pause");
}

void DeletionMenu(Storage* Store) {
	system("cls");
	int Key; 
	cout << "\n---------------  УДАЛЕНИЕ ДАННЫХ  ---------------\n" << endl;
	cout << "Что вы хотите уничтожить?" << endl;
	cout << "1 - Конкретное изделие" << endl;	
	cout << "2 - Сжечь весь склад (удаление всего содержимого)\n" << endl;
	cin >> Key;
	try {
		switch (Key) {
		case 1:	{
			cout << "Изделие с каким номером вы хотите уничтожить?" << endl;
			cin >> Key;
			Store->DelSomeContent(Key);
			break;
		}
		case 2: {
			Store->DelAllContent(); 
			break; 
		}
		default:
			puts("Такой команды не предусмотрено!");
			break;
		}
	}
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\nПроизошла неизвестная ошибка!\n" << endl; }	
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
	cout << "\n-------------  ДОБАВЛЕНИЕ ДАННЫХ  -------------\n" << endl;
	cout << "Изделие какого типа вы хотите добавить на склад?" << endl;
	cout << "1 - Деталь" << endl;	
	cout << "2 - Датчик" << endl;
	cout << "3 - Механизм" << endl;
	cout << "4 - Узел" << endl;
	cout << "5 - Устройство\n" << endl;
	cin >> Key;
	try {
		switch (Key) {
		case 1:	{
			cout << "Название детали: ";
			cin >> S1;
			cout << "Вес: ";
			cin >> N1;
			cout << "Стоимость: ";
			cin >> N2;
			Detail* D = new Detail(S1,N1,N2); 
			Store->AddContent(D);	
			break;
		}
		case 2: {
			cout << "Название датчика: ";
			cin >> S1;
			cout << "Тип замеряемой характеристики: ";
			cin >> S2;
			cout << "Стоимость: ";
			cin >> N1;
			Sensor* S = new Sensor(S1,S2,N1);
			Store->AddContent(S);
			break; 
		}
		case 3: {
			cout << "Название механизма: ";
			cin >> S1;
			cout << "Время износа: ";
			cin >> N1;
			Mechanism* M = new Mechanism(S1,N1);
			Store->AddContent(M);
			break; 
		}
		case 4: {
			cout << "Название узла: ";
			cin >> S1;
			Group* G = new Group(S1);
			Store->AddContent(G);
			break; 
		}
		case 5: {
			cout << "Название устройства: ";
			cin >> S1;
			Device* Dev = new Device(S1);
			Store->AddContent(Dev);
			break; 
		}	
		default:
			puts("Такой команды не предусмотрено!");
			break;
		}
		if (!(Key<0 || Key>5)) cout << "Изделие успешно добавлено и ждёт вас на складе!" << endl;
	}
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\nПроизошла неизвестная ошибка!\n" << endl; }	
	cout << "" << endl;
	system("pause");
}

void MovementMenu(Storage* Store) {
	system("cls");
	int Key1, Key2;
	cout << "\n---------------------  СБОРКА ИЗДЕЛИЙ  ---------------------\n" << endl;
	cout << "На складе лежат изделия, которые пока никуда не присоединены." << endl;
	cout << "Вы можете присоединить одно из них к другому узделию, однако" << endl;
	cout << "важно соблюдать ПРАВИЛА иерархии:" << endl;
	cout << "| ДЕТАЛИ и ДАТЧИКИ присоединяются к МЕХАНИЗМАМ" << endl;
	cout << "| МЕХАНИЗМЫ присоединятся к УЗЛАМ" << endl;
	cout << "| УЗЛЫ присоединяются к УСТРОЙСТВАМ" << endl;
	cout << "| УСТРОЙСТВА никуда нельзя присоединить\n" << endl;
	cout << "\nСейчас на складе лежат следующие изделия, доступные для сборки:" << endl;
	Store->printSimpleContent();
	cout << "\nКАКОЕ изделие вы собираетесь присоединять?" << endl;
	cin >> Key1;
	cout << "В КАКОЕ изделие вы собираетесь присоединять" << endl;
	cin >> Key2;
	try { Store->Joining(Key1,Key2); }
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\nПроизошла неизвестная ошибка!\n" << endl; }	
	cout << "" << endl;
	system("pause");
}

void GenerationMenu(Storage* Store) {
	system("cls");
	int Key=0;
	cout << "\n---------------------  ГЕНЕРАЦИЯ ИЗДЕЛИЙ  ---------------------\n" << endl;
	while (Key<=0 || Key>20) {
		cout << "Сколько изделий необходимо сгенерировать?" << endl;
		cin >> Key;	
		if (Key<=0) cout << "Введите положительное число!" << endl;
		if (Key>20) cout << "Лучше не генерировать больше 20 изделий за раз!" << endl;
	}
	Store->Gen(Key);
	cout << "Новые случайные изделия ждут вас на складе!" << endl;
	cout << "" << endl;
	system("pause");
}

