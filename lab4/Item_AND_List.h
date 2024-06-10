#pragma once
#include <iostream>
#include <strings.h>
#define MAX_STR 256

class Item;

struct Node { //узел односвязного списка
	Item* Val; //содержимое узла
	Node* Next; //указатель на следующий узел
};

class List { //односвязный СПИСОК с указателями на базовый абстрактный класс
	private:	
		Node* Head; //первый элемент списка
	public:
		List();
		~List();
		bool Empty() const;  //пуст ли список?
		void Insert(Item* V);//добавляет новый элемент в конец списка
		void Del(Node* Addr);//удаляет элемент с адресом Addr
		void Clear();//удаляет все содержимое списка вместе с содержимым его элементов
		
		void printList() const;//выводит всех элементов списка
		void printInList(int const N) const;//вывод элемента с номером N
		void printSimpleList() const;//упрощенный вывод "верхушки" списка, то есть просто элементов списка, без вывода списков этих элементов
		
		int NodesWeight() const;//считает суммарный вес элементов списка (и элементов, входящих в списки элементов)
		float NodesCost() const;//считает общую стоимость эл списка
		int NodesTime() const;//считает общее время износа эл списка
		void Delete(int N);  //удаляет элемент с номером N из списка, или из списков, которые принадлежат элементам этого списка
		bool InList(int const N) const;//есть ли элемент в списке? (с учётом списков его элементов и вложенности)
		bool InTopList(int const N) const;//если ли элемент в списке? (только среди элементов, но не среди списков этих элементов)
		
		Item* ComplexSearch(int const N) const; //возвращает адрес узла по его номеру
};

class Item { //ИЗДЕЛИЕ - базовый абстрактный класс
	private:
		char Name[MAX_STR];//название изделия	
		static int NextId; //следующий присваемый серийный номер изделия
	protected:
		int Id; //серийный номер изделия
		List Content; //список указателей на элементы, входящие в изделие
	public:
		Item(const char* name);
		virtual ~Item();
		
		virtual void printAbout() const = 0; //вывод полной информации об изделии
		virtual bool AddContent(Item* item)=0; //добавление к Content нового элемента
		virtual const char* getType() const = 0; //возвращает тип изделия
		virtual int Weight() const = 0; //масса изделия
		virtual float Price() const = 0;//стоимость изделия	
		virtual int Time() const = 0; //расчетное время износа изделия	
		
		void printSimpleAbout() const;	//вывод номера, типа и названия изделия
		friend class List;		
};
