#pragma once
#include "ComplexItem.h"

class Mechanism: public ComplexItem { //��������

	private:
		
		int Timer; //����� ������ �������
		
	public:
		
		Mechanism(const char* name,const int time): ComplexItem(name) {
			if (time <= 0) throw Error("������������ �������� ����������!");
			Timer=time;
			Type=ItemType::MECHANISM;
		}
		~Mechanism() {}
		
		virtual float Price() const override { return ContentCost(); }
		virtual int Time() const override { return Timer; }
		virtual void AddContent(Item* item) override {
			if (item->Type != ItemType::SENSOR && item->Type != ItemType::DETAIL)
				throw Error("� ���������� ����� ������������ ������ ������� � ������");
			Item::AddContent(item);
		}
};



