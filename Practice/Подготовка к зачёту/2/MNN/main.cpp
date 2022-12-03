#include <iostream>

using namespace std;
class A
{
    protected:
    int V;
    public:
    A(int v)
    {
        V=v;
    }
};
class B
{
    protected:
    int C;
    public:
    B(int c)
    {
        C=c;
    }
};
class D:A,B
{
    protected:
    int M;
public:
    D(int v,int c,int m):A(v),B(c)
    {
        M=m;
        cout<<"Initialized class D with: C="<<C<<" V="<<V<<" M="<<M<<endl;
    }
};
int main()
{
    D m(1,2,3);
    return 0;
}
