#include <iostream>
/*Демеонстрирует работу оператора присвоения по умолчанию
или встроенного оператора присвоения
модет привести к не корректной работе объектов использующих
ресурсы
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
        cout<<"\n Konstryktor porabotal\n";
    }
    ~DinMas()
    {
        delete[] Mas;
        Mas=nullptr;
        cout<<"\n Destruktor porabotal\n";
    }
    void Show()
    {
        for(int i=0;i<RazMas;i++)
        {
            cout<<" "<<Mas[i];
        }
        cout<<"\n Adres nachala massiva:"<<Mas<<endl;
    }
};
int main()
{
    DinMas Massiv1(1);
    cout<<"\n Massive1:\n";
    Massiv1.Show();
    DinMas Massiv2(2);
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
