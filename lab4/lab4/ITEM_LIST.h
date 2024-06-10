//#pragma once

#include <iostream>
//#include <strings.h>
#define MAX_STR 256

class Item;

struct Node { //���� ������������ ������
	Item* Val; //���������� ����
	Node* Next; //��������� �� ��������� ����
};

class List { //����������� ������ � ����������� �� ������� ����������� �����
	private:	
		Node* Head; //������ ������� ������
	public:
		bool Empty() const; //���� �� ������?
		void Insert(Item* V);
		void Delete(int Number);
		int NodesWeight() const;
		float NodesCost() const;
		int NodesTime() const;
		void Del(Node* Addr);
		void Clear();
		List();
		~List();
		void printList() const;
};


class Item { //���������� - ������� ����������� �����
	private:
		std::string Name;	//�������� �������	
		static int NextId; //��������� ���������� �������� ����� �������/��������
	protected:
		List Content; //������ ���������� �� ��������, �������� � �������
	public:
		int Id;
		Item(const std::string name);
		virtual ~Item();
		
		virtual void printAbout() const = 0; //����� ������ ���������� �� �������
		virtual void printContent() const = 0; //����� ������������ ������ �������
		virtual void AddContent(Item* item) = 0;
		virtual void DelContent(int Number) = 0;
		
		virtual const char* getType() const = 0; //���������� ��� �������
		virtual int Weight() const = 0; //����� �������
		virtual float Price() const = 0;//��������� �������	
		virtual int Time() const = 0; //��������� ����� ������ �������		
};
