#pragma once
#include "Item.h"
#include "Random.h"

class Storage: public Item { //�����
		
	public:	
	
		Storage(const char* name): Item(name) { Type = ItemType::STORAGE; }
		~Storage() { /*Content.Clear();*/ }

		virtual void printAbout() const final;
		virtual int Weight() const override {} 
		virtual float Price() const override {}
		virtual int Time() const override {}
		virtual void AddContent(Item* item) override { Item::AddContent(item); }
		
		void printAboutContent(int const &Key) const; //����� ����������� ������� �� ������
		void printSimpleStorage() const; //����� ������� �� ������ � ���������� ����
		void DelSomeContent(int const &Key); //�������� ����������� ������� �� ������
		void DelAllContent(); //������ �������� ��������� ������
		void Joining (int const &What, int const &ToWhich); //������������� �������� What � ������ ToWhich
		void Gen (int const &N); //���������� �� ����� N ��������������� ����������
		void GenItem(); //���������� �� ����� ��������������� ��������
};
