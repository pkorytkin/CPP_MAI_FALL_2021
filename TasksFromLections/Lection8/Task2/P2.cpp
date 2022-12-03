#include <iostream>
using namespace std;

class Worker {
private:
    int** Values;
    double* Numbers;
    int Length = 0;
    int** ReadyIndexes = new int* [GroupsCount];
    double ReadyIndexesDelta = 2147483647;
    int SplitCount = 1;
public:
    Worker()
    {
        Request();
    }
    ~Worker()
    {
        delete[] Values;
        delete[] Numbers;
        for (int i = 0; i < GroupsCount; i++)
        {
            delete[] ReadyIndexes[i];
        }
        delete[] ReadyIndexes;
    }
    void Request()
    {
        cout << "Enter Numbers Length: ";
        cin >> Length;
        Numbers = new double[Length];
        for (int i = 0; i < Length; i++)
        {
            cin >> Numbers[i];
        }
        //cout << "Split count: ";

        //cin >> SplitCount;
        if (SplitCount >= Length)
        {
            cout << "Too many splits";
            return;
        }

        GroupsCount = 2;

        GroupSize = Length / GroupsCount;
        Calculate();

    }
private:
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
    int GroupsCount = 0;
    int GroupSize = 0;
public:
    void Calculate()
    {
        GroupsCount = 2;
        //GroupSize = Length / GroupsCount;
        GroupSize = Length - GroupsCount + 1;
        if (GroupsCount * SplitCount != Length)
        {
            GroupSize++;
        }
        int AllDevides = 0;
        int Work = 0;
        int WorkMax = 0;
        cout << "\nLength=" << Length << " MaxGroup=" << GroupSize;
        for (int i = GroupSize; i > 0; i--)
        {
            // AllDevides += Factor(Length) / ((Factor(Length - i) * Factor(i)));
            AllDevides += FastNCCaluclate(Length, i);
        }
        cout << "\nAll types" << AllDevides << endl;
        cout << "\nBigest group" << GroupSize << endl;
        int** Indexes = NULL;
        int* Sizes = NULL;

        Indexes = new int* [AllDevides];
        Sizes = new int[AllDevides];

        for (int i = 0; i < AllDevides; i++)
        {
            Indexes[i] = new int[GroupSize];
            for (int v = 0; v < GroupSize; v++)
            {
                Indexes[i][v] = 0;
            }
        }
        for (int i = 1; i <= GroupSize; i++)
        {
            int s = FastNCCaluclate(Length, i);
            GenerateAllCombinations(i, Work, Indexes);
            WorkMax += s;
            for (int v = Work; v < WorkMax; v++)
            {
                Sizes[v] = i;
            }
            Work = WorkMax;
        }
        for (int i = 0; i < AllDevides; i++)
        {
            cout << "i=" << i;
            for (int v = 0; v < GroupSize; v++)
            {
                if ((Indexes[i][v]) - 1 >= 0) {
                    cout << " " << Numbers[(Indexes[i][v]) - 1];
                }
            }
            cout << endl;
        }
        cout << endl;
        cout << endl << "Group size from 1 to " << GroupSize << endl;
        ReadyIndexes = new int* [GroupsCount];
        int** WorkIndexes = new int* [GroupsCount];
        ReadyIndexesDelta = 2147483647;
        int WorkUsedNumbers = 0;
        for (int i = 0; i < GroupsCount; i++)
        {
            ReadyIndexes[i] = new int[GroupSize];
            WorkIndexes[i] = new int[GroupSize];
            for (int v = 0; v < GroupSize; v++)
            {
                ReadyIndexes[i][v] = 0;
                WorkIndexes[i][v] = 0;
            }
        }
        int* IndexesWork = new int[GroupsCount];
        for (int i = 0; i < GroupsCount; i++)
        {
            IndexesWork[i] = i + 1;
        }
        int Position = 1;
        int i = GroupsCount - 1;
        bool DoBack = false;
        delete[] Values;
        Values = new int* [GroupsCount];
        for (int i = 0; i < GroupsCount; i++)
        {
            Values[i] = new int[GroupSize];
        }
        //Check
        for (int i = 0; i < GroupsCount; i++)
        {
            CloneIndex(Indexes[IndexesWork[i] - 1], Values[i], GroupSize);
        }
        if (CheckIsValid(Values, GroupsCount, GroupSize))
        {

            int Delta = CalculateDelta(Values, GroupSize, GroupsCount);
            cout << "Calculated Delta " << Delta << endl;
            if (ReadyIndexesDelta > Delta)
            {
                CloneIndexes(Values, ReadyIndexes, GroupSize, GroupsCount);
                ReadyIndexesDelta = Delta;
            }

        }



        int WorkNum = 0;
        long long CurrentWorked = 1;
        cout << "Count " << AllDevides << " " << GroupsCount;
        long long MaxWorked = FastNCCaluclate(AllDevides, GroupsCount);
        if (ReadyIndexesDelta > 0) {
            while (i >= 0)

            {

                if (WorkNum >= 1000000)
                {
                    cout << "Working " << CurrentWorked << "/" << MaxWorked << endl;
                    WorkNum = 0;
                }
                if (IndexesWork[i] < AllDevides - GroupsCount + i + 1)
                {
                    IndexesWork[i]++;
                    DoBack = true;
                }
                else
                {
                    i--;
                    continue;
                }

                for (int v = i + 1; v < GroupsCount; v++)
                {
                    IndexesWork[v] = IndexesWork[v - 1] + 1;
                }
                if (i < GroupsCount - 1 && DoBack)
                {
                    i = GroupsCount - 1;

                }
                //Check
                for (int i = 0; i < GroupsCount; i++)
                {
                    CloneIndex(Indexes[IndexesWork[i] - 1], Values[i], GroupSize);
                }
                if (CheckIsValid(Values, GroupsCount, GroupSize))
                {

                    double Delta = CalculateDelta(Values, GroupSize, GroupsCount);
                    cout << "Calculated Delta " << Delta << endl;
                    if (ReadyIndexesDelta > Delta)
                    {
                        CloneIndexes(Values, ReadyIndexes, GroupSize, GroupsCount);
                        ReadyIndexesDelta = Delta;
                    }
                    
                }
                WorkNum++;
                Position++;
                CurrentWorked++;
            }
        }
        delete[] Sizes;
        delete[] WorkIndexes;
        delete[] IndexesWork;
    }
    void PrintReadyGroups()
    {
        if (SplitCount == 0)
        {
            cout << "Error\n";
            return;
        }
        cout << endl;
        for (int i = 0; i < GroupsCount; i++)
        {
            for (int v = 0; v < GroupSize; v++)
            {
                if (ReadyIndexes[i][v] - 1 >= 0) {
                    cout << Numbers[ReadyIndexes[i][v] - 1] << " ";
                }
            }
            // cout << "   Offset=" << GroupOffset[i] << " Size=" << GroupNumSize[i] << endl;
            cout << endl;
        }
        cout << "\nDelta=" << ReadyIndexesDelta << endl;
    }
private:
    bool CheckIsValid(int** values, int GroupCount, int GroupSize)
    {

        return !CheckCollision(values, GroupSize, GroupCount);
    }
    bool CheckCollision(int** t1, int GroupSize, int Count)
    {
        int Num = 0;
        for (int m = 0; m < Count; m++) {
            for (int i = 0; i < GroupSize; i++)
            {
                if (t1[m][i] - 1 >= 0)
                {
                    Num++;
                }
            }
        }
        if (Num != Length)
        {
            return true;
        }
        for (int m = 0; m < Count - 1; m++) {
            for (int i = 0; i < GroupSize; i++)
            {
                for (int z = m + 1; z < Count; z++) {

                    for (int v = 0; v < GroupSize; v++)
                    {
                        if ((v == i && m != z) || v != i) {

                            if (t1[m][i] == t1[z][v] && t1[m][i] - 1 >= 0)
                            {
                                //cout << "Collision\n";
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
    void CloneIndexes(int** From, int** To, int GroupSize, int Count)
    {
        for (int v = 0; v < Count; v++)
        {
            for (int i = 0; i < GroupSize; i++)
            {
                To[v][i] = From[v][i];
            }
        }
    }
    void CloneIndex(int* From, int* To, int Scale)
    {
        for (int i = 0; i < Scale; i++)
        {
            To[i] = From[i];
        }
    }
    double CalculateDelta(int** Indexes, int GroupSize, int Count)
    {
        double Maximal = 0;
        for (int i = 0; i < GroupSize; i++)
        {
            if (Indexes[0][i] - 1 >= 0) {
                Maximal += Numbers[Indexes[0][i] - 1]-((int)Numbers[Indexes[0][i] - 1]);
            }
        }
        double Minimal = 0;
        for (int i = 0; i < GroupSize; i++)
        {
            if (Indexes[1][i] - 1 >= 0) {
                Minimal += Numbers[Indexes[1][i] - 1] - ((int)Numbers[Indexes[1][i] - 1]);
            }
        }
        Maximal -= (int)Maximal;
        Minimal -= (int)Minimal;
        return Maximal>Minimal?Maximal:Minimal;
    }
    int CalculateSum(int** Mass, int ID, int GroupSize)
    {
        int v = 0;
        for (int t = 0; t < GroupSize; t++)
        {
            v += Mass[ID][t];
        }
        return v;
    }
    void PrintIndexes(int* Indexes, int GroupSize)
    {
        cout << endl;
        for (int i = 0; i < GroupSize; i++)
        {
            cout << i << " ";
            cout << Indexes[i] << " ";

            cout << endl;
        }
        cout << endl;
    }
    void ParseByIndexes(int Position, int* Indexes, int GroupSize, int** GroupIndexes)
    {
        for (int i = 0; i < GroupSize; i++)
        {
            GroupIndexes[Position][i] = Indexes[i];
        }
    }
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
            if (IndexesWork[i] < Length - Count + i + 1)
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
};

int main()
{
    Worker w = Worker();
    w.PrintReadyGroups();
    return 0;
}