#include <iostream>
//16 17
using namespace std;
class Massives
{
    double* Mass1=nullptr;
    double* Mass2=nullptr;
    double* Mass3=nullptr;
    int Length1=0;
    int Length2=0;
    int Length3=0;
public:
    Massives(){}
    Massives(const Massives &ob);
    Massives(Massives&& ob)
    {
        Mass1 = ob.Mass1;
        Mass2 = ob.Mass2;
        Mass3 = ob.Mass3;
        Length1 = ob.Length1;
        Length2 = ob.Length2;
        Length3 = ob.Length3;
        ob.Mass1 = nullptr;
        ob.Mass2 = nullptr;
        ob.Mass3 = nullptr;
        ob.Length1 = 0;
        ob.Length2 = 0;
        ob.Length3 = 0;
    }

    Massives& operator=(const Massives& ob);
    Massives& operator=(Massives&& ob)
    {
        if(this==&ob)
        {
            return *this;
        }
        delete[] Mass1;
        delete[] Mass2;
        delete[] Mass3;
        Mass1 = ob.Mass1;
        Mass2 = ob.Mass2;
        Mass3 = ob.Mass3;
        Length1 = ob.Length1;
        Length2 = ob.Length2;
        Length3 = ob.Length3;
        ob.Mass1 = nullptr;
        ob.Mass2 = nullptr;
        ob.Mass3 = nullptr;
        ob.Length1 = 0;
        ob.Length2 = 0;
        ob.Length3 = 0;
        return *this;
    }

    void CreateAndEnter()
    {
        delete[] Mass1;
        delete[] Mass2;
        delete[] Mass3;
        Length1 = 0;
        Length2 = 0;
        Length3 = 0;

        while (Length1 <= 0) {
            cout << "Enter Natural Length1\n";
            cin >> Length1;
        }
        while (Length2 <= 0) {
            cout << "Enter Natural Length2\n";
            cin >> Length2;
        }
        while (Length3 <= 0) {
            cout << "Enter Natural Length3\n";
            cin >> Length3;
        }
        Mass1 = new double[Length1];
        Mass2 = new double[Length2];
        Mass3 = new double[Length3];
        cout << "Enter " << Length1 << " veshestvennich chisel for mass1\n";
        for(int i=0;i<Length1;i++)
        {
            cin>>Mass1[i];
        }
    
        cout << "Enter " << Length2 << " veshestvennich chisel for mass2\n";
        for (int i = 0; i < Length2; i++)
        {
            cin >> Mass2[i];
        }
        cout << "Enter " << Length3 << " veshestvennich chisel for mass3\n";
        for (int i = 0; i < Length3; i++)
        {
            cin >> Mass3[i];
        }
    }
    void Print() const
    {
        cout << "Mass1 Length=" << Length1<<endl;
        for(int i=0;i<Length1;i++)
        {
            cout << Mass1[i] << " ";
        }
        cout << endl;
        cout << "Mass2 Length=" << Length2 << endl;
        for (int i = 0; i < Length2; i++)
        {
            cout << Mass2[i] << " ";
        }
        cout << endl;
        cout << "Mass3 Length=" << Length3 << endl;
        for (int i = 0; i < Length3; i++)
        {
            cout << Mass3[i] << " ";
        }
        cout << endl;
    }
    ~Massives()
    {
        delete[] Mass1;
        delete[] Mass2;
        delete[] Mass3;
        Length1 = 0;
        Length2 = 0;
        Length3 = 0;
    }
    void operator()(int MassNumber,int Position)
    {
        if(MassNumber<=0||MassNumber>3)
        {
            cout << "Mass number must be 1 or 2 or 3\n";
            return;
        }
        if(Position<0)
        {
            cout << "Mass position must be positive\n";
            return;
        }
        if(MassNumber==1)
        {
            if(Position>=Length1)
            {
                cout << "Mass position must be in [0,"<<Length1<<")\n";
                return;
            }
            cout << "Number in Mass1[" << Position << "]=" << Mass1[Position] << endl;
        }
        if (MassNumber == 2)
        {
            if (Position >= Length2)
            {
                cout << "Mass position must be in [0," << Length2 << ")\n";
                return;
            }
            cout << "Number in Mass2[" << Position << "]=" << Mass2[Position] << endl;
        }
        if (MassNumber == 3)
        {
            if (Position >= Length3)
            {
                cout << "Mass position must be in [0," << Length3 << ")\n";
                return;
            }
            cout << "Number in Mass3[" << Position << "]=" << Mass3[Position]<<endl;
        }
    }
};
int main()
{
    Massives m1;
    m1.CreateAndEnter();
    m1.Print();
    /*m1(0, 3);
    m1(3, 3);
    m1(1, 3);
    m1(2, 3);*/
    Massives m2;
    m2.CreateAndEnter();
    m2.Print();
    Massives temp;
    temp=move(m1);
    m1 = move(m2);
    m2 = move(temp);
    cout << endl;
    m1.Print();
    cout << endl;
    m2.Print();
    cout << endl;

    temp.Print();
}
