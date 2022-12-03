// Sam_11_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*
Динамический массив одномерный функция создаёт
функция запрашивает размер и число элементов и просит их заполнить
функция выводит на экран
реализовать оператор сложения
*/
#include <iostream>
using namespace std;
class DynMassive
{
    int* Massive=nullptr;
    int Length;
    /*DynMassive& Clone(const DynMassive& v)
    {
        DynMassive* d=new DynMassive(v.Length,false);
        if (v.Length > 0) {
            for(int i=0;i<v.Length;i++)
            {
                d->Massive[i] = v.Massive[i];
            }
        }
        return *d;
    }*/
    void Dispose()
    {
        delete[] Massive;
        Massive = nullptr;
        Length = 0;
        cout << "Destroy" << UniqueID << endl;
    }
public:
    ~DynMassive()
    {
        
        Dispose();
    }
    DynMassive()
    {
        cout << "Enter Length\n";
        cin >> Length;
        this->Length = Length;
        cout << "Enter " << Length << " Numbers\n";
        Massive = new int[Length];
        for (int i = 0; i < Length; i++)
        {
            cin >> Massive[i];
        }
    }
    void Print()
    {
        for (int i = 0; i < Length; i++)
        {
            cout << Massive[i] << " ";
        }
        cout << endl;
    }
    DynMassive operator=(DynMassive v)
    {
        if (&v == this)
        {
            return *this;
        }
        v.Print();
        Dispose();
        Length = v.Length;

        if (v.Length > 0) {
            Massive = new int[Length];
            for (int i = 0; i < v.Length; i++)
            {
                Massive[i] = v.Massive[i];
            }
        }
        return *this;
    }
    friend DynMassive operator+(const DynMassive& v1,const DynMassive& v2);
};
DynMassive operator+(const DynMassive& v1, const DynMassive& v2)
{
    //DynMassive& mas=*new DynMassive();
    DynMassive mas = DynMassive();
    mas.Dispose();
    mas.Length = max(v1.Length, v2.Length);
    mas.Massive = new int[mas.Length];
    for (int i = 0; i < mas.Length; i++)
    {
        mas.Massive[i] = 0;
    }
    for(int i=0;i<v1.Length;i++)
    {
        mas.Massive[i]+=v1.Massive[i];
    }
    for (int i = 0; i < v2.Length; i++)
    {
        mas.Massive[i] += v2.Massive[i];
    }
    mas.Print();
    return mas;
}
int main()
{
    DynMassive mass1;
    mass1.Print();

    DynMassive mass2;
    mass2.Print();
    DynMassive mass3;
    mass3.Print();
    mass3 = mass1 + mass2;
    mass3.Print();
}