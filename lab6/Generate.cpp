#include "Generate.h"

Item* RandomItem() {
	int R=1+rand()%(5);
	switch (R) {
		case 1: {
			return RandomDetail();
			break;
		}
	/*	case 2: {
			return RandomSensor();
			break;
		}
		case 3: {
			return RandomMechanism();
			break;
		}
		case 4: {
			return RandomGroup();
			break;
		}
		case 5: {
			return RandomDevice();
			break;
		}*/
	}	
}
Item* RandomDetail() {
	int M =1+rand()%(1000-1+1);
	int S =100+rand()%(5000-100+1);
	char N[MAX_STR];
	strcpy(N,RandomName[rand()%(70)]);
///	int n = 0+rand()%(69-0+1);
//	char N[MAX_STR] = RandomName[n];
	Detail* R = new Detail(N,M,S);
	return R;
}

Item* RandomSensor() {
	int S =50+rand()%(1000-50+1);
	char N[MAX_STR];
	strcpy(N,RandomName[rand()%(70)]);
	char M[MAX_STR];
	strcpy(M,RandomMeasure[rand()%(24)]);
	Sensor* R = new Sensor(N,M,S);
	return R;
}

Item* RandomMechanism() {
	int i;
	int T=30+rand()%(2000-30+1);
	char N[MAX_STR];
	strcpy(N,RandomName[rand()%(70)]);
	Mechanism* R = new Mechanism(N,T);
	int n=0+rand()%(3-0+1);
	for (i=0;i<n;i++) R->AddContent(RandomDetail());
	n=0+rand()%(3-0+1);
	for (i=0;i<n;i++) R->AddContent(RandomSensor());
	return R;
}

Item* RandomGroup() {
	char N[MAX_STR];
	strcpy(N,RandomName[rand()%(70)]);
	Group* R = new Group(N);
	int n=0+rand()%(3-0+1);
	for (int i=0;i<n;i++) R->AddContent(RandomMechanism());
	return R;
}

Item* RandomDevice(){
	char N[MAX_STR];
	strcpy(N,RandomName[rand()%(70)]);
	Device* R = new Device(N);
	int n=0+rand()%(3-0+1);
	for (int i=0;i<n;i++) R->AddContent(RandomGroup());
	return R;
}









