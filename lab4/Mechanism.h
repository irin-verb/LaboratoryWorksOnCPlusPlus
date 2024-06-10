#pragma once
#include "ComplexItem.h"

class Mechanism: public ComplexItem { //ÌÅÕÀÍÈÇÌ
	private:
		int Timer; //âğåìÿ èçíîñà èçäåëèÿ	
	public:
		Mechanism(const char* name,const int time): ComplexItem(name) {
			Timer=time;
		}
		~Mechanism() {}
		
		virtual const char* getType() const override {return "ÌÅÕÀÍÈÇÌ";}
		virtual float Price() const override {return Content.NodesCost();}
		virtual int Time() const override {return Timer;}
		virtual bool AddContent(Item* item) override {
			if (strcmp(item->getType(),"ÄÀÒ×ÈÊ")==0 || strcmp(item->getType(),"ÄÅÒÀËÜ")==0) {
				Item::AddContent(item);
				return true;
			}
			else return false;
		}
};
