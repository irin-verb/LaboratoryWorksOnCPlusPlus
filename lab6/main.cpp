#include "Menu.h"
#include "Storage.h"

using namespace std;	

int main() {
	system("chcp 1251");
	Storage MyStorage("�����1");
	MainMenu(&MyStorage);
	return 0;
}

