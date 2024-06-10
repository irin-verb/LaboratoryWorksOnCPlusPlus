#pragma once
#include "Item.h"

using namespace std;

class Sensor: public Item { //������
	
		float Cost; //��������� �������
		char Measure[MAX_STR]; //��� ���������� ��������������
		
	public:
		
		Sensor(const char* name,const char* measure,const int money): Item(name) {
			if (money <= 0) throw Error("������������ �������� ����������!");
			strcpy(Measure, measure);
			Cost=money;	
			Type=ItemType::SENSOR;
		}
		~Sensor() {}
		
		virtual void AddContent(Item* item) override { throw Error("� �������� ������ ������ ������������"); }
		virtual int Weight() const override { return 0; }
		virtual float Price() const override { return Cost; }
		virtual int Time() const override { return 0; }
		virtual void printAbout() const override {
			Item::printAbout();
			cout << "| ������.: " << Measure << endl;
		}
};
