#include <iostream>
using namespace std;

class Worker {

    const int ScaleJump = 3;
    int MassiveLength = ScaleJump;
    int WorkLength = 0;
    int* DynamicMassive = nullptr;
    int** DDMassive = nullptr;
    int PowerX = 0;
    int PowerY = 0;
public:

    void Clone(const Worker& from)
    {
        MassiveLength = from.WorkLength;
        WorkLength = from.WorkLength;
        
        DisposeMassive();
        PowerX = PowerX;
        PowerY = PowerY;

        if(from.WorkLength>0)
        {
            DynamicMassive = new int [WorkLength];
            for(int i=0;i<WorkLength;i++)
            {
                DynamicMassive[i] = from.DynamicMassive[i];
            }
        }
        if(from.PowerY>0)
        {
            DDMassive = new int* [PowerY];
            for (int i = 0; i < PowerY; i++)
            {
                DDMassive[i] = new int [PowerX];
                for(int v=0;v<PowerY;v++)
                {
                    DDMassive[i][v] = from.DDMassive[i][v];
                }
            }
        }
    }
    Worker()
    {
        
    }
    Worker(const Worker& from)
    {
        Clone(from);
    }
    Worker& operator= (const Worker& from)
    {
        if(this==&from)
        {
            return *this;
        }
        Clone(from);
        return *this;
    }
    void DisposeMassive()
    {
        delete[] DynamicMassive;
        if(PowerX!=0)
        {
            for (int i = 0; i < PowerY; i++)
            {
                    delete[] DDMassive[i];
            }
            delete[] DDMassive;
            PowerX = 0;
            PowerY = 0;
        }
    }

    ~Worker()
    {
        DisposeMassive();
    }
    
