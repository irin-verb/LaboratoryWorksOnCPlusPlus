#include "Item.h"

ostream& operator<<(ostream& os, const ItemType& t) {
	switch (t) {
		case ItemType::DETAIL: { return os << "������"; break; }
		case ItemType::SENSOR: { return os << "������"; break; }
		case ItemType::MECHANISM: { return os << "��������"; break; }
		case ItemType::GROUP: { return os << "����"; break; }
		case ItemType::DEVICE: { return os << "����������"; break; }
	}
};

//������������� static-���������� NextId
int Item::NextId = 0;

Item::Item(const char* name) {
	strcpy(Name, name);
	Id = NextId;
	NextId++;
}

Item::~Item() {	
	Clear();
}

void Item::Clear() {
//	vector<Item*>::iterator it;
    auto it = Content.begin();
    while (it != Content.end()) {
    	(*it)->Clear();
        ++it;
    }
	Content.clear(); 
}

void Item::AddContent(Item* item) {
	Content.push_back(item);
}	
	
void Item::DelContent(int const &N) {
	auto it = Content.begin();
    while (it != Content.end()) {
    	if ((*it)->Id == N) {
    		(*it)->Clear(); //������� ����������
    		Content.erase(it); //������� ��� ����
    		break;
		}
		else (*it)->DelContent(N);
        ++it;
    }
}
	
void Item::DelTopContent(int const &N) {
	auto it = Content.begin();
    while (it != Content.end()) {
    	if ((*it)->Id == N) {
    		(*it)->Clear(); //������� ����������
    		Content.erase(it); //������� ���� �������
    		break;
		}
        ++it;
    }
}

Item* Item::SearchContent(int const &N) const {
	Item* R = nullptr;
	vector<Item*>::const_iterator it;
    it = Content.begin();
    if (!(Content.empty())) {
    		while (it != Content.end()) {
    		if ((*it)->Id == N) {
    			R = *it;
			}
    		else {
    			R = (*it)->SearchContent(N);
			}
    		if (R!=nullptr) return R;
    	    ++it;
	}
	return R;
    }	
}

void Item::printAbout() const {
	if (!Content.empty()) {
		cout << " _____________________" << endl;
		cout << "/                     \\" << endl;
		printContent();
		cout << "\n\\_____________________/" << endl;
	}
	cout << "\n������� � " << Id << ": " << Type << endl;
	cout << "| ��������: " << Name << endl;
	cout << "| ���������: " << Price() << " ���" << endl;
	if (Weight() > 0) 
		cout << "| ���: " << Weight() << " �" << endl;
}

void Item::printContent() const {
	vector<Item*>::const_iterator it;
    it = Content.begin();
    while (it != Content.end()) {
    	(*it)->printAbout();
        ++it;
    }		
}

void Item::printSimpleAbout() const {
	cout << Type << " -  \"" << Name << "\"  -   � " << Id << endl;
}

void Item::printSimpleContent() const {
	vector<Item*>::const_iterator it;
    it = Content.begin();
    while (it != Content.end()) {
    	(*it)->printSimpleAbout();
        ++it;
    }		
}

void Item::printSomeContent(int const &N) const {
	vector<Item*>::const_iterator it;
    it = Content.begin();
    while (it != Content.end()) {
    	if ((*it)->Id == N) (*it)->printAbout();
    	else (*it)->printSomeContent(N);
        ++it;
    }
}

bool Item::InTopContent(int const &N) const {
	bool F = false;
	vector<Item*>::const_iterator it;
    it = Content.begin();
    while (it != Content.end()) {
    	if ((*it)->Id == N) F = true;
        ++it;
    }
    return F;
}

bool Item::InContent(int const &N) const {
	bool F = false;
	vector<Item*>::const_iterator it;
    it = Content.begin();
    while (it != Content.end()) {
    	if ((*it)->Id == N) F = true;
    	else F = (*it)->InContent(N);
    	if (F) return F;
        ++it;
    }
    return F;
}

