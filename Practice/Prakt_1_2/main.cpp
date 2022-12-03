#include <iostream>

using namespace std;

int main()
{
    int a;
    int &rB=a;
    cout<<"a="<<a<<" &a="<<&a<<endl;
    cout<<"rB="<<rB<<" &rB="<<&rB<<endl;
    a=8;
    cout<<"a="<<a<<" &a="<<&a<<endl;
    cout<<"rB="<<rB<<" &rB="<<&rB<<endl;
    rB=20;
    cout<<"a="<<a<<" &a="<<&a<<endl;
    cout<<"rB="<<rB<<" &rB="<<&rB<<endl;
    return 0;
}
