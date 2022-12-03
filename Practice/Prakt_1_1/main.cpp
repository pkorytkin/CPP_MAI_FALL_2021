#include <iostream>

using namespace std;

int main()
{
    int x=5;
    cout<<" x="<<x<<" &x="<<&x<<endl;
    int* pA=nullptr;
    cout<<pA<<endl;
    pA=&x;
    cout<<" pA="<<pA<<" *pA="<<*pA<<endl;
    int **pC=nullptr;
    pC=&pA;
    cout<<" pC="<<pC<<" *pC="<<*pC<<" **pC="<<**pC<<endl;
    return 0;
}
