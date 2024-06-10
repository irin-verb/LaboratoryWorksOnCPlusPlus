#include "t1.h"
using namespace std;

//íóëåâàÿ ìàòğèöà äëÿ çàïîëíåíèÿ
float MNull[N][N] = { 0,0,0,0,0,0,0,0,0 };

//ğåçóëüòàòû è èñõîäíûå äàííûå òåñòîâ:

float Test1M1[N][N] = { 3,9,10,-11,23,0,4,7,9 };
float Test1M2[N][N] = { -9,3,11,5,7,8,4,0,55 };
//ñóììà 1 è 2
float Test1R[N][N] = { -6,12,21,-6,30,8,8,7,64 };

float Test2M1[N][N] = { 3,9,10,-11,23,0,4,7,9 };
float Test2M2[N][N] = { -9,3,11,5,7,8,4,0,55 };
//ïğîèçâåäåíèå 1 è 2
float Test2R[N][N] = { 58,72,655,214,128,63,35,61,595 };

float Test3M[N][N] = { -9,3,11,5,7,8,4,0,55 };
const int Test3Sclr = 2;
//óìíîæåíèå íà Sclr
float Test3R[N][N] = { -18,6,22,10,14,16,8,0,110 };

float Test4M[N][N] = { 3,9,10,-11,23,0,4,7,9 };
//òğàíñïîíèğîâàíèå
float Test4R[N][N] = { 3,-11,4,9,23,7,10,0,9 };

float Test5M[N][N] = { 3,-11,4,9,23,7,10,0,9 };
//îïğåäåëèòåëü
float Test5R = -178;

float Test6M[N][N] = { 58,72,655,214,128,63,35,61,595 };
//ïğåîáğàçîâàíèå â îáğàòíóş
float Test6R[N][N] = { 0.0902,-0.0036,-0.0989,-0.1561,0.0145,0.1704,0.0107,-0.0013,-0.0099 };

//åäèíè÷íàÿ ìàòğèöà
float Test7R[N][N] = { 1,0,0,0,1,0,0,0,1 };

//ïğîïîğöèîíàëüíàÿ ìàòğèöà
float Test8M[N][N] = { 1,2,3,4,5,6,7,8,9 };

//ñóììà T1M1 è T1M2 + òğàíñïîíèğîâàíèå ğåçóëüòàòà +óìíîæåíèå íà Sclr
float Test9R[N][N] = { 18,18,-24,-36,-90,-21,-63,-24,-192 };
int Test9Sclr = -3;

void Test::Start() {
	Pass = 0;
	Numb = 0;
}

bool Test::Expect(float& Actual, const float& Expected) {
	cout << "\nÎæèäàåìûé ğåçóëüòàò: " << Expected << endl;
	cout << "Ôàêòè÷åñêèé ğåçóëüòàò: " << Actual << endl;
	return fabs(Actual - Expected) < eps;
}

bool Test::Expect(int& Actual, const int& Expected) {
	cout << "\nÎæèäàåìûé ğåçóëüòàò: " << Expected << endl;
	cout << "Ôàêòè÷åñêèé ğåçóëüòàò: " << Actual << endl;
	return (Actual==Expected);
}

bool Test::ExpectM(Matrix3x3& Actual, int (&Expected)[N]) {
	int i;
	cout << "\nÎæèäàåìûé ğåçóëüòàò: " << endl;
	for (i = 0; i < N; i++)
		switch (Expected[i]) {
		case 1: {cout << i + 1 << ") Ñëîæåíèå" << endl; break; }
		case 2: {cout << i + 1 << ") Óìíîæåíèå" << endl; break; }
		case 3: {cout << i + 1 << ") Óìíîæåíèå íà ñêàëÿğ" << endl; break; }
		case 4: {cout << i + 1 << ") Òğàíñïîíèğîâàíèå" << endl; break; }
		case 5: {cout << i + 1 << ") Íàõîæäåíèå îïğåäåëèòåëÿ" << endl; break; }
		case 6: {cout << i + 1 << ") Ïğåîáğàçîâàíèå â îáğàòíóş" << endl; break; }
		}
	cout << "Ôàêòè÷åñêèé ğåçóëüòàò: " << endl;
	Actual.PrintOp();
	return Actual.Comp(Expected);
}

