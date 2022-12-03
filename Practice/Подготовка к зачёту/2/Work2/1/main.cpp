#include <iostream>
//15 52
using namespace std;
class dmass
{
    int Length=0;
    double* Mass=nullptr;
public:
    dmass(){}
    dmass(const dmass &ob);
    dmass& operator=(const dmass &ob);
    void CreateAndEnter()
    {
        Length=0;
        delete[] Mass;
        while(Length<=0){
            cout<<"Enter natural length for mass\n";
            cin>>Length;
        }
        Mass=new double[Length];
        cout<<"Enter veshestvennie chisla "<<Length<<" shtuk\n";
        for(int i=0;i<Length;i++)
        {
            cin>>Mass[i];
        }
    }
    void Print() const
    {
        cout<<"Length="<<Length<<endl;
        for(int i=0;i<Length;i++)
        {
            cout<<Mass[i]<<" ";
        }
        cout<<endl;
    }
    ~dmass()
    {
        Length=0;
        delete[] Mass;
    }
    double& operator[](int index)
    {
        return Mass[index];
    }
};
int main()
{
    dmass m;
    m.CreateAndEnter();
    m[1]=4;
    m.Print();

    cout<<m[1];
    return 0;
}
