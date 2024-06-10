#pragma once
#include "Item.h"

//предназначен для наследования сущностям, которые могут состоять из других
class ComplexItem: public Item { //СОСТАВНОЕ ИЗДЕЛИЕ
	
	protected:
		
		//сумму масс изделий, входящих в состав изделия
		int ContentWeight() const;
		//сумма стоимости всех изделий, входящих в состав данного
		int ContentCost() const;
		//расчётное время износа изделия исходя из его состава
		int ContentTime() const;
	
	public:
		
		ComplexItem(const char* name): Item(name) {}
		virtual ~ComplexItem() { /*Content.Clear();*/ }
		
		virtual int Weight() const final { return ContentWeight(); }
		virtual void printAbout() const final {
			Item::printAbout();
			cout << "| Время износа: " << Time() << " дней" << endl;
		}
};

