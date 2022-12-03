#include <iostream>
#include <iomanip> 
#include <chrono>
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
void Calc(int8_t* a);
int main()
{
    int8_t v = 0;
    cin >> v;
    auto t1 = high_resolution_clock::now();
    
    //int8_t a = 0;
    int8_t a[1];
    a[0] = 1;
    for (int8_t i1 = 0; i1 < 126; i1++)
    {
        for (int8_t i2 = 0; i2 < 126; i2++)
        {
            for (int8_t i3 = 0; i3 < 126; i3++)
            {
                for (int8_t i4 = 0; i4 < 126; i4++)
                {
                    Calc(a);
                    Calc(a);
                    Calc(a);
                    Calc(a);
                    Calc(a);
                    Calc(a);
                    Calc(a);
                    Calc(a);
                    Calc(a);
                    Calc(a);
                }
            }
        }
    }
    auto t2 = high_resolution_clock::now();
    int speed = (int)duration_cast<milliseconds>(t2 - t1).count();
    cout << "Speed: " << speed<<endl;
    return 0;
}
inline void Calc(int8_t *a)
{
    a[0]++;
    a[0]--;
}
