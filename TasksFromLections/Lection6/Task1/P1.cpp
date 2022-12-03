#include <iostream>
using namespace std;
class Ddv
{
    int LengthY = 0;
    int LengthX = 0;
    int** Massive = nullptr;
public:
    Ddv()
    {
        Massive = nullptr;
        EnterAndFill();
    }
	void Clone(const Ddv& from)
	{
		LengthX = from.LengthX;
		LengthY = from.LengthY;
		if (from.Massive != nullptr)
		{
			Massive = new int*[LengthY];
			for (int i = 0; i < LengthY; i++)
			{
				Massive[i] = new int[LengthX];
				for (int v = 0; v < LengthX; v++)
				{
					Massive[i][v] = from.Massive[i][v];
				}
			}
		}
	}
	Ddv(const Ddv& from)
	{
		Clone(from);
	}
	Ddv& operator=(Ddv& from)
	{
		if(this==&from)
		{
			return *this;
		}
		Dispose();

		Clone(from);
	}
    ~Ddv()
    {
        Dispose();
    }
    void EnterAndFill()
    {
        Dispose();
        cout << "Enter Natural Y Length: ";
        cin >> LengthY;
        cout << endl;
        cout << "Enter Natural X Length: ";
        cin >> LengthX;
        cout << endl;
        Massive = new int* [LengthY];
        for(int i=0;i< LengthY;i++)
        {
            Massive[i] = new int[LengthX];
        }
        cout << "Enter " << LengthY * LengthX<<" numbers" << endl;
        for(int y=0;y< LengthY;y++)
        {
            for (int x = 0; x < LengthX; x++)
            {
                cin>>Massive[y][x];
            }
        }
    }
    void Print()
    {
        if(LengthY==0||LengthX==0)
        {
            cout << "Wrong size\n";
            return;
        }
        for (int y = 0; y < LengthY; y++)
        {
            for (int x = 0; x < LengthX; x++)
            {
                cout<<Massive[y][x]<<" ";
            }
            cout << endl;
        }
    }
private:
    void Dispose()
    {
        if (LengthY > 0) {
            for (int i = 0; i < LengthY; i++)
            {
                delete[] Massive[i];
            }
        }
        delete[] Massive;
    }
};

int main()
{
    Ddv d;
    d.Print();
    Ddv d2 = d;
    d2.Print();
    Ddv d3 = Ddv(d2);
    d3.Print();

}
