#include <iostream>
using namespace std;
//Передаётся ссылка на массив и ссылка на размер массива
void SozdMas(int *&,int&);
//Передаётся копия которую нельзя изменить т.к. константная
void VivMas(const int*const,const int);
int main()
{
    int *Mas=nullptr;
    int K=0;
    SozdMas(Mas,K);
    VivMas(Mas,K);
    delete [] Mas;
    Mas=nullptr;
    return 0;
}
void SozdMas(int *&M,int &K)
{
    K=5;
    M=new int[K];
    for(int i=0;i<K;i++)
        M[i]=(i+1)*(i+2);
    cout<<" Massiv: ";
    for(int i=0;i<K;i++)
        cout<<M[i]<<" ";
    cout<<endl;
}
void VivMas(const int*const M,const int K)
{
    cout<<" Massiv: ";
    for(int i=0;i<K;i++)
        cout<<M[i]<<" ";
    cout<<endl;
}
