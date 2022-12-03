#include <iostream>

using namespace std;
class Parent
{
private:
    int one;
    int two;
    public:
        Parent(int One,int Two)
        {
            one=One;
            two=Two;
            cout<<"Init Parent\n";
        }
        ~Parent()
    {
        cout<<"Delete Parent\n";
    }
};
class Child:public Parent
{
    int Three;
    public:
    Child(int One,int Two,int Three):Parent(One,Two),Three(Three)
    {
        cout<<"Init Child\n";
    }
    ~Child()
    {
        cout<<"Delete Child\n";
    }
};
int main()
{
    Child c(1,2,3);
    return 0;
}