bool Test::ExpectM(Matrix3x3& Actual, float(&Expected)[N][N]) {
	cout << "\n\tÎÆÈÄÀÍÈÅ:" << endl;
	int i, j;
	bool I; //ïğîâåğêà íà åäèíè÷íîñòü äâóìåğíîãî ìàññèâà
	I = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%*.3f  ", 7, Expected[i][j]);
			if ((fabs(Expected[i][i] - 1) >= eps || ((fabs(Expected[i][j]) >= eps) && (i != j))))
				I = 0;
		}
		printf("\n");
	}
	if (!I) printf("\t     ÍÅ åäèíè÷íàÿ");
	else printf("\t        Åäèíè÷íàÿ");
	cout << "\n\tĞÅÇÓËÜÒÀÒ:" << endl;
	Actual.Out();
	return Actual.Compare(Expected);
}

void Test::Success(bool n) {
	++Numb;
	if (n) ++Pass, cout << "\nÓñïåõ!" << endl;
	else cout << "\nÍåóäà÷à!" << endl;
}

void Test::Results()
{
	cout << "\n_______________________________________" << endl;
	cout << "\nĞÅÇÓËÜÒÀÒÛ ÒÅÑÒÈĞÎÂÀÍÈß ÊËÀÑÑÀ MATRI3X3" << endl;
	cout << "Òåñòîâ ïğîéäåíî: " << Pass << " èç " << Numb << endl;
}

void Test::Head() {
	cout << "\n________ÒÅÑÒ ¹" << Pass + 1 << "__________\n" << endl;
}

bool Test::TSumm() {
	//arrange
	this->Head();
	cout << "ÑËÎÆÅÍÈÅ ÌÀÒĞÈÖ 1 È 2\n" << endl;
	Matrix3x3 A(Test1M1);
	Matrix3x3 B(Test1M2);
	Matrix3x3 C(MNull);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	printf("\tÌÀÒĞÈÖÀ 2\n");
	B.Out();
	//act
//	C=A.Summ(B);
	C = (A + B);
	//assert
	return ExpectM(C, Test1R);
}

bool Test::TMult() {
	//arrange
	this->Head();
	cout << "ÓÌÍÎÆÅÍÈÅ ÌÀÒĞÈÖ 1 è 2\n" << endl;
	Matrix3x3 A(Test2M1);
	Matrix3x3 B(Test2M2);
	Matrix3x3 C(MNull);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	printf("\tÌÀÒĞÈÖÀ 2\n");
	B.Out();
	//act
	C = A * B;
	//assert
	return ExpectM(C, Test2R);
}

bool Test::TSclr() {
	//arrange
	this->Head();
	cout << "ÓÌÍÎÆÅÍÈÅ ÌÀÒĞÈÖÛ 1 ÍÀ ×ÈÑËÎ " << Test3Sclr << "\n" << endl;
	Matrix3x3 A(Test3M);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	//act
	//A.Scalar(Test3Sclr);	
	A* Test3Sclr;
	//assert
	return ExpectM(A, Test3R);
}

bool Test::TTransp() {
	//arrange
	this->Head();
	cout << "ÒĞÀÍÑÏÎÍÈĞÎÂÀÍÈÅ ÌÀÒĞÈÖÛ 1\n" << endl;
	Matrix3x3 A(Test4M);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	//act
	//A.Transpos();	
	++A;
	//assert
	return ExpectM(A, Test4R);
}

bool Test::TDet() {
	//arrange
	this->Head();
	cout << "ÍÀÕÎÆÄÅÍÈÅ ÎÏĞÅÄÅËÈÒÅËß ÌÀÒĞÈÖÛ 1\n" << endl;
	Matrix3x3 A(Test5M);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	//act
	float D;
	//D=A.Det();
	D = A.Det();
	//assert
	return Expect(D, Test5R);
}

bool Test::TRev() {
	//arrange
	this->Head();
	cout << "ÏĞÅÎÁĞÀÇÎÂÀÍÈÅ ÌÀÒĞÈÖÛ 1 Â ÎÁĞÀÒÍÓŞ\n" << endl;
	Matrix3x3 A(Test6M);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	//act
	//A.Reverse();
	!A;
	//assert
	return ExpectM(A, Test6R);
}

bool Test::TMath() {
	//arrange
	this->Head();
	cout << "ÏĞÅÎÁĞÀÇÎÂÀÍÈÅ ÌÀÒĞÈÖÛ 1 Â ÎÁĞÀÒÍÓŞ, À ÇÀÒÅÌ ÏÅĞÅÌÍÎÆÅÍÈÅ ÌÀÒĞÈÖ 1 È 2" << endl;
	cout << "(ÏĞÎÂÅĞÊÀ ÔÎĞÌÓËÛ ÈÇ ËÈÍÅÉÍÎÉ ÀËÃÅÁĞÛ À*À^(-1)=Å)\n" << endl;
	Matrix3x3 A(Test6M);
	Matrix3x3 B(Test6M);
	Matrix3x3 C(MNull);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	printf("\tÌÀÒĞÈÖÀ 2\n");
	B.Out();
	//act
	//A.Reverse(); 
	!A;
	C = A * B;
	//assert
	return ExpectM(C, Test7R);
}

