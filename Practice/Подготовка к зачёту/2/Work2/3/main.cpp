#include <iostream>

using namespace std;
// 17 04
class dmass
{
    int LengthY=0;
    int LengthX=0;
    double** Mass=nullptr;

    public:
    dmass(){}
    dmass(int lengthY,int lengthX)
    {
        LengthY=lengthY;
        LengthX=lengthX;

        Mass=new double*[LengthY];
        for(int y=0;y<LengthY;y++)
        {
            Mass[y]=new double[LengthX];
            for(int x=0;x<LengthX;x++)
            {
                Mass[y][x]=0;

            }
        }
    }
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
    dmass& operator=(const dmass&ob)
    {
        if(&ob==this)
        {
            return *this;
        }

        for(int i=0;i<LengthY;i++)
        {
            delete[] Mass[i];
        }
        delete[] Mass;
        LengthY=0;
        LengthX=0;

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
    void CreateAndEnter()
    {
        for(int i=0;i<LengthY;i++)
        {
            delete[] Mass[i];
        }
        delete[] Mass;
        LengthY=0;
        LengthX=0;

        while(LengthY<=0){
            cout<<"Enter natural LengthY\n";
            cin>>LengthY;
        }
        while(LengthX<=0){
            cout<<"Enter natural LengthX\n";
            cin>>LengthX;
        }
        cout<<"Enter "<<(LengthY*LengthX)<<" veshestvennich elementov\n";
        Mass=new double*[LengthY];
        for(int y=0;y<LengthY;y++)
        {
            Mass[y]=new double[LengthX];
            for(int x=0;x<LengthX;x++)
            {
                cin>>Mass[y][x];
            }
        }
    }
    void Print()const
    {
        cout<<"Size Y*X - "<<LengthY<<"*"<<LengthX<<endl;
        for(int y=0;y<LengthY;y++)
        {
            for(int x=0;x<LengthX;x++)
            {
                cout<<Mass[y][x]<<" ";
            }
            cout<<endl;
        }
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
    friend dmass operator*(dmass ob1,dmass ob2);
};
dmass operator*(dmass ob1,dmass ob2)
{
    //Число столбцов и число строк
    if(ob1.LengthX!=ob2.LengthY)
    {
        return dmass();
    }else
    {
        dmass d(ob1.LengthY,ob2.LengthX);
        d.Print();
        for(int y=0;y<d.LengthY;y++)
        {
            for(int x=0;x<d.LengthX;x++)
            {
                for(int h=0;h<ob1.LengthX;h++){
                    d.Mass[y][x]+=ob1.Mass[y][h]*ob2.Mass[h][x];
                }
            }
        }
        d.Print();
        return d;
    }
}
int main()
{
    dmass d;
    d.CreateAndEnter();
    d.Print();
    dmass v;
    v.CreateAndEnter();
    v.Print();
    dmass m=d*v;
    m.Print();
    return 0;
}
