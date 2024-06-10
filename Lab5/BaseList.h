#pragma once
#include <iostream>
#include <math.h>

using namespace std;

//��������� ���� ������������ ������
template <typename T>
struct Node
{
  T Val; //���������� ��������
  Node* Next; //��������� �� ��������� ����
};
 
//����������� ������������ ������ (����� ������)
template <class T, int MaxSize>
class BaseList 
{
protected:
	int Len; 	   //���-�� ��������� ������
	Node<T>* Head; //������ ������� ������
	
	bool Empty() const { return Head==nullptr; }  //���� �� ������?
	virtual bool isCompatible (Node<T>* Elem) = 0;//�������� �� ������� ��� ����������� MaxSize?
	virtual bool isEqual (T a, T b) { return a==b; }//����� �� ��������?
    
    //������� ������� �� ��� ������    
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

	//���������� ����������� ��� ����������� �����
	virtual void CreateValue (T& Value, T Elem) { Value = Elem; }
	
public:
	
	BaseList() { Head = nullptr; Len = 0; }
	virtual ~BaseList() { Clear(); }
	
	//���-�� ��������� � ������
	int getLength() const { return Len; }
	
	//�� ������� �� ������ �� ������� ������?
	bool isIndex(int ind) const { return (ind<Len) && (ind>=0); } 
	
	//������ ������� ������
	void Clear() { 
		while (!Empty())
			DelAddr(Head);	
		Len = 0;
    } 
    
	//�������� ��������� �������� � ������
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
	
	//����� ����������� ������
	virtual void print () {
		cout << "\n| ����������� ������:" << endl;
		Node<T>* Dop;
		Dop=Head;
		for(int i = 0; i < Len; ++i) {
			cout << "| "<< i+1 << " | " << Dop->Val << "\n";
			Dop=Dop->Next;
		}	
		cout << "| ���-�� ���������: " << Len << endl;
		cout << "| ���� �����-����: " << MaxSize << endl;
	} 
	
	//������� ��� ��������� �������� �� ������
	T& operator- (T Elem) {
		while (isExist(Elem))
			for (int i=0; i<Len; i++)
				remove(Elem,i);		
	}   
	
	//������� ������ ������� �� ������ ������
	T& operator-- () { if (!Empty()) remove(Head->Val,0); } 
	
	//�������� ������� � ������ ������
	T& operator+ (T Elem) { insert(Elem,0); } 
	
	//�������� ������� �� ������� n
	void insert(T Elem, int n) { 
		Node<T>* Dop;
		Dop=Head;
		Node<T>* New = new Node<T>; //�������� ������ ��� ����
		CreateValue(New->Val,Elem);
		//New->Val = Elem; 
		Len++;
		if (isCompatible(New)) {
			if (Empty()) { //������� � ������ ������
				New->Next=nullptr;
				Head = New;
			}
			else if (n==Len-1) { //������� � ����� ������
				while ((Dop->Next)!=nullptr) Dop=Dop->Next;
				New->Next=nullptr;
				Dop->Next=New;
			}
			else if (n==0) { //������� � ������ ������
				New->Next = Head;
				Head = New;
			}
			else if ((n<Len-1)&&(n>0)) { //������� � �������� ������
				int i=0;
				while (i<n-1) {  //�������� � ��������������� n ��������
					Dop=Dop->Next;
					i++;
				}
				New->Next = Dop->Next; //��� ����� �� ��������� �� ��, ������ ����� n-��
				Dop->Next = New; //�� ����� n-�� �������� ��������� �� ����� ��
			}
			else { //������� ������� �� ������������ ������
				delete New;
				New=nullptr;
				Len--;
			}	
		}
		else { //������� ������� ������������� �� MaxSize �������� 
			delete New;
			New=nullptr;
			Len--;
		}
	}	
	
	//������� ������� � ������� n
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
	
	//������ � �������� �� �������� �������
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

