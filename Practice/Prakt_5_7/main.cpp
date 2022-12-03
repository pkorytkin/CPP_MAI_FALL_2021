#include <iostream>

using namespace std;
//Передача параметров при множественном наследовании
class A{
public:
    A(int x){}
};
class B:public A{
public:
    B(int y,int x):A(x){}//x для A, y для B
};
class C:public B
{
    //Данные
public:
    C(int z,int x,int y):B(y,x){}//z для C,x y для B
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
