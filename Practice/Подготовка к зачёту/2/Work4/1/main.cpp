#include <iostream>
//13 51
using namespace std;
class dmass
{
    protected:
    int Length=0;
    double* Mass=nullptr;
public:
    dmass(const dmass &ob);
    dmass(dmass &&ob);

    dmass& operator=(const dmass &ob);
    dmass& operator=(dmass &&ob);
    dmass(int length,int prm)
    {
        if(length<=0)
        {
            Length=0;
            Mass=nullptr;
            return;
        }else
        {
            Length=length;
            Mass=new double[Length];
            for(int i=0;i<Length;i++)
            {
                Mass[i]=(i+1)*prm;
            }
        }
    }
    void Print() const
    {
        cout<<"Massive Length="<<Length<<endl;
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
class vmass:public dmass
{
    static int AliveCount;
public:

    vmass(int length,int prm):dmass(length,prm)
    {
        AliveCount++;
    }
    double& operator[](int index)
    {
        return Mass[index];
    }
    ~vmass()
    {
        AliveCount--;
    }
    void ShowAlive()
    {
        cout<<"vmass AliveCount="<<AliveCount<<endl;
    }
};
int vmass::AliveCount=0;
int main()
{
    vmass v(4,5);
    v.Print();
    cout<<v[3]<<endl;
    v[3]=1;
    v.Print();
    v.ShowAlive();
    return 0;
}
