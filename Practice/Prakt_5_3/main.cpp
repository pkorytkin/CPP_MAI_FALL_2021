#include <iostream>

using namespace std;
class A;
class B;
class C;
class D;

class A
{
    public:
    A(){cout<<"Konstruktor A\n";}
    ~A(){cout<<"Destruktor A\n";}
};
class B
{
    public:
    B(){cout<<"Konstruktor B\n";}
    ~B(){cout<<"Destruktor B\n";}
};
class C
{
    public:
    C(){cout<<"Konstruktor C\n";}
    ~C(){cout<<"Destruktor C\n";}
};
class D:B,C,A
{
    public:
    D(){cout<<"Konstruktor D\n";}
    ~D(){cout<<"Destruktor D\n";}
    void V(){cout<<"t\n";}
};
int main()
{
    cout << "Hello world!" << endl;
    D c=D();
    c.V();
    return 0;
}
