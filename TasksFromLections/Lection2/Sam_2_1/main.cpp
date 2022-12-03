#include <iostream>

using namespace std;

void func(int v[]);
void func2(int* v);
int main()
{
    int t[4];
    for(int i=0;i<4;i++){
        //t[i]=i;
        cin>>t[i];
    }
    func(t);
    cout<<endl;
    func2(t);
    cout<<endl<<sizeof(t);
    return 0;
}
void func(int v[])
{
    for(int i=0;i<4;i++){
        cout<<v[i]<<" ";
    }
}
void func2(int* v)
{
    for(int i=0;i<4;i++){
        cout<<v[i]<<" ";
    }
}
