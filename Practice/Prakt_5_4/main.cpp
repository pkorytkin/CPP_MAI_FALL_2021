#include <iostream>
//������� �������� ��������� ����� �������� ������������ �������� ������.
using namespace std;
class A
{
    public:
    //������
    A(int x){}
};
class C
{
    public:
    //������
    C(int x){}
};
class B:public A,public C
{
    //������
public:
    B(int x):A(x),C(x+1){}
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
