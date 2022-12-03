#include <iostream>

using namespace std;
//Указатель Mas создан чтобы один из методов
 //выделял по нему память K размер выделяемого
// массива конструктор инициализирует даныне нулями
//для безопасности, деструктор освобождает память
class DM
{
    int *Mas;
    int K;
public:
    DM({Mas=nullptr; K=0;})
    ~DM(){delete [] Mas;}
};
int main()
{

    return 0;
}
