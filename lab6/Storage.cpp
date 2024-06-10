#include "Storage.h"

using namespace std;

void Storage::printAbout() const {
	if (Content.empty()) throw Error("На складе пока нет изделий!");
	cout << "\n------- СКЛАД ---------\n" << endl;
	printContent();
}

void Storage::printAboutContent(int const &Key) const {
	if (Content.empty()) throw Error("На складе пока нет изделий!");
	if (!(InContent(Key))) throw Error("Такого изделия нет!");
	cout << "\n---- ИЗДЕЛИЕ № "<< Key <<" ------\n" << endl;
	printSomeContent(Key);
}

void Storage::printSimpleStorage() const {
	if (Content.empty()) throw Error("На складе пока нет изделий!");
	cout << "\n------------------- СКЛАД -------------------\n" << endl;
	printSimpleContent();
}

void Storage::DelSomeContent(int const &Key) {
	if (Content.empty()) throw Error("На складе пока нет изделий!");
	if (!(InContent(Key))) throw Error("Такого изделия нет!");
	DelContent(Key);
	cout << "Удаление прошло успешно!" << endl;
}

void Storage::DelAllContent() {
	if (Content.empty()) throw Error("Склад пуст!");
	Clear();
	cout << "Склад успешно уничтожен!" << endl; 
}

void Storage::Joining (int const &What, int const &ToWhich) {	// что - куда
	if (Content.empty()) throw Error("На складе пока нет изделий!");
	if (!(InContent(What))) throw Error("На складе нет элемента, который вы хотите присоединить!");
	if (!(InTopContent(What))) throw Error("Присоединять можно только изделия, лежащие на складе,\nт.е. те, которые еще не присоединены к другим!");
	if (!(InContent(ToWhich))) throw Error("На складе нет элемента, в состав которого вы хотите включить изделие!");
	try {
		SearchContent(ToWhich)->AddContent(SearchContent(What));
		DelTopContent(What);
		cout << "\nПрисоединение прошло успешно!\n" << endl;
	}
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\nПроизошла неизвестная ошибка!\n" << endl; }	
}

void Storage::Gen(int const &N) { for (int i=0;i<N;i++) GenItem(); }	
							
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

