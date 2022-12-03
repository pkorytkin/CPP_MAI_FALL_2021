#include <iostream>

using namespace std;
//ѕередача параметра в родительский конструктор
//и в конструктор класса-наследника
class A{
public:
    A(int x){}
};
class B:public A
{
    //ƒанные
public:
    B(int x,int y):A(x){}//x дл€ A, y дл€ B
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
