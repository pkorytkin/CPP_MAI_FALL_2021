#include <iostream>

using namespace std;
class A;
class B;
class C;
class D;
class E;
class A
{
    public:
    void M();
    // ���� ������
};
class B:public A//B ����������� ����� �� ������ A
{
    public:
    void M();
    //���� ������
};
class C:public B//C ����������� ����� �� ������ B
{
    //���� ������
};
class D
{
    public:
    void M();
    //���� ������
};
class E: public A, public D// E ����������� ����� �� ������ � � ������ D
{
    public:
    void M();
    //���� ������
};
int main()
{
    return 0;
}
