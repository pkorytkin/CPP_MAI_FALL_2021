
#include <iostream>
using namespace std;
double CalculateInX(double x);
int main()
{
    int Count = 0;
    double a = 0;
    double b = 0;
    while(Count<=0)
    {
        cout << "Enter Split Count\n";
        cin >> Count;
    }
    cout << "Enter x From\n";
    cin >> a;
    cout << "Enter x To\n";
    cin >> b;
    double Jump = abs(b - a)/Count;
    double Integral = 0;
    for(int i=0;i<Count;i++)
    {
        double xnoew = a + i * Jump;
        double xnext = a + i * Jump;
        Integral += (CalculateInX(xnoew) + CalculateInX(xnext)) * 0.5 * Jump;
    }
    cout << "Integral=" << Integral;
}
double CalculateInX(double x)
{
    return (0.01 * x * x) + 1;
}