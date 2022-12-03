// 14 46
#include <iostream>
using namespace std;
class Mass
{
    int LengthY = 0;
    int LengthX = 0;
    double** Massive=nullptr;
public:
    Mass()
    {
        
    }
    Mass(const Mass &ob)
    {
        LengthX = ob.LengthX;
        LengthY = ob.LengthY;
        Massive = new double* [LengthY];
        for (int y = 0; y < LengthY; y++)
        {
            Massive[y] = new double[LengthX];
            for (int x = 0; x < LengthX; x++)
            {
                Massive[y][x]=ob.Massive[y][x];
            }
        }
    }
    Mass& operator=(Mass& ob)
    {
        if(this==&ob)
        {
            return *this;
        }
        for (int i = 0; i < LengthY; i++)
        {
            delete[] Massive[i];
        }
        delete[] Massive;

        LengthX = ob.LengthX;
        LengthY = ob.LengthY;
        Massive = new double* [LengthY];
        for (int y = 0; y < LengthY; y++)
        {
            Massive[y] = new double[LengthX];
            for (int x = 0; x < LengthX; x++)
            {
                Massive[y][x] = ob.Massive[y][x];
            }
        }

    }
    void Enter()
    {
        while (LengthY <= 0) {
            cout << "Enter Natural matrix size Y\n";
            cin >> LengthY;
        }
        while (LengthX <= 0) {
            cout << "Enter Natural matrix size X\n";
            cin >> LengthX;
        }
        Massive = new double* [LengthY];
        cout << "Enter " << LengthY << " strok po " << LengthX << " elements\n";
        for(int y=0;y<LengthY;y++)
        {
            Massive[y] = new double [LengthX];
            for(int x=0;x<LengthX;x++)
            {
                cin >> Massive[y][x];
            }
        }
    }
    void Show()
    {
        cout << "Matrix size YnaX " << LengthY<<"na" << LengthX<<endl;
        for (int y = 0; y < LengthY; y++)
        {
            for (int x = 0; x < LengthX; x++)
            {
                cout << Massive[y][x] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    ~Mass()
    {
        for(int i=0;i<LengthY;i++)
        {
            delete[] Massive[i];
        }
        delete[] Massive;
        LengthX = 0;
        LengthY = 0;
    }
    friend Mass operator*(const Mass& ob1, const Mass& ob2);
};
Mass operator*(const Mass& ob1, const Mass& ob2)
{
    Mass ob;
    if(ob1.LengthX!=ob2.LengthY)
    {
        return ob;
    }
    ob.LengthY = ob1.LengthY;
    ob.LengthX = ob2.LengthX;
    ob.Massive = new double*[ob.LengthY];

    for (int y = 0; y < ob.LengthY; y++)
    {
        ob.Massive[y] = new double[ob.LengthX];
        for (int x = 0; x < ob.LengthX; x++)
        {
            ob.Massive[y][x] = 0;
        }
    }
    for(int y=0;y<ob.LengthY;y++)
    {
        for (int x = 0; x < ob.LengthY; x++)
        {
            for (int k = 0; k < ob1.LengthX; k++)
            {
                ob.Massive[y][x] += ob1.Massive[y][k] * ob2.Massive[k][x];
            }
        }
    }
    return ob;
    
}
int main()
{
    Mass m;
    m.Enter();
    m.Show();
    Mass m2;
    m2.Enter();
    m2.Show();
    
    Mass m3 = m * m2;
    m3.Show();

}