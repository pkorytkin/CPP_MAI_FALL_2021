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
           cout<<" adress do pereopreneleniya "<<Mas<<endl;
        delete[]Mas;
        Mas=nullptr;
        RazMas=0;
        if((ob.Mas!=nullptr)&&(ob.RazMas!=0)){
           Mas=ob.Mas;
           cout<<" adress posle pereopreneleniya "<<Mas<<endl;
           RazMas=ob.RazMas;
           ob.Mas=nullptr;
           ob.RazMas=0;
        }
        cout<<"\n Pereopredelennoe prisvoeniye peremesheniem\n";
        return *this;
    }
    DinMas(int k, int m):Mas(nullptr),RazMas(0){

        if(k<1){
            cout<<"\n Konstryktor s parametrami porabotal0\n";
            return;
        }
        RazMas=k;
        Mas=new int[RazMas];
        for(int i=0;i<RazMas;i++)
            Mas[i]=m;
        cout<<"\n Adress nachala massiva created: "<<Mas<<endl;
        cout<<"\n Konstryktor s parametrami porabotal\n";
    }

    ~DinMas(){
        cout<<"\n Adress nachala massiva deleted: "<<Mas<<endl;
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
    //swap move static_cast
    cout<<" ob1(1,10) :\n";
    DinMas ob1(1,10);

    ob1.Show();
    cout<<" ob2(2,20) :\n";
    DinMas ob2(2,20);

    ob2.Show();
    cout<<"\n ob3(ob1) :\n";
    DinMas&ob3(ob1);

    ob3.Show();
    //создание анонимного объекта и установка рвалуе ссылки на него
    cout<<"\n ob4(DinMas(4,40)) :\n";
    DinMas  &&   ob4(DinMas(4,40));

    ob4.Show();
    //DinMas&&ob5(4,40);

    //DinMas&&ob6(ob2);
    cout<<"\n ob7(DinMas(7,70) :\n";
    const DinMas  &   ob7(DinMas(7,70));
    ob7.Show();
    // DinMas  &   ob8(DinMas(8,80));

    cout<<"\n ob4=((DinMas(9,90))) :\n";
    ob4=((DinMas(9,90)));
    ob4.Show();

    cout<<"\n ob11(DinMas(11,110)) :\n";
    DinMas  &&   ob11(DinMas(11,110));
    ob11.Show();

    cout<<"\n ob11(DinMas(12,120)) :\n";
    DinMas  &&   ob12(DinMas(12,120));
    ob12.Show();


    DinMas&&tmp{DinMas(ob11)};

    /*tmp=DinMas(ob11);
    ob11=DinMas(ob12);
    ob12=DinMas(tmp);
*/
    //swap(ob11,ob12);

    //ob11.Show();
    //ob12.Show();

    return 0;
}
