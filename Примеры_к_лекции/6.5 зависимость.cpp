#include <iostream> 
#include <strings.h>

using namespace std;

class Vec3
{
    float x, y, z;
 
public:
    Vec3(float x=0.0f, float y=0.0f, float z=0.0f): x(x), y(y), z(z)
    {
    }
 
    friend ostream& operator<< (ostream &out, const Vec3 &vec3);
};
 
// ѕерегружаем оператор<< класса std::ostream, чтобы определить вывод
// в консоль дл€ нашего класса Vec3
// така€ св€зь будет зависимостью класса Vec3 от std::ostream.
ostream& operator<< (ostream &out, const Vec3& vec3)
{
    // ѕоскольку функци€ перегрузки operator<< €вл€етс€ дружественной классу Vec3, 
	// то мы имеем пр€мой доступ к закрытым членам класса Vec3
    out << "Vec3(" << vec3.x << ", " << vec3.y << ", " << vec3.z << ")";
 
    return out;
}
 
int main(int argc, char** argv)
{
	system("chcp 1251");
	
    Vec3 v(4.4f, 6.3f, 3.1f);
 
 	/*
		Vec3 не имеет пр€мого отношени€ к std::cout (std::ostream) но
		имеет от него зависимость, т.к. функци€ перегрузки оператора << 
		использует std::ostream дл€ вывода содержимого класса Vec3 в консоль
 	*/
    cout << v;
 
    return 0;
}


