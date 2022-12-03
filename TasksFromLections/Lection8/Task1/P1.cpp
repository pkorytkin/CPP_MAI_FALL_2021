
#include <iostream>
using namespace std;
class Calculator {

    double Count = 0;
    double a = 0;
    double b = 0;
    double CalculateInX(double x)
    {
        return (0.01 * x * x) + 1;
    }
public:
    Calculator()
    {
        double Jump = 0;
        while (Jump <= 0)
        {
            //cout << "Enter Split Count\n";
            cout << "Enter h Count\n";
            cin >> Jump;
        }
        cout << "Enter x From\n";
        cin >> a;
        cout << "Enter x To\n";
        cin >> b;
        Count = abs(b - a) / Jump;
        Integral = 0;
        int v = 0;
        for (int i = 0; i < Count; i++)
        {
            if(v==1000000)
            {
                cout << "Working " << i << "/" << Count<<endl;
                v = 0;
            }
            v++;
            double xnoew = a + i * Jump;
            double xnext = a + i * Jump;
            Integral += (CalculateInX(xnoew) + CalculateInX(xnext));
        }
        Integral *= 0.5 * Jump;
        Integral += (CalculateInX(Jump * Count) + CalculateInX(b)) * 0.5 * (abs(b-a) - (Jump * Count));
    }
    double Integral=NAN;
    void Show()
    {
        cout << "Integral=" << Integral;
    }

};
int main()
{
    Calculator c;
    c.Show();
    
}
