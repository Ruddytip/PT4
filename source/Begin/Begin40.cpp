#include "pt4.h"

void Solve()
{
    Task("Begin40");
    double a1, b1, c1;
    double a2, b2, c2;
    pt >> a1 >> b1 >> c1;
    pt >> a2 >> b2 >> c2;
    double d = a1 * b2 - a2 * b1;
    double x = (c1 * b2 - c2 * b1 ) / d;
    double y = (a1 * c2 - a2 * c1 ) / d;
    pt << x << y;
}
