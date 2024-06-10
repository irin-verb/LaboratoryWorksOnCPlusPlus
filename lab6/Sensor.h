#pragma once
#include "Item.h"

using namespace std;

class Sensor: public Item { //ДАТЧИК
	
		float Cost; //стоимость датчика
		char Measure[MAX_STR]; //тип замеряемой характеристики
		
	public:
		
		Sensor(const char* name,const char* measure,const int money): Item(name) {
			if (money <= 0) throw Error("Недопустимые значения параметров!");
			strcpy(Measure, measure);
			Cost=money;	
			Type=ItemType::SENSOR;
		}
		~Sensor() {}
		
		virtual void AddContent(Item* item) override { throw Error("К ДАТЧИКАМ ничего нельзя присоединять"); }
		virtual int Weight() const override { return 0; }
		virtual float Price() const override { return Cost; }
		virtual int Time() const override { return 0; }
		virtual void printAbout() const override {
			Item::printAbout();
			cout << "| Характ.: " << Measure << endl;
		}
};
