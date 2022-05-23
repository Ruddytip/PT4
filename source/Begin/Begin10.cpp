#include "pt4.h"

void Solve()
{
    Task("Begin10");
    double a, b;
    pt >> a >> b;
    pt << (a * a) + (b * b);
    pt << (a * a) - (b * b);
    pt << (a * a) * (b * b);
    pt << (a * a) / (b * b);
}
