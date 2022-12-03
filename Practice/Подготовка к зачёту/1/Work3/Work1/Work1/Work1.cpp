#include <iostream>
using namespace std;
class Massiv
{
    double* Massive=nullptr;
    int Length=0;
public:
    Massiv()
    {

    }
    Massiv(const Massiv& ob);
    Massiv& operator=(const Massiv& ob);
    Massiv(Massiv&& ob)
    {
        if (ob.Length != 0 && ob.Massive != nullptr) {
            Massive = ob.Massive;
            Length = ob.Length;
            ob.Length = 0;
            ob.Massive = nullptr;
        }
    }
    Massiv& operator=(Massiv&& ob)
    {
        if(this==&ob)
        {
            return *this;
        }
        delete[] Massive;
        Length = 0;
        if (ob.Length != 0 && ob.Massive != nullptr) {
            Massive = ob.Massive;
            Length = ob.Length;
            ob.Length = 0;
            ob.Massive = nullptr;
        }
    }
    void CreateAndEnter()
    {
        
        if(Length!=0)
        {
            delete[] Massive;
        }
        Length = 0;
        while (Length <= 0) {
            cout << "Enter natural length\n";
            cin >> Length;
        }
        
        Massive = new double[Length];
        cout << "Enter " << Length << " veshestvennich chisel\n";
        for(int i=0;i<Length;i++)
        {
            cin >> Massive[i];
        }
    }
    Massiv& operator+=(int v)
    {
        if(Length<=0)
        {
            return *this;
        }
        for(int i=0;i<Length;i++)
        {
            Massive[i] += v;
        }
        return *this;
    }
    Massiv& operator+=(double v)
    {
        if (Length <= 0)
        {
            return *this;
        }
        for (int i = 0; i < Length; i++)
        {
            Massive[i] += v;
        }
        return *this;
    }
    Massiv& operator+=(float v)
    {
        if (Length <= 0)
        {
            return *this;
        }
        for (int i = 0; i < Length; i++)
        {
            Massive[i] += v;
        }
        return *this;
    }
    void Print() const
    {
        cout << "Massive Length=" << Length << endl;
        for(int i=0;i<Length;i++)
        {
            cout << Massive[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Massiv m1;
    m1.CreateAndEnter();
    m1.Print();
    m1 += 4;
    m1.Print();
    m1 += 0.3;
    m1.Print();
    Massiv m2;
    m2.CreateAndEnter();
    cout << endl<<endl;

    Massiv temp=move(m2);
    m2=move(m1);
    m1 = move(temp);
    m1.Print();
    m2.Print();
    temp.Print();
}
