#include <iostream>

using namespace std;
const int K=10;
class DinMas;
void f1(DinMas ob);
void f2(DinMas &ob);

class DinMas
{
    int* Mas;
    int RazMas;
public:
    DinMas(const DinMas &ob)
    {
        RazMas= K;
        Mas=new int[RazMas];
        for(int i=0;i<RazMas;i++)
            Mas[i]=ob.Mas[i];
        cout<<"\n Konstryktor ";
        cout<<"Kopirovaniya porabotal\n";
    }
    DinMas()
    {
        RazMas=K;
        Mas=new int[RazMas];
        for(int i=0;i<RazMas;i++)
            Mas[i]=1;
        cout<<"\n Konstryktor porabotal\n";
    }
    ~DinMas(){
        delete[] Mas;
        Mas=nullptr;
        cout<<"\n Destryktor porabotal\n";
    }
    void Show()
    {
        for(int i=0;i<RazMas;i++)
        {
            cout<<" "<<Mas[i];
        }
        cout<<"\n Adress nachala massiva: "<<Mas<<endl;
    }
};
int main()
{
    DinMas Massiv1;
    cout<<"\n Massive1:\n";
    Massiv1.Show();
    DinMas Massiv2=Massiv1;
    cout<<" \n Massive2:\n";
    Massiv2.Show();
    DinMas Massiv3(Massiv1);
    cout<<"\n Massive3:\n";
    Massiv3.Show();
    f1(Massiv1);
    f2(Massiv2);
    return 0;
}
void f1(DinMas ob)
{
    cout<<" Fynkciya f1:\n";
    cout<<" Massiv: ";
    ob.Show();
}
void f2(DinMas &ob)
{
    cout<<" Fynkciya f2:\n";
    cout<<" Massiv: ";
    ob.Show();
}
