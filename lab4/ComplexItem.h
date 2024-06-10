#pragma once
#include "Item_AND_List.h"

//���������� �� Item ���, ��� ������������ ���������� ��������� printAbout � Weight
//������������ ��� ������������ ���������, ������� ����� �������� �� ������
class ComplexItem: public Item { //��������� �������
	public:
		ComplexItem(const char* name): Item(name) {}
		virtual ~ComplexItem() {Content.Clear();}
		virtual int Weight() const final {return Content.NodesWeight();} 
		virtual void printAbout() const final {
			Item::printAbout();
			cout << "| ����� ������: " << Time() << " ����" << endl;
		}
};

