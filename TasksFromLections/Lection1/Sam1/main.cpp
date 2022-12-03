#include <iostream>

using namespace std;

int main()
{
    int m=0;
    int* a1=nullptr;
    int* b1=nullptr;
    int* v=nullptr;
    cin>>m;
    a1=&m;
    b1=&m;
    v=&m;
    cout<<"*a1="<<*a1<<" *b1="<<*b1<<" *v="<<*v<<" m="<<m<<endl;
    cout<<"Set *a1 to 4"<<endl;
    *a1=4;
    cout<<"*a1="<<*a1<<" *b1="<<*b1<<" *v="<<*v<<" m="<<m<<endl;
    cout<<"Set *b1 to 8"<<endl;
    *b1=8;
    cout<<"*a1="<<*a1<<" *b1="<<*b1<<" *v="<<*v<<" m="<<m<<endl;

    cout<<"Set *b1 to 3"<<endl;
    *v=3;
    cout<<"*a1="<<*a1<<" *b1="<<*b1<<" *v="<<*v<<" m="<<m<<endl;
    return 0;
}
