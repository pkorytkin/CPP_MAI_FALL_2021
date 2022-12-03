#include <iostream>
using namespace std;
class Massiver
{
    int Length1;
    int Length2;
    int* Massive1=nullptr;
    int* Massive2=nullptr;
public:
    ~Massiver()
    {
        delete[] Massive1;
        delete[] Massive2;
        Length1 = 0;
        Length2 = 0;
    }
    Massiver(){}
    Massiver(const Massiver &ob)
    {
        Length1 = ob.Length1;
        Length2 = ob.Length2;
        if(Length1>0)
        {
            Massive1 = new int[Length1];
        }
        if (Length2 > 0)
        {
            Massive2 = new int[Length2];
        }
        for (int i = 0; i < Length1; i++)
        {
            Massive1[i]=ob.Massive1[i];
        }
        for (int i = 0; i < Length2; i++)
        {
            Massive2[i]=ob.Massive2[i];
        }
    }
    Massiver& operator=(Massiver &ob)
    {
        if(this==&ob)
        {
            return *this;
        }
        Length1 = ob.Length1;
        Length2 = ob.Length2;
        delete[] Massive1;
        delete[] Massive2;
        if (Length1 > 0)
        {
            Massive1 = new int[Length1];
        }
        if (Length2 > 0)
        {
            Massive2 = new int[Length2];
        }
        for (int i = 0; i < Length1; i++)
        {
            Massive1[i] = ob.Massive1[i];
        }
        for (int i = 0; i < Length2; i++)
        {
            Massive2[i] = ob.Massive2[i];
        }
        return *this;
    }
    const void Show()
    {
        cout << "Length1 " << Length1 << endl;
        for(int i=0;i<Length1;i++)
        {
            cout << Massive1[i] << " ";
        }
        cout << endl;
        cout << "Length2 " << Length2 << endl;
        for (int i = 0; i < Length2; i++)
        {
            cout << Massive2[i] << " ";
        }
        cout << endl;
    }
    void Enter()
    {
        while (Length1 <= 0) {
            cout << "Enter celoe Length1\n";
            cin >> Length1;
        }
        while (Length2 <= 0) {
            cout << "Enter celoe Length2\n";
            cin >> Length2;
        }
        Massive1 = new int[Length1];
        Massive2 = new int[Length2];
        cout << "Enter " << Length1 << " numbers\n";
        for(int i=0;i<Length1;i++)
        {
            cin >> Massive1[i];
        }
        cout << "Enter " << Length2 << " numbers\n";
        for (int i = 0; i < Length2; i++)
        {
            cin >> Massive2[i];
        }
    }
    void MinMax()
    {
        int Min = 0;
        int Max = 0;
        if(Length1!=0&&Length2!=0)
        {
            Min = Massive1[0];
            Max = Min;
        }
        if(Length1==0)
        {
            cout << "Zero Size Length1\n";
            if(Length2==0)
            {
                cout << "Zero Size Length2\n";
                return;
            }else
            {
                Min = Massive2[0];
                Max = Min;
            }
        }
        if (Length2 == 0)
        {
            cout << "Zero Size Length2\n";
            if (Length1 == 0)
            {
                cout << "Zero Size Length1\n";
                return;
            }
            else
            {
                Min = Massive1[0];
                Max = Min;
            }
        }
        for(int i=0;i<Length1;i++)
        {
            if(Massive1[i]<Min)
            {
                Min = Massive1[i];
            }
            if (Massive1[i] > Max)
            {
                Max = Massive1[i];
            }
        }
        for (int i = 0; i < Length2; i++)
        {
            if (Massive2[i] < Min)
            {
                Min = Massive2[i];
            }
            if (Massive2[i] > Max)
            {
                Max = Massive2[i];
            }
        }
        cout << "Min value " << Min << endl;
        cout << "Max value " << Max << endl;
    }
};
int main()
{
    Massiver m;
    m.Enter();
    m.MinMax();
    Massiver t = m;
    t.MinMax();
}
