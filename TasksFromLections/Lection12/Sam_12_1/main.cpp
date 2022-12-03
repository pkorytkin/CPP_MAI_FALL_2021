#include <iostream>

using namespace std;
class Table
{
    int** Matrix=nullptr;
    int SizeY=0;
    int SizeX=0;
public:
    Table()
    {}
    Table(Table& ob)
    {
        SizeY=ob.SizeY;
        SizeX=ob.SizeX;
        if(ob.Matrix!=nullptr)
        {
            Matrix=new int*[SizeY];
            for(int i=0;i<SizeY;i++)
            {
                Matrix[i]=new int[SizeX];
                for(int x=0;x<SizeX;x++)
                {
                    Matrix[i][x]=ob.Matrix[i][x];
                }
            }
        }
    }
    Table& operator=(Table& ob)
    {
        if(&ob==this)
        {
            return *this;
        }
        SizeY=ob.SizeY;
        SizeX=ob.SizeX;
        if(ob.Matrix!=nullptr)
        {
            Matrix=new int*[SizeY];
            for(int i=0;i<SizeY;i++)
            {
                Matrix[i]=new int[SizeX];
                for(int x=0;x<SizeX;x++)
                {
                    Matrix[i][x]=ob.Matrix[i][x];
                }
            }
        }
        return *this;
    }
    void Init()
    {
        cout<<"Size X and Y\n";
        int X=0;
        int Y=0;
        while(X<=0){
            cin>>X;
        }
        while(Y<=0){
            cin>>Y;
        }
        SizeX=X;
        SizeY=Y;
        Matrix=new int*[Y];
        for(int i=0;i<Y;i++)
        {
            Matrix[i]=new int[X];
            for(int x=0;x<X;x++)
            {
                Matrix[i][x]=0;
            }
        }
        cout<<"Enter Horizontal Numbers count="<<X<<endl;
        for(int i=0;i<X;i++)
        {
            cin>>Matrix[0][i];
        }
        cout<<"Enter Vertical Numbers count="<<(Y-1)<<endl;
        for(int i=1;i<Y;i++)
        {
            cin>>Matrix[i][0];
        }
        for(int y=1;y<Y;y++){
            for(int x=1;x<X;x++)
            {
                Matrix[y][x]=Matrix[0][x]*Matrix[y][0];
            }
        }
    }
    void Print()
    {
        for(int Y=0;Y<SizeY;Y++)
        {
            for(int X=0;X<SizeX;X++)
            {
                cout<<Matrix[Y][X]<<"   ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    Table m;
    m.Init();
    m.Print();

    Table m2;
    m2=m;
    m2.Print();
    return 0;
}
