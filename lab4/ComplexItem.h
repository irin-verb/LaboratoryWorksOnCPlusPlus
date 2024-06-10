#pragma once
#include "Item_AND_List.h"

//отличается от Item тем, что окончательно определяет процедуры printAbout и Weight
//предназначен для наследования сущностям, которые могут состоять из других
class ComplexItem: public Item { //СОСТАВНОЕ ИЗДЕЛИЕ
	public:
		ComplexItem(const char* name): Item(name) {}
		virtual ~ComplexItem() {Content.Clear();}
		virtual int Weight() const final {return Content.NodesWeight();} 
		virtual void printAbout() const final {
			Item::printAbout();
			cout << "| Время износа: " << Time() << " дней" << endl;
		}
};

