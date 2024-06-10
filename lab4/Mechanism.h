#pragma once
#include "ComplexItem.h"

class Mechanism: public ComplexItem { //��������
	private:
		int Timer; //����� ������ �������	
	public:
		Mechanism(const char* name,const int time): ComplexItem(name) {
			Timer=time;
		}
		~Mechanism() {}
		
		virtual const char* getType() const override {return "��������";}
		virtual float Price() const override {return Content.NodesCost();}
		virtual int Time() const override {return Timer;}
		virtual bool AddContent(Item* item) override {
			if (strcmp(item->getType(),"������")==0 || strcmp(item->getType(),"������")==0) {
				Item::AddContent(item);
				return true;
			}
			else return false;
		}
};
