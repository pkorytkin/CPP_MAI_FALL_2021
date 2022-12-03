#include <iostream>
using namespace std;
class DinMas
{
    int*Mas;
    int RazMas;
public:
    DinMas(){
        RazMas=0;
        Mas=nullptr;
        cout<<"\n Konstryktor porabotal\n";
    }
    //инициализация значений по умолчанию
    DinMas(int k,int m):Mas{nullptr},RazMas{0}
    {
        if(k<1)
            return;
        RazMas=k;
        Mas=new int[RazMas];
        for(int i=0;i<RazMas;i++)
            Mas[i]=m+i;
        cout<<"\n Konstryktor s parametrami porabotal\n";
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



    ~DinMas(){
        delete[]Mas;
        cout<<"\n Destryktor porabotal\n";
    }
    int& operator[](const int i)
    {
        return Mas[i];
    }
    const int& operator[](const int i)const
    {
        return Mas[i];
    }
    void Show() const {
        cout<<" Vivod massiva : ";
        for(int i=0; i<RazMas; i++){
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

    const DinMas Massiv2(5,6);
    cout<<"\n Massive2:\n";
    Massiv2.Show();

    cout<<"\n Massiv1[3]-100\n";


    return 0;
}
