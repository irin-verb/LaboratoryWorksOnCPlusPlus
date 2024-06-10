#include "Storage.h"

using namespace std;

void Storage::printAbout() const {
	if (Content.empty()) throw Error("�� ������ ���� ��� �������!");
	cout << "\n------- ����� ---------\n" << endl;
	printContent();
}

void Storage::printAboutContent(int const &Key) const {
	if (Content.empty()) throw Error("�� ������ ���� ��� �������!");
	if (!(InContent(Key))) throw Error("������ ������� ���!");
	cout << "\n---- ������� � "<< Key <<" ------\n" << endl;
	printSomeContent(Key);
}

void Storage::printSimpleStorage() const {
	if (Content.empty()) throw Error("�� ������ ���� ��� �������!");
	cout << "\n------------------- ����� -------------------\n" << endl;
	printSimpleContent();
}

void Storage::DelSomeContent(int const &Key) {
	if (Content.empty()) throw Error("�� ������ ���� ��� �������!");
	if (!(InContent(Key))) throw Error("������ ������� ���!");
	DelContent(Key);
	cout << "�������� ������ �������!" << endl;
}

void Storage::DelAllContent() {
	if (Content.empty()) throw Error("����� ����!");
	Clear();
	cout << "����� ������� ���������!" << endl; 
}

void Storage::Joining (int const &What, int const &ToWhich) {	// ��� - ����
	if (Content.empty()) throw Error("�� ������ ���� ��� �������!");
	if (!(InContent(What))) throw Error("�� ������ ��� ��������, ������� �� ������ ������������!");
	if (!(InTopContent(What))) throw Error("������������ ����� ������ �������, ������� �� ������,\n�.�. ��, ������� ��� �� ������������ � ������!");
	if (!(InContent(ToWhich))) throw Error("�� ������ ��� ��������, � ������ �������� �� ������ �������� �������!");
	try {
		SearchContent(ToWhich)->AddContent(SearchContent(What));
		DelTopContent(What);
		cout << "\n������������� ������ �������!\n" << endl;
	}
	catch (Error& E) { cout << E.getInfo() << endl; }
	catch(...) { cout << "\n��������� ����������� ������!\n" << endl; }	
}

void Storage::Gen(int const &N) { for (int i=0;i<N;i++) GenItem(); }	
							
void Storage::GenItem() {
	int K = 1+rand()%(5);
	switch (K) {
		case 1: {AddContent(RandomDetail()); break;}
		case 2: {AddContent(RandomSensor()); break;}
		case 3: {AddContent(RandomMechanism()); break;}
		case 4: {AddContent(RandomGroup()); break;}
		case 5: {AddContent(RandomDevice()); break;}
	}
}

