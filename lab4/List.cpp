#include "Item_AND_List.h"

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

void List::Delete(int N) {
	Node* Dop;
	//если на верхушке списка проходимся по верхушкам
	if(InTopList(N)) {
		Dop=Head;
		if (Dop->Val->Id==N) Del(Dop);
		else while ((Dop->Next!=nullptr) || (Dop!=nullptr)) {
			Dop=Dop->Next;
			if (Dop->Val->Id==N) {
				Del(Dop);
				break;
				}		
		}				
	} //иначе проходимся по содержимому верхушек
	else if (InList(N)) { 
		Dop=Head;
		if (Dop->Val->Content.InList(N)) Dop->Val->Content.Delete(N);
		while ((Dop->Next!=nullptr) && (Dop!=nullptr)) {
			Dop=Dop->Next;
			if (Dop->Val->Content.InList(N)) {
				Dop->Val->Content.Delete(N);
				break;
			}			
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
	//удаляем контент узла
	if(!(Addr->Val->Content.Empty())) {
		Addr->Val->Content.Clear();
	}	
	//удаляем сам узел
	if (Addr!=nullptr) {
		if (Addr==Head) {
			Head=Addr->Next;
			delete Addr;
			Addr = nullptr;
		}
		else {
			Node* Dop;
			Dop=Head;
			while ((Dop->Next!=Addr) && (Dop!=nullptr) && (Dop->Next!=nullptr)) Dop=Dop->Next;
			Dop->Next=Addr->Next;
			delete Addr;
			Addr = nullptr;	
		};
	}		
}

void List::Clear() {while (!Empty()) Del(Head);}
	
List::List() {Head=nullptr;}

List::~List() { std::cout<<std::endl;Clear();}

void List::printList() const {
	if (!Empty()) {
		Node* Dop;
		Dop=Head;
		Dop->Val->printAbout();
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			Dop->Val->printAbout();
		}
	}	
}

void List::printInList(int const N) const {
	if (!Empty()){
		Node* Dop;
		Dop=Head;
		
		if (Dop->Val->Id==N) Dop->Val->printAbout();
		else Dop->Val->Content.printInList(N);
		
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			if (Dop->Val->Id==N) Dop->Val->printAbout();
			else Dop->Val->Content.printInList(N);
		}
	}
}

bool List::InList(int const N) const {
	bool F=false;
	if (!Empty()){
		Node* Dop;
		Dop=Head;
		
		if (Dop->Val->Id==N) F = true;
		else F = Dop->Val->Content.InList(N);
		if (F) return F;
		
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			if (Dop->Val->Id==N) F = true;
			else F = Dop->Val->Content.InList(N);
			if (F) return F;
		}
	}
	return F;
}

bool List::InTopList(int const N) const {
	bool F=false;
	if (!Empty()) {
		Node* Dop;
		Dop=Head;
		if (Dop->Val->Id==N) F = true;	
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			if (Dop->Val->Id==N) F = true;
			if (F) return F;
		}
	}
	return F;
}

void List::printSimpleList() const {
	if (!Empty()) {
		Node* Dop;
		Dop=Head;
		Dop->Val->printSimpleAbout();
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			Dop->Val->printSimpleAbout();
		}
	}
}

Item* List::ComplexSearch(int const N) const {
	Item* R=nullptr;
	if (!Empty()){
		Node* Dop;
		Dop=Head;
		
		if (Dop->Val->Id==N) R=Dop->Val;
		else R = Dop->Val->Content.ComplexSearch(N);
		if (R!=nullptr) return R;
		
		while (Dop->Next!=nullptr) {
			Dop=Dop->Next;
			if (Dop->Val->Id==N) R=Dop->Val;
			else R = Dop->Val->Content.ComplexSearch(N);
			if (R!=nullptr) return R;
		}
	}
	return R;
}
