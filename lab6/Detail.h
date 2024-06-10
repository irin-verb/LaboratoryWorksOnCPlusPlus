#pragma once
#include "Item.h"

class Detail: public Item { //������
	
		int Mass; //����� ������
		int Cost; //��������� ������ 
		
	public:

		Detail(const char* name, const int weight, const int money): Item(name) {
			if ((weight <= 0) || (money <= 0)) throw Error("������������ �������� ����������!");
			Mass=weight;
			Cost=money;
			Type=ItemType::DETAIL;
		}
		~Detail() {}

		virtual void printAbout() const override { Item::printAbout(); }
		virtual void AddContent(Item* item) override { throw Error("� ������� ������ ������ ������������"); }
		virtual int Weight() const override { return Mass; }
		virtual float Price() const override { return Cost; }
		virtual int Time() const override { return 0; }
};




