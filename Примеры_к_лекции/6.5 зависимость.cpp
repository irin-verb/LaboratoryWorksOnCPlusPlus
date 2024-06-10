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
 
// ����������� ��������<< ������ std::ostream, ����� ���������� �����
// � ������� ��� ������ ������ Vec3
// ����� ����� ����� ������������ ������ Vec3 �� std::ostream.
ostream& operator<< (ostream &out, const Vec3& vec3)
{
    // ��������� ������� ���������� operator<< �������� ������������� ������ Vec3, 
	// �� �� ����� ������ ������ � �������� ������ ������ Vec3
    out << "Vec3(" << vec3.x << ", " << vec3.y << ", " << vec3.z << ")";
 
    return out;
}
 
int main(int argc, char** argv)
{
	system("chcp 1251");
	
    Vec3 v(4.4f, 6.3f, 3.1f);
 
 	/*
		Vec3 �� ����� ������� ��������� � std::cout (std::ostream) ��
		����� �� ���� �����������, �.�. ������� ���������� ��������� << 
		���������� std::ostream ��� ������ ����������� ������ Vec3 � �������
 	*/
    cout << v;
 
    return 0;
}


