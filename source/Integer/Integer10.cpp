#include "pt4.h"

void Solve()
{
    Task("Integer10");
    int d;
    pt >> d;
    pt << d % 10 << (d / 10) % 10;
}
