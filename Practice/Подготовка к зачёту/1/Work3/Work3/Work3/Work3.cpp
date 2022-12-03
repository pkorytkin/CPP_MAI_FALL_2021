#include <iostream>
//16 46  17 00 17 39 18 09
using namespace std;
class Massive
{
    double** Mass=nullptr;
    int LengthY=0;
    int LengthX=0;
public:
    Massive(){}
    Massive(int lengthY,int lengthX)
    {
        LengthY = lengthY;
        LengthX = lengthX;
        Mass = new double* [LengthY];
        for (int y = 0; y < LengthY; y++)
        {
            Mass[y] = new double[LengthX];
            for (int x = 0; x < LengthX; x++)
            {
                Mass[y][x] = 0;
            }
        }
        
    }
    Massive(Massive &ob)
    {
        LengthY = ob.LengthY;
        LengthX = ob.LengthX;
        if(LengthY>0)
        {
            Mass = new double* [LengthY];
            for(int y=0;y<LengthY;y++)
            {
                Mass[y] = new double[LengthX];
                for(int x=0;x<LengthX;x++)
                {
                    Mass[y][x] = ob.Mass[y][x];
                }
            }
        }
    }
    Massive(Massive&& ob)
    {
        LengthY = ob.LengthY;
        LengthX = ob.LengthX;
        ob.LengthX = 0;
        ob.LengthY = 0;
        Mass = ob.Mass;
        ob.Mass = nullptr;
    }
    Massive& operator=(const Massive& ob)
    {
        if(this==&ob)
        {
            return *this;
        }
        for (int i = 0; i < LengthY; i++)
        {
            delete[] Mass[i];
        }
        delete[] Mass;
        LengthY = 0;
        LengthX = 0;

        LengthY = ob.LengthY;
        LengthX = ob.LengthX;
        if (LengthY > 0)
        {
            Mass = new double* [LengthY];
            for (int y = 0; y < LengthY; y++)
            {
                Mass[y] = new double[LengthX];
                for (int x = 0; x < LengthX; x++)
                {
                    Mass[y][x] = ob.Mass[y][x];
                }
            }
        }
    }
    Massive& operator=(Massive&& ob)
    {
        if (this == &ob)
        {
            return *this;
        }
        for (int i = 0; i < LengthY; i++)
        {
            delete[] Mass[i];
        }
        delete[] Mass;
        LengthY = ob.LengthY;
        LengthX = ob.LengthX;
        ob.LengthX = 0;
        ob.LengthY = 0;
        Mass = ob.Mass;
        ob.Mass = nullptr;
    }
    void CreateAndEnter()
    {
        for (int i = 0; i < LengthY; i++)
        {
            delete[] Mass[i];
        }
        delete[] Mass;
        LengthY = 0;
        LengthX = 0;

        while (LengthY <= 0) {
            cout << "Enter Y size natural\n";
            cin >> LengthY;
        }
        while (LengthX <= 0) {
            cout << "Enter X size natural\n";
            cin >> LengthX;
        }
        cout << "Enter " << LengthY * LengthX << " veshestvennich numbers\n";
        Mass = new double* [LengthY];
        for(int i=0;i<LengthY;i++)
        {
            Mass[i] = new double[LengthX];
            for(int v=0;v<LengthX;v++)
            {
                cin>>Mass[i][v];
            }
        }
    }
    void Print() const
    {
        cout << "Y size=" << LengthY << " X size=" << LengthX<<endl;
        for (int i = 0; i < LengthY; i++)
        {
            for (int v = 0; v < LengthX; v++)
            {
                cout << Mass[i][v] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    ~Massive()
    {
        for(int i=0;i<LengthY;i++)
        {
            delete[] Mass[i];
        }
        delete[] Mass;
        LengthY = 0;
        LengthX = 0;
    }
    friend Massive operator+(const Massive& ob1, const Massive& ob2);
};
Massive operator+(const Massive &ob1,const Massive &ob2)
{
    int MinLengthY = min(ob1.LengthY, ob2.LengthY);
    int MinLengthX = min(ob1.LengthX, ob2.LengthX);
    int MaxLengthY = max(ob1.LengthY, ob2.LengthY);
    int MaxLengthX = max(ob1.LengthX, ob2.LengthX);
    
    int SetSizeX = 0;
    int SetSizeY = 0;

    int NeedElements = ob1.LengthX * ob1.LengthY + ob2.LengthX * ob2.LengthY;
    if(NeedElements%MinLengthX==0)
    {
        SetSizeX = MinLengthX;
        SetSizeY = NeedElements / MinLengthX;
    }else
    if (NeedElements % MinLengthY == 0)
    {
        SetSizeX = NeedElements / MinLengthY;
        SetSizeY = MinLengthY;
    }else
    {
        SetSizeX = (int)sqrt(NeedElements);
        while(SetSizeX<MinLengthX)
        {
            SetSizeX++;
        }
        SetSizeY = NeedElements / SetSizeX;
        while (SetSizeY < MinLengthY)
        {
            SetSizeY++;
        }
        while(SetSizeX*SetSizeY<NeedElements)
        {
            if(SetSizeX<SetSizeY)
            {
                SetSizeX++;
            }else
            {
                SetSizeY++;
            }
        }
    }

    Massive m(SetSizeY,SetSizeX);
    int PositionY = 0;
    int PositionX = 0;
    for(int y=0;y<ob1.LengthY;y++)
    {
        for (int x = 0; x < ob1.LengthX; x++)
        {
            m.Mass[PositionY][PositionX] = ob1.Mass[y][x];
            PositionX++;
            if(PositionX==SetSizeX)
            {
                PositionX = 0;
                PositionY++;
            }
        }
    }
    m.Print();
    for (int y = 0; y < ob2.LengthY; y++)
    {
        for (int x = 0; x < ob2.LengthX; x++)
        {
            m.Mass[PositionY][PositionX] = ob2.Mass[y][x];
            PositionX++;
            if (PositionX == SetSizeX)
            {
                PositionX = 0;
                PositionY++;
            }
        }
    }
    //Massive m();
    return m;
}
int main()
{
    Massive m1;
    m1.CreateAndEnter();
    m1.Print();
    Massive m2;
    m2.CreateAndEnter();
    m2.Print();
    Massive m3 = m1 + m2;
    m3.Print();
}
