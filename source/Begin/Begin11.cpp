#include "pt4.h"

void Solve()
{
    Task("Begin11");
    double a, b;
    pt >> a >> b;
    pt << abs(a) + abs(b);
    pt << abs(a) - abs(b);
    pt << abs(a) * abs(b);
    pt << abs(a) / abs(b);
}
