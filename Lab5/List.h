#include "BaseList.h"
#include <strings.h>

using namespace std;

//--------------------- int, float -------------------------

template <class T, int MaxSize> 
class List: public BaseList<T,MaxSize> 
{
	//подходит ли элемент под ограничение MaxSize?
	bool isCompatible (Node<T>* Elem) override { 
		return fabs(Elem->Val)<=static_cast<float>(MaxSize);
	}
};

//------------------------ Vec2 ----------------------------
struct Vec2 {
	int x; 
 	int y;

	//конструктор копирования
	Vec2& operator= (Vec2 Value) { 
		x = Value.x;
		y = Value.y;
	    return *this;
	}
	
	bool operator== (Vec2 Value) { 
	    return (x == Value.x) && (y == Value.y);
	}
	
	bool operator!= (Vec2 Value) { 
	    return (x != Value.x) || (y != Value.y);
	}	
};

// перегрузка оператора << класса ostream для Vec2
// для вывода в стандартном потоке вывода
ostream& operator<<(ostream& os, const Vec2& vec) { 
   return os << "(" << vec.x << "; " << vec.y << ")";
}


template <int MaxSize> 
class List<Vec2,MaxSize>: public BaseList<Vec2,MaxSize> 
{	
	//подходит ли элемент под ограничение MaxSize?
	bool isCompatible (Node<Vec2>* Elem) override {
		int X = Elem->Val.x;
		int Y = Elem->Val.y;
		int R = MaxSize;
		return X*X+Y*Y<=R*R;
	}
};

//----------------------- char * ---------------------------
template <int MaxSize> 
class List<char*,MaxSize>: public BaseList<char*,MaxSize> 
{
public: 
	~List() { ClearContent(); }	
	
private:
	//для всех элементов списка удаляет память, 
	//выделенную под строки, хранимые в эл-тах
    void ClearContent() {
    	if (!this->Empty()) {
    		Node<char*>* Dop;
			Dop = this->Head;
    		while (Dop!=nullptr) {
    			delete Dop->Val;
    			Dop->Val =  nullptr;
    			Dop = Dop->Next;
			}
		}	
	}
	
	//равны ли элементы?
	bool isCompatible (Node<char*>* Elem) override { return strlen(Elem->Val) < MaxSize; }
	bool isEqual (char* a, char* b) override { return strcmp(a,b)==0; }
	//bool operator== (char* a, char* b) {return strcmp(a,b)==0}
	
	//конструктор копии
    void CreateValue (char*& Value, char* Elem) override {
		Value = new char[strlen(Elem)];
        if(Elem) strcpy(Value, Elem);
	    else strcpy(Value, " ");
	}
    /*char* operator= (const char* value) {
		printf("OPA COPY");
		char* S = new char[strlen(value)];
        if(value) strcpy(S, value);
	    else strcpy(S, " ");
	    return S;
    }*/
    
	void DelAddr(Node<char*>* Addr) override {
		//cout << "Удаляем " << Addr->Val << endl;
		delete Addr->Val;
		Addr->Val = nullptr;
		BaseList<char*,MaxSize>::DelAddr(Addr);
	}	
};

