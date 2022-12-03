// Prakt_11_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class intX {
    int x;
public:
    friend intX operator+(intX& ob1, intX& ob2);

};

intX operator+(intX &ob1, intX &ob2)
{
    intX ob3;
    ob3.x = ob1.x + ob2.x;
    return ob3;
}

int main()
{
    
    std::cout << "Hello World!\n";
}
