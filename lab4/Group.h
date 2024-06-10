#pragma once
#include "ComplexItem.h"

class Group: public ComplexItem { //����	
	public:
		Group(const char* name): ComplexItem(name) {}
		~Group() {}
		virtual const char* getType() const override {return "����";}
		virtual float Price() const override {
			int S=Content.NodesCost();
			if (Weight()<=20) {}
			else if (Weight()<=50) S=S*1.1;
			else S=S*1.2;
			return S;
		}
		virtual int Time() const override {return Content.NodesTime();}	
		virtual bool AddContent(Item* item) override {
			if (strcmp(item->getType(),"��������")==0) {
				Item::AddContent(item);
				return true;
			}
			else return false;
		}
};


