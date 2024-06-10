#include "m3.h"

using namespace std;

int Object::All = 0;
int Object::Act = 0;

void Object::RestartObjInfo() {
	All = 0;
	Act = 0;
}

Object::Object() {
	All++;
	Act++;
	Ops = 0;
	Op = nullptr;
}

Object::Object(const Object& Obj) {
	int i;
	///*this->*/ClearOp();
	Ops = Obj.Ops;
	if (Ops != 0) {
		Op = new int[Ops];
		for (i = 0; i < Ops; i++)
			Op[i] = Obj.Op[i];
	}
	else Op = nullptr;
}

Object::~Object() {
	Act--;
	ClearOp();
}

void Object::PrintTotalInfo() {
	cout << "Кол-во активных объектов:" << Act << endl;
	cout << "Всего было создано объектов:" << All << endl;
}

void Object::AddOp(int k) {
	int i;
	int* Dop;
	Ops++;
	if ((!Op) || (Ops==0)) {
		Op = new int[Ops];
	}
	else {
		Dop = new int[Ops - 1];
		for (i = 0; i < Ops - 1; i++)
			Dop[i] = Op[i];
		Op = new int[Ops];
		for (i = 0; i < Ops - 1; i++)
			Op[i] = Dop[i];
		delete[] Dop;
		Dop = nullptr;
	}
	Op[Ops - 1] = k;
}

void Object::PrintOp() {
	int i;
	if (!Op) cout << "С объектом не выполнялось операций" << endl;
	else {
		cout << "История операций с объектом:" << endl;
		for (i = 0; i < Ops; i++)
			switch (Op[i]) {
			case 1: {cout << i + 1 << ") Сложение" << endl; break; }
			case 2: {cout << i + 1 << ") Умножение" << endl; break; }
			case 3: {cout << i + 1 << ") Умножение на скаляр" << endl; break; }
			case 4: {cout << i + 1 << ") Транспонирование" << endl; break; }
			case 5: {cout << i + 1 << ") Нахождение определителя" << endl; break; }
			case 6: {cout << i + 1 << ") Преобразование в обратную" << endl; break; }
			}
	}
}

void Object::ClearOp() {
	if (Op) {
		Ops = 0;
		delete[] Op;
		Op = nullptr;
	}
}

Object& Object::operator= (Object& Obj)
{
	if (&Obj == this) {
		cout << "Внимание: выполнено самоприсваивание" << endl;
		return *this;
	}
	int i;
	/*this->*/ClearOp();
	if (Obj.Ops) {
		Ops = Obj.Ops;
		Op = new int[Ops];
		for (i = 0; i <Ops; i++)
			Op[i] = Obj.Op[i];
	}
	return *this;
}

bool Object::Comp(int (&Spis)[N]) {
	if ((!Op) || (Ops>N)) return 0;
	int i;
	for (i = 0; i < Ops; i++)
		if (Op[i]!=Spis[i]) return 0;
	return 1;
}
