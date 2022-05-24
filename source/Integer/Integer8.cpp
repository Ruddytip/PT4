#include "pt4.h"

void Solve()
{
    Task("Integer8");
    int d;
    pt >> d;
    pt << (d % 10) * 10 + d / 10;
}
