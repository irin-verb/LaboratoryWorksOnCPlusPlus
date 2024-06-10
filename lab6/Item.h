#pragma once
#include <iostream>
#include <strings.h>
#include <vector>
#include "Error.h"

#define MAX_STR 256
using namespace std;

//названия типов изделий
enum class ItemType { 
	DETAIL, SENSOR, MECHANISM, GROUP, DEVICE, 	STORAGE
};
// перегрузка оператора << класса ostream для ItemType
// для вывода в стандартном потоке вывода
ostream& operator<<(ostream& os, const ItemType& t);


//ИЗДЕЛИЕ - базовый абстрактный класс
class Item { 

	private:
		
		char Name[MAX_STR];	//название изделия
		static int NextId; //следующий присваемый серийный номер изделия

	protected:
		
		int Id; //серийный номер изделия
		vector<Item*> Content; //массив указателей на элементы, входящие в изделие

	public:
		
		ItemType Type; //тип изделия
		Item(const char* name);
		virtual ~Item();
		
		//ПОИСК, УДАЛЕНИЕ, ДОБАВЛЕНИЕ
		virtual void AddContent(Item* item)=0; //добавление к Content нового элемента 
		void DelContent(int const &N); //удаляет из вложенного состава Content изделия изделие по его номеру
		void DelTopContent(int const &N); //удаляет из непосредственного состава изделия (без состава состава) изд по номеру
		Item* SearchContent(int const &N) const; //возвр указатель на элемент, если найдет его во вложенном составе изделия
		void Clear(); //удаляет всё вложенное содержимое изделия
			
		//ФУНКЦИИ ВЫЧИСЛЕНИЯ ЗНАЧЕНИЙ ДЛЯ ИЗДЕЛИЯ
		virtual int Weight() const = 0;	//общая масса изделия
		virtual float Price() const = 0; //стоимость изделия	
		virtual int Time() const = 0; //расчетное время износа изделия
		
		// ПРОЦЕДУРЫ ВЫВОДА ДАННЫХ
		virtual void printAbout() const = 0; //вывод полной информации об изделии
		void printSimpleAbout() const; //вывод номера, типа и названия изделия	
		void printContent() const; //вывод информации об изделиях в составе данного
		void printSimpleContent() const; //вывод частичной информации об изделиях в составе данного
		void printSomeContent(int const &N) const;//вывод инф-ии об изделии с номером N в составе данного
		
		//ФУНКЦИИ ПРОВЕРКИ, ЕСТЬ ЛИ ЭЛЕМЕНТ В СОСТАВЕ ДРУГОГО
		bool InTopContent(int const &N) const; //определяет, входит ли изделие в состав данного непосредственно
		bool InContent(int const &N) const; //опр, входит ли изделие в состав данного через состав его состава
};

