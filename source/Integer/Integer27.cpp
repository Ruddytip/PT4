#include "pt4.h"

void Solve()
{
    Task("Integer27");
    int k;
    pt >> k;
    pt << (k % 7 + 5) % 7;
}