    void Init()
    {
        DisposeMassive();
        cout << "Enter Numbers:\n";
        DynamicMassive = new int[MassiveLength];

        for (int m = 0; m < MassiveLength; m++)
        {
            DynamicMassive[m] = 0;
        }


        while (true)
        {
            int v = 0;
            cin >> v;
            if (v == 0)
            {
                break;
            }
            else
            {
                if (WorkLength == MassiveLength)
                {
                    int* NewMassive = new int[MassiveLength + ScaleJump];
                    for (int m = 0; m < MassiveLength; m++)
                    {
                        NewMassive[m] = DynamicMassive[m];
                    }
                    for (int m = MassiveLength; m < MassiveLength + ScaleJump; m++)
                    {
                        NewMassive[m] = 0;
                    }
                    DisposeMassive();
                    DynamicMassive = NewMassive;
                    MassiveLength = MassiveLength + ScaleJump;
                }

                DynamicMassive[WorkLength] = v;
                WorkLength++;
            }

        }

        PowerX = (int)sqrt(WorkLength);
        PowerY = PowerX;
        if(PowerX==1)
        {
            PowerX = 2;
        }
        if (PowerY == 1)
        {
            PowerY = 2;
        }
        while (PowerX * PowerY < WorkLength)
        {
            PowerY++;
        }
        DDMassive = new int* [PowerY];
        for (int i = 0; i < PowerY; i++)
        {
            DDMassive[i] = new int[PowerX];
            for (int m = 0; m < PowerX; m++)
            {
                if (i * PowerX + m < WorkLength) {
                    DDMassive[i][m] = DynamicMassive[i * PowerX + m];
                }
                else
                {
                    DDMassive[i][m] = 0;
                }
            }
        }
        for (int i = 0; i < PowerY; i++)
        {
            for (int m = 0; m < PowerX; m++)
            {
                cout << DDMassive[i][m] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "Working\n";

        int AllSplits = 0;
        for (int i = 1; i <= PowerY; i++) {
            AllSplits += FastNCCaluclate(WorkLength, i);
        }
        cout << "All splits=" << AllSplits << endl;
        int BigestGroup = PowerY;

        int** WorkIndexes = new int* [AllSplits];
        for (int i = 0; i < AllSplits; i++)
        {
            WorkIndexes[i] = new int[BigestGroup];
            for (int m = 0; m < BigestGroup; m++)
            {
                WorkIndexes[i][m] = 0;
            }
        }
        int Sp = 0;
        for (int i = 1; i <= PowerY; i++) {
            GenerateAllCombinations(i, Sp, WorkIndexes);
            Sp += FastNCCaluclate(WorkLength, i);
        }
        //cout << endl;
        /*for (int i = 0; i < AllSplits; i++)
        {
            for (int m = 0; m < BigestGroup; m++)
            {
                cout << WorkIndexes[i][m] << " ";
            }
            cout << endl;
        }
        */
        int* FirstMassive = new int[BigestGroup];
        int* SecondMassive = new int[BigestGroup];
        int BestDelta = 2147483647;
        cout << "Bigest group=" << BigestGroup << endl;
        for (int i = 0; i < BigestGroup; i++)
        {
            FirstMassive[i] = 0;
            SecondMassive[i] = 0;
        }

        int w = 0;
        unsigned long long AllWorks =0;
        long long Working = 0;
        for (int i = 0; i < AllSplits - 1; i++)
        {
            for (int m = i + 1; m < AllSplits; m++)
            {
                AllWorks++;
            }
        }
        for (int i = 0; i < AllSplits - 1; i++)
        {
            for (int m = i + 1; m < AllSplits; m++)
            {
                Working++;
                w++;
                if (w >= 100000)
                {
                    cout << Working << "/~" << AllWorks << endl;
                    w = 0;
                }
                bool valid = IsValide(WorkIndexes[i], WorkIndexes[m], BigestGroup, PowerX, PowerY);
                if (valid)
                {
                    int NewDelta = CalculateDelta(WorkIndexes[i], WorkIndexes[m], BigestGroup);
                    //cout << "New calculated delta=" << NewDelta << endl;
                    if (NewDelta < BestDelta)
                    {
                        cout << "Updated delta=" << NewDelta << endl;
                        for (int v = 0; v < BigestGroup; v++)
                        {
                            if (WorkIndexes[i][v] - 1 >= 0) {
                                cout << DynamicMassive[WorkIndexes[i][v] - 1] << " ";
                            }
                        }
                        cout << endl;
                        for (int v = 0; v < BigestGroup; v++)
                        {
                            if (WorkIndexes[m][v] - 1 >= 0) {
                                cout << DynamicMassive[WorkIndexes[m][v] - 1] << " ";
                            }
                        }
                        cout << endl;
                        cout << endl;
                        BestDelta = NewDelta;
                        CloneIndex(WorkIndexes[i], FirstMassive, BigestGroup);
                        CloneIndex(WorkIndexes[m], SecondMassive, BigestGroup);
                    }
                    if (BestDelta == 0)
                    {
                        i = AllSplits;
                        break;
                    }
                }
            }
        }
        cout << "Best delta=" << BestDelta << endl;

        int* FM = FirstMassive;//PowerX
        int* SM = SecondMassive;//PowerY
        if (FirstMassive[PowerY - 1] != 0 && PowerX != PowerY)
        {
            FM = SecondMassive;
            SM = FirstMassive;
        }
        cout << endl;
        cout << endl;
        for (int v = 0; v < BigestGroup; v++)
        {
            cout << FM[v] << " ";
        }
        cout << endl;
        for (int v = 0; v < BigestGroup; v++)
        {
            cout << SM[v] << " ";
        }
        cout << endl;
        cout << endl;

        for (int m = 0; m < PowerX; m++)
        {
            DDMassive[0][m] = FM[m];

        }
        for (int m = 0; m < PowerY; m++)
        {
            DDMassive[m][0] = SM[m];
        }
        int indx = 1;
        for (int i = 1; i < PowerY; i++)
        {
            for (int m = 1; m < PowerX; m++)
            {
                bool stoped = false;
                for (int s = 0; s < PowerX; s++)
                {
                    if (DDMassive[0][s] == indx)
                    {
                        indx++;
                        stoped = true;
                    }
                }
                for (int s = 0; s < PowerY; s++)
                {
                    if (DDMassive[s][0] == indx)
                    {
                        indx++;
                        stoped = true;
                    }
                }
                if (indx - 1 == WorkLength)
                {
                    DDMassive[i][m] =0;
                    continue;
                }
                if (!stoped) {
                    DDMassive[i][m] = indx;
                    indx++;
                }
                else
                {
                    m = m - 1;
                }
            }
        }
    }
    void Print()
    {
        for (int i = 0; i < PowerY; i++)
        {
            for (int m = 0; m < PowerX; m++)
            {
                if (DDMassive[i][m] - 1 >= 0) {
                    DDMassive[i][m] = DynamicMassive[DDMassive[i][m] - 1];
                }
                else
                {
                    DDMassive[i][m] = 0;
                }
                cout << DDMassive[i][m] << " ";
            }
            cout << endl;
        }
    }
    private:
    void GenerateAllCombinations(int Count, int StartGroupPosition, int** Indexes)
    {
        int* IndexesWork = new int[Count];
        for (int i = 0; i < Count; i++)
        {
            IndexesWork[i] = i + 1;
        }
        ParseByIndexes(StartGroupPosition, IndexesWork, Count, Indexes);
        int Position = 1;

        int i = Count - 1;
        bool DoBack = false;
        while (i >= 0)
        {
            if (IndexesWork[i] < WorkLength - Count + i + 1)
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
            ParseByIndexes(StartGroupPosition + Position, IndexesWork, Count, Indexes);
            Position++;
        }

    }
    void ParseByIndexes(int Position, int* Indexes, int GroupSize, int** GroupIndexes)
    {
        for (int i = 0; i < GroupSize; i++)
        {
            GroupIndexes[Position][i] = Indexes[i];
        }
    }
    long long FastNCCaluclate(int N, int K)
    {
        long long Up = 1;

        for (int i = N - K + 1; i <= N; i++)
        {
            Up *= i;
        }
        for (int V = 1; V <= K; V++)
        {
            Up /= V;
        }
        return Up;
    }
    int CalculateSum(int* Massive, int Count)
    {
        int sum = 0;
        for (int i = 0; i < Count; i++)
        {
            if (Massive[i] - 1 >= 0)
            {
                sum += DynamicMassive[Massive[i] - 1];
            }
        }
        return sum;
    }
    bool IsValide(int* FistMassive, int* SecondMassive, int Count, int PowerX, int PowerY)
    {
        bool DuplicateFound = false;
        int DupPositionFirst = -1;
        int DupPositionSecond = -1;
        int ZeroCount = 0;
        int NumbersCount = 0;

        if (PowerX != PowerY)
        {
           /* if (PowerY < Count) {
                if (FistMassive[PowerY] != 0&& SecondMassive[PowerY] != 0)
                {
                    //cout << "Error position\n";
                        return false;
                }
            }*/
            int zeros1 = 0;
            int zeros2 = 0;
            for(int i=PowerX;i<Count;i++)
            {
                if(FistMassive[i]==0)
                {
                    zeros1++;
                }
                if (SecondMassive[i] == 0)
                {
                    zeros1++;
                }
            }
            //cout << "Validate " << zeros1 << " " << zeros2 << endl;

            if (zeros1 >= zeros2) {
                
                if (Count - zeros1 != PowerX)
                {
                    return false;
                }
            }else
            {
                if (Count - zeros2 != PowerX)
                {
                    return false;
                }
            }

        }

        for (int i = 0; i < Count; i++)
        {
            if (FistMassive[i] == 0)
            {
                ZeroCount++;
            }
            else
            {
                NumbersCount++;
            }
        }
        for (int i = 0; i < Count; i++)
        {
            if (SecondMassive[i] == 0)
            {
                ZeroCount++;
            }
            else
            {
                NumbersCount++;
            }
        }

        if (PowerY != PowerX)
        {
            ZeroCount -= Count - PowerX;
        }
        if(PowerX*PowerY-ZeroCount<WorkLength)
        {
            /*for (int i = 0; i<Count; i++)
            {
                cout << FistMassive[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < Count; i++)
            {
                cout << SecondMassive[i] << " ";
            }
            cout << endl;
            cout << "Error " << (PowerX * PowerY) << " " << ZeroCount << " " << WorkLength<<" Minus="<<(Count - PowerX) << "\n";*/
            return false;
        }


        for (int i = 0; i < Count; i++)
        {
            for (int v = 0; v < Count; v++)
            {
                if (FistMassive[i] == SecondMassive[v] && FistMassive > 0)
                {
                    if (!DuplicateFound)
                    {
                        DupPositionFirst = i;
                        DupPositionSecond = v;
                        DuplicateFound = true;
                       //cout << "duped FM="<< FistMassive[i]<<" "<< SecondMassive[i];

                    }
                    else
                    {
                        //cout << "Re dupe found\n";
                        return false;
                    }
                }
            }
        }
        if (!DuplicateFound)
        {
            //cout << "Not found dupe\n";
            for (int i = 0; i < Count; i++)
            {
                for (int v = 0; v < Count; v++)
                {
                    if (FistMassive[i] == SecondMassive[v] && FistMassive == 0)
                    {
                        if (!DuplicateFound)
                        {
                            DupPositionFirst = i;
                            DupPositionSecond = v;
                            DuplicateFound = true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            if (!DuplicateFound)
            {
                //cout << "Not found dupe2\n";
                return false;
            }
        }
        int t = FistMassive[DupPositionFirst];
        FistMassive[DupPositionFirst] = FistMassive[0];
        FistMassive[0] = t;
        //cout << "DupeF=" << FistMassive[0] << endl;

        t = SecondMassive[DupPositionSecond];
        SecondMassive[DupPositionSecond] = SecondMassive[0];
        SecondMassive[0] = t;
        //cout << "DupeS=" << SecondMassive[0]<<endl;

    }

    int CalculateDelta(int* FistMassive, int* SecondMassive, int Count)
    {
        int First = 0;
        int Second = 0;
        for (int v = 0; v < Count; v++)
        {
            if (FistMassive[v] - 1 >= 0)
            {
                First += DynamicMassive[FistMassive[v] - 1];
               // cout << "D " << DynamicMassive[FistMassive[v] - 1];
            }
        }
        //cout << endl;
        for (int v = 0; v < Count; v++)
        {
            if (SecondMassive[v] - 1 >= 0)
            {
                Second += DynamicMassive[SecondMassive[v] - 1];
               // cout << "S " << DynamicMassive[SecondMassive[v] - 1];
            }
        }
        //cout << endl;
        if (First > Second)
        {
            return First - Second;
        }
        else
        {
            return Second - First;
        }
    }
    void CloneIndex(int* From, int* To, int Scale)
    {
        for (int i = 0; i < Scale; i++)
        {
            To[i] = From[i];
        }
    }
};

int main()
{
    Worker w;
    Worker w2;
    w.Init();
    w2.Init();
    cout << "W1:\n";
    w.Print();
    cout << "W2:\n";
    w2.Print();

    w2 = w2;
    w2.Print();

    w2 = w;
    w2.Print();
}