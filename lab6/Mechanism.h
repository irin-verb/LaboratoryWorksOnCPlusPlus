#pragma once
#include "ComplexItem.h"

class Mechanism: public ComplexItem { //МЕХАНИЗМ

	private:
		
		int Timer; //время износа датчика
		
	public:
		
		Mechanism(const char* name,const int time): ComplexItem(name) {
			if (time <= 0) throw Error("Недопустимые значения параметров!");
			Timer=time;
			Type=ItemType::MECHANISM;
		}
		~Mechanism() {}
		
		virtual float Price() const override { return ContentCost(); }
		virtual int Time() const override { return Timer; }
		virtual void AddContent(Item* item) override {
			if (item->Type != ItemType::SENSOR && item->Type != ItemType::DETAIL)
				throw Error("К МЕХАНИЗМАМ можно присоединять только ДАТЧИКИ и ДЕТАЛИ");
			Item::AddContent(item);
		}
};



