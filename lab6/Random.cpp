#include "Random.h"

const char* RandomName[50] = {"m98dAlZW","aMEtpG4E","BtTKM5yd","WQQ2SGnY","1tnlOo77",
							"lrbcHjjy",	"PymAymGq","du4w9Y18","tQwx6qwS","cytuUTiS",
							"g9ftLEba","fRJgxPIL","1JV4zGcW","lLADne4A","bS383SgX",
							"PrlCoVxe","pyf5nyt1","l5noS6fv","5GDFk4CV","9pSDvoTw",
							"0xf9pY55","CFGjEPyT","etYjDorQ","fFVBiit8","83rhnjGm",
							"oDmn7ACy","Lc3qNL7N","TMdDsgLi","dZhpQiOY","OfFiTQhn",
							"IUYjd34h","hH21i1u3","poO232ji","NTsnhhSU","M3IKLEh6",
							"kPzZFtoZ","la5V8N1u","2qzDWY4F","OX8POht6","2OByw2rR",
							"jRVddukz","Gsgg6riZ","6uFPxnZS","FCg9buJn","9Y7a7PFI",
							"M6AfYDj4","wbzFeMcR","xWvWkWKX","75xzfjj1","s9IlPofv"};
const char* RandomMeasure[24] = {"Температура","Давление","Громкость","Длина",
							"Скорость","Напряжение","Мощность","Диаметр",
							"Вязкость","Цвет","Радиоативность","Вибрация",
							"Сила тока","Напряженность","Влажность","Яркость",
							"Уровень","Запах","Индуктивность","Ёмкость",
							"Сопротивление","Вес","Время","Загрязнённость"};						
							
Item* RandomDetail() {
	char N[MAX_STR];
	int m,s;
	strcpy(N,RandomName[rand()%(50)]);
	m = 1+rand()%(1000-1+1);
	s = 100+rand()%(5000-100+1);
	
	Detail* R = new Detail(N,m,s);
	return R;
}

Item* RandomSensor() {
	char N[MAX_STR];
	char M[MAX_STR];
	int s;
	strcpy(N,RandomName[rand()%(50)]);
	strcpy(M,RandomMeasure[rand()%(24)]);
	s = 100+rand()%(5000-100+1);
	
	Sensor* R = new Sensor(N,M,s);
	return R;
}

Item* RandomMechanism() {
	char N[MAX_STR];
	int t;
	strcpy(N,RandomName[rand()%(50)]);
	t = 30+rand()%(2000-30+1);	
	
	int i;
	Mechanism* R = new Mechanism(N,t);
	int n=0+rand()%(3);
	for (i=0;i<n;i++) R->AddContent(RandomDetail());
	n=0+rand()%(3);
	for (i=0;i<n;i++) R->AddContent(RandomSensor());
	return R;
}

Item* RandomGroup() {
	char N[MAX_STR];
	strcpy(N,RandomName[rand()%(50)]);

	Group* R = new Group(N);
	int n=0+rand()%(3);
	for (int i=0;i<n;i++) R->AddContent(RandomMechanism());
	return R;
}

Item* RandomDevice() {
	char N[MAX_STR];
	strcpy(N,RandomName[rand()%(50)]);

	Device* R = new Device(N);
	int n=0+rand()%(3);
	for (int i=0;i<n;i++) R->AddContent(RandomGroup());
	return R;
}
