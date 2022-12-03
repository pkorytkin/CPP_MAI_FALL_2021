#include <iostream>

using namespace std;
//Передача параметра в родительский конструктор
//и в конструктор класса-наследника
class A {
public:
    A(int x) {}
};
class B :public A
{
    //Данные
public:
    B(int x, int y) :A(x) {}//x для A, y для B
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
