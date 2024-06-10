#pragma once
#include "ComplexItem.h"

class Group: public ComplexItem { //����	

	public:
		
		Group(const char* name): ComplexItem(name) {
			Type = ItemType::GROUP;
		}
		~Group() {}
		
		virtual float Price() const override {
			int S=ContentCost();
			if (Weight()<=20) {}
			else if (Weight()<=50) S=S*1.1;
			else S = S*1.2;
			return S;
		}
		virtual int Time() const override { return ContentTime(); }	
		virtual void AddContent(Item* item) override {
			if (item->Type != ItemType::MECHANISM) throw Error("� ����� ����� ������������ ������ ���������");
			Item::AddContent(item);
		}
};


