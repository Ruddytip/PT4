#include "pt4.h"

void Solve()
{
    Task("Integer7");
    int d;
    pt >> d;
    int s = d / 10 + d % 10;
    int p = (d / 10) * (d % 10);
    pt << s << p;
}
