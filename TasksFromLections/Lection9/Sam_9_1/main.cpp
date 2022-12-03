#include <iostream>

using namespace std;
void Work();
class Worker
{
    static int Count;
    public:
    Worker()
    {
        Count++;
    }
    ~Worker()
    {
        Count--;
    }
    static void Show()
    {
        cout<<"Objects alive: "<<Count<<endl;
    }
};
int Worker::Count=0;
int main()
{
    cout << "Hello world!" << endl;
    Worker::Show();

    Worker *w=new Worker();
    Worker::Show();
    Worker w1=Worker();
    Worker::Show();
    Work();
    Worker::Show();
    delete (w);
    Worker::Show();
    return 0;
}
void Work()
{
    Worker w=Worker();
    Worker::Show();
}
