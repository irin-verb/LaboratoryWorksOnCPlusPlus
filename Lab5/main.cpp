#include "Menu.h"

int main() {
	system("chcp 1251");
	MainMenu();

//работа со строками напрямую
/*	List<char*,30> L;
	
	char* s1 = new char[128]; strcpy(s1, "Стр1");
	char* s2 = new char[128]; strcpy(s2, "Стр2");
	char* s3 = new char[128]; strcpy(s3, "Стр3");
	
	L.insert(s1,0); L.insert(s2,0);	L.insert(s3,2);
	L.insert("mda",3); L.insert("mda",4);	
	L.print();
	
	L.remove(s2,0); L+"teststr"; L-"mda"; --L;
	
	delete[] s1; delete[] s2; delete[] s3; // Удаляем строки!
	L.print();
*/	

//работа с int
/*	List<int,6> MyList;

	MyList.insert(2,0);	MyList.insert(3,1); MyList.insert(4,2);
	MyList.insert(66,2); MyList.insert(2,5);
	MyList.print();
	
	MyList.insert(5,3); MyList.remove(5,3);	MyList+6;
	--MyList; MyList-2;
	MyList.print();
*/	

//работа с Vec2
/*	List<Vec2,4> L;

	L.insert({2,3},0); L.insert({2,1},1); L.insert({2,2},2);
	L.print();
	
	Vec2 V = {1,1};
	L+V; L+V; L-V; --L;
	L.print();
*/
	return 0;
}


















