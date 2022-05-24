#include "pt4.h"

void Solve()
{
    Task("Integer25");
    int k;
    pt >> k;
    pt << (k % 7 + 3) % 7;
}
