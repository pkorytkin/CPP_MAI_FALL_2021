#include <iostream>

using namespace std;

int main()
{
    int a =5;
    int &ra=a;
    //����������� ����������
    //int &rb=10;

    //�� const ������ �� ��������� ���������� ������
    //int &rd=a+2;

    //cost ������ �� ��������� �����
    const int& re=12;
    const int&rg=a-4;
    //re=a+10;
    //rg=3;


    int &&rc=100;
    cout<<" rc="<<rc<<endl;
    rc++;
    cout<<" rc="<<rc<<endl;
    rc=50;
    cout<<" rc="<<rc<<endl;


    return 0;
}
