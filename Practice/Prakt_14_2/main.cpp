#include <iostream>

using namespace std;

class DinMas
{
    int*Mas;
    int RazMas;
public:
    const int getRazMas()
    {
        return RazMas;
    }
    DinMas(const DinMas &ob){

        if((ob.Mas!=nullptr)&&(ob.RazMas!=0)){
           Mas=new int[ob.RazMas];
           RazMas=ob.RazMas;
           for(int i=0; i<ob.RazMas; i++){
               Mas[i]=ob.Mas[i];
           }
        }
        cout<<"\n Konstryktor kopirovaniya\n";
    }
    DinMas( DinMas &&ob){

        if((ob.Mas!=nullptr)&&(ob.RazMas!=0)){
           Mas=ob.Mas;
           RazMas=ob.RazMas;
           ob.Mas=nullptr;
           ob.RazMas=0;
        }
        cout<<"\n Kopirovanie peremesheniem\n";
    }
    DinMas&operator=(const DinMas &ob){
        if(this==&ob)
           return *this;
        delete[]Mas;
        Mas=nullptr;
        RazMas=0;
        if((ob.Mas!=nullptr)&&(ob.RazMas!=0)){
           Mas=new int[ob.RazMas];
           RazMas=ob.RazMas;
           for(int i=0; i<ob.RazMas; i++){
               Mas[i]=ob.Mas[i];
           }
        }
        cout<<"\n Pereopredelennoe prisvoenie\n";
        return *this;
    }
    DinMas&operator=( DinMas &&ob){
        if(this==&ob)
           return *this;
        delete[]Mas;
        Mas=nullptr;
        RazMas=0;
        if((ob.Mas!=nullptr)&&(ob.RazMas!=0)){
           Mas=ob.Mas;
           RazMas=ob.RazMas;
           ob.Mas=nullptr;
           ob.RazMas=0;
        }
        cout<<"\n Pereopredelennoe prisvoeniye peremesheniem\n";
        return *this;
    }
    DinMas(int k, int m):Mas(nullptr),RazMas(0){
        if(k<1)
            return;
        RazMas=k;
        Mas=new int[RazMas];
        for(int i=0;i<RazMas;i++)
            Mas[i]=m;
        cout<<"\n Konstryktor s parametrami porabotal\n";
    }

    ~DinMas(){
        delete[]Mas;
        cout<<"\n Destryktor porabotal\n";
    }

    void Create(){
        cout<<" Vvedite razmer (natyralnoe chislo) : ";
        int t;
        cin>>t;
        if(t<=0){
            return;
        }
        RazMas=t;
        Mas=new int[RazMas];
        cout<<" Vvodite celie chisla : \n";
        for(int i=0; i<RazMas; i++){
            cin>>Mas[i];
        }
    }

    void Show() const{
        cout<<" Vivod massiva : ";
        for(int i=0; i<RazMas; i++){
            cout<<" "<<Mas[i];
        }
        cout<<"\n Adress nachala massiva: "<<Mas<<endl;
    }

};
void obmen_kopirovaniem(DinMas &a, DinMas &b)
{
    DinMas c{a};
    a=b;
    b=c;
}
void obmen_peremesheniem(DinMas &a, DinMas &b)
{
    DinMas c=move(a);
    a=move(b);
    b=move(c);
}
int main()
{
    const int KOL=10;
    DinMas Massiv[KOL]={DinMas(1,1),DinMas(2,2),DinMas(3,3),DinMas(4,4),
                        DinMas(5,5),DinMas(6,6),DinMas(7,7),DinMas(8,8),
                               DinMas(9,9),DinMas(10,10)};
    cout<<"\n Vivod massivov:\n\n";
    for(int i=0;i<KOL;i++)
    {
        Massiv[i].Show();
        cout<<endl;
    }
    obmen_kopirovaniem(Massiv[0],Massiv[9]);
    cout<<"\n Vivod massivov:\n\n";
    for(int i=0;i<KOL;i++)
    {
        Massiv[i].Show();
        cout<<endl;
    }


    for(int i=0;i<KOL-1;i++)
    {
        for(int v=i+1;v<KOL;v++)
        {
            if(Massiv[i].getRazMas()<Massiv[v].getRazMas())
            {
                obmen_kopirovaniem(Massiv[i],Massiv[v]);
            }
        }
    }
    cout<<"\n Vivod massivov:\n\n";
    for(int i=0;i<KOL;i++)
    {
        Massiv[i].Show();
        cout<<endl;
    }

    obmen_peremesheniem(Massiv[1],Massiv[8]);

    cout<<"\n Vivod massivov:\n\n";
    for(int i=0;i<KOL;i++)
    {
        Massiv[i].Show();
        cout<<endl;
    }
    return 0;
}
