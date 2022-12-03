#include <iostream>

using namespace std;
class Dmass
{

    int Length=0;
    int* Mass=nullptr;
public:
    static int Count;
    Dmass()
    {
        Count++;
        cout<<"Count "<<Count<<endl;
    }
    Dmass(const Dmass &ob1);
    Dmass& operator=(Dmass&ob2);
    void CreateAndShow()
    {
        Length=0;
        delete[] Mass;

        while(Length<=0)
        {
            cout<<"Enter natural Length for mass\n";
            cin>>Length;
        }
        cout<<"Enter "<<Length<< " integer numbers\n";
        Mass=new int[Length];
        for(int i=0;i<Length;i++)
        {
            cin>>Mass[i];
        }
    }
    void Print() const
    {
        cout<<"Length="<<Length<<endl;
        for(int i=0;i<Length;i++)
        {
            cout<<Mass[i]<<" ";
        }
        cout<<endl;
    }
    ~Dmass()
    {
        Length=0;
        delete[] Mass;
        Count--;
        cout<<"Count "<<Count<<endl;
    }
    void SwapIt(int Count)
    {
        for(int v=0;v<Count;v++){
            int Buffer=Mass[0];

            for(int i=1;i<Length;i++)
            {
                Mass[i-1]=Mass[i];
            }
            Mass[Length-1]=Buffer;
        }
    }
    Dmass& operator<<(int Count)
    {
        SwapIt(Count);
        return *this;

    }
};
int Dmass::Count=0;
int main()
{
    Dmass m;
    m.Print();
    m.CreateAndShow();
    m.Print();
    m<<2;
    m.Print();
    return 0;
}
