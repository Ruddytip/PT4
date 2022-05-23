#include "pt4.h"
#include <cmath>

void Solve()
{
    Task("Begin15");
    double s;
    pt >> s;
    double d = sqrt(s * 4 / 3.14);
    pt << d << 3.14 * d;
}