bool Test::TDetNull() {
	//arrange
	this->Head();
	cout << "ÍÀÕÎÆÄÅÍÈÅ ÎÏĞÅÄÅËÈÒÅËß ÏĞÎÏÎĞÖÈÎÍÀËÜÍÎÉ ÌÀÒĞÈÖÛ 1\n" << endl;
	Matrix3x3 A(Test8M);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	//act
	float D;
	//D=A.Det();
	D = A.Det();
	//assert
	return Expect(D, 0);
}

bool Test::TSummTranspSclr() {
	//arrange
	this->Head();
	cout << "ÑËÎÆÅÍÈÅ ÌÀÒĞÈÖ 1 è 2, À ÇÀÒÅÌ ÒĞÀÍÑÏÎÍÈĞÎÂÀÍÈÅ ĞÅÇÓËÜÒÀÒÀ È ÓÌÍÎÆÅÍÈÅ ÍÀ ×ÈÑËÎ " << Test9Sclr << "\n" << endl;
	Matrix3x3 A(Test1M1);
	Matrix3x3 B(Test1M2);
	Matrix3x3 C(MNull);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	printf("\tÌÀÒĞÈÖÀ 2\n");
	B.Out();
	//act
	C = (A + B);
	//C.Transpos();	
	//C.Scalar(Test9Sclr);
	++C;
	C* Test9Sclr;
	//assert
	return ExpectM(C, Test9R);
}

bool Test::TRevNever() {
	//arrange
	this->Head();
	cout << "ÏĞÅÎÁĞÀÇÎÂÀÍÈÅ ÌÀÒĞÈÖÛ 1 Â ÎÁĞÀÒÍÓŞ" << endl;
	cout << "(ÏÎÏÛÒÊÀ ÏĞÅÎÁĞÀÇÎÂÀÍÈß ÌÀÒĞÈÖÛ Ñ ÍÓËÅÂÛÌ ÎÏĞÅÄÅËÈÒÅËÅÌ Â ÎÁĞÀÒÍÓŞ)\n" << endl;
	Matrix3x3 A(Test8M);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	//act
	//A.Reverse();
	!A;
	//assert
	return ExpectM(A, Test8M);
}

bool Test::CountOfAll() {
	//arrange
	Object::RestartObjInfo();
	this->Head();
	cout << "ÑÎÇÄÀÍÈÅ ÄÂÓÕ ÌÀÒĞÈÖ ÑÒÀÒÈ×ÅÑÊÈÌ ÌÅÒÎÄÎÌ ÃÅÍÅĞÀÖÈÈ" << endl;
	cout << "È ÏÎÄÑ×¨Ò ÄËß ÍÈÕ ÊÎËÈ×ÅÑÒÂÀ ÑÎÇÄÀÍÍÛÕ ÎÁÚÅÊÒÎÂ" << endl;
	//act
	Matrix3x3 A = Matrix3x3::St(-100,100);
	Matrix3x3 B = Matrix3x3::St(-100,100);	
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
	printf("\tÌÀÒĞÈÖÀ 2\n");
	B.Out();
	//assert
	int T=2;
	int R=Object::GetAll();
	return Expect(R,T);
}

void Test::CountOfAct1() {
	Matrix3x3 A = Matrix3x3::St(-100,100);
	printf("\tÌÀÒĞÈÖÀ 1\n");
	A.Out();
}
void Test::CountOfAct2() {
	Matrix3x3 B(Test4M);
	printf("\tÌÀÒĞÈÖÀ 2\n");
	B.Out();
}
bool Test::CountOfAct() {
	//arrange
	Object::RestartObjInfo();
	this->Head();
	cout << "ÑÎÇÄÀÍÈÅ ÄÂÓÕ ÌÀÒĞÈÖ Â ÄÂÓÕ ÎÒÄÅËÜÍÛÕ ÔÓÍÊÖÈßÕ È ÎÄÍÎÉ - ÍÅÏÎÑĞÅÄÑÒÂÅÍÍÎ Â ÔÓÍÊÖÈÈ ÒÅÑÒÀ" << endl;
	cout << "ÏÎÄÑ×¨Ò ÊÎËÈ×ÅÑÒÂÀ ÀÊÒÈÂÍÛÕ ÎÁÚÅÊÒÎÂ ÏÎÑËÅ ÈÕ ÑÎÇÄÀÍÈß" << endl;
	//act
	CountOfAct1();
	CountOfAct2();
	Matrix3x3 C(Test7R);
	printf("\tÌÀÒĞÈÖÀ 3\n");
	C.Out();
	//assert
	int T=1;
	int R=Object::GetAct();
	return Expect(R,T);
}

