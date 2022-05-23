#include "pt4.h"
#include <cmath>

void Solve()
{
    Task("Begin26");
    double x;
    pt >> x;
    pt << 4 * pow(x - 3, 6) - 7 * pow(x - 3, 3) + 2;
}
