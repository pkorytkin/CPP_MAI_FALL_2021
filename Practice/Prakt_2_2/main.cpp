#include <iostream>

using namespace std;
const int K=10;
void ZapMas(int (&M)[K]);
void VivMas(int (&M)[K]);
int main()
{
    const int K=10;
    int Mas[K];
    ZapMas(Mas);
    VivMas(Mas);

    return 0;
}
void ZapMas(int (&M)[K])
{
    M[0]=0;
    M[1]=1;
    for(int i=2;i<K;i++)
    {
        M[i]=M[i-1]+M[i-2];
    }
    cout<<endl<<sizeof(M);
}
void VivMas(int (&M)[K])
{
    cout<<" Massiv:";
    for(int i=0;i<K;i++)
        {
            cout<<M[i]<<" ";
        }
    cout<<endl;
}
