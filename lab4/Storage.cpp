#include "Storage.h"

using namespace std;

void Storage::printAbout() const {
	if (!Content.Empty()) {
		cout << "\n------- ����� ---------\n" << endl;
		Content.printList();
	}
	else cout << "\n�� ������ ���� ��� �������!\n" << endl;
}

void Storage::printAboutContent(int const Key) const {
	if (Content.InList(Key)) {
		cout << "\n---- ������� � "<< Key <<" ------\n" << endl;
		Content.printInList(Key);
	}
	else cout << "\n������ ������� ���!\n" << endl;
}

void Storage::printSimpleContent() const {
	if (!Content.Empty()) {
		cout << "\n------------------- ����� -------------------\n" << endl;
		Content.printSimpleList();
	}
	else cout << "\n�� ������ ���� ��� �������!\n" << endl;
}

void Storage::DelSomeContent(int const Key) {
	if (Content.InList(Key)) {
		Content.Delete(Key);
		cout << "\n�������� ������ �������!\n" << endl;
	}
	else cout << "\n������ ������� ���!\n" << endl;
}

void Storage::DelAllContent() {
	if (!Content.Empty()) {
		Content.Clear();
		cout << "\n����� ������� ���������!\n" << endl;
	}
	else cout << "\n����� ����!\n" << endl;
}

void Storage::Joining (int const What, int const ToWhich) {
	if (Content.Empty()) cout << "������! ����� ����" << endl;
	else if (!Content.InList(What)) cout << "������! �� ������ ��� ��������, ������� �� ������ ������������" << endl;
	else if (!Content.InTopList(What)) {
		cout << "������! ������������ ����� ������ �������, ������� �� ������" << endl;
		cout << "�� ���� �������� ����� ����� ��������� �������:" << endl;
		printSimpleContent();
	}
	else if (strcmp(Content.ComplexSearch(What)->getType(),"����������")==0) cout << "������! ������� ���������� ������ �������� � ������ ������ �������" << endl;
	else if (!Content.InList(ToWhich)) cout << "������! �� ������ ��� ��������, � ������ �������� �� ������ �������� �������" << endl;
	else if (!Content.ComplexSearch(ToWhich)->AddContent(Content.ComplexSearch(What))) {
		const char* Type = (Content.ComplexSearch(ToWhich)->getType());
		cout << "������ �������������! \n� ���� ������� " << Type;
		if (strcmp(Type,"������")==0 || strcmp(Type,"������")==0) cout << " ������ ������ ������������";
		else if (strcmp(Type,"��������")==0) cout << " ����� ������������ ������ ��� ������� ������ � ������";
		else if (strcmp(Type,"����")==0) cout << " ����� ������������ ������ ��� ������� ��������";
		else if (strcmp(Type,"����������")==0) cout << " ����� ������������ ������ ��� ������� ����";
		cout << ", � �� ���������� ������������ " << Content.ComplexSearch(What)->getType();
		}
	else {
		Content.Delete(What);
		cout << "������������� ������ �������!" << endl;
	}
}

void Storage::Gen(int const N) {for (int i=0;i<N;i++) GenItem();}	
							
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

