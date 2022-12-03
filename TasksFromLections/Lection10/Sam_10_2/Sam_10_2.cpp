#include <iostream>

using namespace std;
class Massive
{
private:
    bool is2x2=false;
    int SizeX=0;
    int SizeY=0;
    int* HorizontalMassive = nullptr;
    int** MassiveX_X = nullptr;
public:
    Massive(int size,int numberInit)
    {
        if(size<=0)
        {
            cout << "Wrong size\n";
            while (size <= 0)
                cin >> size;
        }
        SizeX = size;
        is2x2 = false;
        HorizontalMassive = new int[size];
        for(int i=0;i< SizeX;i++)
        {
            HorizontalMassive[i] = numberInit;
        }
    }
    Massive(int sizeX, int sizeY, int numberInit)
    {
        if (sizeX <= 0)
        {
            cout << "Wrong sizeX\n";
            while (sizeX <= 0)
                cin >> sizeX;
        }
        if (sizeY <= 0)
        {
            cout << "Wrong sizeY\n";
            while (sizeY <= 0)
                cin >> sizeY;
        }
        SizeX = sizeX;
        SizeY = sizeY;
        is2x2 = true;
        MassiveX_X = new int*[SizeY];
        for (int i = 0; i < SizeY; i++)
        {
            MassiveX_X[i] = new int[SizeX];
            for (int x = 0; x < SizeX; x++)
            {
                MassiveX_X[i][x] = numberInit;
            }
        }
    }
    ~Massive()
    {
        delete[] HorizontalMassive;
        for(int i=0;i<SizeY;i++)
        {
            delete[] MassiveX_X[i];
            
        }
        delete[] MassiveX_X;
    }
    Massive(const Massive& v);
    Massive& operator=(const Massive& v);
    void Show()
    {
        if(is2x2)
        {
            for (int i = 0; i < SizeY; i++)
            {
                for (int x = 0; x < SizeX; x++)
                {
                    cout << MassiveX_X[i][x] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        else {
            for (int x = 0; x < SizeX; x++)
            {
                cout << HorizontalMassive[x] << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    std::cout << "Hello World!\n";
    Massive v(-20,1);
    v.Show();
    cout << endl;
    Massive v2(20,20, 3);
    v2.Show();
}