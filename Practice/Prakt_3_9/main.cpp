#include <iostream>

using namespace std;
class A
{
    int x;
public :
    void vv_x(int i){x=i;}
    int vozvr_x(){return x;}
};
int main()
{
    A ob;
    ob.vv_x(5);
    cout<<" ob.x="<<ob.vozvr_x()<<endl;
    return 0;
}
