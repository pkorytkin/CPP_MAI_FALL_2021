#include <iostream>
//14 32 15 05
using namespace std;
class dmass
{
    int LengthY=0;
    int LengthX=0;
    double** Mass=nullptr;
    public:
        dmass(){}
    dmass(const dmass&ob)
    {
        LengthY=ob.LengthY;
        LengthX=ob.LengthX;
        if(LengthY>0)
        {
            Mass=new double*[LengthY];
            if(LengthX>0)
            {
                for(int y=0;y<LengthY;y++)
                {
                    Mass[y]=new double[LengthX];
                    for(int x=0;x<LengthX;x++)
                    {
                        Mass[y][x]=ob.Mass[y][x];
                    }
                }
            }
        }
    }
    dmass(dmass&&ob)
    {
        LengthY=ob.LengthY;
        LengthX=ob.LengthX;
        Mass=ob.Mass;
        ob.Mass=nullptr;
        ob.LengthX=0;
        ob.LengthY=0;
    }
    dmass& operator=(const dmass&ob)
    {
        if(this==&ob)
        {
            return*this;
        }
        for(int y=0;y<LengthY;y++)
        {
            delete[] Mass[y];
        }
        delete[] Mass;
        LengthY=ob.LengthY;
        LengthX=ob.LengthX;
        if(LengthY>0)
        {
            Mass=new double*[LengthY];
            if(LengthX>0)
            {
                for(int y=0;y<LengthY;y++)
                {
                    Mass[y]=new double[LengthX];
                    for(int x=0;x<LengthX;x++)
                    {
                        Mass[y][x]=ob.Mass[y][x];
                    }
                }
            }
        }

        return *this;
    }
    dmass& operator=(dmass&&ob)
    {
        if(this==&ob)
        {
            return*this;
        }

        LengthY=ob.LengthY;
        LengthX=ob.LengthX;
        Mass=ob.Mass;

        ob.LengthX=0;
        ob.LengthY=0;
        ob.Mass=nullptr;

        return *this;
    }

    dmass(int SizeY,int SizeX,int prm)
    {
        if(SizeY>0&&SizeX>0)
        {
            LengthY=SizeY;
            LengthX=SizeX;
            Mass=new double*[LengthY];
            for(int y=0;y<LengthY;y++)
            {
                Mass[y]=new double[SizeX];
                for(int x=0;x<LengthX;x++)
                {
                    Mass[y][x]=prm*(y+1)+(x+1);
                }
            }
        }
    }
    void Print()const
    {
        cout<<"SizeY="<<LengthY<<" SizeX="<<LengthX<<endl;
        for(int y=0;y<LengthY;y++)
        {
            for(int x=0;x<LengthX;x++)
            {
                cout<<Mass[y][x]<<"\t";
                //printf("%d3.3 ",Mass[y][x])
            }
            cout<<endl;
        }
        //cout<<endl;
    }
    double Sum()const
    {
        double sum=0;
        for(int y=0;y<LengthY;y++)
        {
            for(int x=0;x<LengthX;x++)
            {
                sum+=Mass[y][x];
            }
        }
        return sum;
    }
    ~dmass()
    {
        for(int i=0;i<LengthY;i++)
        {
            delete[] Mass[i];
        }
        delete[] Mass;
        LengthY=0;
        LengthX=0;
    }
};
void Sort(dmass* Mass,int Length)
{
    for(int i=0;i<Length-1;i++)
    {
        for(int v=i+1;v<Length;v++)
        {
            if(Mass[i].Sum()>Mass[v].Sum())
            {
                swap(Mass[i],Mass[v]);
            }
        }
    }
}
int main()
{
    cout<<"Enter N\n";
    int N=0;
    cin>>N;
    dmass* Mass=new dmass[N];
    for(int i=0;i<N;i++)
    {
        Mass[i]=dmass(N-i+1,N-i+1,i);
        Mass[i].Print();
        cout<<Mass[i].Sum()<<endl;
    }
    cout<<endl<<endl<<endl;
    Sort(Mass,N);
    for(int i=0;i<N;i++)
    {
        Mass[i].Print();
        cout<<Mass[i].Sum()<<endl;
    }
    return 0;
}
