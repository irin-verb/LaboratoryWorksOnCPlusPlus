#pragma once
#include "ComplexItem.h"

class Device: public ComplexItem { //����������
	private:
	protected:
	public:
		Device(const char* name): ComplexItem(name) {}
		~Device() {}
		
		virtual const char* getType() const override {return "����������";}
		virtual float Price() const override {return Content.NodesCost();} 
		virtual int Time() const override {return Content.NodesTime();}	
		virtual bool AddContent(Item* item) override {
			if (strcmp(item->getType(),"����")==0) {
				Item::AddContent(item);
				return true;
			}
			else return false;
		}
};
