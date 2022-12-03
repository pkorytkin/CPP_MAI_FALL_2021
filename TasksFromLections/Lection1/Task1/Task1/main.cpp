#include <iostream>
#define N 16
#define M 4
using namespace std;

int main()
{
    int a=4;
    int* v=*a;
    cout<<a<<" "<<*a;
    int mass[N];
    for(int i=0;i<N;i++)
    {
        //cin>>mass[i];
        mass[i]=17-i;
    }
    for(int x=0;x<N;x++)
    {
        for(int i=x;i<N;i++)
        {
            if(mass[x]>mass[i])
            {
                int v=mass[x];
                mass[x]=mass[i];
                mass[i]=v;
            }
        }
    }
    for(int x=0;x<N;x++)
    {
        cout<<mass[x]<<" ";
    }
    cout<<endl;
    int matrix[M][M];

    int y=0;
    bool toRight=true;
    while(y<M)
    {
        if(toRight)
        {
            for(int x=0;x<M;x++)
            {
                matrix[x][y]=mass[y*M+x];
            }
            cout<<endl;
            toRight=false;
        }else
        {
            for(int x=M-1;x>=0;x--)
            {
                matrix[M-x-1][y]=mass[y*M+x];
            }
            cout<<endl;
            toRight=true;
        }
        y++;
    }
    for(int y=0;y<M;y++)
    {
        for(int x=0;x<M;x++)
        {
            cout<<matrix[x][y]<<" ";
        }
    cout<<endl;
    }
    return 0;
}
