// Project8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip> 
#include <chrono>
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
class Worker

{
    float Massive[36];
    float** Matrix;
public:
    Worker()
    {
        Matrix = new float* [6];
        for (int i = 0; i < 6; i++)
        {
            Matrix[i] = new float[6];
            for(int v=0;v<6;v++)
            {
                Matrix[i][v] = 0;
            }
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
            cin >> Massive[i];
            //Massive[i] = -i;
            //cout << "Enter more " << (36 - i)<<endl;
        }
        for (int i = 0; i < 36; i++)
        {
            
            cout << Massive[i]<<" ";
        }
        cout << endl;
    }
    unsigned int Min(unsigned int one, unsigned int two)
    {
        return one < two ? one : two;
    }
    void Calculate()
    {
        int8_t X_NumbersCount = 20;
        int8_t Y_NumbersCount = 12;
        int8_t Z_NumbersCount = 4;
        unsigned long long X_NumbersCombinations = FastNCCaluclate(36, X_NumbersCount);
        unsigned short Y_NumbersCombinations =(unsigned short) FastNCCaluclate(16, Y_NumbersCount);


        int8_t X_I_Process = X_NumbersCount - 1;
        int8_t Y_I_Process = Y_NumbersCount - 1;
        uint8_t* X_Indexes = PrepareIndexes(X_NumbersCount);
        uint8_t* Y_Indexes = PrepareIndexes(Y_NumbersCount);

        uint8_t* Z_Indexes = new uint8_t[4];
        

        float BestDelta = INT32_MAX;
        uint8_t* BestX = new uint8_t[X_NumbersCount];
        uint8_t* BestY = new uint8_t[Y_NumbersCount];
        uint8_t* BestZ = new uint8_t[Z_NumbersCount];
        float WorkDelta = 0;

        uint8_t* NotUsedIndexes = new uint8_t[16];
        uint8_t g = 1;

        unsigned long long WorksToDo = X_NumbersCombinations * Y_NumbersCombinations;
        unsigned long long WorkInProgress = 0;
        unsigned int WorkProgress = 0;

        unsigned long long X_Long = 0;
        unsigned int CurrentMaxX = 0;

        auto t1 = high_resolution_clock::now();
        auto t2 = high_resolution_clock::now();

        uint8_t speed = 0;
        unsigned short Y = 0;
        unsigned int X = 0;
        uint8_t t = 0;
        uint8_t m = 0;
        
        while (X_Long < X_NumbersCombinations) {
            CurrentMaxX = Min(4294967295, (unsigned int)(X_NumbersCombinations- CurrentMaxX));
            for (X = 0; X < CurrentMaxX; X++)
            {
                Y_I_Process = Y_NumbersCount - 1;
                //delete Y_Indexes;


                g = 1;
                for (t = 0; t < 16; t++)
                {
                    for (m = 0; m < X_NumbersCount; m++)
                    {
                        if (g == X_Indexes[m])
                        {
                            g++;
                            m = -1;
                            continue;
                        }
                    }
                    NotUsedIndexes[t] = g;
                    g++;

                }

                ResetIndexes(Y_NumbersCount, Y_Indexes);


                for (Y = 0; Y < Y_NumbersCombinations; Y++)
                {
                    g = 1;
                    for (t = 0; t < 4; t++)
                    {
                        for (m = 0; m < Y_NumbersCount; m++)
                        {
                            if (g == Y_Indexes[m])
                            {
                                g++;
                                m = -1;
                                continue;
                            }
                        }
                        Z_Indexes[t] = g;
                        g++;
                    }
                    WorkDelta = CalculateDelta(X_Indexes, Y_Indexes, Z_Indexes, NotUsedIndexes, X_NumbersCount, Y_NumbersCount, Z_NumbersCount);
                    if (WorkDelta < BestDelta)
                    {
                        cout << "New delta " << WorkDelta << endl;
                        CloneIndex(X_Indexes, BestX, X_NumbersCount);
                        CloneIndex(Y_Indexes, NotUsedIndexes, BestY, Y_NumbersCount);
                        CloneIndex(Z_Indexes, NotUsedIndexes, BestZ, Z_NumbersCount);
                        BestDelta = WorkDelta;
                        //if (BestDelta < 1) {
                            for (int k = 0; k < X_NumbersCount; k++)
                            {
                                cout << Massive[BestX[k] - 1] << " ";
                            }
                            cout << endl;
                            for (int k = 0; k < Y_NumbersCount; k++)
                            {
                                cout << Massive[BestY[k] - 1] << " ";
                            }
                            cout << endl;
                            for (int k = 0; k < Z_NumbersCount; k++)
                            {
                                cout << Massive[BestZ[k] - 1] << " ";
                            }
                            cout << endl;
                        //}
                        if (BestDelta == 0)
                        {
                            X = CurrentMaxX;
                            X_Long = X_NumbersCombinations;
                            break;
                        }
                    }
                    if (WorkProgress >= 10000000)
                    {
                        t2 = high_resolution_clock::now();

                        WorkInProgress+=WorkProgress;
                        speed =(uint8_t)duration_cast<milliseconds>(t2 - t1).count();
                        
                        cout << "Working in progress " << WorkInProgress << "/" << WorksToDo<<" Ms/milion="<< (speed)/10<<" Remaining hours="<<((WorksToDo-WorkInProgress)/10000000)* speed/3600000 << endl;
                        WorkProgress = 0;
                        t1 = t2;
                    }
                    WorkProgress++;
                    
                    GetCombination(Y_NumbersCount, Y_Indexes, Y_I_Process, 16);
                }
                GetCombination(X_NumbersCount, X_Indexes, X_I_Process, 36);
            }
            CurrentMaxX += 4294967295;
        }
        cout << "Best delta " << WorkDelta << endl;
        float X_Sum = 0;
        float Y_Sum = 0;
        float Z_Sum = 0;
        for (int8_t k = 0; k < X_NumbersCount; k++)
        {
            X_Sum += Massive[BestX[k] - 1];
            cout << Massive[BestX[k]-1] << " ";
        }
        cout << endl;
        for (int8_t k = 0; k < Y_NumbersCount; k++)
        {
            Y_Sum += Massive[BestY[k] - 1];
            cout << Massive[BestY[k]-1] << " ";
        }
        cout << endl;
        for (int8_t k = 0; k < Z_NumbersCount; k++)
        {
            Z_Sum += Massive[BestZ[k] - 1];
            cout << Massive[BestZ[k] - 1] << " ";
        }
        cout << endl;
        cout << "X_Sum=" << X_Sum << " Y_Sum=" << Y_Sum<<" Z_Sum=" << Z_Sum << " Delta=" << abs(X_Sum - Y_Sum)<<endl;
        for (uint8_t i = 0; i < 6; i++)
        {
            Matrix[0][i] = Massive[BestX[i] - 1];
        }
        for (uint8_t i = 6; i < 11; i++)
        {
            Matrix[i - 5][5] = Massive[BestX[i] - 1];
        }
        for (uint8_t i = 11; i < 16; i++)
        {
            Matrix[5][15 - i] = Massive[BestX[i] - 1];
        }
        for (uint8_t i = 16; i < 20; i++)
        {
            Matrix[20 - i][0] = Massive[BestX[i] - 1];
        }


        for (uint8_t i = 0; i < 4; i++)
        {
            Matrix[1][i + 1] = Massive[BestY[i] - 1];
        }
        for (uint8_t i = 4; i < 7; i++)
        {
            Matrix[i - 3 + 1][4] = Massive[BestY[i] - 1];
        }
        for (uint8_t i = 7; i < 10; i++)
        {
            Matrix[4][9 - i + 1] = Massive[BestY[i] - 1];
        }
        for (uint8_t i = 10; i < 12; i++)
        {
            Matrix[11 - i + 2][1] = Massive[BestY[i] - 1];
        }
        uint8_t LastIndex = 1;
        bool finded = false;
        for (uint8_t y = 2; y < 4; y++)
        {
            for (uint8_t x = 2; x < 4; x++)
            {
                finded = false;
                for (uint8_t i = 0; i < X_NumbersCount; i++)
                {
                    if (LastIndex == BestX[i])
                    {
                        LastIndex++;
                        i = -1;
                    }
                }
                for (uint8_t i = 0; i < Y_NumbersCount; i++)
                {
                    if (LastIndex == BestY[i])
                    {
                        LastIndex++;
                        i = -1;
                        finded = true;
                    }
                }
                if (finded)
                {
                    x--;
                    continue;
                }
                Matrix[y][x] = Massive[LastIndex - 1];
                //cout << "Set " << y << " " << x << "=" << LastIndex << endl;
                LastIndex++;

            }
        }
        for (uint8_t Y = 0; Y < 6; Y++)
        {
            for (uint8_t X = 0; X < 6; X++)
            {
                cout << std::setw(10) << Matrix[Y][X] << " ";
            }
            cout << endl;
        }
        cout << endl;

    }
    float MaxMax(float a,float b)
    {
        if(a>b)
        {
            return a;
        }else
        {
            return b;
        }
    }
    float MinMin(float a, float b)
    {
        if (a > b)
        {
            return b;
        }
        else
        {
            return a;
        }
    }
    float CalculateDelta(uint8_t* X_Indexes, uint8_t* Y_Indexes, uint8_t* Z_Indexes, uint8_t* NotUsedIndexes, uint8_t X_Count, uint8_t Y_Count, uint8_t Z_Count)
    {
        float v1 = 0;
        float v2 = 0;
        float v3 = 0;
        int i = 0;
        for (i = 0; i < Z_Count; i++)
        {
            v1 += Massive[NotUsedIndexes[Z_Indexes[i] - 1] - 1];
        }
        for (i = 0; i < X_Count; i++)
        {
            v2 += Massive[X_Indexes[i] - 1];
        }
        for (i = 0; i < Y_Count; i++)
        {
            v3 += Massive[NotUsedIndexes[Y_Indexes[i] - 1] - 1];
        }

        float max = MaxMax(MaxMax(v1, v2), v3);
        float min= MinMin(MinMin(v1, v2), v3);
        return max-min;
    }
    long long FastNCCaluclate(int N, int K)
    {
        long long Up = 1;

        int* Devides = new int[K];
        int V = 1;
        int i = 0;
        for (V = 1; V <= K; V++)
        {
            Devides[V - 1] = V;
        }

        for (i = N - K + 1; i <= N; i++)
        {
            Up *= i;
            for (V = 0; V < K; V++)
            {
                if (Devides[V] != 0 && Up % Devides[V] == 0)
                {
                    Up /= Devides[V];
                    Devides[V] = 0;
                }
            }
        }
        delete[] Devides;
        return Up;
    }
private:
    void CloneIndex(uint8_t* From, uint8_t* To, uint8_t Scale)
    {
        uint8_t i = 0;
        for (i = 0; i < Scale; i++)
        {
            To[i] = From[i];
        }
    }
    void CloneIndex(uint8_t* From, uint8_t* NotUsedIndexes, uint8_t* To, uint8_t Scale)
    {
        uint8_t i = 0;
        for (i = 0; i < Scale; i++)
        {
            To[i] = NotUsedIndexes[From[i] - 1];
        }
    }
    uint8_t* PrepareIndexes(uint8_t Count)
    {
        uint8_t* IndexesWork = new uint8_t[Count];
        uint8_t i = 0;
        for (i = 0; i < Count; i++)
        {
            IndexesWork[i] = i + 1;
        }
        return IndexesWork;
    }
    void ResetIndexes(uint8_t Count, uint8_t* IndexesWork)
    {
        uint8_t i = 0;
        for (i = 0; i < Count; i++)
        {
            IndexesWork[i] = i + 1;
        }
    }
    bool DoBack = false;
    void GetCombination(uint8_t Count, uint8_t* IndexesWork, int8_t& i, int8_t NumbersCount)
    {
        DoBack = false;
        uint8_t v = 0;
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

            for (v = i + 1; v < Count; v++)
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