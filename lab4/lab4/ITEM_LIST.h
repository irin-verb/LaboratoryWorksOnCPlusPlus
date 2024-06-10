//#pragma once

#include <iostream>
//#include <strings.h>
#define MAX_STR 256

class Item;

struct Node { //узел односв€зного списка
	Item* Val; //содержимое узла
	Node* Next; //указатель на следующий узел
};

class List { //односв€зный список с указател€ми на базовый абстрактный класс
	private:	
		Node* Head; //первый элемент списка
	public:
		bool Empty() const; //пуст ли список?
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


class Item { //”—“–ќ…—“¬ќ - базовый абстрактный класс
	private:
		std::string Name;	//название издели€	
		static int NextId; //следующий присваемый серийный номер издели€/элемента
	protected:
		List Content; //список указателей на элементы, вход€щие в изделие
	public:
		int Id;
		Item(const std::string name);
		virtual ~Item();
		
		virtual void printAbout() const = 0; //вывод полной информации об изделии
		virtual void printContent() const = 0; //вывод составл€ющих частей издели€
		virtual void AddContent(Item* item) = 0;
		virtual void DelContent(int Number) = 0;
		
		virtual const char* getType() const = 0; //возвращает тип издели€
		virtual int Weight() const = 0; //масса издели€
		virtual float Price() const = 0;//стоимость издели€	
		virtual int Time() const = 0; //расчетное врем€ износа издели€		
};
