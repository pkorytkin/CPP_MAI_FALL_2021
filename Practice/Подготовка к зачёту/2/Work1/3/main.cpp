#include <iostream>
//15 16
using namespace std;
class dmass
{
    protected:
    int length1;
    int length2;
    double* mass1;
    double* mass2;
public:
    dmass(const dmass&ob)
    {
        length1=ob.length1;
        length2=ob.length2;
        if(length1>0)
        {
            mass1=new double[length1];
            for(int i=0;i<length1;i++)
            {
                mass1[i]=ob.mass1[i];
            }
        }
        if(length2>0)
        {
            mass2=new double[length2];
            for(int i=0;i<length2;i++)
            {
                mass2[i]=ob.mass2[i];
            }
        }
    }
    dmass& operator=(const dmass &ob)
    {
        if(&ob==this)
        {
            return *this;
        }
        length1=ob.length1;
        length2=ob.length2;
        if(length1>0)
        {
            mass1=new double[length1];
            for(int i=0;i<length1;i++)
            {
                mass1[i]=ob.mass1[i];
            }
        }
        if(length2>0)
        {
            mass2=new double[length2];
            for(int i=0;i<length2;i++)
            {
                mass2[i]=ob.mass2[i];
            }
        }
        return *this;
    }
    dmass(int Length1,int Length2,double num1,double num2)
    {
        length1=Length1;
        length2=Length2;
        mass1=new double[length1];
        mass2=new double[length2];
        for(int i=0;i<length1;i++)
        {
            mass1[i]=num1;
        }
        for(int i=0;i<length2;i++)
        {
            mass2[i]=num2;
        }
    }
    void Print()const
    {
        cout<<"Length1="<<length1<<endl;
        for(int i=0;i<length1;i++)
        {
            cout<<mass1[i]<<" ";
        }
        cout<<endl;
        cout<<"Length2="<<length2<<endl;
        for(int i=0;i<length2;i++)
        {
            cout<<mass2[i]<<" ";
        }
        cout<<endl;
    }
};
class dmass2:public dmass
{
    double sum1=0;
    double sum2=0;
    public:
    dmass2(int Length1,int Length2,double num1,double num2):dmass(Length1,Length2,num1,num2)
    {

    }
    void CalculateSum()
    {
        sum1=0;
        sum2=0;
        for(int i=0;i<length1;i++)
        {
            sum1+=mass1[i];
        }
        for(int i=0;i<length2;i++)
        {
            sum2+=mass2[i];
        }
        if(sum1-((int)sum1)>=0.5)
        {
            sum1=((int)sum1)+1;
        }else
        {
            sum1=(int)sum1;
        }
        if(sum2-((int)sum2)>=0.5)
        {
            sum2=((int)sum2)+1;
        }else
        {
            sum2=(int)sum2;
        }
        cout<<"Sum1= "<<sum1<<" Sum2="<<sum2<<endl;
    }
};
int main()
{
    dmass2 m(2,4,3.1,5.1);
    m.Print();
    m.CalculateSum();
    return 0;
}
