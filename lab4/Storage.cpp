#include "Storage.h"

using namespace std;

void Storage::printAbout() const {
	if (!Content.Empty()) {
		cout << "\n------- СКЛАД ---------\n" << endl;
		Content.printList();
	}
	else cout << "\nНа складе пока нет изделий!\n" << endl;
}

void Storage::printAboutContent(int const Key) const {
	if (Content.InList(Key)) {
		cout << "\n---- ИЗДЕЛИЕ № "<< Key <<" ------\n" << endl;
		Content.printInList(Key);
	}
	else cout << "\nТакого изделия нет!\n" << endl;
}

void Storage::printSimpleContent() const {
	if (!Content.Empty()) {
		cout << "\n------------------- СКЛАД -------------------\n" << endl;
		Content.printSimpleList();
	}
	else cout << "\nНа складе пока нет изделий!\n" << endl;
}

void Storage::DelSomeContent(int const Key) {
	if (Content.InList(Key)) {
		Content.Delete(Key);
		cout << "\nУдаление прошло успешно!\n" << endl;
	}
	else cout << "\nТакого изделия нет!\n" << endl;
}

void Storage::DelAllContent() {
	if (!Content.Empty()) {
		Content.Clear();
		cout << "\nСклад успешно уничтожен!\n" << endl;
	}
	else cout << "\nСклад пуст!\n" << endl;
}

void Storage::Joining (int const What, int const ToWhich) {
	if (Content.Empty()) cout << "Ошибка! Склад пуст" << endl;
	else if (!Content.InList(What)) cout << "Ошибка! На складе нет элемента, который вы хотите присоединить" << endl;
	else if (!Content.InTopList(What)) {
		cout << "Ошибка! Присоединять можно только изделия, лежащие на складе" << endl;
		cout << "То есть выбирать можно среди следующих изделий:" << endl;
		printSimpleContent();
	}
	else if (strcmp(Content.ComplexSearch(What)->getType(),"УСТРОЙСТВО")==0) cout << "Ошибка! Готовые УСТРОЙСТВА нельзя включать в состав других изделий" << endl;
	else if (!Content.InList(ToWhich)) cout << "Ошибка! На складе нет элемента, в состав которого вы хотите включить изделие" << endl;
	else if (!Content.ComplexSearch(ToWhich)->AddContent(Content.ComplexSearch(What))) {
		const char* Type = (Content.ComplexSearch(ToWhich)->getType());
		cout << "Ошибка совместимости! \nК типу изделия " << Type;
		if (strcmp(Type,"ДЕТАЛЬ")==0 || strcmp(Type,"ДАТЧИК")==0) cout << " ничего нельзя присоединять";
		else if (strcmp(Type,"МЕХАНИЗМ")==0) cout << " можно присоединять только тип изделий ДЕТАЛЬ и ДАТЧИК";
		else if (strcmp(Type,"УЗЕЛ")==0) cout << " можно присоединять только тип изделий МЕХАНИЗМ";
		else if (strcmp(Type,"УСТРОЙСТВО")==0) cout << " можно присоединять только тип изделий УЗЕЛ";
		cout << ", а Вы попытались присоединить " << Content.ComplexSearch(What)->getType();
		}
	else {
		Content.Delete(What);
		cout << "Присоединение прошло успешно!" << endl;
	}
}

void Storage::Gen(int const N) {for (int i=0;i<N;i++) GenItem();}	
							
void Storage::GenItem() {
	int K = 1+rand()%(5);
	switch (K) {
		case 1: {AddContent(RandomDetail()); break;}
		case 2: {AddContent(RandomSensor()); break;}
		case 3: {AddContent(RandomMechanism()); break;}
		case 4: {AddContent(RandomGroup()); break;}
		case 5: {AddContent(RandomDevice()); break;}
	}
}

