#include <iostream>
using namespace std;
class DinMas
{
    int* Mas;
    int RazMas;
public:

    DinMas(const DinMas& ob) {

        if ((ob.Mas != nullptr) && (ob.RazMas != 0)) {
            Mas = new int[ob.RazMas];
            RazMas = ob.RazMas;
            for (int i = 0; i < ob.RazMas; i++) {
                Mas[i] = ob.Mas[i];
            }
        }
        cout << "\n Konstryktor kopirovaniya\n";
    }
    DinMas& operator=(const DinMas& ob) {
        if (this == &ob)
            return *this;
        delete[]Mas;
        Mas = nullptr;
        RazMas = 0;
        if ((ob.Mas != nullptr) && (ob.RazMas != 0)) {
            Mas = new int[ob.RazMas];
            RazMas = ob.RazMas;
            for (int i = 0; i < ob.RazMas; i++) {
                Mas[i] = ob.Mas[i];
            }
        }
        cout << "\n Pereopredelennoe prisvoenie\n";
        return *this;
    }

    DinMas() {
        RazMas = 0;
        Mas = nullptr;
        cout << "\n Konstryktor porabotal\n";
    }

    ~DinMas() {
        delete[]Mas;
        cout << "\n Destryktor porabotal\n";
    }

    void Create() {
        cout << " Vvedite razmer (natyralnoe chislo) : ";
        int t;
        cin >> t;
        if (t <= 0) {
            return;
        }
        RazMas = t;
        Mas = new int[RazMas];
        cout << " Vvodite celie chisla : \n";
        for (int i = 0; i < RazMas; i++) {
            cin >> Mas[i];
        }
    }

    void Show() {
        cout << " Vivod massiva : ";
        for (int i = 0; i < RazMas; i++) {
            cout << " " << Mas[i];
        }
        cout << "\n Adress nachala massiva: " << Mas << endl;
    }
    DinMas operator -() const
    {
        cout << " Ynarnii minus nachinaet raboty\n";
        DinMas ob(*this);
        for (int i = 0; i < ob.RazMas; i++)
        {
            ob.Mas[i] = -Mas[i];
        }
        cout << " Ynarnii minus zakancivaniet raboty\n";
        return ob;

    }
    friend bool operator==(const DinMas& ob1, const DinMas& ob2);
    friend bool operator!=(const DinMas& ob1, const DinMas& ob2);
};
bool operator==(const DinMas& ob1, const DinMas& ob2)
{
    if ((ob1.Mas==nullptr)&&(ob2.Mas==nullptr))
    {
        return true;
    }
    if( ob1.RazMas != ob2.RazMas)
    {
        return false;
    }
    bool flag = true;
    for(int i=0;i<ob1.RazMas;i++)
    {
        if(ob1.Mas[i]!=ob2.Mas[i])
        {
            flag = false;
        }
    }
    return flag;
}
bool operator!=(const DinMas& ob1, const DinMas& ob2)
{
    return !(ob1==ob2);
}
int main()
{
    DinMas Massiv1;
    cout << "\n Massive1:\n";
    Massiv1.Create();
    Massiv1.Show();

    DinMas Massiv2;
    cout << "\n Massive2:\n";
    Massiv2.Create();
    Massiv2.Show();

    if(Massiv1==Massiv2)
    {
        cout << " Massiv1 raven Massiv2\n";
    }else
    {
        cout << " Massiv1 neraven Massiv2\n";
    }
    if (Massiv1 != Massiv2)
    {
        cout << " Massiv1 neraven Massiv2\n";
    }
    else
    {
        cout << " Massiv1 raven Massiv2\n";
    }
    return 0;
}