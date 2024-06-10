#pragma once
#include "Item_AND_List.h"

using namespace std;

class Sensor: public Item { //ДАТЧИК	
		float Cost; //стоимость датчика
		char Measure[MAX_STR]; //тип замеряемой характеристики
	public:
		Sensor(const char* name,const char* measure,const int money): Item(name) {
			strcpy(Measure, measure);
			Cost=money;	}
		~Sensor() {}
		
		virtual bool AddContent(Item* item) override {return false;}
		virtual const char* getType() const override {return "ДАТЧИК";}
		virtual int Weight() const override {return 0;}
		virtual float Price() const override {return Cost;}
		virtual int Time() const override {return 0;}
		virtual void printAbout() const override {
			Item::printAbout();
			cout << "| Характ.: " << Measure << endl;
		}
};
