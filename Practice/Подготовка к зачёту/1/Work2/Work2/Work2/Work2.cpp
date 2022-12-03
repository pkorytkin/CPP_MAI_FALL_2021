#include <iostream>
//14 12
using namespace std;
class Mass
{
    int Length1 = 0;
    int Length2 = 0;
    int Length3 = 0;
    double* mas1=nullptr;
    double* mas2=nullptr;
    double* mas3=nullptr;
public:
    Mass()
    {

    }
    Mass(Mass &ob)
    {
        delete[] mas1;
        delete[] mas2;
        delete[] mas3;
        Length1 = ob.Length1;
        Length2 = ob.Length2;
        Length3 = ob.Length3;
        if(ob.Length1>0)
        {
            mas1 = new double[Length1];
            for(int i=0;i<Length1;i++)
            {
                mas1[i] = ob.mas1[i];
            }
        }
        if (ob.Length2 > 0)
        {
            mas2 = new double[Length2];
            for (int i = 0; i < Length2; i++)
            {
                mas2[i] = ob.mas2[i];
            }
        }
        if (ob.Length3 > 0)
        {
            mas3 = new double[Length3];
            for (int i = 0; i < Length3; i++)
            {
                mas3[i] = ob.mas3[i];
            }
        }
    }
    Mass& operator=(Mass &ob)
    {
        if(&ob==this)
        {
            return *this;
        }
        delete[] mas1;
        delete[] mas2;
        delete[] mas3;
        Length1 = ob.Length1;
        Length2 = ob.Length2;
        Length3 = ob.Length3;
        if (ob.Length1 > 0)
        {
            mas1 = new double[Length1];
            for (int i = 0; i < Length1; i++)
            {
                mas1[i] = ob.mas1[i];
            }
        }
        if (ob.Length2 > 0)
        {
            mas2 = new double[Length2];
            for (int i = 0; i < Length2; i++)
            {
                mas2[i] = ob.mas2[i];
            }
        }
        if (ob.Length3 > 0)
        {
            mas3 = new double[Length3];
            for (int i = 0; i < Length3; i++)
            {
                mas3[i] = ob.mas3[i];
            }
        }
    }
    ~Mass()
    {
        delete[] mas1;
        delete[] mas2;
        delete[] mas3;
        Length1 = 0;
        Length2 = 0;
        Length3 = 0;
    }
    void Enter()
    {
        while (Length1 <= 0) {
            cout << "Enter natural number for length1\n";
            cin >> Length1;
        }
        while (Length2 <= 0) {
            cout << "Enter natural number for length2\n";
            cin >> Length2;
        }
        while (Length3 <= 0) {
            cout << "Enter natural number for length3\n";
            cin >> Length3;
        }
        mas1 = new double[Length1];
        mas2 = new double[Length2];
        mas3 = new double[Length3];
        cout << "Enter " << Length1 << " veshestvennich numbers for mas1\n";
        for(int i=0;i<Length1;i++)
        {
            cin >> mas1[i];
        }
        cout << "Enter " << Length2 << " veshestvennich numbers for mas2\n";
        for (int i = 0; i < Length2; i++)
        {
            cin >> mas2[i];
        }
        cout << "Enter " << Length3 << " veshestvennich numbers for mas3\n";
        for (int i = 0; i < Length3; i++)
        {
            cin >> mas3[i];
        }
    }
    void Show() const
    {
        if (Length1 > 0)
        {
            for (int i = 0; i < Length1; i++)
            {
                cout<< mas1[i]<<" ";
            }
            cout << endl;
        }else
        {
            cout << "mas1 empty\n";
        }
        if (Length2 > 0)
        {
            for (int i = 0; i < Length2; i++)
            {
                cout << mas2[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "mas2 empty\n";
        }
        if (Length3 > 0)
        {
            for (int i = 0; i < Length3; i++)
            {
                cout << mas3[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "mas3 empty\n";
        }
    }
    void MaxMid()
    {
        double s1 = 0;
        double s2 = 0;
        double s3 = 0;
        for (int i = 0; i < Length1; i++)
        {
            s1 += mas1[i];
        }
        for (int i = 0; i < Length2; i++)
        {
            s2 += mas2[i];
        }
        for (int i = 0; i < Length3; i++)
        {
            s3 += mas3[i];
        }
        s1 /= Length1;
        s2 /= Length2;
        s3 /= Length3;
        int Length = Length1;
        double* maxNumber = &s1;
        double* maxPrtr = mas1;
        Length=MaxMax(&s1,&s2,mas1,mas2,&maxPrtr,&maxNumber,Length1,Length2);
        Length=MaxMax(maxNumber, &s3, maxPrtr, mas2, &maxPrtr, &maxNumber,Length,Length3);
        cout << "Naibolshee " << *maxNumber<<endl;
        for(int i=0;i< Length;i++)
        {
            cout << maxPrtr[i] << " ";
        }
        cout << endl;
    }
    private:
    int MaxMax(double* s1, double* s2,double* Mas1,double* Mas2, double** masPtr, double** sPtr,int Length1,int Length2)
    {
        if (*s1 > *s2)
        {
            *sPtr = s1;
            *masPtr = Mas1;
            return Length1;
        }else
        if (*s1 < *s2)
        {
            *sPtr = s2;
            *masPtr = Mas2;
            return Length2;
        }
        else
        {
            cout << "Dva srednich arifmetchieskih sovpali\n";
            *sPtr = s1;
            *masPtr = Mas1;
            return Length1;
        }
    }
};
int main()
{
    Mass m;
    m.Enter();
    m.Show();
    m.MaxMid();
    /*Mass m2;
    m2.Enter();
    m2.Show();
    m2 = m;
    m2.Show();
    m2.MaxMid();*/
}
