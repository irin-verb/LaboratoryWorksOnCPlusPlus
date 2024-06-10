#include "ITEM_LIST.h"
using namespace std;

bool List::Empty() const {return Head==nullptr;} 

void List::Insert(Item* V) { 
	Node* New = new Node();
	New->Next=nullptr;
	New->Val=V;
	if (Empty()) Head=New;		
	else {
		Node* Dop;
		Dop=Head;
		while ((Dop->Next)!=nullptr) Dop=Dop->Next;
		Dop->Next=New;
	}	
}
		
void List::Delete(int Number) {
	if (!Empty()) {
		Node* Dop;
		Dop=Head;			
		if (Dop->Val->Id==Number) Del(Dop);
		else {
			while((Dop->Val->Id!=Number) and (Dop!=nullptr)) Dop=Dop->Next;
			if (Dop!=nullptr) Del(Dop);
		}
	}
}
		
int List::NodesWeight() const {
	int S=0;
	if (!Empty()) {
		Node* Dop;
		Dop=Head;
		S+=Dop->Val->Weight();
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			S+=Dop->Val->Weight();
		}
	}
	return S;
}
		
float List::NodesCost() const {
	float S=0;
	if (!Empty()) {
		Node* Dop;
		Dop=Head;
		S+=Dop->Val->Price();
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			S+=Dop->Val->Price();
		}
	}
	return S;
}

int List::NodesTime() const { 
	if (Empty()) return 0;
	else {
		Node* Dop;
		Dop = Head;
		int max=Dop->Val->Time();
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			max = Dop->Val->Time()>max ? Dop->Val->Time() : max;
		}
		return max;
	}
}

void List::Del(Node* Addr) { 
	if (Addr!=nullptr){
		Node* Dop; 
		if (Addr==Head) {
			Head=Addr->Next;
			delete Addr;
			Addr = nullptr;
		}
		else {
			Dop=Head;
			while ((Dop->Next!=Addr) and (Dop!=nullptr)) Dop=Dop->Next;
			if (Dop!=nullptr) {
				Dop->Next=Addr->Next;
				delete Addr;
				Addr = nullptr;
			}	
		};
	}
}

void List::Clear() {while (!Empty()) Del(Head);}	
	
List::List() {Head=nullptr;}

List::~List() {Clear();}

void List::printList() const {
	if (Empty()) {
		cout<< "Пока в изделии нет составных частей" <<endl;	
	}
	else {
		Node* Dop;
		Dop=Head;
		Dop->Val->printAbout();
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			Dop->Val->printAbout();
		}
	}	
}


Item::Item(const string name) {
	//strcpy(Name, name);
	//strcpy_s(Name, name);
	Name = name;
	Id = NextId;
	NextId++;
}

Item::~Item() {Content.Clear();}
		
int Item::NextId = 1;

//void Item::AddContent(Item* item) {Content.Insert(item);}
//void Item::DelContent(int Number) {Content.Delete(Number);}

void Item::printAbout() const {
	cout << "ИЗДЕЛИЕ № " << Id << ": " << getType() << endl;
	cout << "| Название: " << Name << endl;
	cout << "| Стоимость: " << Price() << " руб" << endl;
	if (Weight() > 0) 
		cout << "| Вес: " << Weight() << " кг" << endl;
}

void Item::printContent() const {
	if (!Content.Empty()) {
		cout << "СОСТАВ:" << endl;
			cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
			Content.printList();
			cout << "---------------------------------" << endl;
	}
}
