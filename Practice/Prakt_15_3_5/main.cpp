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
    // Тело класса
};
class B:public A//B Производный класс от класса A
{
    public:
    void M();
    //тело класса
};
class C:public B//C Производный класс от класса B
{
    //тело класса
};
class D
{
    public:
    void M();
    //Тело класса
};
class E: public A, public D// E производный класс от класса А и класса D
{
    public:
    void M();
    //Тело класса
};
int main()
{
    return 0;
}
