#include <iostream>

using namespace std;
class BaseClass;
class ParrentClass;
class BaseClass
{
    protected: int Length;
    protected: * Massiv;
    public:
    BaseClass()
    {
        Length=0;
        Massiv=nullptr;
    }
    ~BaseClass()
    {
        delete[] Massiv;
    }

    void Init()
    {
        cout<<"Enter natural number: ";

        cin>>Length;
        cout<<"Enter  numbers "<<Length<<endl;
        Massiv=new int[Length];
        for(int i=0;i<Length;i++)
        {
            cin>>Massiv[i];
        }
    }
    void Print()
    {
        cout<<"Length "<<Length<<endl;
        for(int i=0;i<Length;i++)
        {
            cout<<Massiv[i]<<" ";
        }
        cout<<endl;
    }
};
class ParrentClass:public BaseClass
{
public:
    void PrintNumber()
    {
        cout<<"Enter number ID from 0 to "<<Length<<" excluded \n";
        int v=0;

        cin>>v;
        cout<<"\nMassiv["<<v<<"]="<<Massiv[v];
    }
    void ChangeNumber()
    {
        cout<<"Enter number ID from 0 to "<<Length<<" excluded ";
        int v=0;
        cin>>v;
        cout<<"\nEnter new value: ";
        int newValue=0;
        cin>>newValue;
        Massiv[v]=newValue;
    }
};
int main()
{
    ParrentClass c=ParrentClass();
    c.Init();
    c.Print();
    c.ChangeNumber();
    c.Print();
    c.PrintNumber();
    return 0;
}
