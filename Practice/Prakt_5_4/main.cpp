#include <iostream>
//синтакс передачи параметра через параметр конструктору базового класса.
using namespace std;
class A
{
    public:
    //Данные
    A(int x){}
};
class C
{
    public:
    //Данные
    C(int x){}
};
class B:public A,public C
{
    //Данные
public:
    B(int x):A(x),C(x+1){}
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
