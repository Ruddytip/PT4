#include "pt4.h"

void Solve()
{
    Task("Integer12");
    int d;
    pt >> d;
    int a = d / 100;
    int b = (d / 10) % 10;
    int c = d % 10;
    pt << c * 100 + b * 10 + a;
}
