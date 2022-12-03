#include <iostream>

using namespace std;
class Matrix
{
    static const int X_Size=4;
    static const int Y_Size=3;
    //int** Data=new int*[X_Size];
    int Data[X_Size][Y_Size];
public:

    Matrix(int Value)
    {

        for(int x=0;x<X_Size;x++)
        {
            //Data[x]=new int[Y_Size];
            for(int y=0;y<Y_Size;y++)
            {
                Data[x][y]=Value;
            }
        }
    }
    void Set_Value(int X,int Y,int Value)
    {
        if(X<X_Size&&Y<Y_Size&&X>=0&&Y>=0)
        {
            Data[Y][X]=Value;
        }else
        {
            cout<<"Выход за границу матрицы\n";
        }
    }
    int Get_Value(int X,int Y)
    {
        if(X<X_Size&&Y<Y_Size&&X>=0&&Y>=0)
        {
            return Data[Y][X];
        }else
        {
            cout<<"Выход за границу матрицы\n";
        }
    }
    void Print_Matrix()
    {
        for(int x=0;x<X_Size;x++)
        {
            for(int y=0;y<Y_Size;y++)
            {
                cout<<Data[x][y]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
int main()
{
    Matrix m(1);
    m.Print_Matrix();
    m.Set_Value(2,2,4);
    m.Print_Matrix();
    cout<<"[2][2]="<<m.Get_Value(2,2);


    return 0;
}
