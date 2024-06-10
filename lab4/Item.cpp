#include "Item_AND_List.h"

using namespace std;

Item::Item(const char* name) {
	strcpy(Name, name);
	Id = NextId;
	NextId++;
}

Item::~Item() {Content.Clear();}
		
int Item::NextId = 0;

void Item::printAbout() const {
	if (!Content.Empty()) {
		cout << " _____________________" << endl;
		cout << "/                     \\" << endl;
		Content.printList();
		cout << "\n\\_____________________/" << endl;
	}
	cout << "\nИЗДЕЛИЕ № " << Id << ": " << getType() << endl;
	cout << "| Название: " << Name << endl;
	cout << "| Стоимость: " << Price() << " руб" << endl;
	if (Weight() > 0) 
		cout << "| Вес: " << Weight() << " г" << endl;
}

void Item::printSimpleAbout() const {
	cout << getType() << " -  \"" << Name << "\"  -   № " << Id << endl;
}

bool Item::AddContent(Item* item) {Content.Insert(item);return true;}
