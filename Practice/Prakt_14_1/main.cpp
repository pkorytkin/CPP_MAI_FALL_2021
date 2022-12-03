#include <iostream>
using namespace std;

class Matrix
{
    int**Mas;
    int Col,Row;
public:
    Matrix(int c,int r,int x):Col(c),Row(r)
    {
        Mas=new int*[c];
        for(int i=0;i<Col;i++)
        {
            Mas[i]=new int[Row];
            for(int j=0;j<Row;j++)
            {
                Mas[i][j]=x;
            }
        }
    }
    ~Matrix()
    {
        for(int i=0;i<Col;i++)
        {
            delete[] Mas[i];
        }
        delete[] Mas;
    }
    int& operator() (int c,int r)
    {
        return Mas[c][r];
    }
    const int& operator() (int c,int r)const
    {
        return Mas[c][r];
    }
};

int main()
{
    Matrix Matrica1(2,3,1);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<Matrica1(i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    Matrica1(1,1)=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<Matrica1(i,j)<<" ";
        }
        cout<<endl;
    }
    const Matrix Matrica2(10,12,5);
    cout<<endl;

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<12;j++)
        {
            cout<<Matrica2(i,j)<<" ";
        }
        cout<<endl;
    }
    //Matrica2(1,1)=0;
    return 0;
}
