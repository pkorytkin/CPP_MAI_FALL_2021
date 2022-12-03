#include <iostream>

using namespace std;
class DMass;
class IMass;
class DMass
{
    static const int Length=6;
    double Massive[Length];
    public:
    DMass():Massive{1.2,3.4,5.9,-7,-9,-27}
    {

    }
    friend void Show(const DMass &v1,const IMass &v2);
};
class IMass
{
    static const int Length=6;
    double Massive[Length];
    public:
    IMass():Massive{13,2,9,18,6,17}
    {

    }
    friend void Show(const DMass &v1,const IMass &v2);
};
int main()
{
    DMass d;
    IMass i;

    Show(d,i);
    return 0;
}
void Show(const DMass &v1,const IMass &v2)
{
    double MinNumber=v1.Massive[0];
    double MaxNumber=MinNumber;
    for(int i=1;i<v1.Length;i++)
    {
        if(v1.Massive[i]>MaxNumber)
        {
            MaxNumber=v1.Massive[i];
        }else
        if(v1.Massive[i]<MinNumber)
        {
            MinNumber=v1.Massive[i];
        }
    }
    for(int i=1;i<v2.Length;i++)
    {
        if(v2.Massive[i]>MaxNumber)
        {
            MaxNumber=v2.Massive[i];
        }else
        if(v2.Massive[i]<MinNumber)
        {
            MinNumber=v2.Massive[i];
        }
    }
    cout<<"Max Number: "<<MaxNumber<<endl;
    cout<<"Min Number: "<<MinNumber<<endl;
}
