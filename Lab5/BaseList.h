#pragma once
#include <iostream>
#include <math.h>

using namespace std;

//структура узла односвязного списка
template <typename T>
struct Node
{
  T Val; //содержимое элемента
  Node* Next; //указатель на следующий узел
};
 
//односвязный динамический список (общий шаблон)
template <class T, int MaxSize>
class BaseList 
{
protected:
	int Len; 	   //кол-во элементов списка
	Node<T>* Head; //первый элемент списка
	
	bool Empty() const { return Head==nullptr; }  //пуст ли список?
	virtual bool isCompatible (Node<T>* Elem) = 0;//подходит ли элемент под ограничение MaxSize?
	virtual bool isEqual (T a, T b) { return a==b; }//равны ли элементы?
    
    //удаляет элемент по его адресу    
	virtual void DelAddr(Node<T>* Addr) {	  
		if (Addr!=nullptr) {
			if (Addr==Head) {
				Head=Addr->Next;
				delete Addr;
				Addr = nullptr;
				Len--;
			}
			else {
				Node<T>* Dop;
					Dop=Head;
				while (Dop->Next!=Addr)
					Dop=Dop->Next;
				Dop->Next=Addr->Next;
				delete Addr;
				Addr = nullptr;	
				Len--;
			};
		}
	} 

	//конструтор копирования для большинства типов
	virtual void CreateValue (T& Value, T Elem) { Value = Elem; }
	
public:
	
	BaseList() { Head = nullptr; Len = 0; }
	virtual ~BaseList() { Clear(); }
	
	//кол-во элементов в списке
	int getLength() const { return Len; }
	
	//не выходит ли индекс за пределы списка?
	bool isIndex(int ind) const { return (ind<Len) && (ind>=0); } 
	
	//полная очистка списка
	void Clear() { 
		while (!Empty())
			DelAddr(Head);	
		Len = 0;
    } 
    
	//проверка вхождения элемента в список
	bool isExist(T Elem) { 
		bool F = false;
		Node<T>* Dop;
		Dop=Head;
		while (Dop!=nullptr) {
			//if (Dop->Val==Elem)
			if (isEqual(Dop->Val,Elem))
				F = true;
			Dop = Dop->Next;
		}
		return F;
	} 
	
	//вывод содержимого списка
	virtual void print () {
		cout << "\n| ОДНОСВЯЗНЫЙ СПИСОК:" << endl;
		Node<T>* Dop;
		Dop=Head;
		for(int i = 0; i < Len; ++i) {
			cout << "| "<< i+1 << " | " << Dop->Val << "\n";
			Dop=Dop->Next;
		}	
		cout << "| КОЛ-ВО ЭЛЕМЕНТОВ: " << Len << endl;
		cout << "| МАКС ХАРАК-ТИКА: " << MaxSize << endl;
	} 
	
	//удалить все вхождения элемента из списка
	T& operator- (T Elem) {
		while (isExist(Elem))
			for (int i=0; i<Len; i++)
				remove(Elem,i);		
	}   
	
	//удалить первый элемент из начала списка
	T& operator-- () { if (!Empty()) remove(Head->Val,0); } 
	
	//добавить элемент в начало списка
	T& operator+ (T Elem) { insert(Elem,0); } 
	
	//добавить элемент на позицию n
	void insert(T Elem, int n) { 
		Node<T>* Dop;
		Dop=Head;
		Node<T>* New = new Node<T>; //выделяем память под узел
		CreateValue(New->Val,Elem);
		//New->Val = Elem; 
		Len++;
		if (isCompatible(New)) {
			if (Empty()) { //вставка в пустой список
				New->Next=nullptr;
				Head = New;
			}
			else if (n==Len-1) { //вставка в конец списка
				while ((Dop->Next)!=nullptr) Dop=Dop->Next;
				New->Next=nullptr;
				Dop->Next=New;
			}
			else if (n==0) { //вставка в начало списка
				New->Next = Head;
				Head = New;
			}
			else if ((n<Len-1)&&(n>0)) { //вставка в середину списка
				int i=0;
				while (i<n-1) {  //приходим к предшествующему n элементу
					Dop=Dop->Next;
					i++;
				}
				New->Next = Dop->Next; //Наш новый эл указывает на эл, идущие после n-го
				Dop->Next = New; //Эл перед n-ым начинает указывать на новый эл
			}
			else { //попытка вставки на недопустимый индекс
				delete New;
				New=nullptr;
				Len--;
			}	
		}
		else { //попытка вставки недопустимого по MaxSize значения 
			delete New;
			New=nullptr;
			Len--;
		}
	}	
	
	//удалить элемент с позиции n
	void remove(T Elem, int n) {
		if (isExist(Elem)) {
			int D = 0;
			Node<T>* Dop;
			Dop=Head;
		
			while (Dop!=nullptr) {
				//if ((D==n)&&(Dop->Val==Elem)) {
				if ((D==n)&&(isEqual(Dop->Val,Elem))) {
					DelAddr(Dop);
					break;
				}
				D++;
				Dop = Dop->Next;
			}	
		}	
	}
	
	//доступ к элементу на заданной позиции
	T& operator[](int index) { 
		if ((index<Len) && (index>=0)) {
			Node<T>* Dop;
			Dop=Head;
			for (int i=0;i<index;i++) 
				Dop=Dop->Next;
			return Dop->Val;
		}
	}	
	
};

