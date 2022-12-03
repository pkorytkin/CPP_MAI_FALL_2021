#include <iostream>
using namespace std;
class Massiver
{
protected:
    int Length1 = 0;
    int Length2 = 0;
    float* Massive1 = nullptr;
    float* Massive2 = nullptr;
public:
    Massiver(int length1,int length2, float Parm1, float Parm2)
    {
        Length1 = length1;
        Length2 = length2;
        if(length1<0)
        {
            cout << "First Length1 is less or zero\n";
        }else
        {
            Massive1 = new float[Length1];
        }
        if (length2 < 0)
        {
            cout << "First Length2 is less or zero\n";
        }
        else
        {
            Massive2 = new float[Length2];
        }
        for(int i=0;i<Length1;i++)
        {
            Massive1[i] = Parm1;
        }
        for (int i = 0; i < Length2; i++)
        {
            Massive2[i] = Parm2;
        }
    }
    const void Print()
    {
        cout << "Length1=" << Length1<<endl;
        for(int i=0;i<Length1;i++)
        {
            cout << Massive1[i] << " ";
        }
        cout << endl;
        cout << "Length2=" << Length2 << endl;
        for (int i = 0; i < Length2; i++)
        {
            cout << Massive2[i] << " ";
        }
        cout << endl;
        
    }
    ~Massiver()
    {
        Length1 = 0;
        Length2 = 0;
        delete[] Massive1;
        delete[] Massive2;
    }
    Massiver(const Massiver& ob)
    {
        Length1 = ob.Length1;
        Length2 = ob.Length2;
        if(Length1>0)
        {
            Massive1 = new float[Length1];
        }
        if (Length2 > 0)
        {
            Massive2 = new float[Length2];
        }
        for(int i=0;i<Length1;i++)
        {
            Massive1[i] = ob.Massive1[i];
        }
        for (int i = 0; i < Length2; i++)
        {
            Massive2[i] = ob.Massive2[i];
        }
    }
    Massiver& operator=(const Massiver& ob)
    {
        if(&ob==this)
        {
            return *this;
        }
        delete[] Massive1;
        delete[] Massive2;

        Length1 = ob.Length1;
        Length2 = ob.Length2;
        if (Length1 > 0)
        {
            Massive1 = new float[Length1];
        }
        if (Length2 > 0)
        {
            Massive2 = new float[Length2];
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
};
class BMas:public Massiver
{
    int Sum1;
    int Sum2;
public:
    void CalculateSum1()
    {
        float sum1 = 0;
        for(int i=0;i<Length1;i++)
        {
            sum1 += Massive1[i];
        }
        int v = (int)sum1;
        if(abs(sum1-v)>=0.5)
        {
            Sum1= v + 1;
        }else
        {
            Sum1= v;
        }
        cout << Sum1<<endl;
    }
    void CalculateSum2()
    {
        float sum2 = 0;
        for (int i = 0; i < Length2; i++)
        {
            sum2 += Massive2[i];
        }
        int v = (int)sum2;
        if (abs(sum2 - v) >= 0.5)
        {
            Sum2 = v + 1;
        }
        else
        {
            Sum2 = v;
        }
        cout << Sum2<<endl;
    }
    BMas(int length1, int length2, float Parm1, float Parm2):Massiver(length1,length2,Parm1,Parm2)
    {

    }
};
int main()
{
    BMas m(5,10,0.9,2.13);
    m.Print();
    BMas d = m;
    d.Print();
    d.CalculateSum1();
    d.CalculateSum2();
}
