#include <iostream>

using namespace std;
//�������� ��������� � ������������ �����������
//� � ����������� ������-����������
class A{
public:
    A(int x){}
};
class B:public A
{
    //������
public:
    B(int x,int y):A(x){}//x ��� A, y ��� B
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
