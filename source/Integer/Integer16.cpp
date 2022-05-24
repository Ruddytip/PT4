#include "pt4.h"

void Solve()
{
    Task("Integer16");
    int d;
    pt >> d;
    int a = d / 100;
    int b = (d / 10) % 10;
    int c = d % 10;
    pt << a * 100 + c * 10 + b;
}
