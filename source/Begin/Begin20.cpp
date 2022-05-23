#include "pt4.h"
#include <cmath>

void Solve()
{
    Task("Begin20");
    double x1, y1;
    double x2, y2;
    pt >> x1 >> y1 >> x2 >> y2;
    pt << sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
