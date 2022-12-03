#include <iostream>
using namespace std;
int modul(int x)
{
    if(x>=0)
    {
        return x;
    }
    return -x;
}
double modul(double x)
{
    if (x >= 0)
    {
        return x;
    }
    return -x;
}
int main()
{
    int a = -3, b=10;
    double e = -7.35, g = 9.8;
    cout << " a=" << a << ", |a|=" << modul(a) << endl;
    cout << " b=" << b << ", |b|=" << modul(b) << endl;
    cout << " e=" << e << ", |e|=" << modul(e) << endl;
    cout << " g=" << g << ", |g|=" << modul(g) << endl;
    return 0;
}