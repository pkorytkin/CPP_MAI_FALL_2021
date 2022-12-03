#include <iostream>
using namespace std;
//0 45
class MassV
{
    int Length = 0;
    double* Massive=nullptr;
public:
    MassV(){}
    MassV(MassV &ob);

    ~MassV()
    {
        delete[] Massive;
        Length = 0;
    }
    MassV& operator=(MassV& ob2);
    void CreateAndEnter()
    {
        cout << "Enter natural length \n";
        cin >> Length;
        while(Length<=0)
        {
            cout << "Enter natural length ";
            cin >> Length;
        }
        Massive = new double[Length];
        cout << "Enter " << Length << " veshestvennich chisel\n";
        for(int i=0;i<Length;i++)
        {
            cin >> Massive[i];
        }
        cout << "Done.\n";
    }
    
    void Print() const
    {
        if(Length<=0)
        {
            cout << "Empty massive length=0\n";
        }else
        {
            cout << "Massive Length="<<Length<<endl;
            for(int i=0;i<Length;i++)
            {
                cout << Massive[i] << " ";
            }
            cout << endl;
            cout << "Massive Length=" << Length << endl;
            for (int i = 0; i < Length; i++)
            {
                cout << LengthCalculator(Massive[i]) << " \n";
            }
            cout << endl;
        }
    }
    double& operator[](int Index)const
    {
        if (Index < 0 || Index >= Length)
        {
            cout << "Array out of range";

        }
        return Massive[Index];
    }
    double& operator[](int Index)
    {
        if(Index<0||Index>=Length)
        {
            cout << "Array out of range";
            
        }
        return Massive[Index];
    }
    void Sort()
    {
        for(int i=0;i<Length;i++)
        {
            for(int v=i+1;v<Length;v++)
            {
                if(LengthCalculator(Massive[i])< LengthCalculator(Massive[v]))
                {
                    double t = Massive[i];
                    Massive[i] = Massive[v];
                    Massive[v] = t;
                }
            }
        }
    }
private:
    //5 1.12 3.8 9.742 1 6
    int LengthCalculator(const double number)const
    {
        double Number = number;
        int Length = 0;

        Number -= (int)Number;

        while (abs(Number- ((int)Number)) >0.00001)
        {
            cout << Number << " " << ((int)Number) << " ";
            Number *= 10;
            Number -= (int)Number;
            Length++;
        }
        cout << endl;
        return Length;
        /*double Number = number;
        Number -= (int)Number;
        int Length = 0;
        while(Number!=0)
        {
            cout << Number << " ";
            Number *= 10;
            Number -= (int)Number;
            Length++;
        }
        cout << endl;
        return Length;*/
        /*
        
        
        if (Number > 0.00000000000000001) {
            double number = Number - (int)Number;
            double d = 0;
            double Jumper = 0.1;
            bool worked = false;
            int Length = 0;
            while (number - d > 0.000000001)
            {
                worked = false;
                while (d + Jumper < number)
                {
                    d += Jumper;
                    worked = true;
                }
                if (!worked)
                {
                    d -= Jumper;
                    Jumper /= 10;
                    Length++;
                }
                cout << d << " " << number << endl;
            }
            return Length;
        }else
        {
            return 0;
        }
        
        */
    }
    
};
int main()
{
    MassV v;
    v.CreateAndEnter();
    v.Print();
    v.Sort();
    v.Print();
}
