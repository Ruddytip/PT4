#include "pt4.h"

void Solve()
{
    Task("Integer14");
    int d;
    pt >> d;
    int a = d / 100;
    int b = (d / 10) % 10;
    int c = d % 10;
    pt << c * 100 + a * 10 + b;
}
