#include "pt4.h"

void Solve()
{
    Task("Begin34");
    double x, a;
    double y, b;
    pt >> x >> a >> y >> b;
    pt << static_cast<double>(a / x) << static_cast<double>(b / y);
    pt << static_cast<double>(a / x) / static_cast<double>(b / y);
}
