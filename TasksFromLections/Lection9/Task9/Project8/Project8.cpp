// Project8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip> 
using namespace std;
class Worker
{
    double Massive[36];
    double** Matrix;
public:
    Worker()
    {
        Matrix = new double* [6];
        for(int i=0;i<6;i++)
        {
            Matrix[i] = new double[6];
        }
        RequestNumbers();
    }
    ~Worker()
    {
        for (int i = 0; i < 6; i++)
        {
            delete[] Matrix[i];
        }
        delete[] Matrix;
    }
    void RequestNumbers()
    {
        for (int i = 0; i < 36; i++)
        {
            //cin >> Massive[i];
            Massive[i] = -i;
        }
    }
    void Calculate()
    {
        int X_NumbersCount = 20;
        int Y_NumbersCount = 12;
        long long X_NumbersCombinations = FastNCCaluclate(36, X_NumbersCount);
        long long Y_NumbersCombinations = FastNCCaluclate(16, Y_NumbersCount);
        

        int X_I_Process = X_NumbersCount-1;
        int Y_I_Process = Y_NumbersCount - 1;
        int* X_Indexes = PrepareIndexes(X_NumbersCount);
        int* Y_Indexes = PrepareIndexes(Y_NumbersCount);

        int BestDelta = INT32_MAX;
        int* BestX = new int[X_NumbersCount];
        int* BestY = new int[Y_NumbersCount];
        int WorkDelta = 0;

        int* NotUsedIndexes = new int[16];
        int g = 1;
        for (long long X = 0; X < X_NumbersCombinations; X++)
        {
            Y_I_Process = Y_NumbersCount - 1;
            delete Y_Indexes;

            
            g = 1;
            for(int t=0;t<16;t++)
            {
                for(int m=0;m<X_NumbersCount;m++)
                {
                    if(g==X_Indexes[m])
                    {
                        g++;
                        m = -1;
                        continue;
                    }
                }
                NotUsedIndexes[t] = g;
                g++;
                
            }
            
            Y_Indexes = PrepareIndexes(Y_NumbersCount);


            for(long long Y=0;Y< Y_NumbersCombinations;Y++)
            {
                WorkDelta = CalculateDelta(X_Indexes, Y_Indexes, NotUsedIndexes, X_NumbersCount, Y_NumbersCount);
                if(WorkDelta<BestDelta)
                {
                    cout << "New delta " << WorkDelta<<endl;
                    CloneIndex(X_Indexes,BestX,X_NumbersCount);
                    CloneIndex(Y_Indexes,NotUsedIndexes, BestY, Y_NumbersCount);
                    BestDelta = WorkDelta;
                    for (int k = 0; k < X_NumbersCount; k++)
                    {
                        cout << Massive[BestX[k]-1] << " ";
                    }
                    cout << endl;
                    for (int k = 0; k < Y_NumbersCount; k++)
                    {
                        cout << Massive[BestY[k]-1] << " ";
                    }
                    cout << endl;
                    if (BestDelta == 0)
                    {
                        X = X_NumbersCombinations;
                        break;
                    }
                }
                
                GetCombination(Y_NumbersCount, Y_Indexes, Y_I_Process,16);
            }
            GetCombination(X_NumbersCount, X_Indexes, X_I_Process,36);
        }
        cout << "Best delta " << WorkDelta<<endl;
        
        for(int i=0;i<X_NumbersCount;i++)
        {
            BestX[i] = i + 1;
        }

        for (int i = 0; i < Y_NumbersCount; i++)
        {
            BestY[i] = X_NumbersCount+ i + 1;
        }
        for(int i=0;i<6;i++)
        {
            Matrix[0][i] = Massive[BestX[i] - 1];
        }
        for (int i = 6; i < 11; i++)
        {
            Matrix[i-5][5] = Massive[BestX[i] - 1];
        }
        for (int i = 11; i < 16; i++)
        {
            Matrix[5][15-i] = Massive[BestX[i] - 1];
        }
        for (int i = 16; i < 20; i++)
        {
            Matrix[20-i][0] = Massive[BestX[i] - 1];
        }

        
        for (int i = 0; i < 4; i++)
        {
            Matrix[1][i+1] = Massive[BestY[i] - 1];
        }
        for (int i = 4; i < 7; i++)
        {
            Matrix[i - 3+1][4] = Massive[BestY[i] - 1];
        }
        for (int i = 7; i < 10; i++)
        {
            Matrix[4][9 - i+1] = Massive[BestY[i] - 1];
        }
        for (int i = 10; i < 12; i++)
        {
            Matrix[11 - i+2][1] = Massive[BestY[i] - 1];
        }
        int LastIndex = 1;
        for(int y=2;y<4;y++)
        {
            for (int x = 2; x < 4; x++)
            {
                bool finded = false;
                for(int i=0;i<X_NumbersCount;i++)
                {
                    if(LastIndex==BestX[i])
                    {
                        LastIndex++;
                        i = -1;
                    }
                }
                for (int i = 0; i < Y_NumbersCount; i++)
                {
                    if (LastIndex == BestY[i])
                    {
                        LastIndex++;
                        i = -1;
                        finded = true;
                    }
                }
                if(finded)
                {
                    x--;
                    continue;
                }
                Matrix[y][x] =Massive[ LastIndex-1];
                //cout << "Set " << y << " " << x << "=" << LastIndex << endl;
                LastIndex++;
                
            }
        }
        for(int Y=0;Y<6;Y++)
        {
            for (int X = 0; X < 6; X++)
            {
                cout << std::setw(10)<< Matrix[Y][X] << " ";
            }
            cout << endl;
        }
        cout << endl;

    }
    bool CheckUnique(int* X_Indexes, int* Y_Indexes, int X_Count, int Y_Count)
    {
        for(int i=0;i<X_Count;i++)
        {
            for (int v = 0; v < Y_Count; v++)
            {
                if(X_Indexes[i]==Y_Indexes[v])
                {
                    return false;
                }
            }
        }
        return true;
    }
    double CalculateDelta(int* X_Indexes, int* Y_Indexes,int* NotUsedIndexes, int X_Count, int Y_Count)
    {
        int v = 0;
        for(int i=0;i<X_Count;i++)
        {
            v += Massive[X_Indexes[i] - 1];
        }
        for (int i = 0; i < Y_Count; i++)
        {
            v -= Massive[NotUsedIndexes[Y_Indexes[i] - 1]-1];
        }
        return abs(v);
    }
    long long FastNCCaluclate(int N, int K)
    {
        long long Up = 1;

        int* Devides = new int[K];
        for (int V = 1; V <= K; V++)
        {
            Devides[V - 1] = V;
        }

        for (int i = N - K + 1; i <= N; i++)
        {
            Up *= i;
            for (int V = 0; V < K; V++)
            {
                if(Devides[V]!=0&&Up%Devides[V]==0)
                {
                    Up /= Devides[V];
                    Devides[V] = 0;
                }
            }
        }
        delete Devides;
        return Up;
    }
private:
    void CloneIndex(int* From, int* To, int Scale)
    {
        for (int i = 0; i < Scale; i++)
        {
            To[i] = From[i];
        }
    }
    void CloneIndex(int* From,int*NotUsedIndexes, int* To, int Scale)
    {
        for (int i = 0; i < Scale; i++)
        {
            To[i] = NotUsedIndexes[From[i]-1];
        }
    }
    void ParseByIndexes(int Position, int* Indexes, int GroupSize, int** GroupIndexes)
    {
        for (int i = 0; i < GroupSize; i++)
        {
            GroupIndexes[Position][i] = Indexes[i];
        }
    }
    int* PrepareIndexes(int Count)
    {
        int* IndexesWork = new int[Count];
        for (int i = 0; i < Count; i++)
        {
            IndexesWork[i] = i + 1;
        }
        return IndexesWork;
    }
    void GetCombination(int Count, int* IndexesWork, int &i,int NumbersCount)
    {
        bool DoBack = false;
        while (i >= 0)
        {
            if (IndexesWork[i] < NumbersCount - Count + i + 1)
            {
                IndexesWork[i]++;
                DoBack = true;
            }
            else
            {
                i--;
                continue;
            }

            for (int v = i + 1; v < Count; v++)
            {
                IndexesWork[v] = IndexesWork[v - 1] + 1;
            }
            if (i < Count - 1 && DoBack)
            {
                i = Count - 1;

            }
            return;
        }
        
    }
    
};
int main()
{
    Worker w = Worker();
    w.Calculate();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
