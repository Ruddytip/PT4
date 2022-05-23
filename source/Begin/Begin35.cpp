#include "pt4.h"

void Solve()
{
    Task("Begin35");
    double v, u, t1, t2;
    pt >> v >> u >> t1 >> t2;
    pt << v * t1 + (v - u) * t2;
}
