#include <iostream>

using namespace std;
//�������� ���������� ��� ������������� ������������
class A{
public:
    A(int x){}
};
class B:public A{
public:
    B(int y,int x):A(x){}//x ��� A, y ��� B
};
class C:public B
{
    //������
public:
    C(int z,int x,int y):B(y,x){}//z ��� C,x y ��� B
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
