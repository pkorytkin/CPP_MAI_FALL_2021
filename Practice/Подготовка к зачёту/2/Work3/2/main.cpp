#include <iostream>
//17 51 18 07
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
    dmass(const dmass&ob);
    dmass(dmass&&ob)
    {
        Length1=ob.Length1;
        Length2=ob.Length2;
        Length3=ob.Length3;
        Mass1=ob.Mass1;
        Mass2=ob.Mass2;
        Mass3=ob.Mass3;
        ob.Length1=0;
        ob.Length2=0;
        ob.Length3=0;
        ob.Mass1=nullptr;
        ob.Mass2=nullptr;
        ob.Mass3=nullptr;
    }

    dmass& operator=(const dmass&ob);
    dmass& operator=(dmass&&ob)
    {
        if(this==&ob)
        {
            return *this;
        }

        delete[] Mass1;
        delete[] Mass2;
        delete[] Mass3;
        Length1=0;
        Length2=0;
        Length3=0;

        Length1=ob.Length1;
        Length2=ob.Length2;
        Length3=ob.Length3;
        Mass1=ob.Mass1;
        Mass2=ob.Mass2;
        Mass3=ob.Mass3;
        ob.Length1=0;
        ob.Length2=0;
        ob.Length3=0;
        ob.Mass1=nullptr;
        ob.Mass2=nullptr;
        ob.Mass3=nullptr;

        return *this;
    }
    void CreateAndEnter()
    {
        delete[] Mass1;
        delete[] Mass2;
        delete[] Mass3;
        Length1=0;
        Length2=0;
        Length3=0;
        while(Length1<=0){
            cout<<"Enter Length1\n";
            cin>>Length1;
        }
        while(Length2<=0){
            cout<<"Enter Length2\n";
            cin>>Length2;
        }
        while(Length3<=0){
            cout<<"Enter Length3\n";
            cin>>Length3;
        }
        Mass1=new double[Length1];
        Mass2=new double[Length2];
        Mass3=new double[Length3];
        cout<<"Enter "<<Length1<<" numbers for mass1\n";
        for(int i=0;i<Length1;i++)
        {
            cin>>Mass1[i];
        }

        cout<<"Enter "<<Length2<<" numbers for mass2\n";
        for(int i=0;i<Length2;i++)
        {
            cin>>Mass2[i];
        }

        cout<<"Enter "<<Length3<<" numbers for mass3\n";
        for(int i=0;i<Length3;i++)
        {
            cin>>Mass3[i];
        }
    }
    void Print()const
    {
        cout<<"Mass1 length="<<Length1<<endl;
        for(int i=0;i<Length1;i++)
        {
            cout<<Mass1[i]<<" ";
        }
        cout<<endl;

        cout<<"Mass2 length="<<Length2<<endl;
        for(int i=0;i<Length2;i++)
        {
            cout<<Mass2[i]<<" ";
        }
        cout<<endl;

        cout<<"Mass3 length="<<Length3<<endl;
        for(int i=0;i<Length3;i++)
        {
            cout<<Mass3[i]<<" ";
        }
        cout<<endl;
    }
    ~dmass()
    {
        delete[] Mass1;
        delete[] Mass2;
        delete[] Mass3;
        Length1=0;
        Length2=0;
        Length3=0;
    }
    void operator()(int id,int position)
    {
        if(id<1||id>3)
        {
            cout<<"Out of range [1,3]\n";
            return;
        }
        if(id==1)
        {
            if(position<Length1&&position>=0){
                cout<<"Mass1["<<position<<"]="<<Mass1[position]<<endl;
            }else
            {
                cout<<"Out of [0,"<<Length1<<"]\n";
            }
        }
        if(id==2)
        {
            if(position<Length2&&position>=0){
            cout<<"Mass2["<<position<<"]="<<Mass2[position]<<endl;
            }else
            {
                cout<<"Out of [0,"<<Length2<<"]\n";
            }
        }
        if(id==3)
        {
            if(position<Length3&&position>=0){
            cout<<"Mass3["<<position<<"]="<<Mass3[position]<<endl;
            }else
            {
                cout<<"Out of [0,"<<Length3<<"]\n";
            }
        }
    }
};
int main()
{
    dmass d;
    d.CreateAndEnter();
    d.Print();
    d(5,2);
    d(1,2);

    dmass v;
    v.CreateAndEnter();
    swap(d,v);
    swap(d,v);
    d.Print();
    v.Print();
    return 0;
}
