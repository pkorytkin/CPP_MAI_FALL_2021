#include <iostream>

using namespace std;
class A
{
    int x;
    static int y;

public:
    void show_x(){cout<<" x="<<x<<endl;}
    void show_y(){cout<<" y="<<y<<endl;}
    void set_x(int t){x=t;}
    void set_y(int t){y=t;}
};
int A::y;
int main()
{
    A ob1,ob2;
    ob1.set_x(1);
    ob1.set_y(10);
    ob1.show_x();
    ob1.show_y();
    ob2.set_x(2);
    ob2.set_y(20);
    ob2.show_x();
    ob2.show_y();
    return 0;
}
