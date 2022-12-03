#include <iostream>
using namespace std;
class Matrix
{
    int matrix[3][3];

public:
    Matrix(int Number)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                matrix[y][x] = Number;
            }
        }
    }
    Matrix(const Matrix& clone)
    {
        for(int y=0;y<3;y++)
        {
            for(int x=0;x<3;x++)
            {
                matrix[y][x] = clone.matrix[y][x];
            }
        }
    }
    Matrix operator+(const Matrix &ob2)
    {
        Matrix m(*this);
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                m.matrix[y][x] += ob2.matrix[y][x];
            }
        }
        return m;
    }
    Matrix operator-(const Matrix& ob2)
    {
        Matrix m(*this);
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                m.matrix[y][x] -= ob2.matrix[y][x];
            }
        }
        return m;
    }
    Matrix& operator=(const Matrix& ob2)
    {
        if(&ob2==this)
        {
            return *this;
        }
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                matrix[y][x] = ob2.matrix[y][x];
            }
        }
        return *this;
    }
    Matrix operator*(const Matrix& ob2)
    {
        Matrix m(0);
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                for(int k=0;k<3;k++)
                {
                    m.matrix[y][x] += matrix[y][k] * ob2.matrix[k][x];
                }
            }
        }
        return m;
    }
    void Print()
    {
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                cout << matrix[y][x] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Matrix m1(1);
    m1.Print();
    Matrix m2(2);
    m2.Print();
    m1=m1 + m2;
    m1.Print();
    Matrix m3(1);
    m3.Print();
    m3=m3-m2;
    m3.Print();
    m3 = m3 * m1;
    m3.Print();
}
