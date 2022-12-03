#include <iostream>
using namespace std;
double sum(double v1, double v2)
{

    cout << "sum d="<<v1 <<" "<<"d="<<v2<<endl;
    return v1 + v2;
}
int sum(int v1, int v2)
{
    cout << "sum i=" << v1 << " " << "i=" << v2 << endl;
    return v1 + v2;
}
double sum(double v1, int v2)
{
    cout << "sum d=" << v1 << " " << "i=" << v2 << endl;
    return v1 + v2;
}
double sum(int v1, double v2)
{
    cout << "sum i=" << v1 << " " << "d=" << v2 << endl;
    return v1 + v2;
}
int main()
{
    cout << sum(1, 1)<<endl;
    cout << sum(1, 1.4) << endl;
    cout << sum(2.3, 1) << endl;
    cout << sum(1.5, 1.3) << endl;
}
