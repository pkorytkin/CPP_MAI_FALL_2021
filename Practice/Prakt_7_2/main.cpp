#include <iostream>
/*Демеонстрирует работу оператора присвоения по умолчанию
или встроенного оператора присвоения
модет привести к не корректной работе объектов использующих
ресурсы
*/
using namespace std;

class DinMas
{
    int* Mas;
    int Length;
public:
    void Dispose();
    DinMas& operator= (const DinMas &ob);
    DinMas(int x,int Length);
    ~DinMas();
    void Show();
};
int main()
{
    DinMas Massiv1(1,4);
    cout<<"\n Massive1:\n";
    Massiv1.Show();
    DinMas Massiv2(2,6);
    cout<<"\n Massive2:\n";
    Massiv2.Show();
    Massiv2=Massiv1;
    cout<<"\n Posle Massiv2=Massiv1:\n";
    cout<<"\n Massive1:\n";
    Massiv1.Show();
    cout<<"\n Massive2:\n";
    Massiv2.Show();
    return 0;
}

DinMas& DinMas::operator=(const DinMas &ob)
{
    if(this==&ob){
        return *this;
    }
    Dispose();

    Mas=new int[ob.Length];
    Length=ob.Length;
    for(int i=0;i<Length;i++)
    {
        Mas[i]=ob.Mas[i];
    }
    cout<<"\n Pereopredelenie prisvoenie\n";
    return *this;
}
DinMas::DinMas(int x,int length)
{
    Length=length;
    Mas=new int[Length];
    for(int i=0;i<Length;i++)
    {
        Mas[i]=x;
    }
    cout<<"\n Konstryktor porabotal\n";
}
DinMas::~DinMas()
{
    Dispose();
    cout<<"\n Destryktor porabotal\n";

}
void DinMas::Show()
{
    for(int i=0;i<Length;i++)
        cout<<" "<<Mas[i];
    cout<<"\n Adress nachala massiva: "<<Mas<<endl;
}
void DinMas::Dispose()
{
    delete[] Mas;
    Mas=nullptr;
}
