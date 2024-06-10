#include <iostream> 
#include <strings.h>

using namespace std;



class Parent
{
public:
	// dynamic_cast работает только с полиморфными классами, если убрать virtual - будет ошибка:
	// [Error] cannot dynamic_cast 'p' (of type 'class Parent*') to type 'class Child*' (source type is not polymorphic)
    virtual ~Parent() {}
};
 
 
class Child : public Parent
{
};
 
 
 
template <class TypeTo, class TypeFrom>
void cast(TypeFrom *p)
{
    cout << boolalpha << ( dynamic_cast<TypeTo>(p) != nullptr ) << endl;
}
 
 

int main(int argc, char** argv) 
{
	//system("chcp 1251");
	
	int i = 5;
	//long long l = dynamic_cast<long long>(i); // dynamic_cast работает только с указателями или ссылками
												// [Error] cannot dynamic_cast 'i' (of type 'int') to type 'long long int' (target is not pointer or reference)
	
    Parent*	ptrParent = new Parent();
    Child*	ptrChild = new Child();
    Parent*	ptrParentChild = new Child();
 
    cast<Parent*>(ptrChild);
    cast<Parent*>(ptrParentChild);
    cast<Child*>(ptrParent); // нисходящее приведение типов лишено смысла, т.к. ptrParent не имеет части от Child класса
    cast<Child*>(ptrParentChild);
    
    Parent* p1 = static_cast<Parent*>(ptrChild);
    Parent* p2 = static_cast<Parent*>(ptrParentChild);
 	Child*  c1 = static_cast<Child*>(ptrParent);
 	Child*  c2 = static_cast<Child*>(ptrParentChild);
 	
    delete ptrParentChild;
    delete ptrChild;
    delete ptrParent;
    
    
 	

	return 0;
}

