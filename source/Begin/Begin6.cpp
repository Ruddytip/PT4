#include "pt4.h"

void Solve()
{
    Task("Begin6");
    double a, b, c;
    pt >> a >> b >> c;
    pt << a * b * c;
    pt << 2 * (a * b + b * c + c * a);
}
