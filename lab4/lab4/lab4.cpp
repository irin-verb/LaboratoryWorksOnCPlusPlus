//#include <iostream>
#include "ITEM_LIST.h"
using namespace std;

 class Detail : public Item {
 private:
	 int Mass; 
	 float Cost; 
 public:
	 Detail(const string name, const int weight, const float money) : Item(name) {
		 Mass = weight;
		 Cost = money;
	 }
	 ~Detail() {}

	 virtual void printAbout() const override { Item::printAbout(); }
	 virtual void printContent() const override {}
	 virtual void AddContent(Item* item) override {}
	 virtual void DelContent(int Number) override {}

	 virtual const char* getType() const override { return "ДЕТАЛЬ"; }
	 virtual int Weight() const override { return Mass; }
	 virtual float Price() const override { return Cost; }
	 virtual int Time() const override { return 0; }
 };

 class Sensor : public Item { //ÄÀÒ×ÈÊ
 private:
	 float Cost;
	 string Measure;
 public:
	 Sensor(const string name, const char* measure, const float money) : Item(name) {
		 Measure = measure;
		 Cost = money;
	 }
	 ~Sensor() {}

	 virtual void printAbout() const override {
		 Item::printAbout();
		 cout << "| Характеристика: " << Measure << endl;
	 }
	 virtual void printContent() const override {}
	 virtual void AddContent(Item* item) override {}
	 virtual void DelContent(int Number) override {}

	 virtual const char* getType() const override { return "ДАТЧИК"; }
	 virtual int Weight() const override { return 0; }
	 virtual float Price() const override { return Cost; }
	 virtual int Time() const override { return 0; }
 };


 class ComplexItem : public Item {
 private:
 protected:
 public:
	 ComplexItem(const string name) : Item(name) {}
	 virtual ~ComplexItem() {}

	 virtual void printAbout() const final {
		 Item::printAbout();
		 cout << "| Время износа: " << Time() << " дней" << endl;
	 }
	 virtual void printContent() const final { Item::printContent(); }
	 virtual void AddContent(Item* item) final { Item::AddContent(item); }
	 virtual void DelContent(int Number) final { Item::DelContent(Number); }
	 virtual int Weight() const final { return Content.NodesWeight(); }
 };


 class Mechanism : public ComplexItem { 
 private:
	 int Timer; 
 public:
	 Mechanism(const string name, const int time) : ComplexItem(name) {
		 Timer = time;
	 }
	 ~Mechanism() {}
	 virtual const char* getType() const override { return "МЕХАНИЗМ"; }
	 virtual float Price() const override { return Content.NodesCost(); }
	 virtual int Time() const override { return Timer; }
 };

 class Group : public ComplexItem { 
 public:
	 Group(const string name) : ComplexItem(name) {}
	 ~Group() {}
	 virtual const char* getType() const override { return "УЗЕЛ"; }
	 virtual float Price() const override {
		 float S = Content.NodesCost();
		 if (Weight() <= 20) {}
		 else if (Weight() <= 50) S = S * 1.1f;
		 else S = S * 1.2f;
		 return S;
	 }
	 virtual int Time() const override { return Content.NodesTime(); }
 };


 int main() {
	 system("chcp 1251");

	 Detail* D1 = new Detail("деталька", 56, 100);
	 Sensor* D2 = new Sensor("датчик", "температура", 66);
	 Mechanism* M1 = new Mechanism("механизм", 16);
	 Group* G = new Group("УЗЕЕЕЕЕЛ");
	 M1->AddContent(D1);
	 M1->AddContent(D2);
	 G->AddContent(M1);
	 G->printAbout();

	// M1->DelContent(1);
	 delete D1;
	 D1 = nullptr;
	// G->printAbout();

	 //	delete D1;
	 //	D1 = nullptr;
	 delete D2;
	 D2 = nullptr;
	 delete M1;
	 M1 = nullptr;
	 delete G;
	 G = nullptr;
	 cout << "ee" << endl;

	 /*
		 Mechanism M1("Ìeõàíèçì1",16 );
		 Detail D1("Äåòàëü1",56,100);
		 Detail D2("Äåòàëü1",70,110);
		 Detector D3

		 M1.AddContent(& D1);
		 M1.AddContent(& D2);
		 M1.AddContent(& D3);

		 //M1.printAbout();

		 Mechanism M2("Ìeõàíèçì2",8 );
		 Detail K1("Äåòàëü1",3,12);
		 Detail K2("Äåòàëü1",1,12);
		 Detector K3("Äàò÷èê1","Äàâëåíèå",30);

		 M2.AddContent(& K1);
		 M2.AddContent(& K2);
		 M2.AddContent(& K3);

		 //M2.printAbout();

		 Group P("Òåñòîâàÿ ãðóïïà");
		 P.AddContent(& M1);
		 P.AddContent(& M2);
		 P.printAbout();
		 cout << "ÑÒÎÈÌÎÑÒÜ ÈÙÄÅËÈß" << P.Price() << endl;*/

	 return 0;
 }