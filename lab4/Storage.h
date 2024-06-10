#pragma once
#include "Item_AND_List.h"
#include "Random.h"

class Storage: public Item { //�����
	private:
	protected:
	public:	
		Storage(const char* name): Item(name) {}
		~Storage() {Content.Clear();}

		virtual void printAbout() const final;
		virtual const char* getType() const final {return "�����";}
		virtual int Weight() const override {} 
		virtual float Price() const override {}
		virtual int Time() const override {}
		virtual bool AddContent(Item* item) override {Item::AddContent(item);return true;}
		
		void printAboutContent(int const Key) const; //����� ����������� ������� �� ������
		void printSimpleContent() const; //����� ������� �� ������ � ���������� ����
		void DelSomeContent(int const Key); //�������� ����������� ������� �� ������
		void DelAllContent(); //������ �������� ��������� ������
		void Joining (int const What, int const ToWhich); //������������� �������� What � ������ ToWhich
		void Gen (int const N); //���������� �� ����� N ��������������� ����������
		void GenItem();//���������� �� ����� ��������������� ��������
};
