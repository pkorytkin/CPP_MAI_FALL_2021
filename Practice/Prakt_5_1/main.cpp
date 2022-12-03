#include <iostream>

using namespace std;
//прототип классов
class A;
class B;
class A{
    int xa;
    public:
    A(){cout<<"Konstruktor classa A\n";}
    ~A(){cout<<"Destruktor classa A\n";}
    void vvod_xa(int i){xa=i;}
    int vivod_xa(){return xa;}
};
class B:public A{
    int xb;
    public:
    B(){cout<<"Konstruktor classa B\n";}
    ~B(){cout<<"Destruktor classa B\n";}
    void vvod_xb(int i){xb=i;}
    int vivod_xb(){return xb;}
};
int main()
{
    //инициализация снизу вверх
    B ob;
    ob.vvod_xb(1);
    cout<<" ob.xb="<<ob.vivod_xb()<<endl;
    ob.vvod_xa(2);
    cout<<" ob.xa="<<ob.vivod_xa()<<endl;
    //уничтожение сверху вниз
    return 0;
}
