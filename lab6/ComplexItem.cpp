#include "ComplexItem.h"

int ComplexItem::ContentWeight() const {
	int S=0;
	vector<Item*>::const_iterator it;
	it = Content.begin();
	while (it != Content.end()) {
		S += (*it)->Weight();
		++it;
	}
	return S;
}

int ComplexItem::ContentCost() const {
	int S=0;
	vector<Item*>::const_iterator it;
	it = Content.begin();
	while (it != Content.end()) {
		S += (*it)->Price();
   		++it;
	}
	return S;
}

int ComplexItem::ContentTime() const {
	int max=0;
	vector<Item*>::const_iterator it;
	it = Content.begin();
	while (it != Content.end()) {
		if ((*it)->Time() > max) max=(*it)->Time();
 		++it;
  	}
	return max;
}
