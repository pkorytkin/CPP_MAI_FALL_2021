#include <iostream>
//17 40 17 51
using namespace std;
class dmass
{
    int Length=0;
    double* Mass=nullptr;
    public:
    dmass(){}
    dmass(const dmass&ob);
    dmass(dmass&&ob)
    {
        Length=ob.Length;
        Mass=ob.Mass;
        ob.Mass=nullptr;
        ob.Length=0;
    }

    dmass& operator=(const dmass&ob);
    dmass& operator=(dmass&&ob)
    {
        if(&ob==this)
        {
            return *this;
        }

        delete[] Mass;
        Length=0;

        Length=ob.Length;
        Mass=ob.Mass;
        ob.Mass=nullptr;
        ob.Length=0;

        return *this;
    }
    void CreateAndEnter()
    {
        delete[] Mass;
        Length=0;
        while(Length<=0){
            cout<<"Enter natural Length\n";
            cin>>Length;
        }
        Mass=new double[Length];
        cout<<"Enter "<<Length<<" veshestvennich chisel\n";
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
    ~dmass()
    {
        delete[] Mass;
        Length=0;
    }

    dmass& operator+=(const int Plus)
    {
        for(int i=0;i<Length;i++)
        {
            Mass[i]+=Plus;
        }
        return *this;
    }
    dmass& operator+=(const float Plus)
    {
        for(int i=0;i<Length;i++)
        {
            Mass[i]+=Plus;
        }
        return *this;
    }
    dmass& operator+=(const double Plus)
    {
        for(int i=0;i<Length;i++)
        {
            Mass[i]+=Plus;
        }
        return *this;
    }
};
int main()
{
    cout<<"d object:\n";
    dmass d;
    d.CreateAndEnter();
    d.Print();
    cout<<endl<<endl;
    cout<<"v object:\n";
    dmass v;
    v.CreateAndEnter();
    v+=4;
    v.Print();
    v+=0.1;
    v.Print();
    cout<<endl<<endl;
    swap(d,v);
    cout<<"d object:\n";
    d.Print();
    cout<<"v object:\n";
    v.Print();

    return 0;
}
