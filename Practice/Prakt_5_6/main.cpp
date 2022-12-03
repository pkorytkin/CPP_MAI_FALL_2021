#include <iostream>

using namespace std;
//ѕередача параметра в родительский конструктор
//и в конструктор класса-наследника
class A{
public:
    A(int x){}
};
class B{
public:
    B(int y){}
};
class C:public A,public B
{
    //ƒанные
public:
    C(int z,int x,int y):A(x),B(y){}//z дл€ C,x дл€ A, y дл€ B
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
