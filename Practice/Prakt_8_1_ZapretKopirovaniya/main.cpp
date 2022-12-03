#include <iostream>
/*Блокировка конструктора присвоения и копированияы
*/
using namespace std;

const int K=10;
class DinMas
{
    int* Mas;
    int RazMas;
public:
    DinMas(int x)
    {
        RazMas=K;
        Mas=new int[RazMas];
        for(int i=0;i<RazMas;i++)
        {
            Mas[i]=x;
        }
    }
    ~DinMas()
    {
        delete[] Mas;
    }
    void Show()
    {
        for(int i=0;i<RazMas;i++)
        {
            cout<<" "<<Mas[i];
        }
        //cout<<"\n Adres nachala massiva:"<<Mas<<endl;
    }
    DinMas(const DinMas &ob);//Копирование запрещено
    DinMas& operator=(const DinMas &ob);//Присвоение запрещено
};
int main()
{
    DinMas Massiv1(1);
    DinMas Massiv2(2);
    cout<<"\n Massive1:\n";
    Massiv1.Show();
    cout<<"\n Massive2:\n";
    Massiv2.Show();
    //Massiv2=Massiv1;
    //DinMas Massiv3=Massiv1;
    //Massiv2=Massiv1;
    //Massiv1=Massiv1+Massiv2;
    return 0;
}
