#pragma once
#include "Item.h"

//������������ ��� ������������ ���������, ������� ����� �������� �� ������
class ComplexItem: public Item { //��������� �������
	
	protected:
		
		//����� ���� �������, �������� � ������ �������
		int ContentWeight() const;
		//����� ��������� ���� �������, �������� � ������ �������
		int ContentCost() const;
		//��������� ����� ������ ������� ������ �� ��� �������
		int ContentTime() const;
	
	public:
		
		ComplexItem(const char* name): Item(name) {}
		virtual ~ComplexItem() { /*Content.Clear();*/ }
		
		virtual int Weight() const final { return ContentWeight(); }
		virtual void printAbout() const final {
			Item::printAbout();
			cout << "| ����� ������: " << Time() << " ����" << endl;
		}
};

