#include <iostream>

using namespace std;
class dmass
{
    int Length1=0;
    int Length2=0;
    int Length3=0;
    double* Mass1=nullptr;
    double* Mass2=nullptr;
    double* Mass3=nullptr;
    public:
    dmass(){}
    dmass(const dmass& ob)
    {
        Length1=ob.Length1;
        Length2=ob.Length2;
        Length3=ob.Length3;
        if(Length1>0)
        {
            Mass1=new double[Length1];
            for(int i=0;i<Length1;i++)
            {
                Mass1[i]=ob.Mass1[i];
            }
        }
        if(Length2>0)
        {
            Mass2=new double[Length2];
            for(int i=0;i<Length2;i++)
            {
                Mass2[i]=ob.Mass2[i];
            }
        }
        if(Length3>0)
        {
            Mass3=new double[Length3];
            for(int i=0;i<Length3;i++)
            {
                Mass3[i]=ob.Mass3[i];
            }
        }
    }
    dmass& operator=(const dmass& ob)
    {
        if(&ob==this)
            {
                return *this;
            }
                    delete []Mass1;
        delete []Mass2;
        delete []Mass3;
        Length1=ob.Length1;
        Length2=ob.Length2;
        Length3=ob.Length3;
        if(Length1>0)
        {
            Mass1=new double[Length1];
            for(int i=0;i<Length1;i++)
            {
                Mass1[i]=ob.Mass1[i];
            }
        }
        if(Length2>0)
        {
            Mass2=new double[Length2];
            for(int i=0;i<Length2;i++)
            {
                Mass2[i]=ob.Mass2[i];
            }
        }
        if(Length3>0)
        {
            Mass3=new double[Length3];
            for(int i=0;i<Length3;i++)
            {
                Mass3[i]=ob.Mass3[i];
            }
        }
        return *this;
    }
    void CreateAndEnter()
    {
        Length1=0;
        Length2=0;
        Length3=0;
        delete []Mass1;
        delete []Mass2;
        delete []Mass3;
        while(Length1<=0){
            cout<<"Enter natural length1\n";
            cin>>Length1;
        }
        while(Length2<=0){
            cout<<"Enter natural length2\n";
            cin>>Length2;
        }
        while(Length3<=0){
            cout<<"Enter natural length3\n";
            cin>>Length3;
        }
        Mass1=new double[Length1];
        Mass2=new double[Length2];
        Mass3=new double[Length3];
        cout<<"Enter veshestvenni numbers for mass1\n";
        for(int i=0;i<Length1;i++)
            {
                cin>>Mass1[i];
            }
        cout<<"Enter veshestvenni numbers for mass2\n";
        for(int i=0;i<Length2;i++)
            {
                cin>>Mass2[i];
            }
            cout<<"Enter veshestvenni numbers for mass3\n";
        for(int i=0;i<Length3;i++)
            {
                cin>>Mass3[i];
            }
    }
    void Print()const
    {
        cout<<"Mass 1 length="<<Length1<<endl;
        for(int i=0;i<Length1;i++)
        {
            cout<<Mass1[i]<<" ";
        }
        cout<<endl;

        cout<<"Mass 2 length="<<Length2<<endl;
        for(int i=0;i<Length2;i++)
        {
            cout<<Mass2[i]<<" ";
        }
        cout<<endl;

        cout<<"Mass 3 length="<<Length3<<endl;
        for(int i=0;i<Length3;i++)
        {
            cout<<Mass3[i]<<" ";
        }
        cout<<endl;
    }
    void Sred()
    {
        int Length=0;
        int MaxID=-1;
        double* MassPtr=nullptr;
        double MaxSred=0;

        int Lengthtemp=Length1;
        int MaxIDtemp=1;
        double* MassPtrTemp=Mass1;
        double MaxSredTemp=0;
        for(int i=0;i<Length1;i++)
        {
            MaxSredTemp+=Mass1[i];
        }
        MaxSredTemp/=Length1;

        MaxID=MaxIDtemp;
        MassPtr=MassPtrTemp;
        MaxSred=MaxSredTemp;
        Length=Lengthtemp;

        Lengthtemp=Length2;
        MaxIDtemp=2;
        MassPtrTemp=Mass2;
        MaxSredTemp=0;
        for(int i=0;i<Length2;i++)
        {
            MaxSredTemp+=Mass2[i];
        }
        MaxSredTemp/=Length2;
        if(MaxSredTemp>MaxSred)
        {
            MaxID=MaxIDtemp;
            MassPtr=MassPtrTemp;
            MaxSred=MaxSredTemp;
            Length=Lengthtemp;
        }

        Lengthtemp=Length3;
        MaxIDtemp=3;
        MassPtrTemp=Mass3;
        MaxSredTemp=0;
        for(int i=0;i<Length3;i++)
        {
            MaxSredTemp+=Mass3[i];
        }
        MaxSredTemp/=Length3;
        if(MaxSredTemp>MaxSred)
        {
            MaxID=MaxIDtemp;
            MassPtr=MassPtrTemp;
            MaxSred=MaxSredTemp;
            Length=Lengthtemp;
        }

        cout<<"MaxMass ID="<<MaxID<<endl;
        cout<<"Srednee max="<<MaxSred<<endl;
        for(int i=0;i<Length;i++)
        {
            cout<<MassPtr[i]<<" ";
        }
        cout<<endl;
    }
    ~dmass()
    {
        Length1=0;
        Length2=0;
        Length3=0;
        delete []Mass1;
        delete []Mass2;
        delete []Mass3;
    }
};
int main()
{
    dmass d;
    d.CreateAndEnter();
    d.Print();
    dmass m(d);
    m.Print();
    dmass v=m;
    v.Print();
    v.Sred();
    return 0;
}
