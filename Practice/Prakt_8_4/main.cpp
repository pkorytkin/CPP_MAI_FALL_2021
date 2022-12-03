#include <iostream>

using namespace std;
class B;
class A
{
    int x;
public:
    A(int i):x(i){}
    friend B;
};
class B
{
    int y;
public:
    B(int i):y(i)
    {
    }
    void Sravnenie(A&obA)
    {
        if(y>obA.x)cout<<" Dannie ob'ekta classa B bolse\n";
        if(y<obA.x)cout<<" Dannie ob'ekta classa A bolse\n";
        if(y==obA.x)cout<<" Dannie ob'ektov classov A i B ravni\n";
    }
};
int main()
{
    A ob1(3);
    B ob2(4);
    ob2.Sravnenie(ob1);
    return 0;
}
