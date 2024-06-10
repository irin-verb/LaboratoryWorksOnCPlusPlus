#pragma once
#include <iostream>
#include <strings.h>
#include <vector>
#include "Error.h"

#define MAX_STR 256
using namespace std;

//�������� ����� �������
enum class ItemType { 
	DETAIL, SENSOR, MECHANISM, GROUP, DEVICE, 	STORAGE
};
// ���������� ��������� << ������ ostream ��� ItemType
// ��� ������ � ����������� ������ ������
ostream& operator<<(ostream& os, const ItemType& t);


//������� - ������� ����������� �����
class Item { 

	private:
		
		char Name[MAX_STR];	//�������� �������
		static int NextId; //��������� ���������� �������� ����� �������

	protected:
		
		int Id; //�������� ����� �������
		vector<Item*> Content; //������ ���������� �� ��������, �������� � �������

	public:
		
		ItemType Type; //��� �������
		Item(const char* name);
		virtual ~Item();
		
		//�����, ��������, ����������
		virtual void AddContent(Item* item)=0; //���������� � Content ������ �������� 
		void DelContent(int const &N); //������� �� ���������� ������� Content ������� ������� �� ��� ������
		void DelTopContent(int const &N); //������� �� ����������������� ������� ������� (��� ������� �������) ��� �� ������
		Item* SearchContent(int const &N) const; //����� ��������� �� �������, ���� ������ ��� �� ��������� ������� �������
		void Clear(); //������� �� ��������� ���������� �������
			
		//������� ���������� �������� ��� �������
		virtual int Weight() const = 0;	//����� ����� �������
		virtual float Price() const = 0; //��������� �������	
		virtual int Time() const = 0; //��������� ����� ������ �������
		
		// ��������� ������ ������
		virtual void printAbout() const = 0; //����� ������ ���������� �� �������
		void printSimpleAbout() const; //����� ������, ���� � �������� �������	
		void printContent() const; //����� ���������� �� �������� � ������� �������
		void printSimpleContent() const; //����� ��������� ���������� �� �������� � ������� �������
		void printSomeContent(int const &N) const;//����� ���-�� �� ������� � ������� N � ������� �������
		
		//������� ��������, ���� �� ������� � ������� �������
		bool InTopContent(int const &N) const; //����������, ������ �� ������� � ������ ������� ���������������
		bool InContent(int const &N) const; //���, ������ �� ������� � ������ ������� ����� ������ ��� �������
};

