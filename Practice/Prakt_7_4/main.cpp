#include <iostream>

using namespace std;

class DinMassiv
{
    double*Mas;
    int RazmerMas;
public:
    DinMassiv(int K,double x, double y);
    ~DinMassiv(){cout<<"Destryktor \n\n";
    delete[]Mas;}
    DinMassiv(const DinMassiv &ob);
    DinMassiv& operator= (const DinMassiv&ob);
    void PeresozdanieMassiva();
    void VivodMas();
};
int main()
{
    DinMassiv ob1(6, 4.5,7.3);
    ob1.VivodMas();
    ob1.PeresozdanieMassiva();
    ob1.VivodMas();
    DinMassiv ob2(0,0,0);
    ob2.VivodMas();
    ob2.PeresozdanieMassiva();
    ob2.VivodMas();
    DinMassiv ob3(ob1);
    ob3.VivodMas();
    DinMassiv ob4=ob2;
    ob4.VivodMas();
    ob4=ob3;
    ob4.VivodMas();
    return 0;
}
DinMassiv::DinMassiv(int K,double x, double y)
{
    cout<<" Konstryktor nachal raboty\n\n";
    if(K<=0)
    {
        cout<<" Razmer massiva nedopystim\n";
        Mas=nullptr;
        RazmerMas=0;
        return;
    }
    RazmerMas=K;
    Mas=new double[RazmerMas];
    for(int i=0;i<RazmerMas;i++)
        Mas[i]=(x-i)*(x+i)+y*y;
}
DinMassiv::DinMassiv(const DinMassiv&ob)
{
    cout<<" Konstryktor kopitovanya nachal raboty\n\n";
    if(ob.Mas==nullptr)
    {
        Mas=nullptr;
        RazmerMas=0;
        return;
    }
    RazmerMas=ob.RazmerMas;
    Mas=new double[RazmerMas];
    for(int i=0;i<RazmerMas;i++)
    {
        Mas[i]=ob.Mas[i];
    }
}
DinMassiv& DinMassiv::operator= (const DinMassiv &ob)
{
    cout<<" Pereopredelennii operator prsvaivanya nachel raboty\n\n";
    if(this==&ob)
    {
        return *this;
    }
    delete [] Mas;
    if(ob.Mas==nullptr)
    {
        Mas=nullptr;
        RazmerMas=0;
        return *this;
    }
    RazmerMas=ob.RazmerMas;
    Mas=new double[RazmerMas];
    for(int i=0;i<RazmerMas;i++)
        Mas[i]=ob.Mas[i];
    return *this;
}
void DinMassiv::PeresozdanieMassiva()
{
    if(Mas!=nullptr)
    {
        cout<<" Massiv uje zadan:\n";
    for(int i=0;i<RazmerMas;i++)
        cout<<" "<<Mas[i];
    cout<<"\n Chtobi perezapisat vydite - 1\n";
    cout<<" Chtoby ne perevapisivat vvedite - 0 \n";
    int f;
    cin>>f;
    if(f==0)
        return;
    }
    cout<<" Vvedity razmer massiva:";
    cin>>RazmerMas;
    delete[] Mas;
    Mas=new double[RazmerMas];
    cout<<" Vvedite veshestvennie chisla:\n";
    for(int i=0;i<RazmerMas;i++)
    {
        cout<<" Mas["<<i<<"]=";
    cin>>Mas[i];
    }
    cout<<" Vvod zavershon\n";
}
void DinMassiv::VivodMas()
{
    if(Mas==nullptr){
        cout<<" Massiv ne bil zadan\n\n";
        return;
    }
    cout<<" Zadan massiv:\n";
    for(int i=0;i<RazmerMas;i++)
    {
        cout<<" "<<Mas[i];
    }
    cout<<endl<<endl;
}
