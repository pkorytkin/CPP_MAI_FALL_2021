#include <iostream>

using namespace std;

int main()
{
    int a =5;
    int &ra=a;
    //константная переменная
    //int &rb=10;

    //не const ссылку на временную переменную нельзя
    //int &rd=a+2;

    //cost ссылку на временную можно
    const int& re=12;
    const int&rg=a-4;
    //re=a+10;
    //rg=3;


    int &&rc=100;
    cout<<" rc="<<rc<<endl;
    rc++;
    cout<<" rc="<<rc<<endl;
    rc=50;
    cout<<" rc="<<rc<<endl;


    return 0;
}
