#include <iostream>
// 18 37
using namespace std;
class dmass
{
    int LengthY=0;
    int LengthX=0;
    double** Mass=nullptr;
    public:
    dmass(){}
    dmass(int Y,int X)
    {
        if(X<=0||Y<=0)
        {
            X=0;
            Y=0;
        }
        if(X>0&&Y>0){
            LengthY=Y;
            LengthX=X;
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
    }
    dmass(const dmass&ob)
    {
        LengthY=ob.LengthY;
        LengthX=ob.LengthX;

        if(LengthY>0)
        {
            Mass=new double*[LengthY];
            if(LengthX>0){
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
        ob.LengthY=0;
        ob.LengthX=0;
        Mass=ob.Mass;
        ob.Mass=nullptr;
    }

    dmass& operator=(const dmass&ob)
    {
        if(this==&ob)
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
            if(LengthX>0){
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
        ob.LengthY=0;
        ob.LengthX=0;
        Mass=ob.Mass;
        ob.Mass=nullptr;

        return *this;
    }
    void Create()
    {
       for(int i=0;i<LengthY;i++)
        {
            delete[] Mass[i];
        }
        delete[] Mass;
        LengthY=0;
        LengthX=0;

        while(LengthY<=0)
        {
            cout<<"Enter natural LengthY\n";
            cin>>LengthY;
        }

        while(LengthX<=0)
        {
            cout<<"Enter natural LengthX\n";
            cin>>LengthX;
        }
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
        cout<<"LengthY="<<LengthY<<" LengthX="<<LengthX<<endl;
        for(int y=0;y<LengthY;y++)
        {
            for(int x=0;x<LengthX;x++)
            {
                cout<<Mass[y][x]<<" \t";
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
    dmass operator+(dmass ob2)
    {
        int TheMin=Min(Min(LengthY,LengthX),Min(ob2.LengthX,ob2.LengthY));
        int TheMax=Max(Max(LengthY,LengthX),Max(ob2.LengthX,ob2.LengthY))*2;

        int NeedNumbers=LengthX*LengthY+ob2.LengthX*ob2.LengthY;

        int xBest=TheMax;
        int yBest=TheMax;



        for(int y=TheMin;y<TheMax;y++)
        {
            for(int x=TheMin;x<TheMax;x++)
            {
                if(x*y-NeedNumbers>=0&&xBest*yBest>y*x)
                {
                    xBest=x;
                    yBest=y;
                    if(x*y-NeedNumbers==0)
                    {
                        y=TheMax;
                        break;
                    }
                }

            }
        }
        dmass d(xBest,yBest);


        int posX=0;
        int posY=0;

        for(int y=0;y<LengthY;y++)
        {
            for(int x=0;x<LengthX;x++)
            {
                d.Mass[posY][posX]=Mass[y][x];
                posX++;
                if(posX==d.LengthX)
                {
                    posY++;
                    posX=0;
                }
            }
        }
        for(int y=0;y<ob2.LengthY;y++)
        {
            for(int x=0;x<ob2.LengthX;x++)
            {
                d.Mass[posY][posX]=ob2.Mass[y][x];
                posX++;
                if(posX==d.LengthX)
                {
                    posY++;
                    posX=0;
                }
            }
        }
return d;
    }
    int Min(int a,int b)
    {
        if(a<b)
        {
            return a;
        }
        return b;
    }
    int Max(int a,int b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
};
int main()
{
    cout<<"Create v and print\n";
    dmass v;
    v.Create();
    v.Print();
    cout<<"Create m and print\n";
    dmass m;
    m.Create();
    m.Print();
    swap(v,m);
    cout<<"Swap\n";
    v.Print();
    m.Print();
    cout<<"Sum two\n";

    dmass t=v+m;
    t.Print();
    return 0;
}
