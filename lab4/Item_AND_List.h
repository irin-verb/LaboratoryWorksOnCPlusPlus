#pragma once
#include <iostream>
#include <strings.h>
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
		List();
		~List();
		bool Empty() const;  //���� �� ������?
		void Insert(Item* V);//��������� ����� ������� � ����� ������
		void Del(Node* Addr);//������� ������� � ������� Addr
		void Clear();//������� ��� ���������� ������ ������ � ���������� ��� ���������
		
		void printList() const;//������� ���� ��������� ������
		void printInList(int const N) const;//����� �������� � ������� N
		void printSimpleList() const;//���������� ����� "��������" ������, �� ���� ������ ��������� ������, ��� ������ ������� ���� ���������
		
		int NodesWeight() const;//������� ��������� ��� ��������� ������ (� ���������, �������� � ������ ���������)
		float NodesCost() const;//������� ����� ��������� �� ������
		int NodesTime() const;//������� ����� ����� ������ �� ������
		void Delete(int N);  //������� ������� � ������� N �� ������, ��� �� �������, ������� ����������� ��������� ����� ������
		bool InList(int const N) const;//���� �� ������� � ������? (� ������ ������� ��� ��������� � �����������)
		bool InTopList(int const N) const;//���� �� ������� � ������? (������ ����� ���������, �� �� ����� ������� ���� ���������)
		
		Item* ComplexSearch(int const N) const; //���������� ����� ���� �� ��� ������
};

class Item { //������� - ������� ����������� �����
	private:
		char Name[MAX_STR];//�������� �������	
		static int NextId; //��������� ���������� �������� ����� �������
	protected:
		int Id; //�������� ����� �������
		List Content; //������ ���������� �� ��������, �������� � �������
	public:
		Item(const char* name);
		virtual ~Item();
		
		virtual void printAbout() const = 0; //����� ������ ���������� �� �������
		virtual bool AddContent(Item* item)=0; //���������� � Content ������ ��������
		virtual const char* getType() const = 0; //���������� ��� �������
		virtual int Weight() const = 0; //����� �������
		virtual float Price() const = 0;//��������� �������	
		virtual int Time() const = 0; //��������� ����� ������ �������	
		
		void printSimpleAbout() const;	//����� ������, ���� � �������� �������
		friend class List;		
};
