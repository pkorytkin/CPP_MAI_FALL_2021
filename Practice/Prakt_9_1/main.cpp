#include <iostream>

using namespace std;
void f1();

int main()
{
    for(int i=0;i<10;i++)
    f1();

    return 0;
}
void f1()
{
    int a=0;
    static int b=0;
    cout<<" a="<<a<<" b="<<b<<endl;
    a++;
    b++;
    cout<<" a="<<a<<" b="<<b<<endl<<endl;
}
