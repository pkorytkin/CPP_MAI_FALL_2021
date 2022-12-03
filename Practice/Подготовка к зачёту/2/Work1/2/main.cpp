#include <iostream>
//14 58
using namespace std;

class dmass
{
    int Length1=0;
    int Length2=0;
    int* Mass1=nullptr;
    int* Mass2=nullptr;
public:
    dmass(){}
    dmass(const dmass &ob1)
    {
        Length1=ob1.Length1;
        Length2=ob1.Length2;
        if(Length1>0)
        {
            Mass1=new int[Length1];
            for(int i=0;i<Length1;i++)
            {
                Mass1[i]=ob1.Mass1[i];
            }
        }
        if(Length2>0)
        {
            Mass2=new int[Length2];
            for(int i=0;i<Length2;i++)
            {
                Mass2[i]=ob1.Mass2[i];
            }
        }
    }
    dmass& operator=(const dmass &ob1)
    {
        if(&ob1==this)
        {
            return *this;
        }
         Length1=ob1.Length1;
        Length2=ob1.Length2;
        if(Length1>0)
        {
            Mass1=new int[Length1];
            for(int i=0;i<Length1;i++)
            {
                Mass1[i]=ob1.Mass1[i];
            }
        }
        if(Length2>0)
        {
            Mass2=new int[Length2];
            for(int i=0;i<Length2;i++)
            {
                Mass2[i]=ob1.Mass2[i];
            }
        }
        return *this;
    }
    void CreateAndEnter()
    {
        while(Length1<=0){
            cout<<"Enter Length1 natural number\n";
            cin>>Length1;
        }
        while(Length2<=0){
            cout<<"Enter Length2 natural number\n";
            cin>>Length2;
        }
        Mass1=new int[Length1];
        Mass2=new int[Length2];
        for(int i=0;i<Length1;i++)
        {
            cout<<"Enter number for mass1:";
            cin>>Mass1[i];
            cout<<endl;
        }
        for(int i=0;i<Length2;i++)
        {
            cout<<"Enter number for mass2:";
            cin>>Mass2[i];
            cout<<endl;
        }
    }
    void Print() const
    {
        cout<<"Mass1 Length="<<Length1<<endl;
        for(int i=0;i<Length1;i++)
            {
                cout<<Mass1[i]<<" ";
            }
        cout<<endl;
        cout<<"Mass2 Length="<<Length2<<endl;
        for(int i=0;i<Length2;i++)
            {
                cout<<Mass2[i]<<" ";
            }
        cout<<endl;
    }
    void FindMaxAndMin()
    {
        int Max=Mass1[0];
        int Min=Max;
        for(int i=0;i<Length1;i++)
        {
            if(Mass1[i]>Max)
            {
                Max=Mass1[i];
            }
            if(Mass1[i]<Min)
            {
                Min=Mass1[i];
            }
        }
        for(int i=0;i<Length2;i++)
        {
            if(Mass2[i]>Max)
            {
                Max=Mass2[i];
            }
            if(Mass2[i]<Min)
            {
                Min=Mass2[i];
            }
        }
        cout<<"Max value="<<Max<<endl;
        cout<<"Min value="<<Min<<endl;
    }
};
int main()
{
    dmass d;
    d.CreateAndEnter();
    d.Print();
    dmass m=d;
    m.Print();
    m.FindMaxAndMin();
    return 0;
}
