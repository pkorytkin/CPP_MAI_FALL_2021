#include <iostream>
using namespace std;
class Massiver
{
    int* Massive=nullptr;
    int Length=0;
    
public:
    static int Created;
    Massiver() { Created++; }
    ~Massiver()
    {
        Created--;
        delete[] Massive;
        Length = 0;
    }
    void Prepare()
    {
        cout << "Enter Celoe Length\n";
        cin >> Length;
        Massive = new int[Length];
        cout << "Enter " << Length << " Massive numbers\n";
        for (int i = 0; i < Length; i++)
        {
            cin >> Massive[i];
        }
    }
    void const Print()
    {
        if (Length > 0) {
            for (int i = 0; i < Length; i++)
            {
                cout << Massive[i] << " ";
            }
            cout << endl;
        }else
        {
            cout << "Zero Length\n";
        }
    }
    void operator<<(int Count)
    {
        CycleSwapLeft(Count);
    }
    void CycleSwapLeft(int SwapCount)
    {
        if(SwapCount<=0)
        {
            cout << "Wrong swap number \n";
            return;
        }
        int Temp = 0;
        for(int i=0;i< SwapCount;i++)
        {
            Temp = Massive[0];
            for(int v=1;v<Length;v++)
            {
                Massive[v - 1] = Massive[v];
            }
            Massive[Length - 1] = Temp;
        }
    }
    Massiver(const Massiver &m);
    Massiver operator=(Massiver &m);

};
int Massiver::Created = 0;
int main()
{
    Massiver m1;
    Massiver m2;
    Massiver m3;
    cout << "Created " << Massiver::Created<<endl;
    m1.Prepare();
    m1.Print();
    m2.Print();
    m1.CycleSwapLeft(2);
    m1 << 4;
    m1.Print();
    
   
}
