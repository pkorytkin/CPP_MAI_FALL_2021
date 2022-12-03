#include <iostream>
using namespace std;

int main()
{
    int x=10;
    cout<<" x="<<x<<" &x"<<&x<<endl<<endl;
    int y=20;
    cout<<" y="<<y<<" &y="<<&y<<endl<<endl;

    int *pa=nullptr;
    pa=new int;
    *pa=5;
    cout<<" *pa="<<*pa<<" pa="<<pa<<endl<<endl;

    double *pb=new double;
    *pb=64.5;
    cout<<" *pb="<<*pb<<" pb="<<pb<<endl<<endl;

    const int K=5;
    int *Mas=new int[K];
    for(int i=0; i<K;i++)
        Mas[i]=(i+1)*10;
    for(int i=0; i<K;i++)
        cout<<" Mas["<<i<<"]"<<Mas[i]<<endl;
    cout<<" Mas="<<Mas<<endl<<endl;

    delete pa;
    delete pb;
    delete []Mas;
    //delete не лишает доступа к памяти
    for(int i=0;i<K;i++)
        cout<<" Mas["<<i<<"]="<<Mas[i]<<endl;
    cout<<" Mas="<<Mas<<endl<<endl;

    pa=nullptr;
    pb=nullptr;
    Mas=nullptr;

    for(int i=0;i<K;i++)
        cout<<" Mas["<<i<<"]="<<Mas[i]<<endl;
    cout<<" Mas="<<Mas<<endl<<endl;

    return 0;
}
