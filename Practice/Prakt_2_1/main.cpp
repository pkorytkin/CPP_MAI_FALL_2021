#include <iostream>

using namespace std;
void ZapMas(int *M, const int K);
void VivMas(const int *M, const int K);
int main()
{
    const int K=10;
    int Mas[K];
    ZapMas(Mas,K);
    VivMas(Mas,K);

    return 0;
}
void ZapMas(int *M,const int K)
{
    M[0]=0;
    M[1]=1;
    for(int i=2;i<K;i++)
    {
        M[i]=M[i-1]+M[i-2];
    }
    cout<<endl<<sizeof(M);
}
void VivMas(const int *M,const int K)
{
    cout<<" Massiv:";
    for(int i=0;i<K;i++)
        {
            cout<<M[i]<<" ";
        }
    cout<<endl;
}
