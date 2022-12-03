#include <iostream>

using namespace std;
class A
{
public:
    A()
    {
        cout<<"vizvan konstruktor klassa A\n";
    }
    ~A()
    {
        cout<<"vizvan destruktor klassa A\n";
    }
};
class B
{
    int z;
public:

    B(int x)
    {
        cout<<"vizvan konstruktor klassa B\n"; z=x;
    }
    ~B()
    {
        cout<<"vizvan destruktor klassa B\n";
        cout<<" z="<<z<<endl;
    }
};
int main()
{
    A ob;
    B ob2(10);
    cout << "Hello world!" << endl;
    return 0;
}
