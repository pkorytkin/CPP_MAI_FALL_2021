#include <iostream>

using namespace std;

int main()
{
    int Length=0;
    double* Mass=nullptr;
    cout<<"Enter Length\n";
    cin>>Length;

    Mass=new double[Length];

    cout<<"Enter numbers\n";
    for(int i=0;i<Length;i++)
    {
        cin>>Mass[i];
    }



    for(int i=0;i<Length-1;i++)
    {
        for(int v=i+1;v<Length;v++)
        {
            if(Mass[i]>Mass[v])
            {
                double temp=Mass[i];
                Mass[i]=Mass[v];
                Mass[v]=temp;
            }
        }
    }

    for(int i=0;i<Length;i++)
    {
        cout<<Mass[i]<<" ";
    }
    cout<<endl;

    return 0;
}
