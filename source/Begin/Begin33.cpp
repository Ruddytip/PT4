#include "pt4.h"

void Solve()
{
    Task("Begin33");
    double x, a ,y;
    pt >> x >> a >> y;
    pt << static_cast<double>(a / x) << static_cast<double>(a / x) * y;
}
