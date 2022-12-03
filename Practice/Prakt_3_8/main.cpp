#include <iostream>

using namespace std;
class A
{
    int x;
public :
    void vvx(int i){x=i;}
    int vozx(){return x;}

    //Конструктор
    A()
    {
        cout<<" Zaravotal konstruktor klassa A\n";
    }
    //Деструктор
    ~A()
    {
        cout<<" Zaravotal destruktor klassa A\n";
    }
};
int main()
{
    A ob;
    ob.vvx(5);
    cout<<" ob.x="<<ob.vozx()<<endl;
    return 0;
}
