#include "pt4.h"

void Solve()
{
    Task("Integer30");
    int k;
    pt >> k;
    int n = (k / 100);
    if(k % 100) ++n;
    pt << n;
}
