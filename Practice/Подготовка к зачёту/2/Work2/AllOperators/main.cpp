#include <iostream>

using namespace std;
class Op
{
    int Length=0;
    int* V=nullptr;
public:
    Op(const Op&ob)
    {
        Length=ob.Length;
        V=new int[Length];
        for(int i=0;i<Length;i++)
        {
            V[i]=ob.V[i];
        }

    }
    Op(int length,int v)
    {
        Length=length;
        V=new int[Length];
        for(int i=0;i<Length;i++)
        {
            V[i]=v;
        }
    }
    void Print()const
    {
        cout<<"Length="<<Length<<endl;
        for(int i=0;i<Length;i++)
        {
            cout<<V[i]<<" ";
        }
        cout<<endl;
    }
    Op operator-()
    {
        Op o(Length,0);

        for(int i=0;i<Length;i++)
        {
            o.V[i]=-V[i];
        }
        return o;
    }
    Op operator+()
    {
        Op o(Length,0);

        for(int i=0;i<Length;i++)
        {
            o.V[i]=+V[i];
        }
        return o;
    }
    Op& operator +=(const Op&ob)
    {
        int* k=new int[ob.Length+Length];
        for(int i=0;i<Length;i++)
        {
            k[i]=V[i];
        }
        for(int i=Length;i<Length+ob.Length;i++)
        {
            k[i]=ob.V[i-Length];
        }
        Length=Length+ob.Length;
        delete[] V;
        V=k;
        return *this;
    }
    Op operator +(const Op&ob)
    {
        Op v(Length+ob.Length,0);
        for(int i=0;i<Length;i++)
        {
            v.V[i]=V[i];
        }
        for(int i=Length;i<Length+ob.Length;i++)
        {
            v.V[i]=ob.V[i-Length];
        }
        return v;
    }
    bool operator==(const Op &ob)
    {
        return ob.Length==Length;
    }
    bool operator!=(const Op &ob)
    {
        return ob.Length!=Length;
    }
    int& operator[](int index)
    {
        return V[index];
    }
};
int main()
{
    Op m(4,2);
    Op d=m;
    d+=d+m;
    d.Print();
    m.Print();

    cout<<"Is equal "<<(d==d)<<endl;
    cout<<m[1];
    return 0;
}
