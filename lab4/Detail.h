#pragma once
#include "Item_AND_List.h"

class Detail: public Item { //ƒ≈“јЋ№
		int Mass; //масса детали
		int Cost; //стоимость детали
	public:
		Detail(const char* name,const int weight,const int money): Item(name) {
			Mass=weight;
			Cost=money;
		}
		~Detail() {}

		virtual void printAbout() const override {Item::printAbout();}
		virtual bool AddContent(Item* item) override {return false;}
		virtual const char* getType() const override {return "ƒ≈“јЋ№";}
		virtual int Weight() const override {return Mass;}
		virtual float Price() const override {return Cost;}
		virtual int Time() const override {return 0;}
};
