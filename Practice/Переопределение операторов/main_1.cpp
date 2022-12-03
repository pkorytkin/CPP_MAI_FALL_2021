#include <iostream>
using namespace std;

class DinMas
{
    int*Mas;
    int RazMas;

public:

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

    DinMas(){
        RazMas=0;
        Mas=nullptr;
        cout<<"\n Konstryktor porabotal\n";
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

    void Show() {
        cout<<" Vivod massiva : ";
        for(int i=0; i<RazMas; i++){
            cout<<" "<<Mas[i];
        }
        cout<<"\n Adress nachala massiva: "<<Mas<<endl;
    }

    friend DinMas operator+(const DinMas &ob1, const DinMas &ob2);
};

int main()
{
    DinMas Massiv1;
    cout<<"\n Massive1:\n";
    Massiv1.Create();
    Massiv1.Show();

    DinMas Massiv2;
    cout<<"\n Massive2:\n";
    Massiv2.Create();
    Massiv2.Show();

    DinMas Massiv3;
    cout<<"\n Massive3:\n";
    Massiv3.Create();
    Massiv3.Show();

    cout<<"\n Massive3=Massive1+Massive2:\n";
    Massiv3=Massiv1+Massiv2;
    Massiv3.Show();

    return 0;
}

DinMas operator+(const DinMas &ob1, const DinMas &ob2){
    cout<<" Operator+ nachal raboty\n";
    DinMas ob3;
    if((ob1.RazMas!=0)||(ob2.RazMas!=0)){
       if(ob1.RazMas>ob2.RazMas){
           ob3.RazMas=ob1.RazMas;
           ob3.Mas=new int[ob3.RazMas];
           for(int i=0; i<ob3.RazMas; i++){
              ob3.Mas[i]=ob1.Mas[i];
           }
           for(int i=0; i<ob2.RazMas; i++){
              ob3.Mas[i]+=ob2.Mas[i];
           }
      }else{
       ob3.RazMas=ob2.RazMas;
       ob3.Mas=new int[ob3.RazMas];
       for(int i=0; i<ob3.RazMas; i++){
              ob3.Mas[i]=ob2.Mas[i];
           }
           for(int i=0; i<ob1.RazMas; i++){
              ob3.Mas[i]+=ob1.Mas[i];
           }
       }
    }
    cout<<" Operator+ zakanchivaet raboty\n";
    return ob3;
}



