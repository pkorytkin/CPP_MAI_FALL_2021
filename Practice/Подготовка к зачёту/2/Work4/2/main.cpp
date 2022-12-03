#include <iostream>
#include <utility>
using namespace std;

class dmass
{

    int Length=0;
    int* Mass=nullptr;
public:
    dmass(){}
    dmass(const dmass&ob)
    {
        Length=ob.Length;
        if(Length>0)
        {
            Mass=new int[Length];
            for(int i=0;i<Length;i++)
            {
               Mass[i]=ob.Mass[i];
            }
        }
    }
    dmass(dmass&&ob)
    {
        Length=ob.Length;
        Mass=ob.Mass;

        ob.Length=0;
        ob.Mass=nullptr;
    }

    dmass& operator=(const dmass&ob)
    {
        if(this==&ob)
            {
                return *this;
            }
        delete[] Mass;
        Length=ob.Length;
        if(Length>0)
        {
            Mass=new int[Length];
            for(int i=0;i<Length;i++)
            {
               Mass[i]=ob.Mass[i];
            }
        }

        return *this;
    }
    dmass& operator=(dmass&&ob)
    {
        if(this==&ob)
        {
            return *this;
        }
        delete[] Mass;
        Length=ob.Length;
        Mass=ob.Mass;

        ob.Length=0;
        ob.Mass=nullptr;

        return *this;
    }
    dmass(int length,int prm)
    {
        if(length<=0)
        {
            Length=0;
            Mass=nullptr;
        }else
        {
            Length=length;
            Mass=new int[Length];
            for(int i=0;i<Length;i++)
            {
                Mass[i]=(i+1)*prm;
            }
        }
    }
    void Print()const
    {
        cout<<" Mass Length="<<Length<<endl;
        for(int i=0;i<Length;i++)
        {
            cout<<Mass[i]<<" ";
        }
        cout<<endl;
    }

    ~dmass()
    {
        Length=0;
        delete[] Mass;
    }
};
void Sdvig(dmass* Mass,int MassLength,int Count)
{
    for(int i=0;i<Count;i++)
    {
        dmass tmp=move(Mass[0]);
        for(int i=1;i<MassLength;i++)
        {
            Mass[i-1]=Mass[i];
            swap(Mass[i-1],Mass[i]);
        }
        Mass[MassLength-1]=move(tmp);
    }
}
int main()
{
    cout<<"Enter N\n";
    int N=0;
    cin>>N;
    dmass m(N,0);

    dmass* Mass=new dmass[N];
    for(int i=0;i<N;i++)
    {
        Mass[i]=dmass(i+1,i+2);
        Mass[i].Print();
    }
    cout<<"Enter sdvig count natural\n";
    int sdvig=0;
    cin>>sdvig;
    Sdvig(Mass,N,sdvig);
    cout<<endl<<endl;
    for(int i=0;i<N;i++)
    {
        Mass[i].Print();
    }

    return 0;
}
