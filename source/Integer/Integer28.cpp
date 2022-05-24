#include "pt4.h"

void Solve()
{
    Task("Integer28");
    int k, n;
    pt >> k >> n;
    pt << (k % 7 + n - 1) % 7;
}
