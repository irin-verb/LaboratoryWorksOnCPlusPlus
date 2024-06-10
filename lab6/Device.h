#pragma once
#include "ComplexItem.h"

class Device: public ComplexItem { //УСТРОЙСТВО

	private:
	protected:
	public:
		
		Device(const char* name): ComplexItem(name) { 
			Type = ItemType::DEVICE; 
		}
		~Device() {}
		
		virtual float Price() const override { return ContentCost(); }
		virtual int Time() const override { return ContentTime(); }
		virtual void AddContent(Item* item) override {
			if (item->Type != ItemType::GROUP) throw Error("К УСТРОЙСТВАМ можно присоединять только УЗЛЫ");
			Item::AddContent(item);
		}
};