bool Test::TrueCopy() {
	//arrange
	this->Head();
	cout << "ÏĞÈĞÀÂÍÈÂÀÍÈÅ Ê ÍÎÂÎÉ ÌÀÒĞÈÖÅ - ÓÆÅ ÈÍÈÖÈÀËÈÇÈĞÎÂÀÍÍÎÉ" << endl;
	cout << "ÈÇÌÅÍÅÍÈÅ ÇÍÀ×ÅÍÈÉ Â ÈÇÍÀ×ÀËÜÍÎÉ ÌÀÒĞÈÖÅ È ÏĞÎÂÅĞÊÀ, ÍÅ ÈÇÌÅÍÈËÈÑÜ ËÈ ÇÍÀ×ÅÍÈß" << endl;
	float T[N][N] = { 18,18,-24,-36,-90,-21,-63,-24,-192 };
	Matrix3x3 A(T);
	printf("\tÈÇÍÀ×ÀËÜÍÀß ÌÀÒĞÈÖÀ\n");
	A.Out();
	//act
	Matrix3x3 B = A;
	++A; !A; A*3; 
	printf("\tÈÇÌÅÍ¨ÍÍÀß ÈÇÍÀ×ÀËÜÍÀß\n");
	A.Out();
	//assert
	return ExpectM(B,T);
}

bool Test::TrueOperations1() {
	//arrange
	this->Head();
	cout << "ÒĞÀÍÑÏÎÍÈĞÎÂÀÍÈÅ ÌÀÒĞÈÖÛ, ÎÁĞÀÙÅÍÈÅ, ÓÌÍÎÆÅÍÈÅ ÍÀ ÑÊÀËßĞ" << endl;
	cout << "ÏĞÎÂÅĞÊÀ ÑÏÈÑÊÀ ÈÑÒÎĞÈÈ ÎÏÅĞÀÖÈÉ İÒÎÉ ÌÀÒĞÈÖÛ." << endl;
	float R[N][N] = { 3,9,10,-11,23,0,4,7,9 };
	Matrix3x3 A(R);
	printf("\tÌÀÒĞÈÖÀ\n");
	A.Out();
	//act
	++A;
	!A;
	A*2;
	printf("  ÏĞÅÎÁĞÀÇÎÂÀÍÍÀß ÌÀÒĞÈÖÀ\n");
	A.Out();
	//assert
	int T[N]={4,6,3}; 
	return ExpectM(A,T);
}
bool Test::TrueOperations2() {
	//arrange
	this->Head();
	cout << "ÑÎÇÄÀÍÈÅ ÌÀÒĞÈÖÛ À È Å¨ ÒĞÀÍÑÏÎÍÈĞÎÂÀÍÈÅ. ÈÍÈÖÈÀËÈÇÀÖÈß ÌÀÒĞÈÖÛ Â ×ÅĞÅÇ À" << endl;
	cout << "ÓÌÍÎÆÅÍÈÅ ÌÀÒĞÈÖÛ Â ÍÀ ÍÅÊÎÒÎĞÓŞ ÌÀÒĞÈÖÓ Ñ È ÑËÎÆÅÍÈÅ Ñ ÌÀÒĞÈÖÅÉ D." << endl;
	cout << "ÏĞÎÂÅĞÊÀ ÑÏÈÑÊÀ ÎÏÅĞÀÖÈÉ ÌÀÒĞÈÖÛ Â." << endl;
	//act
	Matrix3x3 A = Matrix3x3::St(-10,10);
	++A;
	Matrix3x3 B = A;
	Matrix3x3 C(Test3R);
	Matrix3x3 D(Test9R);
	B*C;
	B+D;
	//assert
	int T[N]={2,1};
	return ExpectM(B,T);
}

//çàïóñê Unit-òåñòèğîâàíèÿ
void Test::Run() {
	Start();
	
	Success(TSumm());
	Success(TMult());
	Success(TSclr());
	Success(TTransp());
	Success(TDet());
	Success(TRev());
	Success(TMath());
	Success(TDetNull());
	Success(TSummTranspSclr());
	Success(TRevNever());
	
	Success(CountOfAll());
	Success(CountOfAct());
	Success(TrueCopy());
	Success(TrueOperations1());
	Success(TrueOperations2());
	
	
	Results();
}
