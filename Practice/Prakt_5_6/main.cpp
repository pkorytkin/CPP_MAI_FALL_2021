#include <iostream>

using namespace std;
//�������� ��������� � ������������ �����������
//� � ����������� ������-����������
class A{
public:
    A(int x){}
};
class B{
public:
    B(int y){}
};
class C:public A,public B
{
    //������
public:
    C(int z,int x,int y):A(x),B(y){}//z ��� C,x ��� A, y ��� B
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
