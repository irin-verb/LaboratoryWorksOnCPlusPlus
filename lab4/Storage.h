#pragma once
#include "Item_AND_List.h"
#include "Random.h"

class Storage: public Item { //СКЛАД
	private:
	protected:
	public:	
		Storage(const char* name): Item(name) {}
		~Storage() {Content.Clear();}

		virtual void printAbout() const final;
		virtual const char* getType() const final {return "СКЛАД";}
		virtual int Weight() const override {} 
		virtual float Price() const override {}
		virtual int Time() const override {}
		virtual bool AddContent(Item* item) override {Item::AddContent(item);return true;}
		
		void printAboutContent(int const Key) const; //вывод конкретного изделия на складе
		void printSimpleContent() const; //вывод изделий на складе в упрощенном виде
		void DelSomeContent(int const Key); //удаление конкретного изделия на складе
		void DelAllContent(); //полное удаление элементов склада
		void Joining (int const What, int const ToWhich); //присоединение элемента What в состав ToWhich
		void Gen (int const N); //добавление на склад N сгенерированных сущностецй
		void GenItem();//добавление на склад сгенерированной сущности
};
