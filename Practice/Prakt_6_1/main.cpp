#include <iostream>

using namespace std;

int main()
{
    int** Mas=nullptr;

    const int N=6, M=4;
    Mas=new int*[N];

    for(int i=0;i<N;i++)
        Mas[i]=new int[M];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        Mas[i][j]=i*10+j;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        cout<<" Mas["<<i<<"]="<<Mas[i][j]<<"\t";
        cout<<endl;
    }
    cout<<" Mas="<<Mas<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<" Mas["<<i<<"]="<<Mas[i]<<endl;
    }

    for(int i=0;i<N;i++)
        delete[] Mas[i];
    delete []Mas;
    Mas=nullptr;

    return 0;
}
